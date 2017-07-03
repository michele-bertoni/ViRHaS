#include "capturethread.h"

//#define IMG_FORMAT V4L2_PIX_FMT_YUV420
//#define IMG_FORMAT V4L2_PIX_FMT_YUYV
//#define IMG_FORMAT V4L2_PIX_FMT_RGB24
#define IMG_FORMAT V4L2_PIX_FMT_MJPEG
//#define IMG_FORMAT V4L2_PIX_FMT_YVYU
//#define IMG_FORMAT V4L2_PIX_FMT_NV12
//#define IMG_FORMAT V4L2_PIX_FMT_NV21
//#define IMG_FORMAT V4L2_PIX_FMT_H264
#define IMG_FIELD V4L2_FIELD_NONE

CaptureThread::CaptureThread(QObject *parent) : QThread(parent)
{
	setDeviceName("/dev/video0");
}

void CaptureThread::print_errno(const char *s)
{
	fprintf(stderr, "%s error %d, %s\n", s, errno, strerror(errno));
}

int CaptureThread::xioctl(int fh, int request, void *arg)
{

	int r;

	do {
		r = ioctl(fh, request, arg);
	} while (-1 == r && EINTR == errno);

	return r;
}

void CaptureThread::setResolution(QSize s)
{
	if(!this->isRunning())
        resolution = s;
}

int CaptureThread::read_frame()
{
	struct v4l2_buffer buf;
	CLEAR(buf);
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	buf.memory = V4L2_MEMORY_MMAP;
	if (-1 == xioctl(fd, VIDIOC_DQBUF, &buf)) {
		switch (errno) {
		case EAGAIN:
			return 0;

		case EIO:
			/* Could ignore EIO, see spec. */

			/* fall through */

		default:
			print_errno("VIDIOC_DQBUF");
		}
	}
	process_image(buffers[buf.index].start, buf.bytesused);
	if (-1 == xioctl(fd, VIDIOC_QBUF, &buf))
		print_errno("VIDIOC_QBUF");
	return 1;
}

bool CaptureThread::start_capturing()
{
	unsigned int i;
	enum v4l2_buf_type type;
	bool ok = true;

	for (i = 0; i < n_buffers; ++i) {
		struct v4l2_buffer buf;

		CLEAR(buf);
		buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory = V4L2_MEMORY_MMAP;
		buf.index = i;

		if (-1 == xioctl(fd, VIDIOC_QBUF, &buf))
		{
			print_errno("VIDIOC_QBUF");
			ok = false;
		}
	}
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if (-1 == xioctl(fd, VIDIOC_STREAMON, &type))
	{
		print_errno("VIDIOC_STREAMON");
		ok = false;
	}
	return ok;
}

void CaptureThread::stop_capturing()
{
	enum v4l2_buf_type type;
	type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	if (-1 == xioctl(fd, VIDIOC_STREAMOFF, &type))
		print_errno("VIDIOC_STREAMOFF");
}

void CaptureThread::init_mmap()
{
	struct v4l2_requestbuffers req;

	CLEAR(req);

	req.count = 4;
	req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	req.memory = V4L2_MEMORY_MMAP;

	if (-1 == xioctl(fd, VIDIOC_REQBUFS, &req)) {
		if (EINVAL == errno) {
			fprintf(stderr, "%s does not support "
                 "memory mapping\n", (char*)deviceName.toUtf8().constData());
		} else {
			print_errno("VIDIOC_REQBUFS");
		}
	}

	if (req.count < 2) {
		fprintf(stderr, "Insufficient buffer memory on %s\n",
             (char*)deviceName.toUtf8().constData());
	}

	buffers = (buffer*)calloc(req.count, sizeof(*buffers));

	if (!buffers) {
		fprintf(stderr, "Out of memory\n");
	}

	for (n_buffers = 0; n_buffers < req.count; ++n_buffers) {
		struct v4l2_buffer buf;

		CLEAR(buf);

		buf.type	= V4L2_BUF_TYPE_VIDEO_CAPTURE;
		buf.memory	  = V4L2_MEMORY_MMAP;
		buf.index	   = n_buffers;

		if (-1 == xioctl(fd, VIDIOC_QUERYBUF, &buf))
			print_errno("VIDIOC_QUERYBUF");

		buffers[n_buffers].length = buf.length;
		buffers[n_buffers].start =
			mmap(NULL /* start anywhere */,
				  buf.length,
				  PROT_READ | PROT_WRITE /* required */,
				  MAP_SHARED /* recommended */,
				  fd, buf.m.offset);

		if (MAP_FAILED == buffers[n_buffers].start)
			print_errno("mmap");
	}
}

bool CaptureThread::init_device()
{
	struct v4l2_capability cap;
	struct v4l2_cropcap cropcap;
	struct v4l2_crop crop;
	unsigned int min;
	bool ok = true;

	if (-1 == xioctl(fd, VIDIOC_QUERYCAP, &cap)) {
		if (EINVAL == errno) {
			fprintf(stderr, "%s is no V4L2 device\n",
                 (char*)deviceName.toUtf8().constData());
		} else {
			print_errno("VIDIOC_QUERYCAP");
		}
		ok = false;
	}

	if (!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)) {
		fprintf(stderr, "%s is no video capture device\n",
             (char*)deviceName.toUtf8().constData());
		ok = false;
	}
	if (!(cap.capabilities & V4L2_CAP_STREAMING)) {
		fprintf(stderr, "%s does not support streaming i/o\n",
             (char*)deviceName.toUtf8().constData());
		ok = false;
	}

	/* Select video input, video standard and tune here. */


	CLEAR(cropcap);

	cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	if (0 == xioctl(fd, VIDIOC_CROPCAP, &cropcap)) {
		crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
		crop.c = cropcap.defrect; /* reset to default */

		if (-1 == xioctl(fd, VIDIOC_S_CROP, &crop)) {
			switch (errno) {
			case EINVAL:
				/* Cropping not supported. */
				break;
			default:
				/* Errors ignored. */
				break;
			}
			ok = false;
		}
	} else {
		/* Errors ignored. */
	}


	CLEAR(fmt);

	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	fmt.fmt.pix.width	   = resolution.width();
	fmt.fmt.pix.height	  = resolution.height();
	fmt.fmt.pix.pixelformat = IMG_FORMAT;
	fmt.fmt.pix.field	   = IMG_FIELD;

	if (-1 == xioctl(fd, VIDIOC_S_FMT, &fmt))
	{
		print_errno("VIDIOC_S_FMT");
		ok = false;
	}
/*
	if (-1 == xioctl(fd, VIDIOC_G_FMT, &fmt))
		print_errno("VIDIOC_G_FMT");
*/
		/* Note VIDIOC_S_FMT may change width and height. */

	/* Buggy driver paranoia. */
	min = fmt.fmt.pix.width * 2;
	if (fmt.fmt.pix.bytesperline < min)
		fmt.fmt.pix.bytesperline = min;
	min = fmt.fmt.pix.bytesperline * fmt.fmt.pix.height;
	if (fmt.fmt.pix.sizeimage < min)
		fmt.fmt.pix.sizeimage = min;

	init_mmap();
	return ok;
}

void CaptureThread::uninit_device(void)
{
	unsigned int i;
		for (i = 0; i < n_buffers; ++i)
			if (-1 == munmap(buffers[i].start, buffers[i].length))
				print_errno("munmap");
	free(buffers);
}

void CaptureThread::close_device()
{
	if (-1 == close(fd))
		print_errno("close");

	fd = -1;
}

bool CaptureThread::open_device()
{
	struct stat st;
	bool ok = true;

    if (-1 == stat((char*)deviceName.toUtf8().constData(), &st)) {
		fprintf(stderr, "Cannot identify '%s': %d, %s\n",
             (char*)deviceName.toUtf8().constData(), errno, strerror(errno));
		ok = false;
	}
	else if (!S_ISCHR(st.st_mode)) {
        fprintf(stderr, "%s is no device\n", (char*)deviceName.toUtf8().constData());
		ok = false;
	}
	else
	{
        fd = open((char*)deviceName.toUtf8().constData(), O_RDWR /* required */ | O_NONBLOCK, 0);

		if (-1 == fd) {
			fprintf(stderr, "Cannot open '%s': %d, %s\n",
                 (char*)deviceName.toUtf8().constData(), errno, strerror(errno));
			ok = false;
		}
	}
	return ok;
}

void CaptureThread::mainloop(void)
{
	while (!mustStop) {
		fd_set fds;
		struct timeval tv;
		int r;

		FD_ZERO(&fds);
		FD_SET(fd, &fds);

		/* Timeout. */
		tv.tv_sec = 2;
		tv.tv_usec = 0;

		r = select(fd + 1, &fds, NULL, NULL, &tv);

		if (-1 == r) {
				if (EINTR == errno)
						continue;
				print_errno("select");
		}

		if (0 == r) {
				fprintf(stderr, "select timeout\n");
		}

		read_frame();
		QCoreApplication::processEvents();
	}
	mustStop = false;
}

void CaptureThread::run()
{
	open_device();
	init_device();
	start_capturing();
	mainloop();
	stop_capturing();
	uninit_device();
	close_device();
}

void CaptureThread::process_image(const void *p, int size)
{
	emit newFrame((char*)p,size);




	/*
	QByteArray ba((unsigned char*)p,size);
	qDebug()<<"source array size:"<<ba.size();
	QElapsedTimer timer;

	for(int i = 0; i < 10; i++)
	{
		timer.start();
		QByteArray dest = qCompress(ba,i);
		qDebug()<<"quality ="<<i<<", compressed size ="<<dest.size()<<", time ="<<timer.elapsed();
	}

	emit renderedImage(ba);
	*/
	/*
	char header [50];
	sprintf(header,"P6\n%d %d 255\n",fmt.fmt.pix.width,fmt.fmt.pix.height);
	int len = size+qstrlen(header);
	unsigned char* asil=(unsigned char*)malloc(len);
	memcpy(asil, header, qstrlen(header));
	memcpy(asil+qstrlen(header), p, size);
	QImage *qq=new QImage();
	if(qq->loadFromData(asil,len,"PPM")){
		emit renderedImage(*qq);
	}
	else
		qDebug()<<"loadFromData failed";
	free(asil);
	delete qq;*/
}

CaptureThread::~CaptureThread()
{
}

void CaptureThread::stopCapture()
{
	mustStop = true;
}

void CaptureThread::setDeviceName(QString s) {
	deviceName=s;
}

void CaptureThread::setFps(int fps){
    if(!this->isRunning())
        this->set_framerate(fps);
}

bool CaptureThread::set_framerate(int fps){
    struct v4l2_streamparm parm;

    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    parm.parm.capture.timeperframe.numerator = 1;
    parm.parm.capture.timeperframe.denominator = fps;

    int ret = xioctl(this->fd, VIDIOC_S_PARM, &parm);

    if(ret < 0){
        return false;
    }

    this->fps=fps;
    return true;

}

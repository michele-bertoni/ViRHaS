#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QCoreApplication>
#include <QDataStream>
#include <QString>
#include <QDebug>
#include <QBuffer>
#include <QImage>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <typeinfo>
#include <iostream>
#include <libv4l2.h>
#include <libv4lconvert.h>
#include <QElapsedTimer>
#include <QSize>

#define CLEAR(x) memset(&(x), 0, sizeof(x))
#define DEFAULT_IMG_WIDTH 1280
#define DEFAULT_IMG_HEIGHT 720

class CaptureThread : public QThread
{
	Q_OBJECT

public:
	CaptureThread(QObject *parent = 0);
	~CaptureThread();
	void setDeviceName(QString s);
	QSize getResolution(){ return resolution; }
	void setResolution(QSize s);
    void setFps(int fps);

public slots:
	void stopCapture();

protected:
	void run();
	bool initDevice();
signals:
	void newFrame(char* data, int size);

private:
	QString deviceName;
    QSize resolution;
    int fps;
	bool mustStop = false;
	struct buffer {
		void   *start;
		size_t  length;
	};
	int				fd = -1;
	buffer			*buffers = NULL;
	unsigned int	n_buffers = 0;
	int				out_buf = 0;
	struct v4l2_format fmt;
	static void print_errno(const char *s);
	static int xioctl(int fh, int request, void *arg);
	int read_frame();
	bool start_capturing();
	void stop_capturing();
	void init_mmap();
	bool init_device();
	void uninit_device();
	void close_device();
	bool open_device();
	void mainloop();
	void process_image(const void *p, int size);
    bool set_framerate(int fps);
};

#endif // CAPTURETHREAD_H

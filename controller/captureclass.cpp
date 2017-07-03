#include "captureclass.h"

CaptureClass::CaptureClass(QObject *parent) :
	QObject(parent)
{
    cap = new CaptureThread(this);
    vserver = new WebSocketServer(this, Video);

    connect(cap, SIGNAL(newFrame(char*, int)), vserver, SLOT(onNewFrame(char*, int)), Qt::BlockingQueuedConnection);
    connect(vserver, SIGNAL(newVideoSettings(vidsett_t)), this, SLOT(startRecording(vidsett_t)));
    connect(vserver, SIGNAL(clientDisconnected()), this, SLOT(stopRecording()));

}

bool CaptureClass::isRecording(){
    return cap->isRunning();
}

void CaptureClass::startRecording(vidsett_t resolution){
    if(this->isRecording()){
        return;
    }
    cap->setResolution(QSize(resolution.res_w, resolution.res_h));
    cap->setFps(resolution.fps);
    cap->start();
}

void CaptureClass::stopRecording(){
    cap->stopCapture();
}

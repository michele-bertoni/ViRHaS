#include "camerastream.h"

CameraStream::CameraStream(QObject *parent) : QObject(parent)
{
    socket = new QWebSocket("", QWebSocketProtocol::VersionLatest, this);

    socket->open(QUrl("ws://192.168.1.3:9696/"));

    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onNewFrame(QByteArray)));
}

void CameraStream::onNewFrame(QByteArray frame){
    emit newFrame(&frame);
}

void CameraStream::disconnectFromHost(){
    socket->close();
    socket->deleteLater();
}

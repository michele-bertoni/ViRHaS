#include "controlstransmission.h"

ControlsTransmission::ControlsTransmission(QObject *parent) : QObject(parent)
{
    socket = new QWebSocket("", QWebSocketProtocol::VersionLatest, this);
}

void ControlsTransmission::connectToHost(){
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    socket->open(QUrl("ws://192.168.1.3:9999/"));

    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onReceivedNewMessage(QByteArray)));
}

void ControlsTransmission::onReceivedNewMessage(QByteArray message){
    int type, message_key;

    //message types: 0= NULL, 1= newConnection messages, 2= videoMessages
    //message keys: type 1: 1= connection estabilished, 2= connection refused for too many hosts
    //              type 2: 1= OK, 2= camera 1 busy, 3= camera 2 busy, 4= cameras 1 and 2 busy

    QDataStream stream(message);

    stream.setVersion(QDataStream::Qt_5_2);
    stream  >> type
            >> message_key;

    emit newMessage(type, message_key);
}

void ControlsTransmission::onError(QAbstractSocket::SocketError error){
    emit newError(error, socket->errorString());
}

void ControlsTransmission::sendControls(int action, double value){
    control_t control;
    QByteArray byte_control;
    QDataStream stream(&byte_control, QIODevice::ReadWrite);

    int flag=1;

    control.action = action;
    control.value = (float)value;

    stream.setVersion(QDataStream::Qt_5_2);
    stream.setFloatingPointPrecision(QDataStream::SinglePrecision);

    stream  << flag
            << control.action
            << control.value;

    socket->sendBinaryMessage(byte_control);
    socket->flush();
}

void ControlsTransmission::sendSettings(vidsett_t videosettings){
    QByteArray byte_control;
    QDataStream stream(&byte_control, QIODevice::ReadWrite);

    int flag=2;

    stream.setVersion(QDataStream::Qt_5_2);

    stream  << flag
            << videosettings.res_w
            << videosettings.res_h
            << videosettings.fps
            << videosettings.lcam
            << videosettings.rcam;

    socket->sendBinaryMessage(byte_control);
    socket->flush();
}

void ControlsTransmission::sendMessage(int type, int message_key){
    QByteArray message;
    QDataStream stream(&message, QIODevice::ReadWrite);

    stream.setVersion(QDataStream::Qt_5_2);

    stream  << type
            << message_key;

    socket->sendBinaryMessage(message);
    socket->flush();
}

void ControlsTransmission::disconnectFromHost(){
    socket->close();
    socket->deleteLater();
}

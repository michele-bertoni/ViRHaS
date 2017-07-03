#include "websocketclient.h"

WebSocketClient::WebSocketClient(QObject *parent, ServerType stype) : QObject(parent)
{
    //members initialization
    this->servertype = stype;   //set server type passed through constructor
    this->status = Disconnected;    //initialize server status as disconnected from client
    this->pairingflag = false;  //client needs to receive a response to its handshake from server
    this->serverurl = this->wsUrlContructor();  //initialize url of default server, using servertype information

    this->socket = new QWebSocket("", QWebSocketProtocol::VersionLatest, this);

    //socket 'connects' initialization
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError))); //in case of errors
    connect(socket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onReceivedNewMessage(QByteArray)));   //received messages pairing
    connect(socket, SIGNAL(disconnected()), this, SLOT(onWSDisconnession()));   //disconnession pairing

}

ServerType WebSocketClient::getServerType()
{
    return this->servertype;    //returns the type of the server this socket is or may be connected to
}

bool WebSocketClient::isConnected()
{
    if(this->status == Connected)   //if connection is estabilished returns true
        return true;

    return false;   //otherwise returns false
}

void WebSocketClient::connectSocket()
{
    socket->open(this->serverurl);  //opens WebSocket with the server having the url given by wsUrlConstructor() method
    this->status = Connected;    //set server status as connected to client
}

void WebSocketClient::disconnectSocket()
{
    socket->close();
}

QUrl WebSocketClient::wsUrlContructor()
{
    //url construction in the form of "ws://'IPv4_address':'port'/"
    QString surl(WS_URL_PREFIX);

    switch(this->servertype){
    case Control:
        surl.append(CONTROL_SERVER_IP);
        surl.append(WS_URL_SEPARATOR);
        surl.append(CONTROL_SERVER_PORT);
        break;

    case Camera_1:
        surl.append(CAMERA1_SERVER_IP);
        surl.append(WS_URL_SEPARATOR);
        surl.append(CAMERA1_SERVER_PORT);
        break;

    case Camera_2:
        surl.append(CAMERA2_SERVER_IP);
        surl.append(WS_URL_SEPARATOR);
        surl.append(CAMERA2_SERVER_PORT);
        break;
    }

    surl.append(WS_URL_SUFFIX);

    return QUrl(surl);  //returns a QUrl object
}

void WebSocketClient::onReceivedNewMessage(QByteArray message)
{

    if(!this->pairingflag || this->servertype == Control){
        QDataStream stream(message);
        int type;
        bool serverstatus;
        int message;

        stream.setVersion(QDataStream::Qt_5_2);

        stream >> type;

        if(type == STATUS_MSG){
            stream  >> serverstatus;
            std::cout << type << ", " << serverstatus <<"\n";
        }
        else if(type == EVENT_MSG){
            stream >> message;

            emit newEvent(message);

        }
        else{
            this->socket->close();
            this->connectSocket();
            return;
        }
        if(serverstatus){
            this->pairingflag = true;   //handshake completed
            //std::cout << this->servertype << " paired\n";
            emit connectionStatusChanged(Connected);
        }
    }
    else{
        emit newFrame(&message);
    }
}

void WebSocketClient::onError(QAbstractSocket::SocketError error)
{
    emit newError(error, socket->errorString());
}

void WebSocketClient::onWSDisconnession()
{
    this->status = Disconnected;    //set server status as disconnected from client
    emit connectionStatusChanged(this->status);
    this->pairingflag = false;  //client needs to receive a response to its handshake from server
}

void WebSocketClient::sendControls(int action, double value){
    if(this->servertype != Control)
        return;
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

void WebSocketClient::sendSettings(vidsett_t videosettings){
    if(this->servertype != Camera_1 && this->servertype != Camera_2)
        return;
    QByteArray byte_control;
    QDataStream stream(&byte_control, QIODevice::ReadWrite);

    std::cout << "Sending videosettings: ";

    int flag=VIDSETTS_MSG;

    stream.setVersion(QDataStream::Qt_5_2);

    stream  << flag
            << videosettings.res_w
            << videosettings.res_h
            << videosettings.fps;

    std::cout << flag << ", "
              << videosettings.res_w << ", "
              << videosettings.res_h << ", "
              << videosettings.fps << "\n";

    socket->sendBinaryMessage(byte_control);
    socket->flush();
}


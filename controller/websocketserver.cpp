#include "websocketserver.h"

WebSocketServer::WebSocketServer(QObject *parent, ServerType type) : QObject(parent)
{
    server = new QWebSocketServer("", QWebSocketServer::NonSecureMode, this);

    status = Ok;
    this->servertype = type;

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(this->servertype == Control)
        this->port = 9999;
    else if(this->servertype == Video)
        this->port = 9696;

    if(!server->listen(QHostAddress::Any, this->port)){
        std::cout << "Server on port " << this->port << " could not start!\n";
    }
    else{
        std::cout << "Server started on port " << this->port << "...\n";
    }
}

void WebSocketServer::newConnection()
{
    QByteArray connection_message;
    QDataStream stream(&connection_message, QIODevice::ReadWrite);
    QString peeraddress;

    int type;
    bool message;

    stream.setVersion(QDataStream::Qt_5_2);

    QWebSocket* tmpclient = server->nextPendingConnection();
    peeraddress=tmpclient->peerAddress().toString();
    std::cout << "New connection: " << peeraddress.toStdString() << "\n";

    type = STATUS_MSG;
    if (this->status == Ok) {
        message = OK;
        client = tmpclient;

        //Grab the socket and assign it to the socket holder
        connect(client, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onReceivedNewMessage(QByteArray)));
        connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnession()));
    }
    else{
        message = BUSY;
    }

    stream << type
           << message;

    tmpclient->sendBinaryMessage(connection_message);
    tmpclient->flush();

    if(this->status == Busy){
        tmpclient->close();
        tmpclient->deleteLater();
        return;
    }

    status = Busy;
}

void WebSocketServer::onReceivedNewMessage(QByteArray arr){
    QDataStream stream(arr);
    int type;

    //std::cout << "New data: " << arr.toStdString() <<"\n";
    //client->write("Ricevuto\n");

    stream.setVersion(QDataStream::Qt_5_2);
    stream.setFloatingPointPrecision(QDataStream::SinglePrecision);

    stream >> type;

    if(type == CONTROL_MSG && servertype == Control){
        control_t control;

        stream  >> control.action
                >> control.value;
        emit controlEdited(control);
        //std::cout << control.action << ", " << control.value <<"\n";
    }

    else if(type == VIDSETTS_MSG && servertype == Video){
        vidsett_t videosettings;

        stream  >> videosettings.res_w
                >> videosettings.res_h
                >> videosettings.fps;

        emit newVideoSettings(videosettings);
        std::cout << videosettings.res_w << ", " << videosettings.res_h << ", " << videosettings.fps << "\n";
    }

    else if(type == CLOSECONNECTION_MSG){
        client->close();
    }

}

void WebSocketServer::onNewFrame(char *data, int size){
    if(status == Busy && this->servertype == Video){
        QByteArray frame(data, size);

        client->sendBinaryMessage(frame);
        client->flush();

        //std::cout << "Frame sent\n";
    }
}

void WebSocketServer::onNewEvent(RobotEvent ev)
{
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::ReadWrite);
    stream.setVersion(QDataStream::Qt_5_2);

    int type = EVENT_MSG;
    int message = (int)ev;

    stream << type
           << message;

    client->sendBinaryMessage(arr);
    client->flush();
}

void WebSocketServer::onClientDisconnession(){
    emit clientDisconnected();
    status = Ok;
    client->deleteLater();
    std::cout << "Client disconnected\n";
}

#include "controlserver.h"

ControlServer::ControlServer(QObject *parent) : QObject(parent)
{
    server = new QWebSocketServer("", QWebSocketServer::NonSecureMode, this);

    controlstatus = Ok;

    camstatus = Ok;

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 9999)){
        std::cout << "Server could not start\n";
    }
    else{
        std::cout << "Server started...\n";
    }

}


void ControlServer::newConnection(){
    QByteArray connection_message;
    QDataStream stream(&connection_message, QIODevice::ReadWrite);
    QString peeraddress;

    int type, message;

    stream.setVersion(QDataStream::Qt_5_2);

    QWebSocket* s = server->nextPendingConnection();
    tmpclient->append(s);
    peeraddress=s->peerAddress().toString();
    std::cout << "New connection: " << peeraddress.toStdString() << "\n";

    type = 1;
    if (this->controlstatus == Ok) {
        message = 1;
    }
    else{
        message = 0;
    }

    stream << type
           << message;

    s->sendBinaryMessage(connection_message);
    s->flush();

    type = 2;
    if (this->camstatus == Ok) {
        message = 1;
    }
    else{
        message = 0;
    }

    stream << type
           << message;

    s->sendBinaryMessage(connection_message);
    s->flush();

    //Grab the socket and assign it to the socket holder

    connect(s, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onReceivedNewMessage(QByteArray)));

    return;
}

void ControlServer::onReceivedNewMessage(QByteArray arr){
    QDataStream stream(arr);
    int flag;

    //std::cout << "New data: " << arr.toStdString() <<"\n";
    //client->write("Ricevuto\n");

    stream.setVersion(QDataStream::Qt_5_2);
    stream.setFloatingPointPrecision(QDataStream::SinglePrecision);

    stream  >> flag;

    if(flag == 1){
        control_t control;

        stream  >> control.action
                >> control.value;
        emit controlEdited(control.action, control.value);
        //std::cout << control.action << ", " << control.value <<"\n";
    }
    else if(flag == 2){        
        vidsett_t videosettings;

        stream  >> videosettings.res_w
                >> videosettings.res_h
                >> videosettings.fps;

        emit newVideoSettings(videosettings);

        /*std::cout << videosettings.res_w << ", "
                    << videosettings.res_h << ", "
                    << videosettings.fps << ", "
                    << camflag.lcam << ", "
                    << camflag.rcam << "\n";*/
    }
    else if(flag == 3){
        int message;

        stream >> message;

        if(message == 0){
            tmpclient->close();
        }
        else if(message == 1){
            client = tmpclient
        }

    }

}



void ControlServer::sendMessageToClient(int type, int key_message){
    QByteArray message;
    QDataStream stream(&message, QIODevice::ReadWrite);

    stream << type
           << key_message;

    client->sendBinaryMessage(message);
    client->flush();
}

void ControlServer::sendMessageToTmpClient(int type, int key_message){
    QByteArray message;
    QDataStream stream(&message, QIODevice::ReadWrite);

    stream << type
           << key_message;

    tmpclient->sendBinaryMessage(message);
    tmpclient->flush();
}

void ControlServer::onClientDisconnession(){
    client->deleteLater();
    status = Disconnected;
    std::cout << "Client disconnected\n";

}

void ControlServer::onRefusedClientDisconnession(){
    refusedclient->deleteLater();
}

void ControlServer::onSlaveDisconnession(){
    slave->deleteLater();
    slavestatus = Disconnected;
    std::cout << "Slave disconnected\n";

}

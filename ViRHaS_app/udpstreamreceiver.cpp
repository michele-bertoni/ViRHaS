#include "udpstreamreceiver.h"

UdpStreamReceiver::UdpStreamReceiver(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);

    time = new QTime();
    time->start();

    int i;
    char c;
    for(i=0, c=0; i<PKTSZ; i++){
        nulldatagram.append(c);
    }

    emit newError(QString("New Socket"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeftPointer()));
    timer->start(TIMEOUT);
}

void UdpStreamReceiver::bind(bool flagcam)
{
    if(!flagcam){  //left camera
        socket->bind(QHostAddress::Any, PORT1, QUdpSocket::ShareAddress);
        //emit newError(QString("Bind"));
    }
    else            //rifght camera
        socket->bind(QHostAddress("192.168.1.4"), PORT2, QUdpSocket::ShareAddress);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onNewDatagram()));

    this->flagcam = flagcam;
}

void UdpStreamReceiver::joinFrame()
{
    quint16 joinpointer=nextframepointer;
    bool end = false;

    frame.clear();

    while(!end){
        if(packet[joinpointer].isValid){
            joinpointer -= packet[joinpointer].nsegment;
            end = true;
        }
        else{
            joinpointer--;
        }
    }

    if(!packet[joinpointer].isValid){
        this->skipFrame(joinpointer);
        return;
    }

    do{
        if(packet[joinpointer].isValid){
            frame.append(packet[joinpointer].datagram);
            packet[joinpointer].isValid = false;
        }
        else{
            frame.append(nulldatagram);
        }
    }
    while(joinpointer != nextframepointer);

    emit newFrame(&frame);
    emit newError(QString("New frame\n"));

}

void UdpStreamReceiver::onNewDatagram()
{
    while(socket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        QDataStream stream(datagram);
        quint16 segmentnumber;
        quint16 packetnumber;

        stream >> packetnumber
               >> segmentnumber;

        if(packet[packetnumber].isValid)
            return;

        packet[packetnumber].datagram = datagram.right(datagram.size() - sizeof(segmentnumber) - sizeof(packetnumber));
        packet[packetnumber].isValid = true;
        packet[packetnumber].nsegment = segmentnumber;

        this->moveRightPointer(segmentnumber);

        //emit newError(QString("New packet"));

    }
}

void UdpStreamReceiver::moveLeftPointer()
{
    int timeelapsed = time->elapsed();
    bool flag = false;
    bool precisvalid = true;
    quint16 fpacket;

    while(!flag && leftpointer!=rightpointer){
        if(!packet[leftpointer].isValid){
            if(timeelapsed-packet[leftpointer].msec>=TIMEOUT){
                if(precisvalid){
                    fpacket = this->leftpointer;
                    precisvalid = false;
                }
             }
        }
        else{
            if(nextframepointer != leftpointer-(packet[leftpointer].nsegment+1)){
                nextframepointer=leftpointer-(packet[leftpointer].nsegment+1);
                QTimer::singleShot(2, this, SLOT(joinFrame()));
            }
            if(!precisvalid){
                sendNacks(fpacket, this->leftpointer-1);
                precisvalid = true;
            }
        }
        if(!precisvalid){
            sendNacks(fpacket, this->leftpointer-1);
        }
        this->leftpointer++;
    }
}

void UdpStreamReceiver::moveRightPointer(quint16 currentposition)
{
    int timeelapsed = time->elapsed();

    while(this->rightpointer != currentposition){
        if(!packet[this->rightpointer].isValid){
            packet[this->rightpointer].msec = timeelapsed;
        }
        this->rightpointer++;
    }
}

void UdpStreamReceiver::sendNacks(quint16 fpacket, quint16 lpacket)
{
    QByteArray nack;
    QDataStream stream(&nack, QIODevice::ReadWrite);

    stream << fpacket
           << lpacket;

    if(this->flagcam==0)  //left camera
        socket->writeDatagram(nack, QHostAddress("192.168.1.7"), PORT1);
    else            //rifght camera
        socket->writeDatagram(nack, QHostAddress("192.168.1.4"), PORT2);
}

void UdpStreamReceiver::skipFrame(quint16 skippointer)
{
    do{
        packet[skippointer].isValid = false;
    } while(skippointer != nextframepointer);
}

void UdpStreamReceiver::disconnectFromHost()
{
    socket->disconnectFromHost();
    socket->deleteLater();
}


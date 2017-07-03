#ifndef UDPSTREAMRECEIVER_H
#define UDPSTREAMRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
#include <QTime>
#include <QTimer>

#define PKTSZ 1000
#define MAXNPKT 65536
#define PORT1 9696
#define PORT2 9797
#define TIMEOUT 2   //msecs elapsed before retrasmission request

typedef struct buffer_s{
    QByteArray datagram;
    quint16 nsegment;
    bool isValid;
    int msec;
} buffer_t;

class UdpStreamReceiver : public QObject
{
    Q_OBJECT
public:
    explicit UdpStreamReceiver(QObject *parent = 0);
    void bind(bool flagcam);
    bool flagcam;
    QByteArray frame;

signals:
    void newFrame(QByteArray* frame);
    void newError(QString);

public slots:
    void joinFrame();
    void moveLeftPointer();

private:
    QUdpSocket *socket;
    QByteArray nulldatagram;
    buffer_t packet[65536];
    quint16 leftpointer; //first non-requested empty cell
    quint16 rightpointer; //latest segment number
    QByteArray buffer;
    QTime *time;
    QTimer *timer;
    void moveRightPointer(quint16 currentposition);
    void sendNacks(quint16 fpacket, quint16 lpacket);
    void skipFrame(quint16 skippointer);
    quint16 nextframepointer;
    void disconnectFromHost();


private slots:
    void onNewDatagram();
};

#endif // UDPSTREAMRECEIVER_H

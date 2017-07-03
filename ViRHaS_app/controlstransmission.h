#ifndef CONTROLSTRANSMISSION_H
#define CONTROLSTRANSMISSION_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QHostAddress>
#include <QIODevice>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QUrl>
#include <QAbstractSocket>

#define SERVER_IP_ADDRESS "192.168.1.3"
#define SERVER_PORT 9999

typedef struct control_s{
    int action;
    float value;
} control_t;

typedef struct vidsett_s{
    int res_w, res_h, fps;
    bool lcam, rcam;

} vidsett_t;


class ControlsTransmission : public QObject
{
    Q_OBJECT
public:
    explicit ControlsTransmission(QObject *parent = 0);
    void connectToHost();
    void sendControls(int action, double value);
    void disconnectFromHost();
    void sendSettings(vidsett_t videosettings);
    void sendMessage(int type, int message_key);

signals:
    void newMessage(int, int);
    void newError(QAbstractSocket::SocketError, QString);

public slots:

private:
    QWebSocket* socket;

private slots:
    void onReceivedNewMessage(QByteArray message);
    void onError(QAbstractSocket::SocketError error);

};

#endif // CONTROLSTRANSMISSION_H

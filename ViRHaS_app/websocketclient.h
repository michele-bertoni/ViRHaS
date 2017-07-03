#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QWebSocket>
#include <QHostAddress>
#include <QIODevice>
#include <QUrl>
#include <QString>
#include <QAbstractSocket>
#include "status_enum.h"
#include "server_information.h"
#include "robot_structures.h"
#include <iostream>

#define BUSY false
#define OK true

#define STATUS_MSG 1
#define EVENT_MSG 2

#define CONTROL_MSG 1
#define VIDSETTS_MSG 2
#define CLOSECONNECTION_MSG 3

class WebSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClient(QObject *parent = 0, ServerType stype = Control);
    ServerType getServerType();
    bool isConnected();
    void connectSocket();
    void disconnectSocket();

signals:
    void connectionStatusChanged(State);
    void newFrame(QByteArray*);
    void newError(QAbstractSocket::SocketError, QString);
    void newEvent(int eventType);

public slots:
    void sendSettings(vidsett_t videosettings);
    void sendControls(int action, double value);

private:
    QWebSocket* socket;
    ServerType servertype;
    QUrl serverurl;
    State status;
    QUrl wsUrlContructor();
    bool pairingflag;

private slots:
    void onReceivedNewMessage(QByteArray message);
    void onError(QAbstractSocket::SocketError error);
    void onWSDisconnession();

};

#endif // WEBSOCKETCLIENT_H

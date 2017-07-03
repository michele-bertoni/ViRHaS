#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <QObject>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <status_enum.h>
#include <vidsett.h>
#include <events_enum.h>

#define BUSY false
#define OK true

#define STATUS_MSG 1
#define EVENT_MSG 2
#define CONTROL_MSG 1
#define VIDSETTS_MSG 2
#define CLOSECONNECTION_MSG 3

typedef struct control_s{
    int action;
    float value;
} control_t;

class WebSocketServer : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketServer(QObject *parent = 0, ServerType type = Control);

signals:
    void controlEdited(control_t control);
    void newVideoSettings(vidsett_t videosettings);
    void clientDisconnected();

public slots:
    void onNewFrame(char* data, int size);
    void onNewEvent(RobotEvent ev);

private:
    QWebSocketServer *server;
    QWebSocket *client;
    ServerType servertype;
    State status;
    int port;

private slots:
    void newConnection();
    void onClientDisconnession();
    void onReceivedNewMessage(QByteArray arr);
};

#endif // WEBSOCKETSERVER_H

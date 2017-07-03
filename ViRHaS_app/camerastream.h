#ifndef CAMERASTREAM_H
#define CAMERASTREAM_H

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

class CameraStream : public QObject
{
    Q_OBJECT
public:
    explicit CameraStream(QObject *parent = 0);

signals:
    void newFrame(QByteArray* frame);

public slots:

private:
    QWebSocket *socket;
    void disconnectFromHost();

private slots:
    void onNewFrame(QByteArray frame);
};

#endif // CAMERASTREAM_H

#ifndef CAPTURECLASS_H
#define CAPTURECLASS_H

#include <QObject>
#include <QElapsedTimer>
#include <QTimer>
#include <QByteArray>
#include <QList>
#include <QHostAddress>
#include <QSize>
#include <QFile>
#include <QDateTime>
#include "capturethread.h"
#include "vidsett.h"
#include "websocketserver.h"

#define TCP_PORT 14231
#define AVERAGE_FPS 30

class CaptureClass : public QObject
{
	Q_OBJECT
public:
    explicit CaptureClass(QObject *parent = 0);
    bool isRecording();

signals:

public slots:
    void startRecording(vidsett_t resolution);
    void stopRecording();

private:
    CaptureThread *cap;
    WebSocketServer *vserver;

private slots:

};

#endif // CAPTURECLASS_H

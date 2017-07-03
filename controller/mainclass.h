#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QElapsedTimer>
#include <QTimer>
#include <QByteArray>
#include <QUdpSocket>
#include <QList>
#include <QHostAddress>
#include <QSize>
#include <QFile>
#include <QDateTime>
#include "captureclass.h"
#include <QSettings>
#include <stdio.h>
#include <controlclass.h>
#include <iostream>

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = 0);
    bool isMainHost();
    void quit();

signals:

public slots:

private:
    ControlClass *control;
    CaptureClass *video;
    void argExec();
    void printHelp();
    void setAppMode(bool flag);

private slots:

};

#endif // MAINCLASS_H

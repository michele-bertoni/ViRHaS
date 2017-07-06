#ifndef ARDUINOCOMMUNICATION_H
#define ARDUINOCOMMUNICATION_H

#include <QObject>
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/QSerialPortInfo"
#include "iostream"
#include "QByteArray"


class ArduinoCommunication : public QObject
{
    Q_OBJECT
public:
    explicit ArduinoCommunication(QObject *parent = 0);

signals:

public slots:
    void sendToArduino(QByteArray);

private:
    QSerialPort arduinoPort;
    QByteArray lastSent = QByteArray();
    bool compare(QByteArray array);
};

#endif // ARDUINOCOMMUNICATION_H

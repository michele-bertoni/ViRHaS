#ifndef ARDUINOCOMMUNICATION_H
#define ARDUINOCOMMUNICATION_H

#include <QObject>
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/QSerialPortInfo"


class ArduinoCommunication : public QObject
{
    Q_OBJECT
public:
    explicit ArduinoCommunication(QObject *parent = 0);

signals:

public slots:
    void sendToArduino(QString);

private:
    QSerialPort arduinoPort;
};

#endif // ARDUINOCOMMUNICATION_H

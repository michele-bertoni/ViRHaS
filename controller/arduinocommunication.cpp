#include "arduinocommunication.h"

ArduinoCommunication::ArduinoCommunication(QObject *parent) : QObject(parent)
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for(QSerialPortInfo p: ports){
        if(p.portName().startsWith("/dev/ttyACM")){
            arduinoPort.setPort(p);
            arduinoPort.open(QIODevice::WriteOnly);
            arduinoPort.setBaudRate(115200);
        }
    }
}

void ArduinoCommunication::sendToArduino(QString toSend)
{
    if(arduinoPort.isOpen()){
        arduinoPort.write(toSend.toUtf8());
    }
}

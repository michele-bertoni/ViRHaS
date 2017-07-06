#include "arduinocommunication.h"

ArduinoCommunication::ArduinoCommunication(QObject *parent) : QObject(parent)
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for(QSerialPortInfo p: ports){
        if(p.portName().startsWith("ttyACM")){
            std::cout << "Opening " << p.portName().toStdString() << "\n";
            arduinoPort.setPort(p);
            arduinoPort.setBaudRate(QSerialPort::Baud115200);
            arduinoPort.open(QIODevice::WriteOnly);
        }
    }
}

void ArduinoCommunication::sendToArduino(QByteArray toSend)
{
    if(compare(toSend))
        return;

    //else
    if(arduinoPort.isOpen()){
        const char* data = toSend.data();
        std::cout << (int)data[0] << " "
                  << (int)data[1] << " "
                  << (int)data[2] << "\n";
        arduinoPort.write(toSend);
        lastSent = toSend;
    }
}

bool ArduinoCommunication::compare(QByteArray array)
{
    char* a1 = lastSent.data();
    char* a2 = array.data();

    for(int i=0; i<3; i++){
        if(a1[i]!=a2[i])
            return false;
    }
    return true;
}

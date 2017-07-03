#ifndef CONTROLCLASS_H
#define CONTROLCLASS_H

#include <QObject>
#include <websocketserver.h>
#include <actions_enum.h>
#include <events_enum.h>
#include <speedvector.h>
#include <arduinocommunication.h>

class ControlClass : public QObject
{
    Q_OBJECT
public:
    explicit ControlClass(QObject *parent = 0);
    SpeedVector *speedVector;

signals:

public slots:

private slots:
    void actionSlot(control_t control);

private:
    WebSocketServer *cserver;
    ArduinoCommunication *arduinoComm;
    float acceleration; //value from 0 to +1
    float deceleration; //value from -1 to 0
    float ypmovement;   //value from -1 to +1
    float ymmovement;   //value from -1 to +1
    float xpmovement;   //value from -1 to +1
    float xmmovement;   //value from -1 to +1
    float mrotation;    //value from -1 to 0
    float protation;    //value from 0 to +1
    bool turbo;         //value 0 or 1

    float module;
    float xDir;
    float yDir;
    float wRot;

};

#endif // CONTROLCLASS_H

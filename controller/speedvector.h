#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QtMath>

#define TURBOMULTIPLIER 0.5

#define MINSTRAFE 0.01
#define MINFORWARD 0.01
#define MINANGULAR 0.1

class SpeedVector : public QObject
{
    Q_OBJECT
public:
    explicit SpeedVector(QObject *parent = 0)
    {
        this->angular = 0;
        this->strafe = 0;
        this->forward = 0;
    }
    float strafe;
    float forward;
    float angular;

    void setStrafeForward(float module, float xp, float yp)
    {
        if(xp==0 && yp==0){
            this->strafe = 0;
            this->forward =0;
            return;
        }

        float angle = qAtan2(yp, xp);

        this->strafe = qCos(angle)*module;
        this->forward = qSin(angle)*module;

        if(this->strafe < MINSTRAFE && this->strafe > -MINSTRAFE)
            this->strafe = 0;

        if(this->forward < MINFORWARD && this->forward > -MINFORWARD)
            this->forward = 0;

    }
    void setAngular(float rot)
    {
        this->angular = rot;
        if(this->angular < MINANGULAR && this->angular > -MINANGULAR)
            this->angular = 0;
    }

    QString toString(){
        QString vectorString;

        vectorString = QString::number(strafe) + "," +
                QString::number(forward) + "," +
                QString::number(angular) + "\n";

        return vectorString;
    }

    QByteArray toByteArray(){
        char byteArray[4];

        byteArray[0]=(char)(floor(50*strafe)+50);
        byteArray[1]=(char)(floor(50*forward)+50);
        byteArray[2]=(char)(floor(50*angular)+50);
        byteArray[3]='n';

        return QByteArray(byteArray, 4);
    }

};

#endif // VECTOR_H

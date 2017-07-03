#ifndef CONTROLSOCKET_H
#define CONTROLSOCKET_H

#include <QObject>
#include <vidsett.h>

typedef struct control_s{
    int action;
    float value;
} control_t;

class ControlServer : public QObject
{
    Q_OBJECT
public:
    explicit ControlServer(QObject *parent = 0);

signals:


};

#endif // CONTROLSOCKET_H

#ifndef VIBRATOR_H
#define VIBRATOR_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#endif

#define _VIBRATION_PERIOD   500 //milliseconds

class Vibrator : public QObject
{
    Q_OBJECT
public:
    explicit Vibrator(QObject *parent = 0);

signals:

public slots:
    void vibrate(int milliseconds);
    void continuousVibration();
    void setVibrationStatus(bool status);

private:
#ifdef Q_OS_ANDROID
    QAndroidJniObject vibratorService;
#endif
    QTimer *timer;
};

#endif // VIBRATOR_H

#include "vibrator.h"

Vibrator::Vibrator(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_ANDROID
    QAndroidJniObject vibroString = QAndroidJniObject::fromString("vibrator");
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    QAndroidJniObject appctx = activity.callObjectMethod("getApplicationContext","()Landroid/content/Context;");
    vibratorService = appctx.callObjectMethod("getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;", vibroString.object<jstring>());

    this->timer = new QTimer(this);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(continuousVibration()));

#endif
}

#ifdef Q_OS_ANDROID
void Vibrator::vibrate(int milliseconds) {
    if (vibratorService.isValid()) {
        jlong ms = milliseconds;
        jboolean hasvibro = vibratorService.callMethod<jboolean>("hasVibrator", "()Z");
        vibratorService.callMethod<void>("vibrate", "(J)V", ms);
    } else {
        qDebug() << "No vibrator service available";
    }
}

void Vibrator::continuousVibration()
{
    vibrate(_VIBRATION_PERIOD);
}

void Vibrator::setVibrationStatus(bool status)
{
    if(status){
        this->timer->start();
    }

    else{
        this->timer->stop();
    }
}

#else

void Vibrator::vibrate(int milliseconds) {
    Q_UNUSED(milliseconds);
}

void Vibrator::continuousVibration()
{

}

void Vibrator::setVibrationStatus(bool status)
{
    Q_UNUSED(status);
}


#endif

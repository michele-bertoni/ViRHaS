#ifndef GAMEPADMONITOR_H
#define GAMEPADMONITOR_H

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadManager>

#define GP_THRESHOLD 0.2
#define NGPBUTTONS 27

QT_BEGIN_NAMESPACE
class QGamepad;
QT_END_NAMESPACE

class GamepadMonitor : public QObject
{
    Q_OBJECT
public:
    explicit GamepadMonitor(QObject *parent = 0);
    ~GamepadMonitor();
    QGamepad *m_gamepad;

private:


private slots:
    void AxisLeftXAction(double);
    void AxisLeftYAction(double);
    void AxisRightXAction(double);
    void AxisRightYAction(double);
    void ButtonAAction(bool);
    void ButtonBAction(bool);
    void ButtonXAction(bool);
    void ButtonYAction(bool);
    void ButtonL1Action(bool);
    void ButtonL2Action(double);
    void ButtonL3Action(bool);
    void ButtonR1Action(bool);
    void ButtonR2Action(double);
    void ButtonR3Action(bool);
    void ButtonCenterAction(bool);
    void ButtonUpAction(bool);
    void ButtonDownAction(bool);
    void ButtonLeftAction(bool);
    void ButtonRightAction(bool);
    void ButtonSelectAction(bool);
    void ButtonStartAction(bool);
    void ButtonGuideAction(bool);

signals:
    void gamepadKeyPressed(int key_id, double value);
};

#endif // GAMEPADMONITOR_H

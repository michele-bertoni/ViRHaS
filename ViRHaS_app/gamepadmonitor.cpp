#include "gamepadmonitor.h"

GamepadMonitor::GamepadMonitor(QObject *parent)
    : QObject(parent)
    , m_gamepad(0)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
    connect(m_gamepad, SIGNAL(axisLeftXChanged(double)), this, SLOT(AxisLeftXAction(double)));
    connect(m_gamepad, SIGNAL(axisLeftYChanged(double)), this, SLOT(AxisLeftYAction(double)));
    connect(m_gamepad, SIGNAL(axisRightXChanged(double)), this, SLOT(AxisRightXAction(double)));
    connect(m_gamepad, SIGNAL(axisRightYChanged(double)), this, SLOT(AxisRightYAction(double)));
    connect(m_gamepad, SIGNAL(buttonAChanged(bool)), this, SLOT(ButtonAAction(bool)));
    connect(m_gamepad, SIGNAL(buttonBChanged(bool)), this, SLOT(ButtonBAction(bool)));
    connect(m_gamepad, SIGNAL(buttonXChanged(bool)), this, SLOT(ButtonXAction(bool)));
    connect(m_gamepad, SIGNAL(buttonYChanged(bool)), this, SLOT(ButtonYAction(bool)));
    connect(m_gamepad, SIGNAL(buttonL1Changed(bool)), this, SLOT(ButtonL1Action(bool)));
    connect(m_gamepad, SIGNAL(buttonL2Changed(double)), this, SLOT(ButtonL2Action(double)));
    connect(m_gamepad, SIGNAL(buttonL3Changed(bool)), this, SLOT(ButtonL3Action(bool)));
    connect(m_gamepad, SIGNAL(buttonR1Changed(bool)), this, SLOT(ButtonR1Action(bool)));
    connect(m_gamepad, SIGNAL(buttonR2Changed(double)), this, SLOT(ButtonR2Action(double)));
    connect(m_gamepad, SIGNAL(buttonR3Changed(bool)), this, SLOT(ButtonR3Action(bool)));
    connect(m_gamepad, SIGNAL(buttonCenterChanged(bool)), this, SLOT(ButtonCenterAction(bool)));
    connect(m_gamepad, SIGNAL(buttonUpChanged(bool)), this, SLOT(ButtonUpAction(bool)));
    connect(m_gamepad, SIGNAL(buttonDownChanged(bool)), this, SLOT(ButtonDownAction(bool)));
    connect(m_gamepad, SIGNAL(buttonLeftChanged(bool)), this, SLOT(ButtonLeftAction(bool)));
    connect(m_gamepad, SIGNAL(buttonRightChanged(bool)), this, SLOT(ButtonRightAction(bool)));
    connect(m_gamepad, SIGNAL(buttonSelectChanged(bool)), this, SLOT(ButtonSelectAction(bool)));
    connect(m_gamepad, SIGNAL(buttonStartChanged(bool)), this, SLOT(ButtonStartAction(bool)));
    connect(m_gamepad, SIGNAL(buttonGuideChanged(bool)), this, SLOT(ButtonGuideAction(bool)));
}


GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}
void GamepadMonitor::AxisLeftXAction(double value){
    if(value<0){
        emit gamepadKeyPressed(1, value*(-1));
        emit gamepadKeyPressed(2, 0.0);
    }
    else{
        emit gamepadKeyPressed(2, value);
        emit gamepadKeyPressed(1, 0.0);
    }
}
void GamepadMonitor::AxisLeftYAction(double value){
    if(value<0){
        emit gamepadKeyPressed(3, value*(-1));
        emit gamepadKeyPressed(4, 0.0);
    }
    else{
        emit gamepadKeyPressed(4, value);
        emit gamepadKeyPressed(3, 0.0);
    }
}
void GamepadMonitor::AxisRightXAction(double value){
    if(value<0){
        emit gamepadKeyPressed(5, value*(-1));
        emit gamepadKeyPressed(6, 0.0);
    }
    else{
        emit gamepadKeyPressed(6, value);
        emit gamepadKeyPressed(5, 0.0);
    }
}
void GamepadMonitor::AxisRightYAction(double value){
    if(value<0){
        emit gamepadKeyPressed(7, value*(-1));
        emit gamepadKeyPressed(8, 0.0);
    }
    else{
        emit gamepadKeyPressed(8, value);
        emit gamepadKeyPressed(7, 0.0);
    }
}
void GamepadMonitor::ButtonAAction(bool value){
    int key_id=9;
    emit gamepadKeyPressed(key_id, value);
}
void GamepadMonitor::ButtonBAction(bool value){
    int key_id=10;
    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonXAction(bool value){
    int key_id=11;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonYAction(bool value){
    int key_id=12;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonL1Action(bool value){
    int key_id=13;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonL2Action(double value){
    int key_id=14;

    emit gamepadKeyPressed(key_id, value);
}
void GamepadMonitor::ButtonL3Action(bool value){
    int key_id=15;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonR1Action(bool value){
    int key_id=16;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonR2Action(double value){
    int key_id=17;

    emit gamepadKeyPressed(key_id, value);
}
void GamepadMonitor::ButtonR3Action(bool value){
    int key_id=18;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonCenterAction(bool value){
    int key_id=19;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonUpAction(bool value){
    int key_id=20;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonDownAction(bool value){
    int key_id=21;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonLeftAction(bool value){
    int key_id=22;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonRightAction(bool value){
    int key_id=23;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonSelectAction(bool value){
    int key_id=24;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonStartAction(bool value){
    int key_id=25;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}
void GamepadMonitor::ButtonGuideAction(bool value){
    int key_id=26;

    if(value)
        emit gamepadKeyPressed(key_id, 1.0);
    else
        emit gamepadKeyPressed(key_id, 0.0);
}

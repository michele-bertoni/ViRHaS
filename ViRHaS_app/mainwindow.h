#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screenconstants.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include "QCoreApplication"
#include "QUrl"
#include "QDesktopServices"
#include "QProcess"
#include "QApplication"
#include "QDebug"
#include "QDesktopWidget"
#include "QSettings"
#include <stdbool.h>
#include <string>
#include <QInputMethod>
#include <gamepadmonitor.h>
#include <mouseeventlabel.h>
#include <websocketclient.h>
#include "screeninitialization.h"
#include "settingsclass.h"
#include "screenmanipulation.h"
#include "errorclass.h"
#include "vibrator.h"

#define NGPACTIONS 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    ButtonsClass *button_class;
    SettingsClass *settings;
    GamepadKeyClass *gpkey;
    ScreenManipulation *screen_manipulation;
    //actions:  0 NULL, 1 ACCELERATOR, 2 BRAKE, 3 Y-_MOVEMENT, 4 Y+_MOVEMENT, 5 X-_MOVEMENT, 6 X+_MOVEMENT, 7 L_ROTATION, 8 R_ROTATION, 9 TURBO
    //buttons:  0 NULL, 1 AxisLeftX, 2 AxisLeftY, 3 AxisRightX, 4 AxisRightY, 5 ButtonA, 6 ButtonB, 7 ButtonX, 8 ButtonY, 9 ButtonL1, 10 ButtonL2, 11 ButtonL3,
    //          12 ButtonR1, 13 ButtonR2, 14 ButtonR3, 15 ButtonCenter, 16 ButtonUp, 17 ButtonDown, 18 ButtonLeft, 19 ButtonRight, 20 ButtonSelect, 21 ButtonStart, 22 ButtonGuide

    //actions
    double value_action[NGPACTIONS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //buttons
    QString gamepadbutton[NGPBUTTONS]={"NULL", "AxisLeftX-", "AxisLeftX+", "AxisLeftY-", "AxisLeftY+", "AxisRightX-", "AxisRightX+", "AxisRightY-", "AxisRightY+", "ButtonA", "ButtonB", "ButtonX", "ButtonY", "ButtonL1", "ButtonL2", "ButtonL3", "ButtonR1", "ButtonR2", "ButtonR3", "ButtonCenter", "ButtonUp", "ButtonDown", "ButtonLeft", "ButtonRight", "ButtonSelect", "ButtonStart", "ButtonGuide"};

public slots:

private:
    GamepadMonitor* gamepadmonitor;
    ScreenInitialization *screen_init;
    WebSocketClient* controls_transmission;
    ErrorClass *robotError;
    WebSocketClient* camera1;
    WebSocketClient* camera2;
    Vibrator* vibrator;

private slots:
    void onPlayKeyPressed(int key_id, double value);
    void playGame();
    void stopGame();
    void startCamera1();
    void startCamera2();
    void startControl();
    void stopCamera1();
    void stopCamera2();
    void stopControl();
    void onCamera1ConnessionSwitch(State status);
    void onCamera2ConnessionSwitch(State status);
    void onControlConnessionSwitch(State status);
    void showWindowsError();
    void onNewEvent(int eventType);

};

#endif // MAINWINDOW_H

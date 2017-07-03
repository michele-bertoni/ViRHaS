#ifndef GAMEPADKEYCLASS_H
#define GAMEPADKEYCLASS_H

#include <QObject>
#include <QObject>
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
#include "windows_enum.h"

#define NGPACTIONS 10
#define NGPBUTTONS 27

class GamepadKeyClass : public QObject
{
    Q_OBJECT
public:
    explicit GamepadKeyClass(QObject *parent = 0, Ui::MainWindow *ui = 0);
    int checkEditGpAction(int, int);
    const QString gamepadbutton[NGPBUTTONS]={"NULL", "AxisLeftX-", "AxisLeftX+", "AxisLeftY-", "AxisLeftY+", "AxisRightX-", "AxisRightX+", "AxisRightY-", "AxisRightY+", "ButtonA", "ButtonB", "ButtonX", "ButtonY", "ButtonL1", "ButtonL2", "ButtonL3", "ButtonR1", "ButtonR2", "ButtonR3", "ButtonCenter", "ButtonUp", "ButtonDown", "ButtonLeft", "ButtonRight", "ButtonSelect", "ButtonStart", "ButtonGuide"};

signals:
    void playKeyPressed(int key_id, double value);

public slots:
    void enableGamepad();
    void disableGamepad();
    void disableEditGpAction1(int);
    void disableEditGpAction2(int);
    void disableEditGpAction3(int);
    void disableEditGpAction4(int);
    void disableEditGpAction5(int);
    void disableEditGpAction6(int);
    void disableEditGpAction7(int);
    void disableEditGpAction8(int);
    void disableEditGpAction9(int);
    void enableEditGpAction1();
    void enableEditGpAction2();
    void enableEditGpAction3();
    void enableEditGpAction4();
    void enableEditGpAction5();
    void enableEditGpAction6();
    void enableEditGpAction7();
    void enableEditGpAction8();
    void enableEditGpAction9();
    void disconnectLastGamepadKeyPressed();
    void gamepadKeyGrabber(int key_id, double value);

private:
    Ui::MainWindow *ui;
    void settGamepadKeyGrabber(int key_id, double value);
    void playGamepadKeyGrabber(int key_id, double value);

};

#endif // GAMEPADKEYCLASS_H

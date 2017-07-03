#ifndef SETTINGSCLASS_H
#define SETTINGSCLASS_H

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
#include <buttonsclass.h>
#include "gamepadkeyclass.h"
#include "robot_structures.h"

typedef struct sett_s{
    int s3D, lcam, rcam, invcanv, seplinecol, seplinew, gamepad;
    int c1w, c1h, c2w, c2h, c1x, c1y, c2x, c2y, c1f2D, c1f3D, c2f2D, c2f3D;
    int w, h, fps;
} sett_t;

class SettingsClass : public QObject
{
    Q_OBJECT
public:
    explicit SettingsClass(QObject *parent = 0, Ui::MainWindow *ui = 0, ButtonsClass *button_class = 0, GamepadKeyClass *gpkey = 0);
    QSettings settings;
    sett_t sett;

    //controls
    int action_button[NGPBUTTONS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int button_action[NGPACTIONS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

signals:

public slots:
    void initSettings();
    void confirmSettings();
    void loadDefSetts();
    void saveDefSetts();
    vidsett_t getVidSett();

private:
    Ui::MainWindow *ui;
    QDesktopWidget desktop;
    ButtonsClass *button_class;
    GamepadKeyClass *gpkey;

};

#endif // SETTINGSCLASS_H

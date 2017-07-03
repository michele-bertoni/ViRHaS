#ifndef SCREENINITIALIZATION_H
#define SCREENINITIALIZATION_H

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
#include <settingsclass.h>
#include "gamepadkeyclass.h"

class ScreenInitialization : public QObject
{
    Q_OBJECT
public:
    explicit ScreenInitialization(QObject *parent = 0, Ui::MainWindow *ui = 0, ButtonsClass *button_class = 0, GamepadKeyClass *gpkey = 0);
    void setSettings(SettingsClass *settings);

signals:

public slots:
     void initScreen();
     void centerAndResize(int, int);
     void initButtons();

private:
    Ui::MainWindow *ui;
    ButtonsClass *button_class;
    SettingsClass *settings;
    GamepadKeyClass *gpkey;

private slots:
    void init();
    void initLogos();
};

#endif // SCREENINITIALIZATION_H

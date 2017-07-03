#ifndef BUTTONSCLASS_H
#define BUTTONSCLASS_H

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

namespace Ui {
    class MainWindow;
}

class ButtonsClass : public QObject
{
    Q_OBJECT
public:
    explicit ButtonsClass(QObject *parent = 0, Ui::MainWindow *ui = 0);

signals:
    void previewRequest();
    void connessionRequest();
    void disconnessionRequest();
#ifdef Q_OS_WIN
    void windowsError();
#endif

public slots:
    void nextIndex();
    void prevIndex();
    void quit();
    void connectButton();
    void helpButton();
    void creditsButton();
    void toMainMenu();
    void toGame();
    void configurationButton();
    void enable3D();
    void disable3D();
    void settLeftCamera();
    void settRightCamera();
    void settCamResW();
    void settCamResH();
    void settCamFpsM();
    void settCamFpsP();
    void settC1WM();
    void settC1WP();
    void settC1HM();
    void settC1HP();
    void settC2WM();
    void settC2WP();
    void settC2HM();
    void settC2HP();
    void settC1PosX();
    void settC1PosY();
    void settC2PosX();
    void settC2PosY();
    void settSepLineComboBox(int);
    void settDialogueWindow();
    void settLoadSaveWindow();
    void settCloseDW();
    void preview();
    void enableButtons();
    void disableButtons();
    void stopStreaming();
    void hideError();

private:
    Ui::MainWindow *ui;
#ifdef Q_OS_WIN
    bool closeFlag;
#endif

};

#endif // BUTTONSCLASS_H

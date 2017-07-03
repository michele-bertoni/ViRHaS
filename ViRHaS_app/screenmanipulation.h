#ifndef SCREENMANIPULATION_H
#define SCREENMANIPULATION_H

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
#include "settingsclass.h"
#include "imagewidget.h"

typedef struct resolution_s{
   int canvasWidth, canvasHeight, xCorner, yCorner, imageWidth, imageHeight;
} resolution_t;

namespace Ui {
    class MainWindow;
}

class ScreenManipulation : public QObject
{
    Q_OBJECT
public:
    explicit ScreenManipulation(QObject *parent = 0, Ui::MainWindow *ui = 0, SettingsClass *settings = 0);

signals:

public slots:
    void preview();
    void nextIndex();
    void prevIndex();
    void setStreamingScreen();
    void printImageOnCanvas1(QByteArray* frame_array);
    void printImageOnCanvas2(QByteArray* frame_array);

private:
    Ui::MainWindow *ui;
    SettingsClass *settings;
    void setCanvas1Geometry();
    void setCanvas2Geometry();
    void setSepLineGeometry(int width, int height);
    void setErrorLabels(int width, int height);
    resolution_t center(resolution_t res);
    resolution_t fill(resolution_t res);
    resolution_t fit(resolution_t res);
    resolution_t stretch(resolution_t res);
    void initCanvases();

};

#endif // SCREENMANIPULATION_H

#ifndef ERRORCLASS_H
#define ERRORCLASS_H

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
#include "errors.h"
#include "settingsclass.h"
#include "QAbstractSocket"

class ErrorClass : public QObject
{
    Q_OBJECT
public:
    explicit ErrorClass(QObject *parent = 0, Ui::MainWindow *ui = 0, SettingsClass *settings = 0);

signals:

public slots:
    void onNewError(QAbstractSocket::SocketError error, QString texterror);
    void showError(QString texterror);
    void hideError();

private:
    Ui::MainWindow *ui;
    SettingsClass *settings;

};

#endif // ERRORCLASS_H

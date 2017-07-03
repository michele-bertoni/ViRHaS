#ifndef IMAGEPRINTER_H
#define IMAGEPRINTER_H

#include "imagewidget.h"
#include "QThreadPool"
#include "QRunnable"
#include <QObject>
#include <QMainWindow>
#include "screenconstants.h"
#include "ui_mainwindow.h"


class ImagePrinter : public QRunnable
{
public:
    explicit ImagePrinter(Ui::MainWindow *ui, bool flag);

protected:
    void run();

private:
    Ui::MainWindow *ui;
    bool flag;

};

#endif // IMAGEPRINTER_H

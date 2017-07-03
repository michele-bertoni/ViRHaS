#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("AIRLab Polimi");             //Organization name
    QCoreApplication::setOrganizationDomain("airlab.deib.polimi.it");   //Website
    QCoreApplication::setApplicationName("ViRHaS");                     //Project name

    MainWindow w;
    w.showFullScreen();

    return a.exec();
}

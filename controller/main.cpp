#include <QCoreApplication>
#include "mainclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("AIRLab Polimi");             //Organization name
    QCoreApplication::setOrganizationDomain("airlab.deib.polimi.it");   //Website
    QCoreApplication::setApplicationName("ViRHaS");                     //Project name

    MainClass c;
    return a.exec();
}

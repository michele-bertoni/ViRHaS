#include "mainclass.h"

MainClass::MainClass(QObject *parent) : QObject(parent)
{
    if(QCoreApplication::arguments().length()>1){
        MainClass::argExec();
        MainClass::quit();
    }
    video = new CaptureClass(this);

    if(this->isMainHost()){
        std::cout << "Mainhost\n";
        control = new ControlClass(this);
    }
    else{
        std::cout << "Slave\n";
    }

}

void MainClass::quit(){
    std::exit(0);
}

bool MainClass::isMainHost(){
    QSettings settings; //store settings

    settings.beginGroup("ControllerSettings");
    return settings.value("MainHost").toBool();
}

void MainClass::argExec(){
    if(QCoreApplication::arguments().at(1) == "-h" || QCoreApplication::arguments().at(1) == "--help"){
        printHelp();
    }
    else if(QCoreApplication::arguments().at(1) == "-c" || QCoreApplication::arguments().at(1) == "--controls"){
        setAppMode(true);
    }
    else if(QCoreApplication::arguments().at(1) == "-s" || QCoreApplication::arguments().at(1) == "--slave"){
        setAppMode(false);
    }

    else{
        std::cout << "Unknown option: use './controller -h' for usage information\n";
    }
}

void MainClass::printHelp(){
    /*QFile fp;
    fp.setFileName(":/runcommands.txt");
    if(fp.open(QIODevice::ReadOnly)){
        QByteArray text;
        while(!fp.atEnd()){
            text = fp.readAll();
            std::string string;
            string = text.toStdString();
            std::cout << string;
        }
        fp.close();
    }
    else{
        std::cout << "Unable to find runcommands.txt\n";
    }*/
}

void MainClass::setAppMode(bool flag){
    QSettings settings; //store settings

    settings.beginGroup("ControllerSettings");
    settings.setValue("MainHost", flag);
}

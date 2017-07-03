#include "errorclass.h"

ErrorClass::ErrorClass(QObject *parent, Ui::MainWindow *ui, SettingsClass *settings) : QObject(parent)
{
    this->ui = ui;
    this->settings = settings;
}

void ErrorClass::onNewError(QAbstractSocket::SocketError error, QString texterror){
    switch(error){
    case 0:
        this->showError(ERROR_0);
        break;
    case 1:
        this->showError(ERROR_1);
        break;
    default:
        this->showError(texterror);
        break;
    }
}

void ErrorClass::showError(QString texterror){
    ui->errortext_label->setText(texterror);
    ui->errortext_label2->setText(texterror);
    if(settings->sett.s3D){
        ui->errortext_label->setVisible(true);
        ui->errortext_label2->setVisible(true);
        QTimer::singleShot(2000, this, SLOT(hideError()));
    }
    else{
        ui->errortext_label->setVisible(true);
        ui->X_pushButton->setVisible(true);
    }
}

void ErrorClass::hideError(){
    ui->errortext_label->setText("");
    ui->errortext_label2->setText("");
    ui->errortext_label->setVisible(false);
    ui->errortext_label2->setVisible(false);
    ui->X_pushButton->setVisible(false);
}


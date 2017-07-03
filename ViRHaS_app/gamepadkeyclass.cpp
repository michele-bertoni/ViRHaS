#include "gamepadkeyclass.h"

GamepadKeyClass::GamepadKeyClass(QObject *parent, Ui::MainWindow *ui) : QObject(parent)
{
    this->ui = ui;
}

void GamepadKeyClass::enableGamepad()
{
    ui->gpaction1_text->setEnabled(true);
    ui->gpaction1_pushButton->setEnabled(true);
    ui->gpaction2_text->setEnabled(true);
    ui->gpaction2_pushButton->setEnabled(true);
    ui->gpaction3_text->setEnabled(true);
    ui->gpaction3_pushButton->setEnabled(true);
    ui->gpaction4_text->setEnabled(true);
    ui->gpaction4_pushButton->setEnabled(true);
    ui->gpaction5_text->setEnabled(true);
    ui->gpaction5_pushButton->setEnabled(true);
    ui->gpaction6_text->setEnabled(true);
    ui->gpaction6_pushButton->setEnabled(true);
    ui->gpaction7_text->setEnabled(true);
    ui->gpaction7_pushButton->setEnabled(true);
    ui->gpaction8_text->setEnabled(true);
    ui->gpaction8_pushButton->setEnabled(true);
    ui->gpaction9_text->setEnabled(true);
    ui->gpaction9_pushButton->setEnabled(true);
}

void GamepadKeyClass::disableGamepad()
{
    ui->gpaction1_text->setEnabled(false);
    ui->gpaction1_text->setText("NULL");
    ui->gpaction1_spinBox->setValue(0);
    ui->gpaction1_pushButton->setEnabled(false);
    ui->gpaction2_text->setEnabled(false);
    ui->gpaction2_text->setText("NULL");
    ui->gpaction2_spinBox->setValue(0);
    ui->gpaction2_pushButton->setEnabled(false);
    ui->gpaction3_text->setEnabled(false);
    ui->gpaction3_text->setText("NULL");
    ui->gpaction3_spinBox->setValue(0);
    ui->gpaction3_pushButton->setEnabled(false);
    ui->gpaction4_text->setEnabled(false);
    ui->gpaction4_text->setText("NULL");
    ui->gpaction4_spinBox->setValue(0);
    ui->gpaction4_pushButton->setEnabled(false);
    ui->gpaction5_text->setEnabled(false);
    ui->gpaction5_text->setText("NULL");
    ui->gpaction5_spinBox->setValue(0);
    ui->gpaction5_pushButton->setEnabled(false);
    ui->gpaction6_text->setEnabled(false);
    ui->gpaction6_text->setText("NULL");
    ui->gpaction6_spinBox->setValue(0);
    ui->gpaction6_pushButton->setEnabled(false);
    ui->gpaction7_text->setEnabled(false);
    ui->gpaction7_text->setText("NULL");
    ui->gpaction7_spinBox->setValue(0);
    ui->gpaction7_pushButton->setEnabled(false);
    ui->gpaction8_text->setEnabled(false);
    ui->gpaction8_text->setText("NULL");
    ui->gpaction8_spinBox->setValue(0);
    ui->gpaction8_pushButton->setEnabled(false);
    ui->gpaction9_text->setEnabled(false);
    ui->gpaction9_text->setText("NULL");
    ui->gpaction9_spinBox->setValue(0);
    ui->gpaction9_pushButton->setEnabled(false);
    this->disconnectLastGamepadKeyPressed();
}

void GamepadKeyClass::disableEditGpAction1(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(1, ui->gpaction1_spinBox->value()))){
            switch(check){
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction2(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(2, ui->gpaction2_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction3(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(3, ui->gpaction3_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction4(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(4, ui->gpaction4_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction5(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(5, ui->gpaction5_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction6(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(6, ui->gpaction6_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction7(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(7, ui->gpaction7_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction8(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(8, ui->gpaction8_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 9:
                ui->gpaction9_spinBox->setValue(0);
                ui->gpaction9_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disableEditGpAction9(int value){
    int check;
    if(value){
        if((check=this->checkEditGpAction(9, ui->gpaction9_spinBox->value()))){
            switch(check){
            case 1:
                ui->gpaction1_spinBox->setValue(0);
                ui->gpaction1_text->setText("NULL");
                break;
            case 2:
                ui->gpaction2_spinBox->setValue(0);
                ui->gpaction2_text->setText("NULL");
                break;
            case 3:
                ui->gpaction3_spinBox->setValue(0);
                ui->gpaction3_text->setText("NULL");
                break;
            case 4:
                ui->gpaction4_spinBox->setValue(0);
                ui->gpaction4_text->setText("NULL");
                break;
            case 5:
                ui->gpaction5_spinBox->setValue(0);
                ui->gpaction5_text->setText("NULL");
                break;
            case 6:
                ui->gpaction6_spinBox->setValue(0);
                ui->gpaction6_text->setText("NULL");
                break;
            case 7:
                ui->gpaction7_spinBox->setValue(0);
                ui->gpaction7_text->setText("NULL");
                break;
            case 8:
                ui->gpaction8_spinBox->setValue(0);
                ui->gpaction8_text->setText("NULL");
                break;
            }
        }
        QTimer::singleShot(100, this, SLOT(disconnectLastGamepadKeyPressed()));
    }
}
void GamepadKeyClass::disconnectLastGamepadKeyPressed(){
    ui->lastGamepadKeyPressed->disconnect();
    ui->gpaction1_text->setText(gamepadbutton[(ui->gpaction1_spinBox->value())]);
    ui->gpaction2_text->setText(gamepadbutton[(ui->gpaction2_spinBox->value())]);
    ui->gpaction3_text->setText(gamepadbutton[(ui->gpaction3_spinBox->value())]);
    ui->gpaction4_text->setText(gamepadbutton[(ui->gpaction4_spinBox->value())]);
    ui->gpaction5_text->setText(gamepadbutton[(ui->gpaction5_spinBox->value())]);
    ui->gpaction6_text->setText(gamepadbutton[(ui->gpaction6_spinBox->value())]);
    ui->gpaction7_text->setText(gamepadbutton[(ui->gpaction7_spinBox->value())]);
    ui->gpaction8_text->setText(gamepadbutton[(ui->gpaction8_spinBox->value())]);
    ui->gpaction9_text->setText(gamepadbutton[(ui->gpaction9_spinBox->value())]);
}

void GamepadKeyClass::enableEditGpAction1(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction1_text->setText("*******");
    //ui->gpaction1_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction1_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction1_text, SLOT(setText(QString)));
    connect(ui->gpaction1_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction1(int)));
}
void GamepadKeyClass::enableEditGpAction2(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction2_text->setText("*******");
    //ui->gpaction2_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction2_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction2_text, SLOT(setText(QString)));
    connect(ui->gpaction2_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction2(int)));
}
void GamepadKeyClass::enableEditGpAction3(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction3_text->setText("*******");
    //ui->gpaction3_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction3_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction3_text, SLOT(setText(QString)));
    connect(ui->gpaction3_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction3(int)));
}
void GamepadKeyClass::enableEditGpAction4(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction4_text->setText("*******");
    //ui->gpaction4_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction4_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction4_text, SLOT(setText(QString)));
    connect(ui->gpaction4_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction4(int)));
}
void GamepadKeyClass::enableEditGpAction5(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction5_text->setText("*******");
    //ui->gpaction5_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction5_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction5_text, SLOT(setText(QString)));
    connect(ui->gpaction5_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction5(int)));
}
void GamepadKeyClass::enableEditGpAction6(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction6_text->setText("*******");
    //ui->gpaction6_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction6_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction6_text, SLOT(setText(QString)));
    connect(ui->gpaction6_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction6(int)));
}
void GamepadKeyClass::enableEditGpAction7(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction7_text->setText("*******");
    //ui->gpaction7_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction7_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction7_text, SLOT(setText(QString)));
    connect(ui->gpaction7_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction7(int)));
}
void GamepadKeyClass::enableEditGpAction8(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    GamepadKeyClass::disconnectLastGamepadKeyPressed();
    ui->gpaction8_text->setText("*******");
    //ui->gpaction8_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction8_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction8_text, SLOT(setText(QString)));
    connect(ui->gpaction8_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction8(int)));
}
void GamepadKeyClass::enableEditGpAction9(){
    ui->lastGamepadKeyPressed->setCurrentIndex(0); //reset
    this->disconnectLastGamepadKeyPressed();
    ui->gpaction9_text->setText("*******");
    //ui->gpaction9_spinBox->setValue(0);
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentIndexChanged(int)), ui->gpaction9_spinBox, SLOT(setValue(int)));
    connect(ui->lastGamepadKeyPressed, SIGNAL(currentTextChanged(QString)), ui->gpaction9_text, SLOT(setText(QString)));
    connect(ui->gpaction9_spinBox, SIGNAL(valueChanged(int)), this, SLOT(disableEditGpAction9(int)));
}

int GamepadKeyClass::checkEditGpAction(int action, int button){
    if(action!=1)
        if(ui->gpaction1_spinBox->value()==button)
            return 1;
    if(action!=2)
        if(ui->gpaction2_spinBox->value()==button)
            return 2;
    if(action!=3)
        if(ui->gpaction3_spinBox->value()==button)
            return 3;
    if(action!=4)
        if(ui->gpaction4_spinBox->value()==button)
            return 4;
    if(action!=5)
        if(ui->gpaction5_spinBox->value()==button)
            return 5;
    if(action!=6)
        if(ui->gpaction6_spinBox->value()==button)
            return 6;
    if(action!=7)
        if(ui->gpaction7_spinBox->value()==button)
            return 7;
    if(action!=8)
        if(ui->gpaction8_spinBox->value()==button)
            return 8;
    if(action!=9)
        if(ui->gpaction9_spinBox->value()==button)
            return 9;
    return 0;
}

void GamepadKeyClass::gamepadKeyGrabber(int key_id, double value){
    if(ui->stackedWidget->currentIndex()==Settings){
        this->settGamepadKeyGrabber(key_id, value);
        return;
    }
    if(ui->stackedWidget->currentIndex()==Game){
        this->playGamepadKeyGrabber(key_id, value);
        return;
    }
    return;
}

void GamepadKeyClass::settGamepadKeyGrabber(int key_id, double value)
{
    if(value<0.9 && value>-0.9)
        return;
    ui->lastGamepadKeyPressed->setCurrentIndex(key_id);
}

void GamepadKeyClass::playGamepadKeyGrabber(int key_id, double value){
    if(value<0.10 && value>-0.10){
        emit playKeyPressed(key_id, 0);
        return;
    }
    emit playKeyPressed(key_id, value);
    return;
}

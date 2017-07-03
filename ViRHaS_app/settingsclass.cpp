#include "settingsclass.h"

SettingsClass::SettingsClass(QObject *parent, Ui::MainWindow *ui, ButtonsClass *button_class, GamepadKeyClass *gpkey) : QObject(parent)
{
    this->ui = ui;
    this->button_class = button_class;
    this->gpkey = gpkey;
}

void SettingsClass::initSettings(){    //initialize settings boxes with stored data
    //Video Settings
    //General
    if(sett.s3D){
        button_class->enable3D();
        ui->y3D_radioButton->setChecked(1);
    }
    else{
        button_class->disable3D();
        ui->n3D_radioButton->setChecked(1);
    }
    ui->leftcamera_checkBox->setChecked(sett.lcam);
    button_class->settLeftCamera();
    ui->rightcamera_checkBox->setChecked(sett.rcam);
    button_class->settRightCamera();
    if(sett.invcanv)
        ui->invertcanvasy_radioButton->setChecked(1);
    else
        ui->invertcanvasn_radioButton->setChecked(1);
    ui->sepline_comboBox->setCurrentIndex(sett.seplinecol);
    if(sett.seplinecol){
        ui->sepline_spinBox->setRange(1, 20);
        ui->sepline_spinBox->setEnabled(1);
    }
    else{
        ui->sepline_spinBox->setRange(0, 0);
        ui->sepline_spinBox->setEnabled(0);
    }
    ui->sepline_spinBox->setValue(sett.seplinew);
    //Canvas
    ui->canvas1width_spinBox->setValue(sett.c1w);
    ui->canvas1height_spinBox->setValue(sett.c1h);
    ui->canvas2width_spinBox->setValue(sett.c2w);
    ui->canvas2height_spinBox->setValue(sett.c2h);
    ui->canvas1posx_spinBox->setValue(sett.c1x);
    ui->canvas1posy_spinBox->setValue(sett.c1y);
    ui->canvas2posx_spinBox->setValue(sett.c2x);
    ui->canvas2posy_spinBox->setValue(sett.c2y);
    ui->canvas1fit2D_comboBox->setCurrentIndex(sett.c1f2D);
    ui->canvas1fit3D_comboBox->setCurrentIndex(sett.c1f3D);
    ui->canvas2fit2D_comboBox->setCurrentIndex(sett.c2f2D);
    ui->canvas2fit3D_comboBox->setCurrentIndex(sett.c2f3D);
    //Camera
    ui->camresw_spinBox->setValue(sett.w);
    ui->camresh_spinBox->setValue(sett.h);
    ui->camfps_spinBox->setValue(sett.fps);
    button_class->settCloseDW();

    //Control Settings
    if(sett.gamepad){
        gpkey->enableGamepad();
        ui->enablegamepady_radioButton->setChecked(1);

    }
    else{
        gpkey->disableGamepad();
        ui->enablegamepadn_radioButton->setChecked(1);

    }
    ui->gpaction1_spinBox->setValue(button_action[1]);
    ui->gpaction1_text->setText(gpkey->gamepadbutton[ui->gpaction1_spinBox->value()]);
    ui->gpaction2_spinBox->setValue(button_action[2]);
    ui->gpaction2_text->setText(gpkey->gamepadbutton[ui->gpaction2_spinBox->value()]);
    ui->gpaction3_spinBox->setValue(button_action[3]);
    ui->gpaction3_text->setText(gpkey->gamepadbutton[ui->gpaction3_spinBox->value()]);
    ui->gpaction4_spinBox->setValue(button_action[4]);
    ui->gpaction4_text->setText(gpkey->gamepadbutton[ui->gpaction4_spinBox->value()]);
    ui->gpaction5_spinBox->setValue(button_action[5]);
    ui->gpaction5_text->setText(gpkey->gamepadbutton[ui->gpaction5_spinBox->value()]);
    ui->gpaction6_spinBox->setValue(button_action[6]);
    ui->gpaction6_text->setText(gpkey->gamepadbutton[ui->gpaction6_spinBox->value()]);
    ui->gpaction7_spinBox->setValue(button_action[7]);
    ui->gpaction7_text->setText(gpkey->gamepadbutton[ui->gpaction7_spinBox->value()]);
    ui->gpaction8_spinBox->setValue(button_action[8]);
    ui->gpaction8_text->setText(gpkey->gamepadbutton[ui->gpaction8_spinBox->value()]);
    ui->gpaction9_spinBox->setValue(button_action[9]);
    ui->gpaction9_text->setText(gpkey->gamepadbutton[ui->gpaction9_spinBox->value()]);
}
void SettingsClass::confirmSettings(){ //stores data from settings boxes
    int i;
    //Video Settings
    //General
    sett.s3D=ui->y3D_radioButton->isChecked();
    sett.lcam=ui->leftcamera_checkBox->isChecked();
    sett.rcam=ui->rightcamera_checkBox->isChecked();
    sett.invcanv=ui->invertcanvasy_radioButton->isChecked();
    sett.seplinecol=ui->sepline_comboBox->currentIndex();
    sett.seplinew=ui->sepline_spinBox->value();
    //Canvas
    sett.c1w=ui->canvas1width_spinBox->value();
    sett.c1h=ui->canvas1height_spinBox->value();
    sett.c2w=ui->canvas2width_spinBox->value();
    sett.c2h=ui->canvas2height_spinBox->value();
    sett.c1x=ui->canvas1posx_spinBox->value();
    sett.c1y=ui->canvas1posy_spinBox->value();
    sett.c2x=ui->canvas2posx_spinBox->value();
    sett.c2y=ui->canvas2posy_spinBox->value();
    sett.c1f2D=ui->canvas1fit2D_comboBox->currentIndex();
    sett.c1f3D=ui->canvas1fit3D_comboBox->currentIndex();
    sett.c2f2D=ui->canvas2fit2D_comboBox->currentIndex();
    sett.c2f3D=ui->canvas2fit3D_comboBox->currentIndex();
    //Camera
    sett.w=ui->camresw_spinBox->value();
    sett.h=ui->camresh_spinBox->value();
    sett.fps=ui->camfps_spinBox->value();

    //Control Settings
    sett.gamepad=ui->enablegamepady_radioButton->isChecked();
    button_action[0]=0;
    button_action[1]=ui->gpaction1_spinBox->value();
    button_action[2]=ui->gpaction2_spinBox->value();
    button_action[3]=ui->gpaction3_spinBox->value();
    button_action[4]=ui->gpaction4_spinBox->value();
    button_action[5]=ui->gpaction5_spinBox->value();
    button_action[6]=ui->gpaction6_spinBox->value();
    button_action[7]=ui->gpaction7_spinBox->value();
    button_action[8]=ui->gpaction8_spinBox->value();
    button_action[9]=ui->gpaction9_spinBox->value();
    for(i=0; i<NGPBUTTONS; i++){    //reset action_button
        action_button[i]=0;
    }
    for(i=1; i<NGPACTIONS; i++){        //set action_button
        action_button[button_action[i]]=i;
    }
    //for(i=0; i<NGPBUTTONS; i++)    //debug
    //    printf("Button %d:\taction %d\n", i, action_button[i]);
    button_class->settCloseDW();
}
void SettingsClass::loadDefSetts(){    //initialize settings boxes with default data
    if(!settings.value("controlflag").toBool()){
        this->saveDefSetts();
        return;
    }
    settings.beginGroup("VideoSettings");
    settings.beginGroup("General");
    if(settings.value("3D").toBool()){
        button_class->enable3D();
        ui->y3D_radioButton->setChecked(1);
    }
    else{
        button_class->disable3D();
        ui->n3D_radioButton->setChecked(1);
    }
    ui->y3D_radioButton->setChecked(settings.value("3D").toBool());
    ui->leftcamera_checkBox->setChecked(settings.value("lcam").toBool());
    button_class->settLeftCamera();
    ui->rightcamera_checkBox->setChecked(settings.value("rcam").toBool());
    button_class->settRightCamera();
    if(settings.value("invcanv").toBool())
        ui->invertcanvasy_radioButton->setChecked(1);
    else
        ui->invertcanvasn_radioButton->setChecked(1);
    ui->sepline_comboBox->setCurrentIndex(settings.value("seplinecol").toInt());
    ui->sepline_spinBox->setValue(settings.value("seplinew").toInt());
    settings.endGroup();
    settings.beginGroup("Canvas");
    ui->canvas1width_spinBox->setValue(settings.value("c1w").toInt());
    ui->canvas1height_spinBox->setValue(settings.value("c1h").toInt());
    ui->canvas2width_spinBox->setValue(settings.value("c2w").toInt());
    ui->canvas2height_spinBox->setValue(settings.value("c2h").toInt());
    ui->canvas1posx_spinBox->setValue(settings.value("c1x").toInt());
    ui->canvas1posy_spinBox->setValue(settings.value("c1y").toInt());
    ui->canvas2posx_spinBox->setValue(settings.value("c2x").toInt());
    ui->canvas2posy_spinBox->setValue(settings.value("c2y").toInt());
    ui->canvas1fit2D_comboBox->setCurrentIndex(settings.value("c1f2D").toInt());
    ui->canvas1fit3D_comboBox->setCurrentIndex(settings.value("c1f3D").toInt());
    ui->canvas2fit2D_comboBox->setCurrentIndex(settings.value("c2f2D").toInt());
    ui->canvas2fit3D_comboBox->setCurrentIndex(settings.value("c2f3D").toInt());
    settings.endGroup();
    settings.beginGroup("Camera");
    ui->camresw_spinBox->setValue(settings.value("w").toInt());
    ui->camresh_spinBox->setValue(settings.value("h").toInt());
    ui->camfps_spinBox->setValue(settings.value("fps").toInt());
    settings.endGroup();
    settings.endGroup();
    settings.beginGroup("ControlSettings");
    if(settings.value("gamepad").toBool()){
        gpkey->enableGamepad();
        ui->enablegamepady_radioButton->setChecked(1);

    }
    else{
        gpkey->disableGamepad();
        ui->enablegamepadn_radioButton->setChecked(1);

    }
    settings.beginReadArray("ActionOfButton");
    settings.setArrayIndex(0);
    ui->gpaction1_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction1_text->setText(gpkey->gamepadbutton[ui->gpaction1_spinBox->value()]);
    settings.setArrayIndex(1);
    ui->gpaction2_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction2_text->setText(gpkey->gamepadbutton[ui->gpaction2_spinBox->value()]);
    settings.setArrayIndex(2);
    ui->gpaction3_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction3_text->setText(gpkey->gamepadbutton[ui->gpaction3_spinBox->value()]);
    settings.setArrayIndex(3);
    ui->gpaction4_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction4_text->setText(gpkey->gamepadbutton[ui->gpaction4_spinBox->value()]);
    settings.setArrayIndex(4);
    ui->gpaction5_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction5_text->setText(gpkey->gamepadbutton[ui->gpaction5_spinBox->value()]);
    settings.setArrayIndex(5);
    ui->gpaction6_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction6_text->setText(gpkey->gamepadbutton[ui->gpaction6_spinBox->value()]);
    settings.setArrayIndex(6);
    ui->gpaction7_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction7_text->setText(gpkey->gamepadbutton[ui->gpaction7_spinBox->value()]);
    settings.setArrayIndex(7);
    ui->gpaction8_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction8_text->setText(gpkey->gamepadbutton[ui->gpaction8_spinBox->value()]);
    settings.setArrayIndex(8);
    ui->gpaction9_spinBox->setValue(settings.value("button").toInt());
    ui->gpaction9_text->setText(gpkey->gamepadbutton[ui->gpaction9_spinBox->value()]);
    settings.endArray();
    settings.endGroup();
    button_class->settCloseDW();
}

void SettingsClass::saveDefSetts(){    //overwrite default data with settings boxes content
    settings.setValue("controlflag", QVariant(false));

    settings.beginGroup("VideoSettings");
    settings.beginGroup("General");
    settings.setValue("3D", QVariant(ui->y3D_radioButton->isChecked()));
    settings.setValue("lcam", QVariant(ui->leftcamera_checkBox->isChecked()));
    settings.setValue("rcam", QVariant(ui->rightcamera_checkBox->isChecked()));
    settings.setValue("invcanv", QVariant(ui->invertcanvasy_radioButton->isChecked()));
    settings.setValue("seplinecol", QVariant(ui->sepline_comboBox->currentIndex()));
    settings.setValue("seplinew", QVariant(ui->sepline_spinBox->value()));
    settings.endGroup();
    settings.beginGroup("Canvas");
    settings.setValue("c1w", QVariant(ui->canvas1width_spinBox->value()));
    settings.setValue("c1h", QVariant(ui->canvas1height_spinBox->value()));
    settings.setValue("c2w", QVariant(ui->canvas2width_spinBox->value()));
    settings.setValue("c2h", QVariant(ui->canvas2height_spinBox->value()));
    settings.setValue("c1x", QVariant(ui->canvas1posx_spinBox->value()));
    settings.setValue("c1y", QVariant(ui->canvas1posy_spinBox->value()));
    settings.setValue("c2x", QVariant(ui->canvas2posx_spinBox->value()));
    settings.setValue("c2y", QVariant(ui->canvas2posy_spinBox->value()));
    settings.setValue("c1f2D", QVariant(ui->canvas1fit2D_comboBox->currentIndex()));
    settings.setValue("c1f3D", QVariant(ui->canvas1fit3D_comboBox->currentIndex()));
    settings.setValue("c2f2D", QVariant(ui->canvas2fit2D_comboBox->currentIndex()));
    settings.setValue("c2f3D", QVariant(ui->canvas2fit3D_comboBox->currentIndex()));
    settings.endGroup();
    settings.beginGroup("Camera");
    settings.setValue("w", QVariant(ui->camresw_spinBox->value()));
    settings.setValue("h", QVariant(ui->camresh_spinBox->value()));
    settings.setValue("fps", QVariant(ui->camfps_spinBox->value()));
    settings.endGroup();
    settings.endGroup();
    settings.beginGroup("ControlSettings");
    settings.setValue("gamepad", ui->enablegamepady_radioButton->isChecked());
    settings.beginWriteArray("ActionOfButton", NGPACTIONS-1);
    settings.setArrayIndex(0);
    settings.setValue("button", ui->gpaction1_spinBox->value());
    settings.setArrayIndex(1);
    settings.setValue("button", ui->gpaction2_spinBox->value());
    settings.setArrayIndex(2);
    settings.setValue("button", ui->gpaction3_spinBox->value());
    settings.setArrayIndex(3);
    settings.setValue("button", ui->gpaction4_spinBox->value());
    settings.setArrayIndex(4);
    settings.setValue("button", ui->gpaction5_spinBox->value());
    settings.setArrayIndex(5);
    settings.setValue("button", ui->gpaction6_spinBox->value());
    settings.setArrayIndex(6);
    settings.setValue("button", ui->gpaction7_spinBox->value());
    settings.setArrayIndex(7);
    settings.setValue("button", ui->gpaction8_spinBox->value());
    settings.setArrayIndex(8);
    settings.setValue("button", ui->gpaction9_spinBox->value());
    settings.endArray();
    settings.endGroup();

    settings.setValue("controlflag", QVariant(true));

    settings.sync();
    button_class->settCloseDW();
}

vidsett_t SettingsClass::getVidSett(){
    vidsett_t videosettings;
    videosettings.res_w=this->sett.w;
    videosettings.res_h=this->sett.h;
    videosettings.fps=this->sett.fps;
    if(this->sett.lcam)
        videosettings.lcam=true;
    else
        videosettings.lcam=false;
    if(this->sett.rcam)
        videosettings.rcam=true;
    else
        videosettings.rcam=false;

    return videosettings;

}

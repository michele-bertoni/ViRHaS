#include "buttonsclass.h"

ButtonsClass::ButtonsClass(QObject *parent, Ui::MainWindow *ui) : QObject(parent)
{
    this->ui = ui;
#ifdef Q_OS_WIN
    this->closeFlag = false;
#endif
}

void ButtonsClass::nextIndex()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
}

void ButtonsClass::prevIndex()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
}

void ButtonsClass::quit()
{
    QCoreApplication::quit();
}

void ButtonsClass::connectButton()
{
    emit connessionRequest();
}

void ButtonsClass::helpButton()
{
    QDesktopServices::openUrl(QUrl("http://airwiki.ws.dei.polimi.it/index.php/ViRHaS", QUrl::TolerantMode));
}

void ButtonsClass::creditsButton()
{
    ui->stackedWidget->setCurrentIndex(Credits);
}

void ButtonsClass::toMainMenu()
{
    ui->stackedWidget->setCurrentIndex(MainMenu);
}

void ButtonsClass::toGame()
{
    ui->stackedWidget->setCurrentIndex(Game);
}

void ButtonsClass::configurationButton()
{
    ui->stackedWidget->setCurrentIndex(Settings);
}

void ButtonsClass::enable3D(){
    //ui->y3D_radioButton->setText("1");
    //ui->n3D_radioButton->setText("0");
    ui->leftcamera_checkBox->setChecked(true);
    ui->leftcamera_checkBox->setEnabled(false);
    ui->rightcamera_checkBox->setChecked(true);
    ui->rightcamera_checkBox->setEnabled(false);
    ui->canvas1width_spinBox->setEnabled(false);
    ui->canvas1widthM_pushButton->setEnabled(false);
    ui->canvas1widthP_pushButton->setEnabled(false);
    ui->canvas1width_spinBox->setValue(ui->canvas1width_spinBox->maximum()/2);
    ui->canvas1height_spinBox->setEnabled(false);
    ui->canvas1heightM_pushButton->setEnabled(false);
    ui->canvas1heightP_pushButton->setEnabled(false);
    ui->canvas1height_spinBox->setValue(ui->canvas1height_spinBox->maximum());
    ui->canvas1posx_spinBox->setEnabled(false);
    ui->canvas1posy_spinBox->setEnabled(false);
    ui->canvas1posx_spinBox->setValue(0);
    ui->canvas1posy_spinBox->setValue(0);
    ui->canvas1fit3D_comboBox->setVisible(true);
    ui->canvas1fit2D_comboBox->setVisible(false);
    ui->canvas1fit3D_comboBox->setEnabled(true);
    ui->canvas1fit2D_comboBox->setEnabled(false);
    ui->canvas2width_spinBox->setEnabled(false);
    ui->canvas2widthM_pushButton->setEnabled(false);
    ui->canvas2widthP_pushButton->setEnabled(false);
    ui->canvas2width_spinBox->setValue(ui->canvas2width_spinBox->maximum()/2);
    ui->canvas2height_spinBox->setEnabled(false);
    ui->canvas2heightM_pushButton->setEnabled(false);
    ui->canvas2heightP_pushButton->setEnabled(false);
    ui->canvas2height_spinBox->setValue(ui->canvas1height_spinBox->maximum());
    ui->canvas2posx_spinBox->setEnabled(false);
    ui->canvas2posy_spinBox->setEnabled(false);
    ui->canvas2posx_spinBox->setValue(ui->canvas2posx_spinBox->maximum()/2);
    ui->canvas2posy_spinBox->setValue(0);
    ui->canvas2fit3D_comboBox->setVisible(true);
    ui->canvas2fit2D_comboBox->setVisible(false);
    ui->canvas2fit3D_comboBox->setEnabled(true);
    ui->canvas2fit2D_comboBox->setEnabled(false);
    ui->invertcanvasn_radioButton->setChecked(true);
    ui->invertcanvasy_radioButton->setEnabled(true);
    ui->invertcanvasn_radioButton->setEnabled(true);
    ui->sepline_comboBox->setCurrentIndex(0);
    ui->sepline_comboBox->setEnabled(true);
    ui->sepline_spinBox->setRange(0, 0);
    ui->sepline_spinBox->setEnabled(false);

}
void ButtonsClass::disable3D(){
    //ui->y3D_radioButton->setText("0");
    //ui->n3D_radioButton->setText("1");
    ui->leftcamera_checkBox->setChecked(true);
    ui->leftcamera_checkBox->setEnabled(true);
    ui->rightcamera_checkBox->setChecked(false);
    ui->rightcamera_checkBox->setEnabled(true);
    ui->canvas1width_spinBox->setEnabled(true);
    ui->canvas1widthM_pushButton->setEnabled(true);
    ui->canvas1widthP_pushButton->setEnabled(true);
    ui->canvas1width_spinBox->setValue(ui->canvas1width_spinBox->maximum());
    ui->canvas1height_spinBox->setEnabled(true);
    ui->canvas1heightM_pushButton->setEnabled(true);
    ui->canvas1heightP_pushButton->setEnabled(true);
    ui->canvas1height_spinBox->setValue(ui->canvas1height_spinBox->maximum());
    ui->canvas1posx_spinBox->setEnabled(true);
    ui->canvas1posy_spinBox->setEnabled(true);
    ui->canvas1posx_spinBox->setValue(0);
    ui->canvas1posy_spinBox->setValue(0);
    ui->canvas1fit3D_comboBox->setVisible(false);
    ui->canvas1fit2D_comboBox->setVisible(true);
    ui->canvas1fit2D_comboBox->setEnabled(true);
    ui->canvas1fit3D_comboBox->setEnabled(false);
    ui->canvas2width_spinBox->setEnabled(false);
    ui->canvas2widthM_pushButton->setEnabled(false);
    ui->canvas2widthP_pushButton->setEnabled(false);
    ui->canvas2width_spinBox->setValue(ui->canvas2width_spinBox->minimum());
    ui->canvas2height_spinBox->setEnabled(false);
    ui->canvas2heightM_pushButton->setEnabled(false);
    ui->canvas2heightP_pushButton->setEnabled(false);
    ui->canvas2height_spinBox->setValue(ui->canvas2height_spinBox->minimum());
    ui->canvas2posx_spinBox->setEnabled(false);
    ui->canvas2posy_spinBox->setEnabled(false);
    ui->canvas2posx_spinBox->setValue(0);
    ui->canvas2posy_spinBox->setValue(0);
    ui->canvas2fit3D_comboBox->setVisible(false);
    ui->canvas2fit2D_comboBox->setVisible(true);
    ui->canvas2fit2D_comboBox->setEnabled(false);
    ui->canvas2fit3D_comboBox->setEnabled(false);
    ui->invertcanvasn_radioButton->setChecked(true);
    ui->invertcanvasy_radioButton->setEnabled(false);
    ui->invertcanvasn_radioButton->setEnabled(false);
    ui->sepline_comboBox->setCurrentIndex(0);
    ui->sepline_comboBox->setEnabled(false);
    ui->sepline_spinBox->setRange(0, 0);
    ui->sepline_spinBox->setEnabled(false);
}
void ButtonsClass::settLeftCamera(){
    if(ui->leftcamera_checkBox->isChecked()){
        //ui->leftcamera_checkBox->setText("1");
        ui->canvas1width_spinBox->setEnabled(true);
        ui->canvas1widthM_pushButton->setEnabled(true);
        ui->canvas1widthP_pushButton->setEnabled(true);
        ui->canvas1height_spinBox->setEnabled(true);
        ui->canvas1heightM_pushButton->setEnabled(true);
        ui->canvas1heightP_pushButton->setEnabled(true);
        ui->canvas1posx_spinBox->setEnabled(true);
        ui->canvas1posy_spinBox->setEnabled(true);
        ui->canvas1fit2D_comboBox->setEnabled(true);
        if(ui->rightcamera_checkBox->isChecked()){
            ui->canvas2width_spinBox->setEnabled(true);
            ui->canvas2widthM_pushButton->setEnabled(true);
            ui->canvas2widthP_pushButton->setEnabled(true);
            ui->canvas2height_spinBox->setEnabled(true);
            ui->canvas2heightM_pushButton->setEnabled(true);
            ui->canvas2heightP_pushButton->setEnabled(true);
            ui->canvas2posx_spinBox->setEnabled(true);
            ui->canvas2posy_spinBox->setEnabled(true);
            ui->canvas2fit2D_comboBox->setEnabled(true);
            ui->invertcanvasy_radioButton->setEnabled(true);
            ui->invertcanvasn_radioButton->setEnabled(true);
        }
    }
    else{
        ui->rightcamera_checkBox->setChecked(true);
        //ui->leftcamera_checkBox->setText("0");
        ui->canvas1width_spinBox->setEnabled(true);
        ui->canvas1widthM_pushButton->setEnabled(true);
        ui->canvas1widthP_pushButton->setEnabled(true);
        ui->canvas1height_spinBox->setEnabled(true);
        ui->canvas1heightM_pushButton->setEnabled(true);
        ui->canvas1heightP_pushButton->setEnabled(true);
        ui->canvas1posx_spinBox->setEnabled(true);
        ui->canvas1posy_spinBox->setEnabled(true);
        ui->canvas1fit2D_comboBox->setEnabled(true);
        ui->invertcanvasy_radioButton->setChecked(true);
        ui->invertcanvasy_radioButton->setEnabled(false);
        ui->invertcanvasn_radioButton->setEnabled(false);
    }
}
void ButtonsClass::settRightCamera(){
    if(ui->rightcamera_checkBox->isChecked()){
        //ui->rightcamera_checkBox->setText("1");
        ui->canvas1width_spinBox->setEnabled(true);
        ui->canvas1widthM_pushButton->setEnabled(true);
        ui->canvas1widthP_pushButton->setEnabled(true);
        ui->canvas1height_spinBox->setEnabled(true);
        ui->canvas1heightM_pushButton->setEnabled(true);
        ui->canvas1heightP_pushButton->setEnabled(true);
        ui->canvas1posx_spinBox->setEnabled(true);
        ui->canvas1posy_spinBox->setEnabled(true);
        ui->canvas1fit2D_comboBox->setEnabled(true);
        if(ui->leftcamera_checkBox->isChecked()){
            ui->canvas2width_spinBox->setEnabled(true);
            ui->canvas2widthM_pushButton->setEnabled(true);
            ui->canvas2widthP_pushButton->setEnabled(true);
            ui->canvas2height_spinBox->setEnabled(true);
            ui->canvas2heightM_pushButton->setEnabled(true);
            ui->canvas2heightP_pushButton->setEnabled(true);
            ui->canvas2posx_spinBox->setEnabled(true);
            ui->canvas2posy_spinBox->setEnabled(true);
            ui->canvas2fit2D_comboBox->setEnabled(true);
            ui->invertcanvasy_radioButton->setEnabled(true);
            ui->invertcanvasn_radioButton->setEnabled(true);
        }
    }
    else{
        ui->leftcamera_checkBox->setChecked(true);
        //ui->rightcamera_checkBox->setText("0");
        ui->canvas1width_spinBox->setEnabled(true);
        ui->canvas1widthM_pushButton->setEnabled(true);
        ui->canvas1widthP_pushButton->setEnabled(true);
        ui->canvas1height_spinBox->setEnabled(true);
        ui->canvas1heightM_pushButton->setEnabled(true);
        ui->canvas1heightP_pushButton->setEnabled(true);
        ui->canvas1posx_spinBox->setEnabled(true);
        ui->canvas1posy_spinBox->setEnabled(true);
        ui->canvas1fit2D_comboBox->setEnabled(true);
        ui->invertcanvasn_radioButton->setChecked(true);
        ui->invertcanvasy_radioButton->setEnabled(false);
        ui->invertcanvasn_radioButton->setEnabled(false);
    }
}
void ButtonsClass::settCamFpsM(){
    ui->camfps_spinBox->setValue(ui->camfps_spinBox->value()-1);
}
void ButtonsClass::settCamFpsP(){
    ui->camfps_spinBox->setValue(ui->camfps_spinBox->value()+1);
}
void ButtonsClass::settC1WM(){
    ui->canvas1width_spinBox->setValue(ui->canvas1width_spinBox->value()-DEF_SCREEN_WR);
}
void ButtonsClass::settC1WP(){
    ui->canvas1width_spinBox->setValue(ui->canvas1width_spinBox->value()+DEF_SCREEN_WR);
}
void ButtonsClass::settC1HM(){
    ui->canvas1height_spinBox->setValue(ui->canvas1height_spinBox->value()-DEF_SCREEN_HR);
}
void ButtonsClass::settC1HP(){
    ui->canvas1height_spinBox->setValue(ui->canvas1height_spinBox->value()+DEF_SCREEN_HR);
}
void ButtonsClass::settC2WM(){
    ui->canvas2width_spinBox->setValue(ui->canvas2width_spinBox->value()-DEF_SCREEN_WR);
}
void ButtonsClass::settC2WP(){
    ui->canvas2width_spinBox->setValue(ui->canvas2width_spinBox->value()+DEF_SCREEN_WR);
}
void ButtonsClass::settC2HM(){
    ui->canvas2height_spinBox->setValue(ui->canvas2height_spinBox->value()-DEF_SCREEN_HR);
}
void ButtonsClass::settC2HP(){
    ui->canvas2height_spinBox->setValue(ui->canvas2height_spinBox->value()+DEF_SCREEN_HR);
}
void ButtonsClass::settCamResW(){
    ui->camresw_spinBox->setValue(ui->camresw_spinBox->value()-ui->camresw_spinBox->value()%DEF_SCREEN_WR);
    ui->camresh_spinBox->setValue(ui->camresw_spinBox->value()*DEF_SCREEN_HR/DEF_SCREEN_WR);
}
void ButtonsClass::settCamResH(){
    ui->camresh_spinBox->setValue(ui->camresh_spinBox->value()-ui->camresh_spinBox->value()%DEF_SCREEN_HR);
    ui->camresw_spinBox->setValue(ui->camresh_spinBox->value()*DEF_SCREEN_WR/DEF_SCREEN_HR);
}
void ButtonsClass::settC1PosX(){
    ui->canvas1posx_spinBox->setValue(ui->canvas1posx_spinBox->value()-ui->canvas1posx_spinBox->value()%DEF_SCREEN_WR);
}
void ButtonsClass::settC1PosY(){
    ui->canvas1posy_spinBox->setValue(ui->canvas1posy_spinBox->value()-ui->canvas1posy_spinBox->value()%DEF_SCREEN_HR);
}
void ButtonsClass::settC2PosX(){
    ui->canvas2posx_spinBox->setValue(ui->canvas2posx_spinBox->value()-ui->canvas2posx_spinBox->value()%DEF_SCREEN_WR);
}
void ButtonsClass::settC2PosY(){
    ui->canvas2posy_spinBox->setValue(ui->canvas2posy_spinBox->value()-ui->canvas2posy_spinBox->value()%DEF_SCREEN_HR);
}
void ButtonsClass::settSepLineComboBox(int color){
    //0=No, 1=Black #000000, 2=White #ffffff, 3=Grey #808080, 4=Red #ff0000, 5=Green #00ff00, 6=Blue #0000ff, 7=Yellow #ffff00, 8=Magenta #ff00ff, 9=Cyan #00ffff
    if(!color){
        ui->sepline_spinBox->setRange(0, 0);
        ui->sepline_spinBox->setEnabled(false);
    }
    else{
        ui->sepline_spinBox->setRange(1, 20);
        ui->sepline_spinBox->setValue(1);
        ui->sepline_spinBox->setEnabled(true);
    }
}

void ButtonsClass::settDialogueWindow(){
    ui->sdw_background->setVisible(true);
    ui->sdwX_pushButton->setVisible(true);
    ui->sdwdiscard_pushButton->setVisible(true);
    ui->sdwconfirm_pushButton->setVisible(true);
}
void ButtonsClass::settLoadSaveWindow(){
    ui->sdw_background->setVisible(true);
    ui->sdwX_pushButton->setVisible(true);
    ui->sdwload_pushButton->setVisible(true);
    ui->sdwsave_pushButton->setVisible(true);
}

void ButtonsClass::settCloseDW(){
    ui->sdw_background->setVisible(false);
    ui->sdwX_pushButton->setVisible(false);
    ui->sdwdiscard_pushButton->setVisible(false);
    ui->sdwconfirm_pushButton->setVisible(false);
    ui->sdwload_pushButton->setVisible(false);
    ui->sdwsave_pushButton->setVisible(false);
}

void ButtonsClass::preview()
{
    emit previewRequest();
}

void ButtonsClass::enableButtons(){
    ui->disconnect_pushButton->setVisible(true);
    QTimer::singleShot(2000, this, SLOT(disableButtons()));
}

void ButtonsClass::disableButtons(){
    ui->disconnect_pushButton->setVisible(false);
#ifdef Q_OS_WIN
    if(this->closeFlag)
        emit disconnessionRequest();

    this->closeFlag = false;
#endif
}

void ButtonsClass::stopStreaming()
{
#ifdef Q_OS_WIN
    this->closeFlag = true;
    emit windowsError();
#else
    emit disconnessionRequest();
#endif

}

void ButtonsClass::hideError(){
    ui->errortext_label->setText("");
    ui->errortext_label2->setText("");
    ui->errortext_label->setVisible(false);
    ui->errortext_label2->setVisible(false);
    ui->X_pushButton->setVisible(false);
}

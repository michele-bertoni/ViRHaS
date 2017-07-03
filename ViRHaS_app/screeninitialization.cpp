#include "screeninitialization.h"

ScreenInitialization::ScreenInitialization(QObject *parent, Ui::MainWindow *ui, ButtonsClass *button_class, GamepadKeyClass *gpkey) :
    QObject(parent)
{
    this->ui = ui;
    this->button_class = button_class;
    this->gpkey = gpkey;
    this->init();
}

void ScreenInitialization::setSettings(SettingsClass *settings)
{
    this->settings = settings;
}

void ScreenInitialization::init()
{
#ifdef Q_OS_ANDOROID
    this->initLogos();
#else
    this->initScreen();
#endif
    ui->stackedWidget->setCurrentIndex(PolimiLogo);
    QTimer::singleShot(2000, button_class, SLOT(nextIndex()));  //2 seconds Polimi logo
    QTimer::singleShot(4000, button_class, SLOT(nextIndex()));  //2 seconds AIRLab logo
#ifdef Q_OS_ANDROID
    QTimer::singleShot(4000, this, SLOT(initScreen()));
#endif
}

void ScreenInitialization::initLogos()
{
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
    //Definition of QImages:
    QImage logo_polimi(":/imageformats/logo_polimi.png");
    QImage logo_AIRLab(":/imageformats/logo_airlab.gif");

    desktop.resize(width,height);
    this->centerAndResize(width, height);
    ui->stackedWidget->resize(width, height);

    //page_1
    ui->polimi_logo->resize(width, height);
    ui->polimi_logo->setPixmap(QPixmap::fromImage(logo_polimi.scaled(LOGO_POLIMI_W*width/DEF_SCREEN_W,LOGO_POLIMI_H*height/DEF_SCREEN_H,Qt::KeepAspectRatio,Qt::SmoothTransformation)));

    //page_2
    ui->AIRLab_logo->resize(width, height);
    ui->AIRLab_logo->setPixmap(QPixmap::fromImage(logo_AIRLab.scaled(LOGO_AIRLAB_W*width/DEF_SCREEN_W,LOGO_AIRLAB_H*height/DEF_SCREEN_H,Qt::KeepAspectRatio,Qt::SmoothTransformation)));

}

void ScreenInitialization::initScreen()
{
    //scales mainwindow.ui using screen size and screenconstants.h for constant definition
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
    int delta=height/200;
    int xp=0;
    int yp=0;

    //Definition of QImages:
    QImage logo_polimi(":/imageformats/logo_polimi.png");
    QImage background_polimi(":/imageformats/background_polimi.jpg");
    QImage background_dialoguewindow(":/imageformats/background_dialoguewindow.png");
    QImage background_black(":/imageformats/background_black.jpg");
    QImage logo_AIRLab(":/imageformats/logo_airlab.gif");
    QImage videosettings(":/imageformats/labels/videosettings.png");
    QImage activecameras(":/imageformats/labels/activecameras.png");
    QImage controlsettings(":/imageformats/labels/controlsettings.png");
    QImage enable3D(":/imageformats/labels/enable3D.png");
    QImage camres(":/imageformats/labels/camres.png");
    QImage camfps(":/imageformats/labels/camfps.png");
    QImage c1height(":/imageformats/labels/c1height.png");
    QImage c1width(":/imageformats/labels/c1width.png");
    QImage c1pos(":/imageformats/labels/c1pos.png");
    QImage c1fit(":/imageformats/labels/c1fit.png");
    QImage c2height(":/imageformats/labels/c2height.png");
    QImage c2width(":/imageformats/labels/c2width.png");
    QImage c2pos(":/imageformats/labels/c2pos.png");
    QImage c2fit(":/imageformats/labels/c2fit.png");
    QImage invertcanvas(":/imageformats/labels/invcanv.png");
    QImage sepline(":/imageformats/labels/sepline.png");
    QImage enablegamepad(":/imageformats/labels/enablegamepad.png");
    QImage gpaction1(":/imageformats/labels/gpaction1.png");
    QImage gpaction2(":/imageformats/labels/gpaction2.png");
    QImage gpaction3(":/imageformats/labels/gpaction3.png");
    QImage gpaction4(":/imageformats/labels/gpaction4.png");
    QImage gpaction5(":/imageformats/labels/gpaction5.png");
    QImage gpaction6(":/imageformats/labels/gpaction6.png");
    QImage gpaction7(":/imageformats/labels/gpaction7.png");
    QImage gpaction8(":/imageformats/labels/gpaction8.png");
    QImage gpaction9(":/imageformats/labels/gpaction9.png");

    desktop.resize(width,height);
    this->centerAndResize(width, height);
    ui->stackedWidget->resize(width, height);

    //page_1
    ui->polimi_logo->resize(width, height);
    ui->polimi_logo->setPixmap(QPixmap::fromImage(logo_polimi.scaled(LOGO_POLIMI_W*width/DEF_SCREEN_W,LOGO_POLIMI_H*height/DEF_SCREEN_H,Qt::KeepAspectRatio,Qt::SmoothTransformation)));

    //page_2
    ui->AIRLab_logo->resize(width, height);
    ui->AIRLab_logo->setPixmap(QPixmap::fromImage(logo_AIRLab.scaled(LOGO_AIRLAB_W*width/DEF_SCREEN_W,LOGO_AIRLAB_H*height/DEF_SCREEN_H,Qt::KeepAspectRatio,Qt::SmoothTransformation)));

    //page_3
    ui->background_polimi->resize(width, height);
    ui->background_polimi->setPixmap(QPixmap::fromImage(background_polimi.scaled(width*BACKG_POLIMI_W/DEF_SCREEN_W,height*BACKG_POLIMI_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->configuration_button->setGeometry(width*MAIN_BL_X0, height*MAIN_BL_Y0+height*MAIN_BUTTON_H, width*MAIN_BUTTON_W-delta, height*MAIN_BUTTON_H-delta);
    ui->connect_button->setGeometry(width*MAIN_BL_X0, height*MAIN_BL_Y0, 2*width*MAIN_BUTTON_W, height/6-delta);
    ui->credits_button->setGeometry(width*MAIN_BL_X0, height*MAIN_BL_Y0+2*height*MAIN_BUTTON_H, width*MAIN_BUTTON_W-delta, height*MAIN_BUTTON_H-delta);
    ui->help_button->setGeometry(width*MAIN_BL_X0+width*MAIN_BUTTON_W, height*MAIN_BL_Y0+height*MAIN_BUTTON_H, width*MAIN_BUTTON_W-delta, height*MAIN_BUTTON_H-delta);
    ui->exit_button->setGeometry(width*MAIN_BL_X0+width*MAIN_BUTTON_W, height*MAIN_BL_Y0+2*height*MAIN_BUTTON_H, width*MAIN_BUTTON_W-delta, height*MAIN_BUTTON_H-delta);
    ui->version_label->setGeometry(MAIN_LABEL_X0*delta, height-MAIN_LABEL_H, MAIN_LABEL_W, MAIN_LABEL_H);


    //page_4
    ui->background_polimi_2->resize(width, height);
    ui->background_polimi_2->setPixmap(QPixmap::fromImage(background_polimi.scaled(width*BACKG_POLIMI_W/DEF_SCREEN_W,height*BACKG_POLIMI_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->credits->resize(width, height);
    ui->toMainMenu_button->setGeometry(width*TMM_BUTTON_X0, height*TMM_BUTTON_Y0, height*TMM_BUTTON_W, height*TMM_BUTTON_H);

    //page 5
    ui->background_polimi_3->resize(width, height);
    ui->background_polimi_3->setPixmap(QPixmap::fromImage(background_polimi.scaled(width*BACKG_POLIMI_W/DEF_SCREEN_W,height*BACKG_POLIMI_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->sepsettings_line->setGeometry(width*SETT_SEP_W-delta, 0, 2*delta, height);
    ui->settdialoguewindow_button->setGeometry(width*TMM_BUTTON_X0, height*TMM_BUTTON_Y0, height*TMM_BUTTON_W, height*TMM_BUTTON_H);
    ui->preview_button->setGeometry((width-height*TMM_BUTTON_W)/2, height*TMM_BUTTON_Y0, height*TMM_BUTTON_W, height*TMM_BUTTON_H);
    ui->settloadsavewindow_button->setGeometry(width-height*TMM_BUTTON_W, height*TMM_BUTTON_Y0, height*TMM_BUTTON_W, height*TMM_BUTTON_H);

    xp=width*SETT_LABEL_X0;
    yp=height*SETT_LABEL_Y0;

    ui->videosettings_label->setGeometry(xp, yp, width*SETT_BLABEL_W, height*SETT_BLABEL_H);
    ui->videosettings_label->setPixmap(QPixmap::fromImage(videosettings.scaled(width*TITLE_LABEL_W/DEF_SCREEN_W,height*TITLE_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    yp+=height*SETT_BLABEL_H+delta;

    ui->enable3D_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->enable3D_label->setPixmap(QPixmap::fromImage(enable3D.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->y3D_radioButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->n3D_radioButton->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->activecameras_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->activecameras_label->setPixmap(QPixmap::fromImage(activecameras.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->leftcamera_checkBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->rightcamera_checkBox->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->camres_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->camres_label->setPixmap(QPixmap::fromImage(camres.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->camresw_spinBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->camresh_spinBox->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->camfps_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->camfps_label->setPixmap(QPixmap::fromImage(camfps.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->camfpsM_pushButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    ui->camfps_spinBox->setGeometry(xp+width*5/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->camfpsP_pushButton->setGeometry(xp+width*7/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas1width_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas1width_label->setPixmap(QPixmap::fromImage(c1width.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas1widthM_pushButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    ui->canvas1width_spinBox->setGeometry(xp+width*5/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas1widthP_pushButton->setGeometry(xp+width*7/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas1height_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas1height_label->setPixmap(QPixmap::fromImage(c1height.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas1heightM_pushButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    ui->canvas1height_spinBox->setGeometry(xp+width*5/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas1heightP_pushButton->setGeometry(xp+width*7/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas1pos_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas1pos_label->setPixmap(QPixmap::fromImage(c1pos.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas1posx_spinBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas1posy_spinBox->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas1fit_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas1fit_label->setPixmap(QPixmap::fromImage(c1fit.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas1fit2D_comboBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas1fit3D_comboBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas2width_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas2width_label->setPixmap(QPixmap::fromImage(c2width.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas2widthM_pushButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    ui->canvas2width_spinBox->setGeometry(xp+width*5/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas2widthP_pushButton->setGeometry(xp+width*7/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas2height_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas2height_label->setPixmap(QPixmap::fromImage(c2height.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas2heightM_pushButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    ui->canvas2height_spinBox->setGeometry(xp+width*5/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas2heightP_pushButton->setGeometry(xp+width*7/2*SETT_SLABEL_W, yp, width*SETT_SLABEL_W/2, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas2pos_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas2pos_label->setPixmap(QPixmap::fromImage(c2pos.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas2posx_spinBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->canvas2posy_spinBox->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->canvas2fit_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas2fit_label->setPixmap(QPixmap::fromImage(c2fit.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->canvas2fit2D_comboBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->canvas2fit3D_comboBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->invertcanvas_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->invertcanvas_label->setPixmap(QPixmap::fromImage(invertcanvas.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->invertcanvasy_radioButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->invertcanvasn_radioButton->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->sepline_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->sepline_label->setPixmap(QPixmap::fromImage(sepline.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->sepline_comboBox->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->sepline_spinBox->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    xp+=width*SETT_SEP_W;
    yp=height*SETT_LABEL_Y0;

    ui->lastGamepadKeyPressed->setVisible(false);
    ui->controlssettings_label->setGeometry(xp, yp, width*SETT_BLABEL_W, height*SETT_BLABEL_H);
    ui->controlssettings_label->setPixmap(QPixmap::fromImage(controlsettings.scaled(width*TITLE_LABEL_W/DEF_SCREEN_W,height*TITLE_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    yp+=height*SETT_BLABEL_H+delta;

    ui->enablegamepad_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->enablegamepad_label->setPixmap(QPixmap::fromImage(enablegamepad.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->enablegamepady_radioButton->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    ui->enablegamepadn_radioButton->setGeometry(xp+3*width*SETT_SLABEL_W, yp, width*SETT_SLABEL_W, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction1_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction1_label->setPixmap(QPixmap::fromImage(gpaction1.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction1_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction1_spinBox->setVisible(false);
    ui->gpaction1_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction2_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction2_label->setPixmap(QPixmap::fromImage(gpaction2.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction2_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction2_spinBox->setVisible(false);
    ui->gpaction2_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction3_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction3_label->setPixmap(QPixmap::fromImage(gpaction3.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction3_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction3_spinBox->setVisible(false);
    ui->gpaction3_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction4_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction4_label->setPixmap(QPixmap::fromImage(gpaction4.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction4_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction4_spinBox->setVisible(false);
    ui->gpaction4_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction5_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction5_label->setPixmap(QPixmap::fromImage(gpaction5.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction5_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction5_spinBox->setVisible(false);
    ui->gpaction5_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction6_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction6_label->setPixmap(QPixmap::fromImage(gpaction6.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction6_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction6_spinBox->setVisible(false);
    ui->gpaction6_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction7_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction7_label->setPixmap(QPixmap::fromImage(gpaction7.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction7_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction7_spinBox->setVisible(false);
    ui->gpaction7_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction8_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction8_label->setPixmap(QPixmap::fromImage(gpaction8.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction8_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction8_spinBox->setVisible(false);
    ui->gpaction8_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    ui->gpaction9_label->setGeometry(xp, yp, width*SETT_MLABEL_W, height*SETT_MLABEL_H);
    ui->gpaction9_label->setPixmap(QPixmap::fromImage(gpaction9.scaled(width*SUBT_LABEL_W/DEF_SCREEN_W,height*SUBT_LABEL_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->gpaction9_text->setGeometry(xp+width*SETT_MLABEL_W, yp, width*SETT_SLABEL_W*4/3, height*SETT_SLABEL_H);
    ui->gpaction9_spinBox->setVisible(false);
    ui->gpaction9_pushButton->setGeometry(xp+width*SETT_SLABEL_W*10/3, yp, width*SETT_SLABEL_W*2/3, height*SETT_SLABEL_H);
    yp+=height*SETT_MLABEL_H+delta;

    //page 5 dialogue window
    ui->sdw_background->setGeometry(0, 0, width*BACKG_DW_W/DEF_SCREEN_W, height*BACKG_DW_H/DEF_SCREEN_H);
    ui->sdw_background->setPixmap(QPixmap::fromImage(background_dialoguewindow.scaled(width*BACKG_DW_W/DEF_SCREEN_W,height*BACKG_DW_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->sdw_background->setVisible(false);
    xp=floor((width-2*width*DW_BUTTON_W-delta)/2);
    yp=floor((height-height*DW_BUTTON_H*3/2-delta)/2);
    ui->sdwX_pushButton->setGeometry(xp+2*width*DW_BUTTON_W+delta-height*DW_BUTTON_H/2, yp, height*DW_BUTTON_H/2, height*DW_BUTTON_H/2);
    ui->sdwX_pushButton->setVisible(false);
    yp+=delta+height*DW_BUTTON_H/2;
    ui->sdwdiscard_pushButton->setGeometry(xp, yp, width*DW_BUTTON_W, height*DW_BUTTON_H);
    ui->sdwdiscard_pushButton->setVisible(false);
    ui->sdwload_pushButton->setGeometry(xp, yp, width*DW_BUTTON_W, height*DW_BUTTON_H);
    ui->sdwload_pushButton->setVisible(false);
    ui->sdwconfirm_pushButton->setGeometry(xp+delta+width*DW_BUTTON_W, yp, width*DW_BUTTON_W, height*DW_BUTTON_H);
    ui->sdwconfirm_pushButton->setVisible(false);
    ui->sdwsave_pushButton->setGeometry(xp+delta+width*DW_BUTTON_W, yp, width*DW_BUTTON_W, height*DW_BUTTON_H);
    ui->sdwsave_pushButton->setVisible(false);

    //page 7
    ui->background->resize(width, height);
    ui->background->setPixmap(QPixmap::fromImage(background_black.scaled(width*BACKG_BLACK_W/DEF_SCREEN_W,height*BACKG_BLACK_H/DEF_SCREEN_H,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));
    ui->mouseEvent->setGeometry(0, 0, width*BACKG_DW_W/DEF_SCREEN_W, height*BACKG_DW_H/DEF_SCREEN_H);
    ui->disconnect_pushButton->setGeometry(width*TMM_BUTTON_X0, height*TMM_BUTTON_Y0, height*TMM_BUTTON_W, height*TMM_BUTTON_H);
    ui->disconnect_pushButton->setVisible(false);
    ui->X_pushButton->setGeometry(width*3/4-delta-height/20, height/4+delta, height/20, height/20);
    ui->X_pushButton->setVisible(false);
}

void ScreenInitialization::centerAndResize(int width, int height)
{
    QDesktopWidget desktop;
    QSize newSize(width, height);
    desktop.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );
}

void ScreenInitialization::initButtons(){
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();
    //page 3
    connect(ui->connect_button, SIGNAL(released()), button_class, SLOT(connectButton()));
    connect(ui->configuration_button, SIGNAL(released()), button_class, SLOT(configurationButton()));
    connect(ui->exit_button, SIGNAL(released()), button_class, SLOT(quit()));
    connect(ui->help_button, SIGNAL(released()), button_class, SLOT(helpButton()));
    connect(ui->credits_button, SIGNAL(released()), button_class, SLOT(creditsButton()));

    //page 4
    connect(ui->toMainMenu_button, SIGNAL(released()), button_class, SLOT(toMainMenu()));

    //page 5
    connect(ui->settdialoguewindow_button, SIGNAL(released()), button_class, SLOT(settDialogueWindow()));
    connect(ui->settloadsavewindow_button, SIGNAL(released()), button_class, SLOT(settLoadSaveWindow()));
    connect(ui->preview_button, SIGNAL(released()), button_class, SLOT(preview()));
    connect(ui->y3D_radioButton, SIGNAL(released()), button_class, SLOT(enable3D()));
    connect(ui->n3D_radioButton, SIGNAL(released()), button_class, SLOT(disable3D()));
    connect(ui->leftcamera_checkBox, SIGNAL(released()), button_class, SLOT(settLeftCamera()));
    connect(ui->rightcamera_checkBox, SIGNAL(released()), button_class, SLOT(settRightCamera()));
    ui->canvas1width_spinBox->setRange(0, width);
    ui->canvas1height_spinBox->setRange(0, height);
    ui->canvas1width_spinBox->setValue(width);
    ui->canvas1height_spinBox->setValue(height);
    ui->canvas1posx_spinBox->setRange(0, width);
    ui->canvas1posy_spinBox->setRange(0, height);
    ui->canvas1posx_spinBox->setValue(0);
    ui->canvas1posy_spinBox->setValue(0);
    ui->canvas2width_spinBox->setRange(0, width);
    ui->canvas2height_spinBox->setRange(0, height);
    ui->canvas2width_spinBox->setValue(0);
    ui->canvas2height_spinBox->setValue(0);
    ui->canvas2posx_spinBox->setRange(0, width);
    ui->canvas2posy_spinBox->setRange(0, height);
    ui->canvas2posx_spinBox->setValue(0);
    ui->canvas2posy_spinBox->setValue(0);
    ui->sepline_spinBox->setRange(0, 0);
    #ifdef Q_OS_ANDROID   //autoclose smartphone's virtual keyboard
    connect(ui->canvas1width_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas1height_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas2width_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas2height_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->camresw_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->camresh_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->camfps_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->sepline_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas1posx_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas1posy_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas2posx_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));
    connect(ui->canvas2posy_spinBox, SIGNAL(editingFinished()), QGuiApplication::inputMethod(), SLOT(hide()));

    #endif
    connect(ui->camresw_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settCamResW()));
    connect(ui->camresh_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settCamResH()));
    connect(ui->camfpsM_pushButton, SIGNAL(released()), button_class, SLOT(settCamFpsM()));
    connect(ui->camfpsP_pushButton, SIGNAL(released()), button_class, SLOT(settCamFpsP()));
    connect(ui->canvas1widthM_pushButton, SIGNAL(released()), button_class, SLOT(settC1WM()));
    connect(ui->canvas1widthP_pushButton, SIGNAL(released()), button_class, SLOT(settC1WP()));
    connect(ui->canvas1heightM_pushButton, SIGNAL(released()), button_class, SLOT(settC1HM()));
    connect(ui->canvas1heightP_pushButton, SIGNAL(released()), button_class, SLOT(settC1HP()));
    connect(ui->canvas1posx_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settC1PosX()));
    connect(ui->canvas1posy_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settC1PosY()));
    ui->canvas1fit3D_comboBox->setVisible(false);
    connect(ui->canvas2widthM_pushButton, SIGNAL(released()), button_class, SLOT(settC2WM()));
    connect(ui->canvas2widthP_pushButton, SIGNAL(released()), button_class, SLOT(settC2WP()));
    connect(ui->canvas2heightM_pushButton, SIGNAL(released()), button_class, SLOT(settC2HM()));
    connect(ui->canvas2heightP_pushButton, SIGNAL(released()), button_class, SLOT(settC2HP()));
    connect(ui->canvas2posx_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settC2PosX()));
    connect(ui->canvas2posy_spinBox, SIGNAL(editingFinished()), button_class, SLOT(settC2PosY()));
    ui->canvas2fit3D_comboBox->setVisible(false);
    connect(ui->sepline_comboBox, SIGNAL(currentIndexChanged(int)), button_class, SLOT(settSepLineComboBox(int)));
    connect(ui->sdwX_pushButton, SIGNAL(released()), button_class, SLOT(settCloseDW()));
    connect(ui->sdwdiscard_pushButton, SIGNAL(released()), button_class, SLOT(toMainMenu()));
    connect(ui->sdwdiscard_pushButton, SIGNAL(released()), settings, SLOT(initSettings()));
    connect(ui->sdwconfirm_pushButton, SIGNAL(released()), button_class, SLOT(toMainMenu()));
    connect(ui->sdwconfirm_pushButton, SIGNAL(released()), settings, SLOT(confirmSettings()));
    connect(ui->sdwload_pushButton, SIGNAL(released()), settings, SLOT(loadDefSetts()));
    connect(ui->sdwsave_pushButton, SIGNAL(released()), settings, SLOT(saveDefSetts()));
    connect(ui->enablegamepady_radioButton, SIGNAL(released()), gpkey, SLOT(enableGamepad()));
    connect(ui->enablegamepadn_radioButton, SIGNAL(released()), gpkey, SLOT(disableGamepad()));
    connect(ui->gpaction1_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction1()));
    connect(ui->gpaction2_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction2()));
    connect(ui->gpaction3_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction3()));
    connect(ui->gpaction4_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction4()));
    connect(ui->gpaction5_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction5()));
    connect(ui->gpaction6_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction6()));
    connect(ui->gpaction7_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction7()));
    connect(ui->gpaction8_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction8()));
    connect(ui->gpaction9_pushButton, SIGNAL(released()), gpkey, SLOT(enableEditGpAction9()));

    //page 7
    connect(ui->mouseEvent, SIGNAL(mousePressed()), button_class, SLOT(enableButtons()));
    connect(ui->disconnect_pushButton, SIGNAL(released()), button_class, SLOT(stopStreaming()));
    connect(ui->X_pushButton, SIGNAL(released()), button_class, SLOT(hideError()));

}

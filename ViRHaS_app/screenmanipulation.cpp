#include "screenmanipulation.h"

ScreenManipulation::ScreenManipulation(QObject *parent, Ui::MainWindow *ui, SettingsClass *settings) : QObject(parent)
{
    this->ui = ui;
    this->settings = settings;

}

void ScreenManipulation::preview()
{
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();

    int prev_3D, prev_invcanv, prev_seplinecol, prev_seplinew;
    int prev_c1w, prev_c1h, prev_c2w, prev_c2h, prev_c1x, prev_c1y, prev_c2x, prev_c2y, prev_c1f2D, prev_c1f3D, prev_c2f2D, prev_c2f3D;
    int prev_w, prev_h;

    QImage preview_cam1(":/imageformats/preview_cam1.jpg");
    QImage preview_cam2(":/imageformats/preview_cam2.jpg");

    //General
    prev_3D=ui->y3D_radioButton->isChecked();
    prev_invcanv=ui->invertcanvasy_radioButton->isChecked();
    prev_seplinecol=ui->sepline_comboBox->currentIndex();
    prev_seplinew=ui->sepline_spinBox->value();
    //Canvas
    prev_c1w=ui->canvas1width_spinBox->value();
    prev_c1h=ui->canvas1height_spinBox->value();
    prev_c2w=ui->canvas2width_spinBox->value();
    prev_c2h=ui->canvas2height_spinBox->value();
    prev_c1x=ui->canvas1posx_spinBox->value();
    prev_c1y=ui->canvas1posy_spinBox->value();
    prev_c2x=ui->canvas2posx_spinBox->value();
    prev_c2y=ui->canvas2posy_spinBox->value();
    prev_c1f2D=ui->canvas1fit2D_comboBox->currentIndex();
    prev_c1f3D=ui->canvas1fit3D_comboBox->currentIndex();
    prev_c2f2D=ui->canvas2fit2D_comboBox->currentIndex();
    prev_c2f3D=ui->canvas2fit3D_comboBox->currentIndex();
    //Camera
    prev_w=ui->camresw_spinBox->value();
    prev_h=ui->camresh_spinBox->value();

    preview_cam1=preview_cam1.scaled(prev_w, prev_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    preview_cam2=preview_cam2.scaled(prev_w, prev_h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    //printf("Cam1 W:%d H:%d\n", preview_cam1.width(), preview_cam1.height()); //debug
    //printf("Cam2 W:%d H:%d\n", preview_cam2.width(), preview_cam2.height()); //debug

    ui->previewcanv1_image->setAlignment(Qt::AlignCenter);
    ui->previewcanv2_image->setAlignment(Qt::AlignCenter);
    ui->previewcanv1_image->setGeometry(prev_c1x, prev_c1y, prev_c1w, prev_c1h);
    ui->previewcanv2_image->setGeometry(prev_c2x, prev_c2y, prev_c2w, prev_c2h);

    if(prev_3D){
        if(!prev_invcanv){
            switch(prev_c1f3D){
            case 0:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1));
                break;
            case 1:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToHeight(prev_c1h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToWidth(prev_c1w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaled(prev_c1w, prev_c1h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
            switch(prev_c2f3D){
            case 0:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2));
                break;
            case 1:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToHeight(prev_c2h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToWidth(prev_c2w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaled(prev_c2w, prev_c2h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
        }
        else{
            switch(prev_c1f3D){
            case 0:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2));
                break;
            case 1:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToHeight(prev_c1h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToWidth(prev_c1w,Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaled(prev_c1w, prev_c1h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
            switch(prev_c2f3D){
            case 0:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1));
                break;
            case 1:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToHeight(prev_c2h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToWidth(prev_c2w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaled(prev_c2w, prev_c2h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
        }
    }
    else{
        if(!prev_invcanv){
            switch(prev_c1f2D){
            case 0:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1));
                break;
            case 1:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToHeight(prev_c1h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToWidth(prev_c1w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam1.scaled(prev_c1w, prev_c1h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
            switch(prev_c2f2D){
            case 0:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2));
                break;
            case 1:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToHeight(prev_c2h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToWidth(prev_c2w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam2.scaled(prev_c2w, prev_c2h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
        }
        else{
            switch(prev_c1f2D){
            case 0:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2));
                break;
            case 1:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToHeight(prev_c1h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaledToWidth(prev_c1w,Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv1_image->setPixmap(QPixmap::fromImage(preview_cam2.scaled(prev_c1w, prev_c1h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
            switch(prev_c2f2D){
            case 0:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1));
                break;
            case 1:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToHeight(prev_c2h, Qt::SmoothTransformation)));
                break;
            case 2:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaledToWidth(prev_c2w, Qt::SmoothTransformation)));
                break;
            case 3:
                ui->previewcanv2_image->setPixmap(QPixmap::fromImage(preview_cam1.scaled(prev_c2w, prev_c2h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
                break;
            }
        }
    }
    ui->preview_line->setGeometry((width-ui->sepline_spinBox->maximum())/2, 0, ui->sepline_spinBox->maximum(), height);
    ui->preview_line->setLineWidth(prev_seplinew);
    //0=No, 1=Black #000000, 2=White #ffffff, 3=Grey #808080, 4=Red #ff0000, 5=Green #00ff00, 6=Blue #0000ff, 7=Yellow #ffff00, 8=Magenta #ff00ff, 9=Cyan #00ffff
    switch(prev_seplinecol){
    case 1:
        ui->preview_line->setStyleSheet("color: rgb(0, 0, 0);");
        break;
    case 2:
        ui->preview_line->setStyleSheet("color: rgb(255, 255, 255);");
        break;
    case 3:
        ui->preview_line->setStyleSheet("color: rgb(128, 128, 128);");
        break;
    case 4:
        ui->preview_line->setStyleSheet("color: rgb(255, 0, 0);");
        break;
    case 5:
        ui->preview_line->setStyleSheet("color: rgb(0, 255, 0);");
        break;
    case 6:
        ui->preview_line->setStyleSheet("color: rgb(0, 0, 255);");
        break;
    case 7:
        ui->preview_line->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case 8:
        ui->preview_line->setStyleSheet("color: rgb(255, 0, 255);");
        break;
    case 9:
        ui->preview_line->setStyleSheet("color: rgb(0, 255, 255);");
        break;
    }

    ui->stackedWidget->setCurrentIndex(5);
    QTimer::singleShot(5000, this, SLOT(prevIndex()));  //5 seconds preview
}

void ScreenManipulation::nextIndex()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
}

void ScreenManipulation::prevIndex()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
}

void ScreenManipulation::setStreamingScreen(){
    QDesktopWidget desktop;
    int height=desktop.geometry().height();
    int width=desktop.geometry().width();

    this->setCanvas1Geometry();
    this->setCanvas2Geometry();

    this->initCanvases();

    this->setSepLineGeometry(width, height);

    this->setErrorLabels(width, height);

}

void ScreenManipulation::printImageOnCanvas1(QByteArray *frame_array){
    ui->canvas1->frame.loadFromData(*frame_array, "JPG");

    ui->canvas1->update();
}

void ScreenManipulation::printImageOnCanvas2(QByteArray *frame_array){
   ui->canvas2->frame.loadFromData(*frame_array, "JPG");

   ui->canvas2->update();
}

void ScreenManipulation::setCanvas1Geometry()
{
    int sett_c1f;

    if(settings->sett.s3D)
        sett_c1f=settings->sett.c1f3D;
    else
        sett_c1f=settings->sett.c1f2D;

    resolution_t res;
    res.xCorner = settings->sett.c1x;
    res.yCorner = settings->sett.c1y;
    res.canvasWidth = settings->sett.c1w;
    res.canvasHeight = settings->sett.c1h;
    res.imageWidth = settings->sett.w;
    res.imageHeight = settings->sett.h;

    ui->container1->setGeometry(res.xCorner, res.yCorner, res.canvasWidth, res.canvasHeight);

    switch (sett_c1f) {
    case 0:
        res = this->center(res);
        break;
    case 1:
        res = this->fill(res);
        break;
    case 2:
        res = this->fit(res);
        break;
    case 3:
        res = this->stretch(res);
        break;
    default:
        break;
    }

    ui->canvas1->setFrameGeometry(res.xCorner, res.yCorner, res.canvasWidth, res.canvasHeight);

}

void ScreenManipulation::setCanvas2Geometry()
{
    int sett_c2f;

    if(settings->sett.s3D)
        sett_c2f=settings->sett.c1f3D;
    else
        sett_c2f=settings->sett.c1f2D;

    resolution_t res;
    res.xCorner = settings->sett.c2x;
    res.yCorner = settings->sett.c2y;
    res.canvasWidth = settings->sett.c2w;
    res.canvasHeight = settings->sett.c2h;
    res.imageWidth = settings->sett.w;
    res.imageHeight = settings->sett.h;

    ui->container2->setGeometry(res.xCorner, res.yCorner, res.canvasWidth, res.canvasHeight);

    switch (sett_c2f) {
    case 0:
        res = this->center(res);
        break;
    case 1:
        res = this->fill(res);
        break;
    case 2:
        res = this->fit(res);
        break;
    case 3:
        res = this->stretch(res);
        break;
    default:
        break;
    }

    ui->canvas2->setFrameGeometry(res.xCorner, res.yCorner, res.canvasWidth, res.canvasHeight);
}

void ScreenManipulation::setSepLineGeometry(int width, int height)
{
     ui->line->setGeometry((width-ui->sepline_spinBox->maximum())/2, 0, ui->sepline_spinBox->maximum(), height);
     ui->line->setLineWidth(settings->sett.seplinew);

     //0=No, 1=Black #000000, 2=White #ffffff, 3=Grey #808080, 4=Red #ff0000, 5=Green #00ff00, 6=Blue #0000ff, 7=Yellow #ffff00, 8=Magenta #ff00ff, 9=Cyan #00ffff
     switch(settings->sett.seplinecol){
     case 1:
         ui->line->setStyleSheet("color: rgb(0, 0, 0);");
         break;
     case 2:
         ui->line->setStyleSheet("color: rgb(255, 255, 255);");
         break;
     case 3:
         ui->line->setStyleSheet("color: rgb(128, 128, 128);");
         break;
     case 4:
         ui->line->setStyleSheet("color: rgb(255, 0, 0);");
         break;
     case 5:
         ui->line->setStyleSheet("color: rgb(0, 255, 0);");
         break;
     case 6:
         ui->line->setStyleSheet("color: rgb(0, 0, 255);");
         break;
     case 7:
         ui->line->setStyleSheet("color: rgb(255, 255, 0);");
         break;
     case 8:
         ui->line->setStyleSheet("color: rgb(255, 0, 255);");
         break;
     case 9:
         ui->line->setStyleSheet("color: rgb(0, 255, 255);");
         break;
     }

}

void ScreenManipulation::setErrorLabels(int width, int height)
{
    if(settings->sett.s3D){
        ui->errortext_label->setGeometry(width/16, height/4, width*3/8, height/2);
        ui->errortext_label2->setGeometry(width*9/16, height/4, width*3/8, height/2);
    }
    else{
        ui->errortext_label->setGeometry(width/4, height/4, width/2, height/2);
    }

    ui->errortext_label->setVisible(false);
    ui->errortext_label2->setVisible(false);
}

resolution_t ScreenManipulation::center(resolution_t res)
{
    resolution_t nRes;

    nRes.xCorner = (res.canvasWidth-res.imageWidth)/2;
    nRes.canvasWidth = res.imageWidth;

    nRes.yCorner = (res.canvasHeight-res.imageHeight)/2;
    nRes.canvasHeight = res.imageHeight;

    nRes.imageWidth = res.imageWidth;
    nRes.imageHeight = res.imageHeight;

    return nRes;
}

resolution_t ScreenManipulation::fill(resolution_t res)
{
    resolution_t nRes;
    double ratio = (double)(res.imageWidth)/res.imageHeight;

    nRes.imageHeight = res.canvasHeight;
    nRes.imageWidth = (int)((double)(nRes.imageHeight)*ratio);

    nRes.xCorner = (res.canvasWidth-nRes.imageWidth)/2;
    nRes.yCorner = 0;

    nRes.canvasWidth = nRes.imageWidth;
    nRes.canvasHeight = nRes.imageHeight;

    return nRes;
}

resolution_t ScreenManipulation::fit(resolution_t res)
{
    resolution_t nRes;
    double ratio = (double)(res.imageWidth)/res.imageHeight;

    nRes.imageWidth = res.canvasWidth;
    nRes.imageHeight = (int)((double)(nRes.imageWidth)/ratio);

    nRes.xCorner = 0;
    nRes.yCorner = (res.canvasHeight-nRes.imageHeight)/2;

    nRes.canvasWidth = nRes.imageWidth;
    nRes.canvasHeight = nRes.imageHeight;

    return nRes;

}

resolution_t ScreenManipulation::stretch(resolution_t res)
{
    res.xCorner=0;
    res.yCorner=0;

    res.imageWidth = res.canvasWidth;
    res.imageHeight = res.canvasHeight;

    return res;
}

void ScreenManipulation::initCanvases()
{
    if(!settings->sett.invcanv){
        ui->canvas1->setDefaultFrame(false);
        ui->canvas2->setDefaultFrame(true);
    }
    else{
        ui->canvas1->setDefaultFrame(true);
        ui->canvas2->setDefaultFrame(false);
    }

    if(settings->sett.lcam){
        ui->container1->setVisible(true);
        ui->canvas1->setVisible(true);
    }
    else{
        ui->container1->setVisible(false);
        ui->canvas1->setVisible(false);
    }

    if(settings->sett.rcam){
        ui->container2->setVisible(true);
        ui->canvas2->setVisible(true);
    }
    else{
        ui->container2->setVisible(false);
        ui->canvas2->setVisible(false);
    }
}


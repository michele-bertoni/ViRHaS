#include "imageprinter.h"

ImagePrinter::ImagePrinter(Ui::MainWindow *ui, bool flag)
{
    this->flag = flag;
    this->ui = ui;
}

void ImagePrinter::run()
{
    if(!this->flag){
        ui->canvas1->update();
    }
    else{
        ui->canvas2->update();
    }
}

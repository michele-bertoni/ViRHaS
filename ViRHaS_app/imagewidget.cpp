#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    this->setAutoFillBackground(false);
}

void ImageWidget::setDefaultFrame(bool flag)
{
    if(!flag)
        this->frame = QImage(":/imageformats/preview_cam1.jpg");
    else
        this->frame = QImage(":/imageformats/preview_cam2.jpg");

    this->update();
}

void ImageWidget::setFrameGeometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);

    this->setCanvasSize(w, h);
    this->setCanvasPosition(0, 0);
}

void ImageWidget::setCanvasSize(int w, int h)
{
    this->canvas.setWidth(w);
    this->canvas.setHeight(h);
}

void ImageWidget::setCanvasPosition(int x, int y)
{
    this->canvas.moveTo(x, y);
}

void ImageWidget::paintEvent(QPaintEvent *e)
{
    e->ignore();

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawImage(this->canvas, this->frame);
    painter.save();
    painter.restore();

}

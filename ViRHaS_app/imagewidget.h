#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <QImage>
#include <QPoint>

class ImageWidget : public QOpenGLWidget
{
public:
    ImageWidget(QWidget *parent);
    void setFrame(QImage image);
    void setDefaultFrame(bool flag);
    void setFrameGeometry(int x, int y, int w, int h);
    QImage frame;

protected:
    void paintEvent(QPaintEvent *event);

private:
    QRect canvas;
    void setCanvasSize(int w, int h);
    void setCanvasPosition(int x, int y);

};

#endif // IMAGEWIDGET_H

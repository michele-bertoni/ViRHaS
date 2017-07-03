#include "mouseeventlabel.h"

mouseEventLabel::mouseEventLabel(QWidget *parent) :
    QLabel(parent)
{

}

void mouseEventLabel::mousePressEvent(QMouseEvent *event){
    event->ignore();
    emit mousePressed();
}

void mouseEventLabel::leaveEvent(QEvent *event){
    event->ignore();
    emit mouseLeft();
}

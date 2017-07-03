#ifndef MOUSEEVENTLABEL_H
#define MOUSEEVENTLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

class mouseEventLabel : public QLabel
{
    Q_OBJECT
public:
    explicit mouseEventLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);

signals:
    void mousePressed();
    void mouseLeft();

};

#endif // MOUSEEVENTLABEL_H

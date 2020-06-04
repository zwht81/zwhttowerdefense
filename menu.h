#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "mybutton.h"
#include "mainwindow.h"
#include <QPainter>

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);


signals:

public slots:
private:
    Mybutton* startbutton;//²Ëµ¥°´Å¥
    QImage menuback;//²Ëµ¥±³¾°
};

#endif // MENU_H

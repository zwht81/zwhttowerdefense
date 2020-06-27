#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "mybutton.h"
#include "mainwindow.h"
#include <QPainter>

//菜单界面
class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);


signals:

public slots:
private:
    Mybutton* startbutton;
    Mybutton* intro;//菜单按钮
    QImage menuback;//菜单背景
};

#endif // MENU_H

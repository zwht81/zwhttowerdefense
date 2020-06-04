#include "menu.h"
#include "mybutton.h"
#include "mainwindow.h"



Menu::Menu(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1080,640);
    startbutton= new Mybutton(":/image/start.png");
    startbutton->setParent(this);
    startbutton->move(300,150);
    menuback.load(":/image/menu.jpg");
    MainWindow * scene=new MainWindow;
    connect(startbutton,&QPushButton::clicked,this,[=](){
        this->close();
        scene->show();
    });

}


void Menu::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    pa->drawImage(QRect(0,0,1080,640),menuback);
    pa->end();

}

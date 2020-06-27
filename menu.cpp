#include "menu.h"
#include "mybutton.h"
#include "mainwindow.h"
#include "levelchoose.h"
#include "introduce.h"


Menu::Menu(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1080,640);
    startbutton= new Mybutton(":/image/start.png");
    startbutton->setParent(this);
    startbutton->move(300,150);
    menuback.load(":/image/menu.jpg");
    intro= new Mybutton(":/image/introduc.png");
    intro->setParent(this);
    intro->move(300,350);




    Levelchoose* level=new Levelchoose;
    Introduce *introdu=new Introduce;
    connect(startbutton,&QPushButton::clicked,this,[=](){
        this->close();
        level->show();
    });
    connect(intro,&QPushButton::clicked,this,[=](){
        this->close();
        introdu->show();
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

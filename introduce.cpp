#include "introduce.h"
#include "QPainter"
#include "menu.h"

Introduce::Introduce(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(765,635);
    introback.load(":/image/intro.png");
    back= new Mybutton(":/image/back.png");
    back->setParent(this);
    back->move(600,10);
    back->setFixedSize(100,100);
    back->setIconSize(QSize(100,100));

    connect(back,&QPushButton::clicked,this,[=](){
        this->close();
        Menu* m=new Menu;
        m->show();
    });



}

void Introduce::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    pa->drawImage(QRect(0,0,765,635),introback);
    pa->end();


}

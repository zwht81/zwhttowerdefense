#include "levelchoose.h"
#include "QPainter"
#include "mainwindow.h"
#include <QLineEdit>


Levelchoose::Levelchoose(QWidget *parent) : QMainWindow(parent)
{


    this->setFixedSize(600,200);
    menuback.load(":/image/menu.jpg");
    p1 = new QPushButton;
    p1->setStyleSheet("color:black");
    p1->setGeometry(50,50, 120, 50);
    p1->setFont(QFont("Î¢ÈíÑÅºÚ", 12));
    p1->setParent(this);
    p1->setText(QString("Level 1"));
    p2 = new QPushButton;
    p2->setStyleSheet("color:black");
    p2->setGeometry(250,50, 120, 50);
    p2->setFont(QFont("Î¢ÈíÑÅºÚ", 12));
    p2->setParent(this);
    p2->setText(QString("Level 2"));
    p3 = new QPushButton;
    p3->setStyleSheet("color:black");
    p3->setGeometry(450,50, 120, 50);
    p3->setFont(QFont("Î¢ÈíÑÅºÚ", 12));
    p3->setParent(this);
    p3->setText(QString("Level 3"));

    connect(p1,&QPushButton::clicked,[=]()
    {
        this->close();
        Form *fo=new Form(1);
        fo->show();

    });

    connect(p2,&QPushButton::clicked,[=]()
    {
        this->close();
        Form *fo=new Form(2);
        fo->show();
    });

    connect(p3,&QPushButton::clicked,[=]()
    {
        this->close();
        Form *fo=new Form(3);
        fo->show();
    });


}


void Levelchoose::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);
    pa->drawImage(QRect(0,0,600,200),menuback);
    pa->end();

}


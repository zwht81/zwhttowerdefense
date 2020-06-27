#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "menu.h"


using namespace std;

#define msclick(X, Width, Y, Height)    \
    (ev->x() >= (X) && ev->x() <= (X) + (Width) &&  \
    ev->y() >= (Y) && ev->y() <= (Y) + (Height))

MainWindow::MainWindow(int i,QString name,QWidget *parent) :
    QMainWindow(parent),
    levelnum(i),
    playername(name),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1440,640);
    _map.initialmap(levelnum);
    _player.Initialplayer(playername);
    _game.initialgame(levelnum);
    initialmainwindow();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter * pa;
    pa = new QPainter();
    pa->begin(this);
    _map.drawmap(pa);
    _player.show(pa);
    _game.show(pa);

}


void MainWindow::timerEvent(QTimerEvent *e){
    Q_UNUSED(e);
    losehealth->hide();

    for(_game.itr=_game._enemys.begin();_game.itr!=_game._enemys.end();){
        (*_game.itr)->move();

        if( (*_game.itr)->arrive()){
            (*_game.itr)->injure(10000);
            _game.itr=_game._enemys.erase(_game.itr);
            QMediaPlayer * player = new QMediaPlayer;
            player->setMedia(QUrl("qrc:/sound/crash.mp3"));
            player->setVolume(3);
            player->play();
            losehealth->show();
            _player.healthminus(1);
        }
        else

            if( (*_game.itr)->death()){
                _game.itr=_game._enemys.erase(_game.itr);

                _player.gainmoney();
            }
            else
                _game.itr++;



    }

    /*for(i=0;i<n;i++){
        _game._enemys[i]->move();
        if(_game._enemys[i]->arrive()){
            _game._enemys.erase(_game._enemys.begin()+i);
            _player.healthminus(1);
        }
        if(_game._enemys[i]->death()){
            _game._enemys.erase(_game._enemys.begin()+i);
            _player.gainmoney();
        }
    }*/
    if(_game.getwave()==4&&_player.gethealth()>0){
        _game.win();
        back->show();

    }


    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *ev){
    int n=_map._towerarea.size();
    int i;
    for(i=0;i<n;i++){
        if(msclick(_map._towerarea[i]->GetX(), _map._towerarea[i]->GetWidth(), _map._towerarea[i]->GetY(), _map._towerarea[i]->GetHeight())){

            int flag=1;
            for(_game.itr2=_game._towers.begin();_game.itr2!=_game._towers.end();_game.itr2++){
                if((*_game.itr2)->GetX()==_map._towerarea[i]->GetX()&&(*_game.itr2)->GetY()==_map._towerarea[i]->GetY()){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                buildtowerbutton->move(_map._towerarea[i]->GetX()+20,_map._towerarea[i]->GetY()-40);
                buildtowerbutton->show();
                buildtowerbutton2->move(_map._towerarea[i]->GetX()+20,_map._towerarea[i]->GetY()+80);
                buildtowerbutton2->show();
                buildtowerbutton3->move(_map._towerarea[i]->GetX()-40,_map._towerarea[i]->GetY()+20);
                buildtowerbutton3->show();
                buildtowerbutton4->move(_map._towerarea[i]->GetX()+80,_map._towerarea[i]->GetY()+20);
                buildtowerbutton4->show();

                break;
            }
        }
        else{
            buildtowerbutton->hide();
            buildtowerbutton2->hide();
            buildtowerbutton3->hide();
            buildtowerbutton4->hide();
        }
    }

    for(_game.itr2=_game._towers.begin();_game.itr2!=_game._towers.end();_game.itr2++){
        if(msclick((*_game.itr2)->GetX(), 80, (*_game.itr2)->GetY(), 80)){
            levelup->move((*_game.itr2)->GetX()+20,(*_game.itr2)->GetY()-40);
            levelup->show();
            deletetower->move((*_game.itr2)->GetX()+20,(*_game.itr2)->GetY()+80);
            deletetower->show();
            break;
        }
        else{
            levelup->hide();
            deletetower->hide();
        }
    }


}

void MainWindow::initialmainwindow(){

    playerbutton1= new Mybutton(":/image/player.jpg");
    playerbutton1->setFixedSize(280,200);
    playerbutton1->setIconSize(QSize(280,200));
    playerbutton1->setParent(this);
    playerbutton2= new Mybutton(":/image/player2.jpg");
    playerbutton2->setFixedSize(280,200);
    playerbutton2->setIconSize(QSize(280,200));
    playerbutton2->setParent(this);
    playerbutton1->move(1110,20);
    playerbutton2->move(1110,20);
    playerbutton2->hide();
    connect(playerbutton1,&QPushButton::clicked,this,[=](){
        playerbutton1->hide();
        playerbutton2->show();
    });
    connect(playerbutton2,&QPushButton::clicked,this,[=](){
        playerbutton2->hide();
        playerbutton1->show();
    });
    startbutton= new Mybutton(":/image/startgame.jpg");
    startbutton->setFixedSize(100,100);
    startbutton->setIconSize(QSize(100,100));
    startbutton->setParent(this);
    startbutton->move(1100,430);

    connect(startbutton,&QPushButton::clicked,this,[=](){
        if(!_game.Isstart()){
            _game.startgame();
            timeid1=startTimer(100);
        }
    });


    buildtowerbutton=new Buildtowerbutton(":/image/greenbutton.png",10);
    buildtowerbutton->setParent(this);
    buildtowerbutton->hide();
    buildtowerbutton->setFixedSize(40,40);
    buildtowerbutton->setIconSize(QSize(40,40));
    buildtowerbutton2=new Buildtowerbutton(":/image/bluebottle.png",30);
    buildtowerbutton2->setParent(this);
    buildtowerbutton2->hide();
    buildtowerbutton2->setFixedSize(40,40);
    buildtowerbutton2->setIconSize(QSize(40,40));
    buildtowerbutton3=new Buildtowerbutton(":/image/yellowbottle.png",50);
    buildtowerbutton3->setParent(this);
    buildtowerbutton3->hide();
    buildtowerbutton3->setFixedSize(40,40);
    buildtowerbutton3->setIconSize(QSize(40,40));
    buildtowerbutton4=new Buildtowerbutton(":/image/redbottle.png",15);
    buildtowerbutton4->setParent(this);
    buildtowerbutton4->hide();
    buildtowerbutton4->setFixedSize(40,40);
    buildtowerbutton4->setIconSize(QSize(40,40));



    levelup=new Mybutton(":/image/upgrade.png");
    levelup->setParent(this);
    levelup->hide();
    levelup->setFixedSize(40,40);
    levelup->setIconSize(QSize(40,40));
    deletetower=new Mybutton(":/image/delete.png");
    deletetower->setParent(this);
    deletetower->hide();
    deletetower->setFixedSize(40,40);
    deletetower->setIconSize(QSize(40,40));
    losehealth=new Mybutton(":/image/blood.png");
    losehealth->setParent(this);
    losehealth->hide();
    losehealth->setFixedSize(80,80);
    losehealth->setIconSize(QSize(80,80));
    losehealth->move(760,480);


    connect(buildtowerbutton,&QPushButton::clicked,this,[=](){
        buildtowerbutton->hide();
        buildtowerbutton2->hide();
        buildtowerbutton3->hide();
        buildtowerbutton4->hide();

        if(_player.getmoney()>=buildtowerbutton->cost){
            _player.spendmoney(buildtowerbutton->cost);
            Tower* p1=new Tower1;
            p1->initialtower(buildtowerbutton->x()-20,buildtowerbutton->y());
            _game._towers.push_back(p1);
            repaint();
        }
    });
    connect(buildtowerbutton2,&QPushButton::clicked,this,[=](){
        buildtowerbutton->hide();
        buildtowerbutton2->hide();
        buildtowerbutton3->hide();
        buildtowerbutton4->hide();
        if(_player.getmoney()>=buildtowerbutton2->cost){
            _player.spendmoney(buildtowerbutton2->cost);
            Tower* p1=new Tower2;
            p1->initialtower(buildtowerbutton->x()-20,buildtowerbutton->y());
            _game._towers.push_back(p1);
            repaint();
        }
    });
    connect(buildtowerbutton3,&QPushButton::clicked,this,[=](){
        buildtowerbutton->hide();
        buildtowerbutton2->hide();
        buildtowerbutton3->hide();
        buildtowerbutton4->hide();
        if(_player.getmoney()>=buildtowerbutton3->cost){
            _player.spendmoney(buildtowerbutton3->cost);
            Tower* p1=new Tower3;
            p1->initialtower(buildtowerbutton->x()-20,buildtowerbutton->y());
            _game._towers.push_back(p1);
            repaint();
        }
    });
    connect(buildtowerbutton4,&QPushButton::clicked,this,[=](){
        buildtowerbutton->hide();
        buildtowerbutton2->hide();
        buildtowerbutton3->hide();
        buildtowerbutton4->hide();
        if(_player.getmoney()>=buildtowerbutton4->cost){
            _player.spendmoney(buildtowerbutton4->cost);
            Tower* p1=new Tower4;
            p1->initialtower(buildtowerbutton->x()-20,buildtowerbutton->y());
            _game._towers.push_back(p1);
            repaint();
        }
    });
    connect(levelup,&QPushButton::clicked,this,[=](){
        levelup->hide();
        deletetower->hide();
        if(_player.getmoney()>=20){
            _player.spendmoney(20);


            for(_game.itr2=_game._towers.begin();_game.itr2!=_game._towers.end();_game.itr2++){
                if((*_game.itr2)->GetX()==levelup->x()-20&&(*_game.itr2)->GetY()==levelup->y()+40){
                    (*_game.itr2)->upgrade();

                }

            }

            repaint();
        }
    });
    connect(deletetower,&QPushButton::clicked,this,[=](){
        deletetower->hide();
        levelup->hide();

        for(_game.itr2=_game._towers.begin();_game.itr2!=_game._towers.end();){
            if((*_game.itr2)->GetX()==deletetower->x()-20&&(*_game.itr2)->GetY()==deletetower->y()-80){
                _game._towers.erase(_game.itr2);
                _player.gainmoney();
            }
            else{
                _game.itr2++;
            }

        }
        repaint();
    });
    QPushButton* disranpush = new QPushButton(this);
    disranpush->setStyleSheet("color:black");
    disranpush->setGeometry(880,50, 150, 45);
    disranpush->setFont(QFont("Î¢ÈíÑÅºÚ", 12));

    disranpush->setText(QString(str2qstr(string("ÏÔÊ¾¹¥»÷·¶Î§"))));
    connect(disranpush,&QPushButton::clicked,[=]()
    {//Í¨¹ý¸Ä±ä±êÊ¶Áî·ÀÓùËþ¹¥»÷·¶Î§ÏÔÊ¾»ò¹Ø±Õ
        if (_game.DisplayAllRange)
        {
            _game.DisplayAllRange = false;
            disranpush->setText(QString(str2qstr(string("ÏÔÊ¾¹¥»÷·¶Î§"))));
        }
        else
        {
            _game.DisplayAllRange = true;
            disranpush->setText(QString(str2qstr(string("Òþ²Ø¹¥»÷·¶Î§"))));
        };
        update();
    });


    back= new Mybutton(":/image/back.png");
    back->setParent(this);
    back->move(1100,550);
    back->setFixedSize(100,100);
    back->setIconSize(QSize(100,100));
    back->hide();


    connect(back,&QPushButton::clicked,this,[=](){
        this->close();

        Menu* m=new Menu;
        m->show();
    });
}

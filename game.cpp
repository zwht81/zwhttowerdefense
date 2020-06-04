#include "game.h"
#include "enemy.h"
#include <iostream>
#include <QTime>


#define caldistance(X1, Y1, X2, Y2)           \
    abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))))

using namespace std ;

Game::Game(QWidget *parent) : QWidget(parent)
{


}

void Game::initialgame(){
    isstart=false;
    waveenemy=20;
    tower1.load(":/image/GreenBottle.png");
}

bool Game::Isstart(){
    return isstart;
}

void Game::startgame(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    player->setVolume(30);
    player->play();
    isstart=true;
    createenemy();
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(enemytime()));
    timer1->start(50);
    timer1->setInterval(1000);
    timer2=new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(bullettime()));
    timer2->start(1000);
    timer2->setInterval(200);
}

void Game::createenemy(){
    Enemy* p1=new Enemy;
    p1->initialenemy();
    _enemys.push_back(p1);
}

void Game::show(QPainter *painter){
    int n = _enemys.size();
    int i;
    for(i=0;i<n;i++)
        _enemys[i]->show(painter);
    n = _towers.size();
    for(i=0;i<n;i++){
        _towers[i]->show(painter);
        if(DisplayAllRange)
            painter->drawEllipse(QPoint(_towers[i]->GetX()+40,_towers[i]->GetY()+40),_towers[i]->getrange(),_towers[i]->getrange());
    }
    if(getwin()){
        painter->drawPixmap(500,200,100,100,QPixmap(":/image/win.png"));
    }

}

void Game::enemytime(){
    if(waveenemy>0){
        this->createenemy();
        waveenemy--;
    }

}

void Game::bullettime(){
    int n=_towers.size();
    int i,j;
    for(i=0;i<n;i++){
        if(_towers[i]->hasbullet||_towers[i]->targetenemy==NULL)
            _towers[i]->bullet.setbullet();
        int m=_enemys.size();
        if(!_towers[i]->targetenemy){
            for(j=0;j<m;j++)
                if(caldistance(_enemys[j]->getx(),_enemys[j]->gety(),_towers[i]->GetX(),_towers[i]->GetY())<_towers[i]->getrange()){
                    _towers[i]->settarget(_enemys[j]);
                    _towers[i]->bullet.hasenemy=true;
                    break;
                }
        }
        else{
            if(caldistance(_towers[i]->targetenemy->getx(),_towers[i]->targetenemy->gety(),_towers[i]->GetX(),_towers[i]->GetY())>_towers[i]->getrange()){
                _towers[i]->settarget(NULL);
                _towers[i]->bullet.hasenemy=false;
            }
        }
        if(_towers[i]->targetenemy){
            _towers[i]->bullet.settarget(_towers[i]->targetenemy->getx()+40,_towers[i]->targetenemy->gety()+40);
            _towers[i]->bullet.move();
            _towers[i]->hasbullet=false;

        }
        if(_towers[i]->bullet.crash()){
            _towers[i]->hasbullet=true;
            _towers[i]->bullet.isexploded=true;
            _towers[i]->targetenemy->injure(_towers[i]->getpower());
            if(_towers[i]->targetenemy->death()){
                _towers[i]->settarget(NULL);
                _towers[i]->bullet.hasenemy=false;
            }

        }
        else
            _towers[i]->bullet.isexploded=false;

    }


}



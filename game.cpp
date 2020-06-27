#include "game.h"
#include "enemy.h"
#include <iostream>
#include <QTime>
#include <iostream>

using namespace std;


#define caldistance(X1, Y1, X2, Y2)           \
    abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))))

using namespace std ;

Game::Game(QWidget *parent) : QWidget(parent)
{


}

void Game::initialgame(int num){
    isstart=false;
    wave=0;

    switch(num){
    case 1:{
        waveenemy1=new int[46];
        int temwave11[46]={120,80,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-2,2,2,2,3,1,3,1,3,-1,-1,-1,-1,-1,-1,-1,-1,-2,1,2,2,3,1,1,2,-1,-1,-1,-1,-1,-2};
        for(int i=0;i<46;i++)
            waveenemy1[i]=temwave11[i];
        waveenemy2=new int[26];
        int temwave12[26]={760,80,1,1,2,2,3,-1,-1,-1,-1,-1,-1,-1,-1,3,1,1,1,1,2,2,3,1,2,3};
        for(int i=0;i<26;i++)
            waveenemy2[i]=temwave12[i];
        gameroute1=new route[2];
        gameroute1[0].xmax=120;
        gameroute1[0].xmin=120;
        gameroute1[0].ymin=80;
        gameroute1[0].ymax=480;
        gameroute1[0].direction=2;
        gameroute1[1].xmax=10000;
        gameroute1[1].xmin=0;
        gameroute1[1].ymin=480;
        gameroute1[1].ymax=490;
        gameroute1[1].direction=4;
        gameroute2=new route[1];
        gameroute2[0].xmax=760;
        gameroute2[0].xmin=760;
        gameroute2[0].ymin=0;
        gameroute2[0].ymax=10000;
        gameroute2[0].direction=2;
        break;
    }
    case 2:{
        waveenemy1=new int[46];
        int temwave21[46]={120,80,2,2,2,2,2,-1,-1,-1,-1,-1,-1,-1,-1,-2,2,2,2,2,2,2,2,2,-1,-1,-1,-1,-1,-1,-1,-1,-2,2,2,2,1,1,1,1,-1,-1,-1,-1,-1,-2};
        for(int i=0;i<46;i++)
            waveenemy1[i]=temwave21[i];
        waveenemy2=new int[26];
        int temwave22[26]={680,40,3,3,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,2,2,1,1,1,2,2,3,1,2,3};
        for(int i=0;i<26;i++)
            waveenemy2[i]=temwave22[i];
        gameroute1=new route[6];
        gameroute1[0].xmax=120;
        gameroute1[0].xmin=120;
        gameroute1[0].ymin=80;
        gameroute1[0].ymax=480;
        gameroute1[0].direction=2;
        gameroute1[1].xmax=280;
        gameroute1[1].xmin=0;
        gameroute1[1].ymin=480;
        gameroute1[1].ymax=490;
        gameroute1[1].direction=4;
        gameroute1[2].xmax=290;
        gameroute1[2].xmin=280;
        gameroute1[2].ymin=80;
        gameroute1[2].ymax=1000;
        gameroute1[2].direction=1;
        gameroute1[3].xmax=440;
        gameroute1[3].xmin=280;
        gameroute1[3].ymin=70;
        gameroute1[3].ymax=80;
        gameroute1[3].direction=4;
        gameroute1[4].xmax=450;
        gameroute1[4].xmin=440;
        gameroute1[4].ymin=70;
        gameroute1[4].ymax=480;
        gameroute1[4].direction=2;
        gameroute1[5].xmax=1000;
        gameroute1[5].xmin=440;
        gameroute1[5].ymin=480;
        gameroute1[5].ymax=490;
        gameroute1[5].direction=4;

        gameroute2=new route[3];
        gameroute2[0].xmax=680;
        gameroute2[0].xmin=680;
        gameroute2[0].ymin=0;
        gameroute2[0].ymax=160;
        gameroute2[0].direction=2;

        gameroute2[1].xmax=760;
        gameroute2[1].xmin=680;
        gameroute2[1].ymin=160;
        gameroute2[1].ymax=170;
        gameroute2[1].direction=4;

        gameroute2[2].xmax=770;
        gameroute2[2].xmin=760;
        gameroute2[2].ymin=0;
        gameroute2[2].ymax=10000;
        gameroute2[2].direction=2;



        break;
    }
    case 3:{
        waveenemy1=new int[46];
        int temwave11[46]={120,80,3,3,3,3,3,-1,-1,-1,-1,-1,-1,-1,-1,-2,3,2,3,2,3,2,3,2,-1,-1,-1,-1,-1,-1,-1,-1,-2,1,2,3,1,2,1,1,-1,-1,-1,-1,-1,-2};
        for(int i=0;i<46;i++)
            waveenemy1[i]=temwave11[i];
        waveenemy2=new int[26];
        int temwave12[26]={760,80,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,2,2,2,2,2,2,2,3,3,3,3};
        for(int i=0;i<26;i++)
            waveenemy2[i]=temwave12[i];

        gameroute1=new route[5];

        gameroute1[0].xmax=440;
        gameroute1[0].xmin=120;
        gameroute1[0].ymin=80;
        gameroute1[0].ymax=80;
        gameroute1[0].direction=4;

        gameroute1[1].xmax=450;
        gameroute1[1].xmin=440;
        gameroute1[1].ymin=80;
        gameroute1[1].ymax=240;
        gameroute1[1].direction=2;

        gameroute1[2].xmax=450;
        gameroute1[2].xmin=120;
        gameroute1[2].ymin=240;
        gameroute1[2].ymax=250;
        gameroute1[2].direction=3;

        gameroute1[3].xmax=120;
        gameroute1[3].xmin=110;
        gameroute1[3].ymin=240;
        gameroute1[3].ymax=480;
        gameroute1[3].direction=2;

        gameroute1[4].xmax=1000;
        gameroute1[4].xmin=0;
        gameroute1[4].ymin=480;
        gameroute1[4].ymax=490;
        gameroute1[4].direction=4;


        gameroute2=new route[1];
        gameroute2[0].xmax=760;
        gameroute2[0].xmin=760;
        gameroute2[0].ymin=0;
        gameroute2[0].ymax=10000;
        gameroute2[0].direction=2;
        break;

    }

    }






    tower1.load(":/image/GreenBottle.png");
}

bool Game::Isstart(){
    return isstart;
}

void Game::startgame(){
    player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    player->setVolume(30);
    player->play();
    isstart=true;
    wave++;
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(enemytime1()));
    timer1->start(50);
    timer1->setInterval(2000);
    timer2=new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(bullettime()));
    timer2->start(1000);
    timer2->setInterval(200);
    timer3=new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(enemytime2()));
    timer3->start(1000);
    timer3->setInterval(2000);

}

void Game::createenemy(int n,int i){

    if(n==1){
        if(waveenemy1[i]==1)
        {
            Enemy* p1=new Enemymushroom;
            p1->initialenemy(waveenemy1[0],waveenemy1[1],wave);
            p1->rt=gameroute1;
            _enemys.push_back(p1);
        }
        else
            if(waveenemy1[i]==2){
                Enemy* p1=new Enemybird;
                p1->initialenemy(waveenemy1[0],waveenemy1[1],wave);
                p1->rt=gameroute1;
                _enemys.push_back(p1);
            }
            else{
                if(waveenemy1[i]==3){
                    Enemy* p1=new Enemyturtle;
                    p1->initialenemy(waveenemy1[0],waveenemy1[1],wave);
                    p1->rt=gameroute1;
                    _enemys.push_back(p1);
                }
            }



    }
    if(n==2){
        if(waveenemy2[i]==1)
        {
            Enemy* p1=new Enemymushroom;
            p1->initialenemy(waveenemy2[0],waveenemy2[1],wave);
            p1->rt=gameroute2;
            _enemys.push_back(p1);
        }
        else
            if(waveenemy2[i]==2){
                Enemy* p1=new Enemybird;
                p1->initialenemy(waveenemy2[0],waveenemy2[1],wave);
                p1->rt=gameroute2;
                _enemys.push_back(p1);
            }
            else{
                if(waveenemy2[i]==3){
                    Enemy* p1=new Enemyturtle;
                    p1->initialenemy(waveenemy2[0],waveenemy2[1],wave);
                    p1->rt=gameroute2;
                    _enemys.push_back(p1);
                }
            }
    }

}

void Game::show(QPainter *painter){

    for(itr=_enemys.begin();itr!=_enemys.end();itr++){
        (*itr)->show(painter);
    }

    //  for(i=0;i<n;i++)
    //      _enemys[i]->show(painter);
    painter->setPen(QPen(Qt::yellow,1));

    for(itr2=_towers.begin();itr2!=_towers.end();itr2++){
        (*itr2)->show(painter);
        if(DisplayAllRange)
            painter->drawEllipse(QPoint((*itr2)->GetX()+40,(*itr2)->GetY()+40),(*itr2)->getrange(),(*itr2)->getrange());
    }

    painter->setPen(Qt::black);
    QFont font1;
    font1.setPointSize(30);
    painter->setFont(font1);
    if(getwave()==4)
        painter->drawText(1200,500,"wave: "+QString::number(3));
    else
        painter->drawText(1200,500,"wave: "+QString::number(getwave()));
    if(getwin()){
        painter->drawPixmap(500,200,100,100,QPixmap(":/image/win.png"));
        player->stop();
    }

}

void Game::enemytime1(){
    int i=2;
    while(waveenemy1[i]==0){
        i++;
    }

    if(waveenemy1[i]==-1){
        waveenemy1[i]=0;
        return;
    }
    if(waveenemy1[i]==-2){
        waveenemy1[i]=0;
        wave++;

        return;
    }
    if(waveenemy1[45]==0)
        return;

    createenemy(1,i);
    waveenemy1[i]=0;
}

void Game::enemytime2(){
    int i=2;
    while(waveenemy2[i]==0){
        i++;
    }
    if(waveenemy2[i]==-1){
        waveenemy2[i]=0;
        return;
    }
    if(waveenemy2[25]==0)
        return;

    createenemy(2,i);
    waveenemy2[i]=0;
}

void Game::bullettime(){

    for(itr2=_towers.begin();itr2!=_towers.end();itr2++){
        (*itr2)->bullet.isexploded=false;
        if(!(*itr2)->targetenemy){
            for(itr=_enemys.begin();itr!=_enemys.end();itr++)
                if(caldistance((*itr)->getx(),(*itr)->gety(),(*itr2)->GetX(),(*itr2)->GetY())<(*itr2)->getrange()){
                    (*itr2)->settarget((*itr));
                    (*itr2)->bullet.hasenemy=true;
                    (*itr2)->attack();
                    break;
                }else{
                    (*itr2)->bullet.isexploded=false;
                }
        }
        else{

            if(caldistance((*itr2)->targetenemy->getx(),(*itr2)->targetenemy->gety(),(*itr2)->GetX(),(*itr2)->GetY())>(*itr2)->getrange()){
                (*itr2)->settarget(NULL);
                (*itr2)->bullet.hasenemy=false;
                (*itr2)->bullet.isexploded=false;
            }
            else{
                for(itr=_enemys.begin();itr!=_enemys.end();itr++)
                    if((caldistance((*itr)->getx(),(*itr)->gety(),(*itr2)->GetX(),(*itr2)->GetY())<(*itr2)->getrange())&&
                            caldistance((*itr2)->targetenemy->getx(),(*itr2)->targetenemy->gety(),760,480)>caldistance((*itr)->getx(),(*itr)->gety(),760,480)){
                        (*itr2)->settarget((*itr));
                        (*itr2)->bullet.hasenemy=true;
                        break;
                    }

                for(itr=_enemys.begin();itr!=_enemys.end();itr++)
                    if((caldistance((*itr)->getx(),(*itr)->gety(),(*itr2)->GetX(),(*itr2)->GetY())<(*itr2)->getrange())&&((*itr)->isbird()==1)){
                        (*itr2)->settarget((*itr));
                        (*itr2)->bullet.hasenemy=true;
                        break;
                    }
                (*itr2)->attack();

            }


        }







    }


}



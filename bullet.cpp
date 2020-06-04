#include "bullet.h"

Bullet::Bullet()
{

}

void Bullet::initialbullet(int x, int y){
    this->x=x+30;
    this->y=y+30;
    initialx=x+40;
    initialy=y+40;
    speed=100;
    hasenemy=false;
    bulletpic.load(":/image/bullet.png");
    explosion.load(":/image/explosion.png");
    isexploded=false;


}

void Bullet::setbullet(){
    x=initialx;
    y=initialy;
}

void Bullet::show(QPainter *painter){
    if(hasenemy)
        painter->drawPixmap(x,y,20,20,bulletpic);
    if(isexploded)
        painter->drawPixmap(x,y,40,40,explosion);
}

void Bullet::move(){
   // double tempx=double(speed)*(double(abs(x-targetx)))/(double(abs(x-targetx))+double(abs(y-targety)));
   // double tempy=double(speed)*(double(abs(y-targety)))/(double(abs(x-targetx))+double(abs(y-targety)));
   // x+=tempx;
   // y+=tempy;
     x+=(targetx-x)/2;
     y+=(targety-y)/2;
  /*  int k = (targety - y) / (targetx - x);
    int b = targety - targetx*x;

    x = UpLeftX + 40, bull->coor.y = UpLeftY + 40;*/


}

bool Bullet::crash(){
    if(abs(x-targetx)<30&&abs(y-targety)<30){
        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/sound/crash.mp3"));
        player->setVolume(3);
        player->play();
        return true;
    }
    return false;

}

void Bullet::settarget(int x, int y){
    targetx=x;
    targety=y;
}


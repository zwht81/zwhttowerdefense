#include "tower.h"

Tower::Tower()
{

}



void Tower::initialtower(int x,int y){
    towerpic.load(":/image/GreenBottle.png");
    this->x=x;
    this->y=y+40;
    range=200;
    bullet.initialbullet(this->x,this->y);
    hasbullet=true;
    power=14;
    width=80;
    height=80;
    level=0;
}

void Tower::settarget(Enemy *p){
    targetenemy=p;
}

/*bool Tower::searchenemy(Enemy * p){

    if(range>sqrt(double(p->getx()-this->GetX())*double(p->getx()-this->GetX())
                  +double(p->gety()-this->GetY())*double(p->gety()-this->GetY())
                  )){
        this->bullet.hasenemy=true;
        this->bullet.settarget(p->getx(),p->gety());
        return true;
    }
    return false;





}*/

void Tower::show(QPainter *painter){
    painter->drawPixmap(x-level*10,y-level*10,width,height,towerpic);
    this->bullet.show(painter);
}

int Tower::GetX() const     //获取横坐标
{
    return x;
}

int Tower::GetY() const     //获取横坐标
{
    return y;
}

void Tower::upgrade(){
    power+=10;
    height+=20;
    width+=20;
    level++;
    range+=30;
}




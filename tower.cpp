#include "tower.h"

Tower::Tower()
{

}



void Tower::initialtower(int x,int y){
    towerpic.load(":/image/GreenBottle.png");
    this->x=x;
    this->y=y+40;
    range=200;
    bullet.initialbullet(this->x,this->y,QString(":/image/bullet.png"),QString(":/image/explosion.png"));
    hasbullet=true;
    power=140;
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



void Tower::upgrade(){
    power+=10;
    height+=20;
    width+=20;
    level++;
    range+=30;
}


void Tower::attack(){
    if((this)->hasbullet||(this)->targetenemy==NULL)
        (this)->bullet.setbullet();


    if((this)->targetenemy){
        (this)->bullet.settarget((this)->targetenemy->getx()+40,(this)->targetenemy->gety()+40);
        (this)->bullet.move();
        (this)->hasbullet=false;

    }
    if((this)->bullet.crash()){
        (this)->hasbullet=true;
        (this)->bullet.isexploded=true;
        (this)->targetenemy->injure((this)->getpower());
        if((this)->targetenemy->death()){
            (this)->settarget(NULL);
            (this)->bullet.hasenemy=false;
        }

    }
    else
        (this)->bullet.isexploded=false;
}



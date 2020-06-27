#include "tower3.h"

Tower3::Tower3()
{

}

void Tower3::initialtower(int x,int y){
    towerpic.load(":/image/yellow.png");
    this->x=x;
    this->y=y+40;
    range=100;
    bullet.initialbullet(this->x,this->y,QString(":/image/yellowbullet.png"),QString(":/image/explosion3.png"));
    hasbullet=true;
    power=10;
    width=80;
    height=80;
    level=0;

}

void Tower3::attack(){
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
        targetenemy->getdebuff(2);
        if((this)->targetenemy->death()){
            (this)->settarget(NULL);
            (this)->bullet.hasenemy=false;
        }

    }
    else
        (this)->bullet.isexploded=false;
}

void Tower3::upgrade(){
    power+=10;
    height+=20;
    width+=20;
    level++;
    range+=30;
}

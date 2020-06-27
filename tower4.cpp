#include "tower4.h"

Tower4::Tower4()
{

}

void Tower4::initialtower(int x,int y){
    towerpic.load(":/image/red.png");
    this->x=x;
    this->y=y+40;
    range=400;
    bullet.initialbullet(this->x,this->y,QString(":/image/redbullet.png"),QString(":/image/explosion4.png"));
    hasbullet=true;
    power=5;
    width=80;
    height=80;
    level=0;

}

void Tower4::attack(){
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

void Tower4::upgrade(){
    power+=5;
    height+=20;
    width+=20;
    level++;
    range+=30;
}

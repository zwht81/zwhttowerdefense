#include "enemybird.h"

Enemybird::Enemybird()
{

}


void Enemybird::initialenemy(int x,int y,int wave){
    health=100+20*wave;
    speed=400;
    this->x=x;
    this->y=y;
    enemypic.load(":/image/bird.png");
    debuff=0;



}

void Enemybird::move(){

    double k=(760-x)/(480-y);
    x+=k*speed/80;
    y+=speed/80;


    if(debuffnum<=0)
        speed=400;


}

void Enemybird::getdebuff(int i){
    debuff=i;
    debuffnum=20;
    if(i==2)
        speed=0;
    else{
        if(speed>0)
            speed=200;
    }
}

void Enemybird:: show(QPainter * painter){
    painter->drawPixmap(x,y,120,120,enemypic);
    if(speed==0&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("Ñ£ÔÎ")));
        debuffnum--;

    }
    if(speed==200&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("¼õËÙ")));
        debuffnum--;

    }


}

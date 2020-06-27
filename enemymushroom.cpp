#include "enemymushroom.h"
#include "enemy.h"
#include <iostream>

using namespace std;



Enemymushroom::Enemymushroom()
{

}

void Enemymushroom:: show(QPainter * painter){
    painter->drawPixmap(x,y,80,80,enemypic);
    if(speed==0&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("Ñ£ÔÎ")));
        debuffnum--;

    }
    if(speed==100&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("¼õËÙ")));
        debuffnum--;

    }


}





void Enemymushroom::initialenemy(int x,int y,int wave){
    health=100+30*wave;
    speed=200;
    this->x=x;
    this->y=y;
    enemypic.load(":/image/enemy11.png");
    debuff=0;
}

void Enemymushroom::move(){
    int i;
    int n=_msize(rt)/sizeof(route);
    for(i=0;i<n;i++){
        if(x>=rt[i].xmin&&x<=rt[i].xmax&&y>=rt[i].ymin&&y<=rt[i].ymax){
            switch(rt[i].direction){
            case 1:y-=(speed/40);break;
            case 2:y+=(speed/40);break;
            case 3:x-=(speed/40);break;
            case 4:x+=(speed/40);break;
            }
            break;
        }
    }

    if(debuffnum<=0)
        speed=200;


}

void Enemymushroom::getdebuff(int i){
    debuff=i;
    debuffnum=20;
    if(i==2)
        speed=0;
    else{
        if(speed>0)
            speed=100;
    }
}

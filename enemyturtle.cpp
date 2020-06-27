#include "enemyturtle.h"

Enemyturtle::Enemyturtle()
{

}

void Enemyturtle::initialenemy(int x,int y,int wave){
    health=500+50*wave;
    speed=120;
    this->x=x;
    this->y=y;
    enemypic.load(":/image/turtle3.png");
    debuff=0;


}

void Enemyturtle::move(){
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
    if(debuffnum<=0)
        speed=120;


}

void Enemyturtle::getdebuff(int i){
    debuff=i;
    debuffnum=20;
    if(i==2)
        speed=0;
    else{
        if(speed>0)
            speed=60;
    }
}

void Enemyturtle:: show(QPainter * painter){
    painter->drawPixmap(x,y,80,80,enemypic);
    if(speed==0&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("Ñ£ÔÎ")));
        debuffnum--;

    }
    if(speed==60&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("¼õËÙ")));
        debuffnum--;

    }


}

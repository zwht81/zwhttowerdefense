#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy:: show(QPainter * painter){
    painter->drawPixmap(x,y,80,80,enemypic);
    if(debuff==2&&debuffnum>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("Ñ£ÔÎ")));
        debuffnum--;

    }
    if(debuff==1&&debuffnum>0&&speed>0){
        QFont font1("ËÎÌå",15);
        painter->setFont(font1);
        painter->setPen(Qt::red);
        painter->drawText(x+10,y+60,str2qstr(string("¼õËÙ")));
        debuffnum--;

    }




}

void Enemy::getdebuff(int i){
    debuff=i;
    debuffnum=10;
    if(i==2)
        speed=0;
    else{
        if(speed>0)
            speed=speed/2;
    }
}

void Enemy::initialenemy(int x,int y,int wave){
    health=100;
    speed=10;
    x=80;
    y=80;
    enemypic.load(":/image/enemy11.png");
}

void Enemy::move(){
    if(y>=480)
        x+=5;
    else
        y+=5;

}

bool Enemy::arrive(){
    if((x<=780)&&(x>=760)&&(y>=480)&&(y<=520))
        return true;
    return false;
}

void Enemy::injure(int n){
    health-=n;
}

bool Enemy::death(){
    if(health<=0)
        return true;
    return false;
}

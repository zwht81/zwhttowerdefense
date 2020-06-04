#include "enemy.h"

Enemy::Enemy()
{

}

void Enemy:: show(QPainter * painter){
    painter->drawPixmap(x,y,80,80,enemypic);

}

void Enemy::initialenemy(){
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
    if((x<=680)&&(x>=670)&&(y>=480)&&(y<=520))
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

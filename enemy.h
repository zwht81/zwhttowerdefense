#ifndef ENEMY_H
#define ENEMY_H

#include "QPainter"

class Enemy
{
public:
    Enemy();
    void show(QPainter * painter);
    void initialenemy();
    bool arrive();//是否到达
    void move();  //移动
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void injure(int n); //敌人掉血
    bool death();  //敌人死了

private:
    QPixmap enemypic;

    int speed;
    int x;
    int y;
    int health;  //血量


};

#endif // ENEMY_H

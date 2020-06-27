#ifndef ENEMY_H
#define ENEMY_H

#include "QPainter"
#include "iostream"

using namespace std;
//敌人基类
struct route{
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    int direction;
};//路径

class Enemy
{
public:
    Enemy();
    virtual void show(QPainter * painter);
    virtual void initialenemy(int x,int y,int wave);
    bool arrive();//是否到达
    virtual void move();  //移动
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void injure(int n); //敌人掉血
    bool death();  //敌人死了嘛
    virtual void getdebuff(int i);//减速眩晕
    route *rt;//路径数组
    virtual int isbird()const{ //是否是飞龙
        return 0;
    }
    int gethealth()const{
        return health;
    }

    QString str2qstr(const string str) //qstring中文乱码解决
    {
        return QString::fromLocal8Bit(str.data());
    }


protected:
    QPixmap enemypic;
    int speed;
    int x;
    int y;
    int health;  //血量
    int debuff; //正常 减速 眩晕
    int debuffnum;



};

#endif // ENEMY_H

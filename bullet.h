#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <cmath>
#include <QMediaPlayer>

class Bullet
{
public:
    Bullet();
    void move();
    void show(QPainter * painter);
    void initialbullet(int x,int y);
    void setbullet();  //初始化子弹
    bool crash();   //子弹boom
    void settarget(int x,int y);//子弹找敌人
    bool hasenemy;  //是否有敌人，没有就不画
    bool isexploded; //是否boom，没有不画boom
private:
    int x;
    int y;
    int initialx;
    int initialy;
    int speed;
    int targetx;//目标坐标
    int targety;
    QPixmap bulletpic;
    QPixmap explosion;

};

#endif // BULLET_H

#ifndef TOWER_H
#define TOWER_H

#include <QPainter>
#include <bullet.h>
#include <enemy.h>
#include <vector>

using namespace std;


塔基类
class Tower
{
public:
    Tower();
    virtual void initialtower(int x,int y);//初始化
    void show(QPainter * painter);//画画
    int GetX() const{
        return x;
    }     //获取横坐标
    int GetY() const{
        return y;
    }     //获取横坐标
    int getrange() const{  //返回range
        return range;
    }
    bool hasbullet;
    Bullet  bullet;   //一个塔一发子弹
    Enemy * targetenemy=NULL;   //塔的目标敌人
    void settarget(Enemy *p);   //设置目标
    int getpower()const{
        return power;
    }
    virtual void upgrade(); //升级
    virtual void attack();




protected:
    QPixmap towerpic; //图标
    int x;   //位置
    int y;
    int range;  //范围，花费，威力，大小
    int cost;
    int power;
    int width;
    int height;
    int level;


};


#endif // TOWER_H

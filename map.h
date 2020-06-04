#ifndef MAP_H
#define MAP_H

#include <QPainter>
#include <vector>
#include "towerarea.h"
#include <iostream>

using namespace std;

class Map
{
public:
    Map();
    void drawmap(QPainter* painter);  //画地图
    void initialmap();  //初始化地图
    vector<Towerarea *> _towerarea;  //塔坑放在地图里
private:
    int maparr[16][27];  //地图格子
    QPixmap grass;  //草
    QPixmap road;   //路
    QPixmap towerarea;  //塔坑
    QPixmap entrance;  //敌人入口
    QPixmap home; //家


};

#endif // MAP_H

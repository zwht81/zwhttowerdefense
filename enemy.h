#ifndef ENEMY_H
#define ENEMY_H

#include "QPainter"

class Enemy
{
public:
    Enemy();
    void show(QPainter * painter);
    void initialenemy();
    bool arrive();//�Ƿ񵽴�
    void move();  //�ƶ�
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void injure(int n); //���˵�Ѫ
    bool death();  //��������

private:
    QPixmap enemypic;

    int speed;
    int x;
    int y;
    int health;  //Ѫ��


};

#endif // ENEMY_H

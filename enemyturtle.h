#ifndef ENEMYTURTLE_H
#define ENEMYTURTLE_H


#include "enemy.h"
//牛头人类
class Enemyturtle : public Enemy
{
public:
    Enemyturtle();
    void show(QPainter * painter);
    void getdebuff(int i);


    void initialenemy(int x,int y,int wave);

    void move();  //移动
    int isbird() const{
        return 0;
    }
};

#endif // ENEMYTURTLE_H

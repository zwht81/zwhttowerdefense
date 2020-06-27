#ifndef ENEMYBIRD_H
#define ENEMYBIRD_H

#include "enemy.h"
//∑…¡˙¿‡
class Enemybird : public Enemy
{
public:
    Enemybird();
    void initialenemy(int x,int y,int wave);
    void show(QPainter * painter);
    void getdebuff(int i);
    int isbird() const{
        return 1;
    }

    void move();  //“∆∂Ø


};

#endif // ENEMYBIRD_H

#ifndef ENEMYTURTLE_H
#define ENEMYTURTLE_H


#include "enemy.h"
//ţͷ����
class Enemyturtle : public Enemy
{
public:
    Enemyturtle();
    void show(QPainter * painter);
    void getdebuff(int i);


    void initialenemy(int x,int y,int wave);

    void move();  //�ƶ�
    int isbird() const{
        return 0;
    }
};

#endif // ENEMYTURTLE_H

#ifndef ENEMYMUSHROOM_H
#define ENEMYMUSHROOM_H

#include "enemy.h"

//Ģ����
class Enemymushroom : public Enemy
{
public:
    Enemymushroom();
    void show(QPainter * painter);
    void getdebuff(int i);


    void initialenemy(int x,int y,int wave);

    void move();  //�ƶ�
    int isbird() const{
        return 0;
    }


private:

};

#endif // ENEMYMUSHROOM_H

#ifndef PLAYER_H
#define PLAYER_H

#include "QPainter"
#include "mybutton.h"

class Player
{
public:
    Player();
    void Initialplayer(); //��ʼ��
    void show(QPainter * painter); //��Ѫ����Ǯ
    void healthminus(int n);  //��Ѫ
    int  getmoney();  //����Ǯ
    void spendmoney(int n); //��Ǯ
    void gainmoney(); //��Ǯ
    int  gethealth()const{
        return health;
    }
private:

    int health;
    int money;
};

#endif // PLAYER_H

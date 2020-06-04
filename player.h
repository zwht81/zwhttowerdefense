#ifndef PLAYER_H
#define PLAYER_H

#include "QPainter"
#include "mybutton.h"

class Player
{
public:
    Player();
    void Initialplayer(); //³õÊ¼»¯
    void show(QPainter * painter); //»­ÑªÁ¿£¬Ç®
    void healthminus(int n);  //¿ÛÑª
    int  getmoney();  //·µ»ØÇ®
    void spendmoney(int n); //»¨Ç®
    void gainmoney(); //µÃÇ®
    int  gethealth()const{
        return health;
    }
private:

    int health;
    int money;
};

#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include "QPainter"
#include "mybutton.h"
#include"iostream"
#include "string"

using namespace std;


//玩家类
class Player
{
public:
    Player();
    void Initialplayer(QString name); //初始化
    void show(QPainter * painter); //画血量，钱
    void healthminus(int n);  //扣血
    int  getmoney();  //返回钱
    void spendmoney(int n); //花钱
    void gainmoney(); //得钱
    int  gethealth()const{
        return health;
    }

private:

    int health;
    int money;
    QString playername;//名称
};

#endif // PLAYER_H

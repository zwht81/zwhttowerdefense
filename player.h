#ifndef PLAYER_H
#define PLAYER_H

#include "QPainter"
#include "mybutton.h"
#include"iostream"
#include "string"

using namespace std;


//�����
class Player
{
public:
    Player();
    void Initialplayer(QString name); //��ʼ��
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
    QString playername;//����
};

#endif // PLAYER_H

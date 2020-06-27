#ifndef ENEMY_H
#define ENEMY_H

#include "QPainter"
#include "iostream"

using namespace std;
//���˻���
struct route{
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    int direction;
};//·��

class Enemy
{
public:
    Enemy();
    virtual void show(QPainter * painter);
    virtual void initialenemy(int x,int y,int wave);
    bool arrive();//�Ƿ񵽴�
    virtual void move();  //�ƶ�
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void injure(int n); //���˵�Ѫ
    bool death();  //����������
    virtual void getdebuff(int i);//����ѣ��
    route *rt;//·������
    virtual int isbird()const{ //�Ƿ��Ƿ���
        return 0;
    }
    int gethealth()const{
        return health;
    }

    QString str2qstr(const string str) //qstring����������
    {
        return QString::fromLocal8Bit(str.data());
    }


protected:
    QPixmap enemypic;
    int speed;
    int x;
    int y;
    int health;  //Ѫ��
    int debuff; //���� ���� ѣ��
    int debuffnum;



};

#endif // ENEMY_H

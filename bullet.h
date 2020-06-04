#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <cmath>
#include <QMediaPlayer>

class Bullet
{
public:
    Bullet();
    void move();
    void show(QPainter * painter);
    void initialbullet(int x,int y);
    void setbullet();  //��ʼ���ӵ�
    bool crash();   //�ӵ�boom
    void settarget(int x,int y);//�ӵ��ҵ���
    bool hasenemy;  //�Ƿ��е��ˣ�û�оͲ���
    bool isexploded; //�Ƿ�boom��û�в���boom
private:
    int x;
    int y;
    int initialx;
    int initialy;
    int speed;
    int targetx;//Ŀ������
    int targety;
    QPixmap bulletpic;
    QPixmap explosion;

};

#endif // BULLET_H

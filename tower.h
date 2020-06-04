#ifndef TOWER_H
#define TOWER_H

#include <QPainter>
#include <bullet.h>
#include <enemy.h>
#include <vector>

using namespace std;

class Tower
{
public:
    Tower();
    void initialtower(int x,int y);//��ʼ��
    void show(QPainter * painter);//����
    int GetX() const;     //��ȡ������
    int GetY() const;     //��ȡ������
    int getrange() const{  //����range
        return range;
    }
    bool hasbullet;
    Bullet  bullet;   //һ����һ���ӵ�
    Enemy * targetenemy=NULL;   //����Ŀ�����
    void settarget(Enemy *p);   //����Ŀ��
    int getpower()const{
        return power;
    }
    void upgrade();



private:
    QPixmap towerpic; //ͼ��
    int x;   //λ��
    int y;
    int range;  //��Χ�����ѣ���������С
    int cost;
    int power;
    int width;
    int height;
    int level;


};


#endif // TOWER_H

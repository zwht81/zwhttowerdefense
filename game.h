#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "enemy.h"
#include "enemybird.h"
#include "enemymushroom.h"
#include "enemyturtle.h"
#include "QTimer"
#include "vector"
#include "tower.h"
#include "QTime"
#include <cmath>
#include <QMediaPlayer>

using namespace std;


//��Ϸ
class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    bool Isstart();  //�Ƿ�ʼ�������ظ���ʼ
    void startgame(); //��ʼ��Ϸ
    void initialgame(int num); //��ʼ����Ϸ����������ɶ��
    void createenemy(int n,int i);//��һ������
    void show(QPainter * painter); //����
    //void timerEvent(QTimerEvent *e);
    vector<Enemy *> _enemys;   //��������
    vector<Enemy *>::iterator itr;
    vector<Tower *> _towers;   //������
    vector<Tower *>::iterator itr2;
    bool DisplayAllRange = false;  //�Ƿ���ʾ��Χ

    void win(){
        iswin=true;
    }
    void lose(){
        islose=true;
    }

    bool getwin()const{
        return iswin;
    }
    route* gameroute1; //����·������
    route* gameroute2;
    int getwave()const{
        return wave;
    }
    int levelnum;


private:
    bool isstart;    //�Ƿ�ʼ
    int* waveenemy1;
    int* waveenemy2;
    int wave;
    QPixmap tower1;  //��ͼƬ
    QTimer *timer1;  //���˼�ʱ��
    QTimer *timer2;  //����ʱ��
    QTimer *timer3;
    bool iswin=false;
    bool islose;
    QMediaPlayer * player;

signals:

public slots:
    void enemytime1();
    void enemytime2();//�ۺ���
    void bullettime();
};

#endif // GAME_H

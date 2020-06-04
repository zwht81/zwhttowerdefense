#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "enemy.h"
#include "QTimer"
#include "vector"
#include "tower.h"
#include "QTime"
#include <cmath>
#include <QMediaPlayer>

using namespace std;

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    bool Isstart();  //�Ƿ�ʼ�������ظ���ʼ
    void startgame(); //��ʼ��Ϸ
    void initialgame(); //��ʼ����Ϸ����������ɶ��
    void createenemy();//��һ������
    void show(QPainter * painter); //����
    //void timerEvent(QTimerEvent *e);
    vector<Enemy *> _enemys;   //��������
    vector<Tower *> _towers;   //������
    bool DisplayAllRange = false;  //�Ƿ���ʾ��Χ
    int getwaveenemy()const{
        return waveenemy;
    }
    void win(){
        iswin=true;
    }
    bool getwin()const{
        return iswin;
    }
private:
    bool isstart;    //�Ƿ�ʼ

    int waveenemy;   //һ����������
    QPixmap tower1;  //��ͼƬ
    QTimer *timer1;  //���˼�ʱ��
    QTimer *timer2;  //����ʱ��
    bool iswin=false;

signals:

public slots:
    void enemytime(); //�ۺ���
    void bullettime();
};

#endif // GAME_H

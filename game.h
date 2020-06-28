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


//游戏
class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    bool Isstart();  //是否开始，不能重复开始
    void startgame(); //开始游戏
    void initialgame(int num); //初始化游戏，塔，敌人啥的
    void createenemy(int n,int i);//造一个敌人
    void show(QPainter * painter); //画画
    //void timerEvent(QTimerEvent *e);
    vector<Enemy *> _enemys;   //敌人数组
    vector<Enemy *>::iterator itr;
    vector<Tower *> _towers;   //塔数组
    vector<Tower *>::iterator itr2;
    bool DisplayAllRange = false;  //是否显示范围

    void win(){
        iswin=true;
    }
    void lose(){
        islose=true;
    }

    bool getwin()const{
        return iswin;
    }
    route* gameroute1; //两条路径出敌
    route* gameroute2;
    int getwave()const{
        return wave;
    }
    int levelnum;


private:
    bool isstart;    //是否开始
    int* waveenemy1;
    int* waveenemy2;
    int wave;
    QPixmap tower1;  //塔图片
    QTimer *timer1;  //敌人计时器
    QTimer *timer2;  //塔计时器
    QTimer *timer3;
    bool iswin=false;
    bool islose;
    QMediaPlayer * player;

signals:

public slots:
    void enemytime1();
    void enemytime2();//槽函数
    void bullettime();
};

#endif // GAME_H

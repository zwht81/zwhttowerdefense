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
    bool Isstart();  //是否开始，不能重复开始
    void startgame(); //开始游戏
    void initialgame(); //初始化游戏，塔，敌人啥的
    void createenemy();//造一个敌人
    void show(QPainter * painter); //画画
    //void timerEvent(QTimerEvent *e);
    vector<Enemy *> _enemys;   //敌人数组
    vector<Tower *> _towers;   //塔数组
    bool DisplayAllRange = false;  //是否显示范围
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
    bool isstart;    //是否开始

    int waveenemy;   //一波几个敌人
    QPixmap tower1;  //塔图片
    QTimer *timer1;  //敌人计时器
    QTimer *timer2;  //塔计时器
    bool iswin=false;

signals:

public slots:
    void enemytime(); //槽函数
    void bullettime();
};

#endif // GAME_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <map.h>
#include <player.h>
#include "mybutton.h"
#include "game.h"
#include <QTimer>
#include <vector>
#include "towerarea.h"
#include <QMouseEvent>
#include "buildtowerbutton.h"
#include <QPushButton>
#include "tower1.h"
#include "tower2.h"
#include "tower3.h"
#include "tower4.h"
#include <QMediaPlayer>

using namespace std;

namespace Ui {
class MainWindow;
class levelchoose;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int i,QString name,QWidget *parent = 0);
    void paintEvent(QPaintEvent *e); //画画函数（总）
    void timerEvent(QTimerEvent *e); //计时函数
    void mousePressEvent(QMouseEvent *ev);  //点击
    QString str2qstr(const string str) //qstring中文乱码解决
    {
        return QString::fromLocal8Bit(str.data());
    }
    ~MainWindow();
    void initialmainwindow();

signals:


private:
    Ui::MainWindow *ui;
    Map _map;   //地图
    Player _player;  //玩家
    Game _game;  //游戏，包括塔，敌人
    QString playername;

    Mybutton* playerbutton1;  //右上角按钮1，点着玩的
    Mybutton* playerbutton2;   //点着玩的2
    Mybutton* startbutton;   //开始游戏
    Buildtowerbutton* buildtowerbutton;   //建塔的按钮
    Buildtowerbutton* buildtowerbutton2;
    Buildtowerbutton* buildtowerbutton3;
    Buildtowerbutton* buildtowerbutton4;
    Mybutton* levelup;  //升级按钮
    Mybutton* deletetower;//删除
    Mybutton* losehealth;//掉血
    Mybutton* back;//返回按钮
    int levelnum;


    int timeid1;  //timeid
    int timeid2;
};

#endif // MAINWINDOW_H

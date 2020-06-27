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
    void paintEvent(QPaintEvent *e); //�����������ܣ�
    void timerEvent(QTimerEvent *e); //��ʱ����
    void mousePressEvent(QMouseEvent *ev);  //���
    QString str2qstr(const string str) //qstring����������
    {
        return QString::fromLocal8Bit(str.data());
    }
    ~MainWindow();
    void initialmainwindow();

signals:


private:
    Ui::MainWindow *ui;
    Map _map;   //��ͼ
    Player _player;  //���
    Game _game;  //��Ϸ��������������
    QString playername;

    Mybutton* playerbutton1;  //���Ͻǰ�ť1���������
    Mybutton* playerbutton2;   //�������2
    Mybutton* startbutton;   //��ʼ��Ϸ
    Buildtowerbutton* buildtowerbutton;   //�����İ�ť
    Buildtowerbutton* buildtowerbutton2;
    Buildtowerbutton* buildtowerbutton3;
    Buildtowerbutton* buildtowerbutton4;
    Mybutton* levelup;  //������ť
    Mybutton* deletetower;//ɾ��
    Mybutton* losehealth;//��Ѫ
    Mybutton* back;//���ذ�ť
    int levelnum;


    int timeid1;  //timeid
    int timeid2;
};

#endif // MAINWINDOW_H

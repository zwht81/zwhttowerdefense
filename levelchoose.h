#ifndef LEVELCHOOSE_H
#define LEVELCHOOSE_H

#include <QMainWindow>
#include "qpushbutton.h"
#include <form.h>

//选关界面
class Levelchoose : public QMainWindow
{
    Q_OBJECT
public:
    explicit Levelchoose(QWidget *parent = nullptr);
    QImage menuback;//菜单背景
    QPushButton* p1; //123关
    QPushButton* p2;
    QPushButton* p3;
    void paintEvent(QPaintEvent *e);




signals:

public slots:
};

#endif // LEVELCHOOSE_H

#ifndef LEVELCHOOSE_H
#define LEVELCHOOSE_H

#include <QMainWindow>
#include "qpushbutton.h"
#include <form.h>

//ѡ�ؽ���
class Levelchoose : public QMainWindow
{
    Q_OBJECT
public:
    explicit Levelchoose(QWidget *parent = nullptr);
    QImage menuback;//�˵�����
    QPushButton* p1; //123��
    QPushButton* p2;
    QPushButton* p3;
    void paintEvent(QPaintEvent *e);




signals:

public slots:
};

#endif // LEVELCHOOSE_H

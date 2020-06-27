#ifndef INTRODUCE_H
#define INTRODUCE_H

#include "mybutton.h"
#include <QWidget>


//简介界面
class Introduce : public QWidget
{
    Q_OBJECT
public:
    explicit Introduce(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);

signals:

public slots:
private:
    Mybutton* back;//菜单按钮
    QImage introback;//菜单背景
};

#endif // INTRODUCE_H

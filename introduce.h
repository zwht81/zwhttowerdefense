#ifndef INTRODUCE_H
#define INTRODUCE_H

#include "mybutton.h"
#include <QWidget>


//������
class Introduce : public QWidget
{
    Q_OBJECT
public:
    explicit Introduce(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);

signals:

public slots:
private:
    Mybutton* back;//�˵���ť
    QImage introback;//�˵�����
};

#endif // INTRODUCE_H

#ifndef BUILDTOWERBUTTON_H
#define BUILDTOWERBUTTON_H

#include <QWidget>
#include <mybutton.h>
//继承mybutton，加了一个点一下扣多少钱的
class Buildtowerbutton : public Mybutton
{
    Q_OBJECT
public:
    Buildtowerbutton(QString pix,int n);
    int cost;


};

#endif // BUILDTOWERBUTTON_H

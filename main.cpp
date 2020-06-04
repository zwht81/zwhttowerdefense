#include "mainwindow.h"
#include <QApplication>
#include "menu.h"
//试一下git更新
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();

    return a.exec();
}

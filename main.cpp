#include "mainwindow.h"
#include <QApplication>
#include "menu.h"
//��һ��git����
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();

    return a.exec();
}

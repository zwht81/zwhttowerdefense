#include "inputname.h"
#include <QLineEdit>
#include <QApplication>

inputname::inputname(QWidget *parent) : QWidget(parent)
{

    QApplication app();
    QLineEdit edit;
    edit.setParent(this);
    edit.show();
    edit.setEchoMode(QLineEdit::Password);

        //获取输入框的文本

        QString a =  edit.text();

        //输入框的底层提示文本

        edit.setPlaceholderText("Please input text:");





}

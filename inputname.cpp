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

        //��ȡ�������ı�

        QString a =  edit.text();

        //�����ĵײ���ʾ�ı�

        edit.setPlaceholderText("Please input text:");





}

#ifndef FORM_H
#define FORM_H

#include <QWidget>


//ui�࣬�����������Ƶ�
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(int i, QWidget *parent = 0);
    ~Form();
    int levelnum;


private:
    Ui::Form *ui;
};

#endif // FORM_H

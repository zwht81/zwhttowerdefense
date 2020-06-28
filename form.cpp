#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"

Form::Form(int i,QWidget *parent) :
    QWidget(parent),
    levelnum(i),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Please input name:");

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        this->close();
        MainWindow * scene=new MainWindow(levelnum,ui->lineEdit->text());
        scene->show();

    });

}

Form::~Form()
{
    delete ui;
}

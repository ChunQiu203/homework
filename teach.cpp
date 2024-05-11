#include "teach.h"
#include "ui_teach.h"
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QPushButton>
#include"basescene.h"
teach::teach(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::teach)
{
    ui->setupUi(this);
    this->setFixedSize(500, 314);
    this->move(200, 150);

}
void teach::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


teach::~teach()
{
    delete ui;
}

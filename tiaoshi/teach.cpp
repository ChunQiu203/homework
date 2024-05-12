#include "teach.h"
#include "ui_teach.h"
#include<QPainter>
#include<QPixmap>
teach::teach(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::teach)
{
    ui->setupUi(this);
    this->setFixedSize(500, 314);
    this->move(200, 150);
    //设置应用图片
    setWindowIcon(QPixmap(":/music.ico"));
    setWindowTitle("教学");
    ui->label->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_2->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_3->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_4->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_5->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_6->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_7->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");
    ui->label_8->setStyleSheet("font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)");

    ui->guize->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:25px;color:rgb(120,146,98)}");
    ui->guize->resize(100,33);
    ui->zhuyi->resize(100,33);
    ui->zhuyi->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:25px;color:rgb(120,146,98)}");
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

#include "adjust.h"
#include "ui_adjust.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QSlider>
//静态变量
int adjust::xiaSpeed = 20;
int adjust::chuSpeed = 3000;
int adjust::TimeD=0;
adjust::adjust(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adjust)
{
    ui->setupUi(this);
    resize(500, 314);
    move(200, 150);
    //设置应用图片
    setWindowIcon(QPixmap(":/music.ico"));
    //设置标题
    setWindowTitle("调整");
    ui->xialuo->resize(100,30);
    ui->chuxian->resize(100,30);
    ui->xialuo->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    ui->TimeDelay->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    ui->chuxian->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");

    ui->xiaSlider->setValue(xiaSpeed);
    ui->chuSlider->setValue(chuSpeed);
    ui->TimeDelaySlider->setValue(TimeD);

    ui->TimeDelayNum->setValue(TimeD);
    ui->xiaNum->setValue(xiaSpeed);
    ui->chuNum->setValue(chuSpeed);
    connect(ui->xiaNum,&QSpinBox::valueChanged,[=](){
        xiaSpeed=ui->xiaNum->value();
        ui->xiaSlider->setValue(xiaSpeed);
    });
    connect(ui->xiaSlider,&QSlider::valueChanged,[=](){
        xiaSpeed=ui->xiaSlider->value();
        ui->xiaNum->setValue(xiaSpeed);
    });
    connect(ui->chuNum,&QSpinBox::valueChanged,[=](){
        chuSpeed=ui->chuNum->value();
        ui->chuSlider->setValue(chuSpeed);
        emit this->chuChanged();
    });
    connect(ui->chuSlider,&QSlider::valueChanged,[=](){
        chuSpeed=ui->chuSlider->value();
        ui->chuNum->setValue(chuSpeed);
        emit this->chuChanged();
    });
    connect(ui->TimeDelayNum,&QSpinBox::valueChanged,[=](){
        TimeD=ui->TimeDelayNum->value();
        ui->TimeDelaySlider->setValue(TimeD);
    });
    connect(ui->TimeDelaySlider,&QSlider::valueChanged,[=](){
        TimeD=ui->TimeDelaySlider->value();
        ui->TimeDelayNum->setValue(TimeD);
    });
}
void adjust::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
adjust::~adjust()
{
    delete ui;
}

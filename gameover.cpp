#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(int score,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gameover)
{
    ui->setupUi(this);
    this->setFixedSize(600,600);
    //设置图标
    this->setWindowIcon(QIcon(":/music.ico"));
    //设置标题
    this->setWindowTitle("音游？");
    ui->chongxin->resize(100,33);
    ui->FanHui->resize(100,33);
    ui->OVER->resize(300,100);

    ui->chongxin->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    ui->FanHui->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");

    ui->OVER->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:40px;color:rgb(120,146,98)}");

    ui->Score->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)}");
    ui->SCORE->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)}");
    ui->SCORE->setText(QString::number(score));
    connect(ui->chongxin,&QPushButton::clicked,[=](){
        emit this->Restart();
    });
    connect(ui->FanHui,&QPushButton::clicked,[=](){
        emit this->Back();
    });
}

gameover::~gameover()
{
    delete ui;
}
void gameover::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

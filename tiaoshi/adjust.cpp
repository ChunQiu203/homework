#include "adjust.h"
#include "ui_adjust.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QSlider>

adjust::adjust(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adjust)
{
    ui->setupUi(this);
    ui->setupUi(this);
    resize(500, 314);
    move(200, 150);
    //设置应用图片
    setWindowIcon(QPixmap(":/music.ico"));
    //设置标题
    setWindowTitle("调整");
    //timeDelay =ui->timeDelay->value();

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

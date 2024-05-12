#include "adjust1.h"
#include "ui_adjust1.h"
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QSlider>
adjust1::adjust1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adjust1)
{
    ui->setupUi(this);
    resize(500, 314);
    move(200, 150);

    timeDelay = ui->timeDelay->value();
    }
    void adjust1::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        QPixmap pix;
        pix.load(":/选曲背景.png");
        painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    }

adjust1::~adjust1()
{
    delete ui;
}

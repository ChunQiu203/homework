#include "gametwo.h"
#include "ui_gametwo.h"

#include <QKeyEvent>
#include <QString>
#include "downup.h"

#include <QLabel>
#include <QLine>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRandomGenerator>
#include <QSoundEffect>
#include <QSpinBox>
#include <QTimer>
#include "adjust.h"
#include "choosemusic.h"
#include "down.h"
#include "evaluate.h"
#include "game.h"
#include "musicchoose.h"
#include "teach.h"
#include "timer.h"
#include<QLine>
gametwo::gametwo(QString musicname,QWidget*parent)
    :basescene{parent}
    , ui(new Ui::gametwo)
{
    ui->setupUi(this);
    num = -1;
    s = 0;

    this->musicname=musicname;
    music = new QSoundEffect(this);
    music->setSource(QUrl::fromLocalFile(musicname));
    music->setVolume(0.5f);
    dian = new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/音符.wav"));
    ba = new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/音符miss.wav"));

    restart = new QPushButton(this);
    restart->setText("重新开始");
    restart->resize(80, 20);
    restart->move(40, 550);
    restart->setStyleSheet(
        "QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(80,97,109)}");
    fanhui = new QPushButton(this);
    fanhui->setText("返回大厅");
    fanhui->resize(80, 20);
    fanhui->move(840, 550);
    fanhui->setStyleSheet(
        "QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(80,97,109)}");
    zanting = new QPushButton(this);
    zanting->setText("暂停");
    zanting->resize(80, 20);
    zanting->move(440, 550);
    zanting->setStyleSheet(
        "QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(80,97,109)}");

    //音符出现时钟
    showtime = new QTimer(this);
    connect(ad, &adjust::chuChanged, [=]() {
        showtime->stop();
        showtime->start(ad->chuSpeed);
    });
    connect(this, &gametwo::showScene, [=]() {
        showtime->start(ad->chuSpeed); //设定音符出现时间间隔
        music->play();
    });
    connect(showtime, &QTimer::timeout, [=]() { emit this->showyinfu(); });
    connect(this, &gametwo::gameOver, showtime, &QTimer::stop);

    connect(this, &gametwo::pause, [=]() {
        if (num % 2 == 0) {
            music->stop();
            showtime->stop();
            zanting->setText("开始");
        } else {
            music->play();
            showtime->start(ad->chuSpeed);
            zanting->setText("暂停");
        }
    });

    //判定线设定
    QPushButton *panding = new QPushButton(this);
    panding->move(40, 500);
    panding->resize(920, 5);
    panding->setStyleSheet("QPushButton{border: 0px}");

    QPixmap pix;
    bool ret = pix.load(":/判定线2.png");
    if (!ret) {
        qDebug() << "图片加载失败";
        return;
    }
    //设置图片大小
    panding->setFixedSize(920, 10);
    //设置不规则图片格式
    panding->setStyleSheet("QPushButton{border: none;}");
    //设置图标
    panding->setIcon(pix);
    //设置图标大小
    panding->setIconSize(QSize(pix.width(), pix.height()));

    //分数设定
    score = new QPushButton(this);
    score->setText(QString::number(s));
    score->setStyleSheet("QPushButton{border: none;font-family:'Script MT "
                         "Bold';font-size:40px;color:rgb(22,24,35)}");
    score->resize(100, 33);
    score->move(430, 40);

    connect(this, &gametwo::showyinfu, [=]() { this->generateDownObjecttwo(); });
    jieshu = new QPushButton(this);
    jieshu->setText("结束游戏");
    jieshu->resize(80, 20);
    jieshu->move(800, 40);
    jieshu->setStyleSheet(
        "QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(80,97,109)}");
    connect(jieshu, &QPushButton::clicked, [=]() { emit gameOver(); });
}


void gametwo::generateDownObjecttwo()
{
    QSoundEffect *dian = new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/音符.wav"));
    dian->setVolume(1.0f);
    QSoundEffect *ba = new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/音符miss.wav"));
    ba->setVolume(1.0f);

    downUp *yinfu = new downUp(this, ad->xiaSpeed, ad->chuSpeed, ad->TimeD);
    yinfu->setParent(this);
    yinfu->setVisible(true);
    evaluate *pingjia = new evaluate();
    pingjia->setParent(this);
    pingjia->move(10, 50);
    connect(this, &gametwo::gameOver, [=]() {
        yinfu->self = yinfu->p->remainingTime();
        emit yinfu->p->Stop();
        emit yinfu->timer->Stop();
        music->stop();
        showtime->stop();
    });
    connect(ad, &adjust::xiaChanged, [=]() {
        yinfu->downSpeed = ad->xiaSpeed;
        emit yinfu->timer->Start(yinfu->downSpeed);
    });

    connect(yinfu, &downUp::best, [=]() {
        s += 3;
        score->setText(QString::number(s));
        if (s < -22) {
            emit this->gameOver();
        }
    });
    connect(yinfu, &downUp::good, [=]() {
        s += 2;
        score->setText(QString::number(s));
        if (s < -22) {
            emit this->gameOver();
        }
    });
    connect(yinfu, &downUp::bad, [=]() {
        s++;
        score->setText(QString::number(s));
        if (s < -22) {
            emit this->gameOver();
        }
    });
    connect(yinfu, &downUp::miss, [=]() {
        s--;
        score->setText(QString::number(s));
        if (s < -22) {
            emit this->gameOver();
        }
    });
    connect(yinfu, &downUp::clicked, [=]() {
        yinfu->self = yinfu->p->remainingTime(); //获取剩余时间
        if (yinfu->self - ad->xiaSpeed * 50 <= 15 * ad->xiaSpeed
            && yinfu->self - ad->xiaSpeed * 50 >= -15 * ad->xiaSpeed && yinfu->flag == 0 /*BEST*/) {
            emit pingjia->e1();
            emit yinfu->best();
            dian->play();
            yinfu->flag = 1;
        } else if (yinfu->self - ad->xiaSpeed * 50 <= 30 * ad->xiaSpeed
                   && yinfu->self - ad->xiaSpeed * 50 >= -30 * ad->xiaSpeed
                   && yinfu->flag == 0 /*GOOD*/) {
            emit pingjia->e2();
            emit yinfu->good();
            dian->play();
            yinfu->flag = 1;
        } else if (yinfu->self - ad->xiaSpeed * 50 <= ad->xiaSpeed * 60
                   && yinfu->self - ad->xiaSpeed * 50 >= -60 * ad->xiaSpeed
                   && yinfu->flag == 0 /*BAD*/) {
            emit pingjia->e3();
            emit yinfu->bad();
            dian->play();
            yinfu->flag = 1;
        } else if (yinfu->flag == 0) {
            emit pingjia->e4();
            emit yinfu->miss();
            ba->play();
            yinfu->flag = 1;
        }
    });
}
void gametwo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/夢幻.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}


gametwo::~gametwo()
{
    delete ui;
}

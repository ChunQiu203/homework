#include "down.h"
#include<QTimer>

#include<QOverload>
#include<QPixmap>
#include<QDebug>
#include<QSoundEffect>
#include<QAnimationDriver>
#include<QMovie>
#include<QLabel>
#include<QKeyEvent>
#include <random>
#include<QRandomGenerator>
#include<QGraphicsItem>
#include"evaluate.h"
using namespace std;
down::down(QObject*parent) {
    //设定音符点击音效
    QSoundEffect* dian=new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    QSoundEffect* ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
    resize(80,20);
    //设定音符样式
    QPixmap pix;
    bool ret=pix.load(":/button1.png");
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片大小
    setFixedSize(80,20);
    //设置不规则图片格式
    setStyleSheet("QPushButton{border: none;}");
    //设置图标
    setIcon(pix);
    //设置图标大小
    setIconSize(QSize(pix.width(),pix.height()));


    x = QRandomGenerator::global()->bounded(40,800);
    y = 50;
    this->move(x,y);
    //设置初始位置
    //音符位置要随时间的变化而变化

    //位置计时器
    timer = new QTimer(this);
    timer->start(10);
    //改变音符位置
    connect(timer,&QTimer::timeout,[=](){
        this->move(x,++y);
    });

    //出现计时器
    p=new QTimer(this);
    p->setSingleShot(true);  //表示只计时一次
    p->start(15000);
    //判断时间
    connect(p,&QTimer::timeout,[=](){
        emit down::miss();
    });
    connect(this,&down::disappear,[=](){
        self=15000-p->remainingTime();//获取剩余时间
    });

    //音符消失
    //对比剩余时间，一共计时15秒
    //进行评价，在game界面中实现

    //点击动画的实现
    connect(this,&down::best,this,[=](){
        this->changeSuccess();
    });
    connect(this,&down::good,this,[=](){
        this->changeSuccess();
    });
    connect(this,&down::bad,this,[=](){
        this->changeSuccess();
    });
    connect(this,&down::miss,this,[=](){
        this->changelose();
    });

    qDebug()<<("生成音符");
    qDebug()<<x<<y;

}
void down::changeSuccess()
{
    QPixmap des;
    QString dis=QString(":/button2.png");
    des.load(dis);
    this->setFixedSize(80,20);
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(des);
    this->setIconSize(QSize(80,20));
    QTimer::singleShot(1000,this,[=](){
        this->deleteLater();
    });
}
void down::changelose()
{
    QPixmap des;
    QString dis=QString(":/button3.png");
    des.load(dis);
    this->setFixedSize(80,20);
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(des);
    this->setIconSize(QSize(80,20));
    QTimer::singleShot(1000,this,[=](){
        this->deleteLater();
    });
}



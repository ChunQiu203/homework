#include "downup.h"
#include<QRandomGenerator>
#include<QKeyEvent>
downUp::downUp(QObject*parent,int xia,int Show,int Time)
{
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

    downSpeed=xia;
    changeLocation();

    //出现计时器
    p=new Timer(this);
    F=new Timer(this);
    p->setParent(this);
    p->setSingleShot(true);  //表示只计时一次
    emit p->Start(500*xia+Time);

    emit F->Start(500*xia+Time-Show);
    //判断时间
    connect(p,&Timer::timerTimeout,[=](){
        emit downUp::miss();
    });
    connect(F,&Timer::timerTimeout,[=](){
        setFocus();
    });


    //音符消失
    //进行评价，在game界面中实现
    //点击动画的实现
    connect(this,&downUp::best,this,[=](){
        this->changeSuccess();

    });
    connect(this,&downUp::good,this,[=](){
        this->changeSuccess();
    });
    connect(this,&downUp::bad,this,[=](){
        this->changeSuccess();
    });
    connect(this,&downUp::miss,this,[=](){
        this->changelose();
    });
}
void downUp::changeLocation()
{
    x =QRandomGenerator::global()->bounded(1,9);
    y = 50;
    this->move(6+82*(x-1)+40*x,y);
    //设置初始位置
    //音符位置要随时间的变化而变化
    //位置计时器
    timer = new Timer(this);
    timer->setParent(this);
    emit timer->Start(downSpeed);

    //改变音符位置
    connect(timer,&Timer::timerTimeout,[=](){
        this->move(6+82*(x-1)+40*x,++y);
    });
}
void downUp::changeSuccess()
{
    QPixmap des;
    QString dis=QString(":/button2.png");
    des.load(dis);
    this->setFixedSize(80,20);
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(des);
    this->setIconSize(QSize(80,20));
    emit this->timer->Stop();
    emit this->p->Stop();
    QTimer::singleShot(500,this,[=](){
        this->hide();
    });
}
void downUp::changelose()
{
    QPixmap des;
    QString dis=QString(":/button3.png");
    des.load(dis);
    this->setFixedSize(80,20);
    this->setStyleSheet("QPushButton{border: none;}");
    this->setIcon(des);
    this->setIconSize(QSize(80,20));
    emit this->timer->Stop();
    emit this->p->Stop();
    QTimer::singleShot(500,this,[=](){
        this->hide();
    });
}

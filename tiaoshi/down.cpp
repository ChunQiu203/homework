#include "down.h"
#include<QTimer>
#include<QOverload>
#include<QPixmap>
#include<QDebug>
#include<QSoundEffect>
#include<QAnimationDriver>
#include<QMovie>
#include<QLabel>
down::down(int a,int b) {
    //设定音符点击音效
    QSoundEffect* dian=new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    QSoundEffect* ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
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


    //设置初始位置
    x=a;
    y=b;
    //音符位置要随时间的变化而变化
    connect(this,&down::show,this,[=](){
        this->move(x,y);//起始位置

    });
    //每个音符都有自己的计时器
    timer = new QTimer(this);
    timer->setSingleShot(true);  //表示只计时一次
    connect(timer, &QTimer::timeout, [=](){
        y++;
        this->move(x,y);
    });
    connect(this,&down::show,timer,[=]()
        {
        timer->start(10);
    });
    connect(this,&down::disappear,timer,&QTimer::stop);
    connect(this,&down::disappear,[=]()
            {
        self=timer->interval();//获取计时时间
    });


    //改变音符位置





    //音符消失
    //对比允许时间
    //进行评价
    flag=0;
    connect(this,&down::clicked,[=](){
        flag=1;
        int dianji =self-10/*PERFECT*/;
        if(dianji<0)
            {
            dianji=-dianji;
        }
        else
            {
            dianji=dianji;
        }
        if(dianji<=100/*BEST*/)
            {
            emit down::best();
            dian->play();
        }
        else if(dianji>100/*BEST*/&&dianji<=200/*GOOD*/)
            {
            emit down::good();
            dian->play();
        }
        else if(dianji>200/*GOOD*/&&dianji<=500/*BAD*/)
            {
            emit down::bad();
            dian->play();
        }
        else
            {
            emit down::miss();
            ba->play();
        }
    });

    if(flag==0)
    {
        emit down::miss();
    }
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
}
void down::changeSuccess()
{
    //t=new QTimer(this);
    // this->t->start(20);
    // connect(this->t,&QTimer::timeout,[=](){
    //     QPixmap des;
    //     QString dis=QString(":/未命名的设计.png").arg(this->min++);
    //     des.load(dis);
    //     this->setFixedSize(80,20);
    //     this->setStyleSheet("QPushButton(border:0px)");
    //     this->setIcon(des);
    //     this->setIconSize(QSize(80,20));
    //     if(this->min>this->max)//如果大于最大值，重置最小值，并停止定时器
    //     {
    //         this->min=1;
    //         this->t->stop();
    //     }


   // });
    mo=new QMovie(":/音符消失1.gif");
    mo->setSpeed(200);
    mo->setParent(this);
    QLabel *label=new QLabel();
    label->setMovie(mo);
    mo->start();
    label->show();

    //控制动画循环次数
    connect(mo,&QMovie::frameChanged,[=](int frameNumber){
        //动画执行一次就结束
        if(frameNumber==mo->frameCount()-1)
            {
            mo->stop();
        }
    });

}
void down::changelose()
{
    //t=new QTimer(this);
    // this->t->start(20);
    // connect(this->t,&QTimer::timeout,[=](){
    //     QPixmap des;
    //     QString dis=QString(":/未命名的设计.png").arg(this->min++);
    //     des.load(dis);
    //     this->setFixedSize(80,20);
    //     this->setStyleSheet("QPushButton(border:0px)");
    //     this->setIcon(des);
    //     this->setIconSize(QSize(80,20));
    //     if(this->min>this->max)//如果大于最大值，重置最小值，并停止定时器
    //     {
    //         this->min=1;
    //         this->t->stop();
    //     }


    // });
    lo=new QMovie(":/音符消失1.gif");
    lo->setSpeed(200);
    lo->setParent(this);
    QLabel *label=new QLabel();
    label->setMovie(lo);
    lo->start();
    label->show();

    //控制动画循环次数
    connect(lo,&QMovie::frameChanged,[=](int frameNumber){
        //动画执行一次就结束
        if(frameNumber==mo->frameCount()-1)
        {
            lo->stop();
        }
    });

}

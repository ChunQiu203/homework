#include "click.h"
#include"adjust1.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QTimer>
/*click::click(QPushButton *parent)
    : QPushButton{parent}
{}*/
click::click(QString normalimage=":/button1.png",QString pressimage=":/button1.png",int size=0)
{

    this->normalimagepath=normalimage;
    this->pressimagepath=pressimage;

    QPixmap pix;
    bool ret=pix.load(normalimagepath);
    if(ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片大小
    if(size=0)
    {
        this->resize(pix.width(),pix.height());
    }
    else
    {
        this->resize(size,size/3);
    }
    //设置不规则图片格式
    this->setStyleSheet("QPushButton(border:0px;");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void click::c()
{
    //创建动画对象
    QPropertyAnimation *animational=new QPropertyAnimation(this,"geometry");
    //设置时间间隔
    animational->setDuration(100);
    //创建起始位置
    animational->setStartValue(QVariant(QPoint(this->x(),this->y())));
    //创建结束位置
    animational->setEndValue(QVariant(QPoint(this->x(),this->y()+10)));
    //设置缓和曲线，
    animational->setEasingCurve(QEasingCurve::OutBack);
    //开始执行动画
    animational->start();
}
void click::check()
{
    self=new QTimer(this);
    //connect(self, &QTimer::timeout, this, &click::update);
    self->start(1);
    bool flag=0;
    /*connect(this,&click::clicked,[=](){
        flag=true;
    });
    if(self > 5000)
    {
        emit miss();
        return;
    }
    else if(flag==true)
    {
        if(self-4800<=300&&4800-self<=300)
        {
            emit perfect();
        }
        else if(self-4800<=500&&4800-self<=500)
        {
            emit great();
        }
        return;
    }*/
}


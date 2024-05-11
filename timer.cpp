#include "timer.h"
#include<QObject>
Timer::Timer(QObject*parent)
    : QTimer{parent}
{
    //使用指针变量
    //m_thread=thisthread;
    //this->moveToThread(m_thread);
    //定时任务放在线程中执行，必须指定参数
    //connect(m_thread,&QThread::finished,this,&Timer::stop);
    connect(this,&Timer::Start,this,&Timer::startN);
    connect(this,&Timer::Stop,this,&Timer::stopN);

}
void Timer::startN(int msec)
{
    this->start(msec);
    connect(this, &Timer::timeout,[=](){
        emit this->timerTimeout();
    });
}
void Timer::stopN()
{
    this->stop();
}

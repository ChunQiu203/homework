#ifndef DOWN_H
#define DOWN_H

#include <QObject>
#include<QPushButton>
#include"timer.h"
class down : public QPushButton
{
    Q_OBJECT
public:
    down(QObject*parent,int xia,int Time);
    friend class game;
private:
    //音符位置坐标
    int x;
    int y;
    int self=0;//音符剩余时间
     //改变标志的方法
    void changeSuccess();
    void changelose();
    Timer *timer;//改变音符位置的定时器
    Timer *p;//音符出现的计时器
    bool flag=0;//判断是否点击
signals:
    void show();
    void disappear();
    void miss();
    void best();
    void good();
    void bad();
};

#endif // DOWN_H

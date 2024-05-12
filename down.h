#ifndef DOWN_H
#define DOWN_H

#include <QObject>
#include <QPushButton>
#include<QTime>
#include<QMovie>
#include<QKeyEvent>
#include<QGraphicsItem>
#include"timer.h"
class down : public QPushButton
{
    Q_OBJECT
public:
    down(QObject*parent,int xia);
    int self=0;
    //改变标志的方法
    void changeSuccess();
    void changelose();
    QChar letter;
    int x;
    int y;
    Timer *timer;//改变音符位置的定时器
    Timer *p;
    int min=1;//最小图片
    int max=8;//最大图片
    int flag=0;//判断是否点击
    friend class game;

signals:
    void show();
    void disappear();
    void miss();
    void best();
    void good();
    void bad();
};

#endif // DOWN_H

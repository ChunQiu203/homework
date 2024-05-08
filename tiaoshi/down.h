#ifndef DOWN_H
#define DOWN_H

#include <QObject>
#include <QPushButton>
#include<QTime>
#include<QMovie>
class down : public QPushButton
{
    Q_OBJECT
public:
    down(int a,int b);
    int self=0;
    //改变标志的方法
    void changeSuccess();
    void changelose();
    int x;
    int y;
    QTimer *timer;
    QTimer *t;//点击成功消失的定时器
    int min=1;//最小图片
    int max=8;//最大图片
    QMovie *mo;
    QMovie *lo;
    int flag;//判断是否点击


signals:
    void show();
    void disappear();
    void miss();
    void best();
    void good();
    void bad();
};

#endif // DOWN_H

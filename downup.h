#ifndef DOWNUP_H
#define DOWNUP_H

#include "down.h"
#include<QKeyEvent>
#include<QTimer>
#include<QPixmap>
#include<QSoundEffect>
#include<QLabel>
#include<QRandomGenerator>
#include"evaluate.h"
class downUp : public QPushButton
{
     Q_OBJECT
public:
    downUp(QObject*parent,int xia,int Show,int Time);
    void changeLocation();
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->key() == Qt::Key_A&&x==1)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_S&&x==2)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_D&&x==3)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_F&&x==4)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_J&&x==5)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_K&&x==6)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_L&&x==7)
        {
            emit clicked(true);
        }
        else if(event->key()==Qt::Key_Semicolon&&x==8)
        {
            emit clicked(true);
        }
    }
    friend class game;
    friend class gametwo;
private:
    //音符位置坐标
    int x;
    int y;
    int self=0;//音符剩余时间
    int downSpeed;
        //改变标志的方法
    void changeSuccess();
    void changelose();
    Timer *timer;//改变音符位置的定时器
    Timer *p;//音符出现的计时器
    Timer *F;//焦点计时器
    bool flag=0;//判断是否点击
signals:
    void show();
    void disappear();
    void miss();
    void best();
    void good();
    void bad();
};

#endif // DOWNUP_H

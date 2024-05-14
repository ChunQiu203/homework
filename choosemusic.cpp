#include "choosemusic.h"
#include<QPainter>
#include<QIcon>
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include"musicchoose.h"
#include<QTimer>
#include<QLabel>
#include"game.h"
#include<QSoundEffect>
#include<QMainWindow>
#include"mainwindow.h"
choosemusic::choosemusic(QWidget *parent)
{
    //返回按钮
    fanhui=new QPushButton("返回大厅",this);
    fanhui->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)}");
    fanhui->resize(80,20);
    fanhui->move(this->width()-90,this->height()-40);

    //选曲按钮
    btn1=new musicchoose(":/Dragonflame.jpg",":/Kirara Magic - Dragonflame.wav");
    btn1->setParent(this);
    btn1->move(60,160);

    btn2=new QPushButton(this);
    btn2->move(90,400);
    btn2->setText("Dragon Flame");
    btn2->resize(150,30);
    btn2->setStyleSheet("QPushButton{border: none;font-family:'华文楷体';font-size:24px;color:rgb(66,102,102)；font-}");


    btnmusic=new musicchoose(":/snooze.jpg",":/snooze.wav");
    btnmusic->setParent(this);
    btnmusic->move(360,160);

    btn3=new QPushButton(this);
    btn3->move(400,400);
    btn3->setText("snooze");
    btn3->resize(150,30);
    btn3->setStyleSheet("QPushButton{border: none;font-family:'华文楷体';font-size:24px;color:rgb(66,102,102)；font-}");

    L=new musicchoose(":/Luminescence.png",":/Luminescence.wav");
    L->setParent(this);
    L->move(660,160);

    l1=new QPushButton(this);
    l1->move(690,400);
    l1->setText("Luminescence");
    l1->resize(150,30);
    l1->setStyleSheet("QPushButton{border: none;font-family:'华文楷体';font-size:24px;color:rgb(66,102,102)；font-}");

}

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
    :basescene{parent}

{

    //返回按钮
    fanhui=new QPushButton("返回大厅",this);
    fanhui->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)}");
    fanhui->resize(80,20);
    fanhui->move(this->width()-90,this->height()-40);

    //选曲按钮
    btn1=new musicchoose(":/Dragonflame.jpg",":/Dragonflame.jpg","Dragonflame");
    btn2=new QPushButton(this);
    btn1->setParent(this);
    btn1->move(50,60);
    btn2->move(160,470);
    btn2->setText(btn1->music);
    btn2->resize(200,40);
    btn2->setStyleSheet("QPushButton{border: none;font-family:'华文楷体';font-size:30px;color:rgb(66,102,102)；font-}");



}

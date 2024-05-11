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
#include"mainwindow.h"
choosemusic::choosemusic(QWidget *parent)
    : basescene{parent}
{
    QSoundEffect*choose=new QSoundEffect(this);
    choose->setSource(QUrl::fromLocalFile(":/music/按键音2.wav"));
    choose->setVolume(1.0);
    //返回按钮
    fanhui=new QPushButton("返回大厅",this);
    fanhui->setStyleSheet("QPushButton{border: none;font-family:'华文行楷';font-size:16px;color:rgb(120,146,98)}");
    fanhui->resize(80,20);
    fanhui->move(this->width()-90,this->height()-40);

    //选曲按钮
    musicchoose *btn1=new musicchoose(":/Dragonflame.jpg",":/Dragonflame.jpg","Dragonflame");
    QPushButton*btn2=new QPushButton(this);
    btn1->setParent(this);
    btn1->move(50,60);
    btn2->move(160,470);
    btn2->setText(btn1->music);
    btn2->resize(200,40);
    btn2->setStyleSheet("QPushButton{border: none;font-family:'华文楷体';font-size:30px;color:rgb(66,102,102)；font-}");
    game *play=new game(btn1->music);
    connect(btn2,&musicchoose::clicked,[=](){
        choose->play();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            play->show();
        });
    });
    QSoundEffect*mu=new QSoundEffect(btn1);
    mu->setSource(QUrl::fromLocalFile(":/music/Kirara Magic - Dragonflame.wav"));
    mu->setVolume(1.0);
    connect(btn1,&musicchoose::clicked,[=](){
        mu->play();
    });

}


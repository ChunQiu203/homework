#include "game.h"
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
#include"teach.h"
#include <QSoundEffect>//多媒体模块
/*game::game(QWidget *parent)
    : QMainWindow{parent}
{

}*/
void game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

game::game(QString musicname=":/music/Maozon - Stasis.mp3")
{

    //配置选择场景
    this->setFixedSize(1000,618);
    //设置图标
    this->setWindowIcon(QIcon(":/music.ico"));
    //设置标题
    this->setWindowTitle(musicname);
    QMenuBar *menu=menuBar();//菜单栏创建
    setMenuBar(menu);//将菜单栏放入窗口中
    //创建菜单
    QMenu* jiaoxue=menu->addMenu("教学");
    QMenu* tiaozheng=menu->addMenu("调整");
    //创建菜单项
    QAction* study=jiaoxue->addAction("学习");
    QAction* open=tiaozheng->addAction("打开");
    teach* te=new teach();
    adjust1* ad=new adjust1();
    connect(study,&QAction::triggered,te,&teach::show);
    connect(open,&QAction::triggered,ad,&adjust1::show);

    restart= new QPushButton(this);
    restart->setText("重新开始");
    restart->resize(80,20);
    restart->move(40,550);
    restart->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(84,150,136)}");
    fanhui= new QPushButton(this);
    fanhui->setText("返回大厅");
    fanhui->resize(80,20);
    fanhui->move(840,550);
    fanhui->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(84,150,136)}");
    zanting= new QPushButton(this);
    zanting->setText("暂停");
    zanting->resize(80,20);
    zanting->move(440,550);
    zanting->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(84,150,136)}");


    QSoundEffect*b=new QSoundEffect(music);
    b->setSource(QUrl::fromLocalFile(":/music/按键音2.wav"));
    b->setVolume(1.0);
    connect(restart,&QPushButton::clicked,[=](){
        b->play();
        QTimer::singleShot(600,music,[=](){
            this->update();
        });
    });
    connect(fanhui,&QPushButton::clicked,[=](){
        b->play();
        QTimer::singleShot(600,this,[=](){
            this->hide();
        });
    });
    connect(zanting,&QPushButton::clicked,[=](){
        b->play();
        QTimer::singleShot(600,music,[=](){
            emit game::pause();
        });
    });
    //基本配置
    filename=":/music/"+musicname+".mp3";

}

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
#include<QLine>
#include<QLabel>
#include"game.h"
#include"teach.h"
#include <QSoundEffect>
#include"adjust.h"
game::game(QWidget *parent)
    : QMainWindow{parent}
{}
void game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

game::game(QString musicname)
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
    adjust* ad=new adjust();
    connect(study,&QAction::triggered,te,&teach::show);
    connect(open,&QAction::triggered,ad,&adjust::show);


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

    QSoundEffect*music=new QSoundEffect(this);
    music->setSource(QUrl::fromLocalFile(":/Kirara Magic - Dragonflame.wav"));
    connect(this,&game::showScene,music,&QSoundEffect::play);
    connect(this,&game::pause,music,[=](){
        if(num%2==0)
            {
            music->stop();
        }
        else
            {
            music->play();
        }
    });
    connect(this,&game::back,music,&QSoundEffect::stop);
    connect(this,&game::renew,music,&QSoundEffect::play);
    connect(this,&game::pause,[=](){
        num++;
    });
    //判定线设定
    QPushButton* panding=new QPushButton(this);
    panding->move(40,500);
    panding->resize(920,10);
    panding->setStyleSheet("QPushButton{border: 0px}");

    QPixmap pix;
    bool ret=pix.load(":/判定线.png");
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片大小
    panding->setFixedSize(920,10);
    //设置不规则图片格式
    panding->setStyleSheet("QPushButton{border: none;}");
    //设置图标
    panding->setIcon(pix);
    //设置图标大小
    panding->setIconSize(QSize(pix.width(),pix.height()));


    //基本配置
    //filename=":/music/"+musicname+".mp3";

}


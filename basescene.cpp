#include "basescene.h"
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include"teach.h"
#include"adjust.h"
basescene::basescene(QWidget *parent)
    : QMainWindow{parent}
{
    //配置选择场景
    this->setParent(parent);
    this->setFixedSize(1000,618);
    //设置图标
    this->setWindowIcon(QIcon(":/music.ico"));
    //设置标题
    this->setWindowTitle("音游？");
    menu=menuBar();//菜单栏创建
    setMenuBar(menu);//将菜单栏放入窗口中
    //创建菜单
    jiaoxue=menu->addMenu("教学");

    tiaozheng=menu->addMenu("调整");
    //创建菜单项
    study=jiaoxue->addAction("学习");
    open=tiaozheng->addAction("打开");

    te=new teach();
    ad=new adjust();
    connect(study,&QAction::triggered,te,&teach::show);
    connect(open,&QAction::triggered,ad,&adjust::show);

}
void basescene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
basescene::~basescene()
{
    delete te;
    delete ad;
}

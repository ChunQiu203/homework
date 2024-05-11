#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"sonwindow.h"
#include<QPushButton>
#include<QObject>
#include<QMenuBar>
#include<QToolBar>
#include<QIcon>
#include<QMessageBox>
#include<QPainter>
#include"click.h"
#include"choosemusic.h"
#include<QTimer>
#include"teach.h"
#include"adjust1.h"
#include<QSoundEffect>
#include<QLabel>
#include"game.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小
    setFixedSize(1000,618);
    //设置标题
    setWindowTitle("音游？");
    //设置应用图片
    this->setWindowIcon(QPixmap(":/music.ico"));
    //按键音效
    QSoundEffect *push=new QSoundEffect(this);
    push->setSource(QUrl::fromLocalFile(":/music/按键音.wav"));
    //push->setLoopCount(QSoundEffect::Infinite);
    push->setVolume(0.9f);
    QPushButton * btn =new QPushButton("开始",this);
    btn->setParent(this);
    QPushButton * btn2=new QPushButton("退出",this);
    QPushButton *btn3=new QPushButton("选曲",this);
    btn3->move(430,440);
    btn3->resize(80,20);
    btn->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(120,146,98)}");
    btn2->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(120,146,98)}");
    btn3->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(120,146,98)}");
    btn->move(430,400);
    btn->resize(80,20);
    btn2->move(430,480);
    btn2->resize(80,20);
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


    //选择界面
    this->choose=new sonwindow (this);
    choose->setStyleSheet("color:rgb(187,205,197)");
    choose->setAttribute(Qt::WA_DeleteOnClose);
    choose->setFixedSize(200,100);
    choose->move(700,400);
    QLabel* a=new QLabel(choose);
    a->move(5,10);
    a->setText("你真的确定要退出嘛？");
    a->setStyleSheet("font-family:'楷体';font-size:20px;color:rgb(120,146,98)");
    choose->setWindowTitle("一个重要的选择");

    QPushButton* queren =new QPushButton(choose);
    QPushButton* quxiao=new QPushButton(choose);
    queren->setText("再见");
    queren->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    quxiao->setText("我回来啦");
    quxiao->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    queren->resize(60,20);
    quxiao->resize(60,20);
    queren->move(10,50);
    quxiao->move(120,50);
    //选择界面，按钮信号的处理
    connect(queren,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(600,this,[=](){
            this->close();
        });
    });
    connect(quxiao,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,this,[=](){
            choose->hide();
        });
    });
    //选曲界面
    c=new choosemusic();
    //开始界面，按钮信号的处理3
    connect(c->fanhui,&QPushButton::clicked,[=](){
        QTimer::singleShot(400,this,[=](){
            c->hide();
        });
        QTimer::singleShot(300,this,[=](){
            this->show();
        });//重新显示
    });
    //游戏界面
    game* music=new game(":/music/Kirara Magic - Dragonflame.wav");
    connect(btn,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,music,[=](){
            music->show();
        });
            this->hide();
    });
    QSoundEffect*b=new QSoundEffect(music);
    b->setSource(QUrl::fromLocalFile(":/music/按键音2.wav"));
    b->setVolume(1.0);
    connect(music->fanhui,&QPushButton::clicked,[=](){
        b->play();
        QTimer::singleShot(600,this,[=](){
            music->hide();
            this->show();
        });
    });

    connect(btn2,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,choose,[=](){
            choose->show();
        });
    });
    connect(btn3,&QPushButton::clicked,[=](){
        //延时0.5秒后，进入选择场景
        push->play();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            c->show();
        });
    });
}

//设置背景图
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter back(this);
    QPixmap pix;
    pix.load(":/音游？？.png");
    back.drawPixmap(0,0,this->width(),this->height(),pix);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete c;
    delete choose;
}


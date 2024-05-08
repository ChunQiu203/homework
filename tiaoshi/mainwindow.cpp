#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPushButton>
#include<QSoundEffect>
#include<QPainter>
#include<QPixmap>
#include<QMovie>
#include<QTimer>
#include<QLabel>
#include"teach.h"
#include"adjust.h"
#include"sonwindow.h"
#include"game.h"
#include"choosemusic.h"
#include"musicchoose.h"
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
    setWindowIcon(QPixmap(":/music.ico"));


    //按键音效
    QSoundEffect* background=new QSoundEffect(this);
    background->setSource(QUrl::fromLocalFile(":/久石譲Wiener SymphonikerAntoine Tamestit - Viola Saga：Movement 2 (Pt. 1)-new.wav"));
    background->setLoopCount(QSoundEffect::Infinite);
    background->setVolume(0.5f);
    background->play();
    QSoundEffect *push=new QSoundEffect(this);
    push->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    //push->setLoopCount(QSoundEffect::Infinite);
    push->setVolume(0.9f);
    QSoundEffect*music1=new QSoundEffect(this);
    music1->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
    music1->setVolume(1.0f);
    QSoundEffect*Dragon=new QSoundEffect(this);
    Dragon->setSource(QUrl::fromLocalFile(":/Kirara Magic - Dragonflame.wav"));
    Dragon->setVolume(1.0f);
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

    //设置背景动画
    // QMovie *back=new QMovie(":/背景2.gif");
    // QLabel*b1=new QLabel(this);
    // b1->resize(1000,618);
    // b1->move(0,0);
    // back->setSpeed(50);
    // b1->setMovie(back);
    // back->start();
    // b1->show();

    //以上没有问题
    teach* te=new teach();
    adjust* ad=new adjust();
    connect(study,&QAction::triggered,te,&teach::show);
    connect(open,&QAction::triggered,ad,&adjust::show);


    //选择界面
    sonwindow *choose=new sonwindow (this);
    choose->setStyleSheet("color:rgb(187,205,197)");
    choose->setAttribute(Qt::WA_DeleteOnClose);
    choose->setFixedSize(200,100);
    choose->move(700,400);
    QLabel* a=new QLabel(choose);
    a->move(5,10);
    a->setText("你真的确定要退出嘛？");
    a->setStyleSheet("font-family:'楷体';font-size:14px;color:rgb(120,146,98)");
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

//以上没有问题
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
//以上没有问题
    //游戏界面
    game* music=new game(":/music/Kirara Magic - Dragonflame.wav");
    connect(music->restart,&QPushButton::clicked,[=](){
        music1->play();
        emit music->renew();
        QTimer::singleShot(600,music,[=](){
            music->update();
        });
    });
    connect(music->fanhui,&QPushButton::clicked,[=](){
        music1->play();
        emit music->back();
        QTimer::singleShot(1000,background,[=](){
            background->play();
        });
        QTimer::singleShot(600,this,[=](){
            music->hide();
            this->show();
        });
    });
    connect(music->zanting,&QPushButton::clicked,[=](){
        music1->play();
        QTimer::singleShot(600,music,[=](){
            emit music->pause();
        });
    });


    //选曲界面
    choosemusic *c=new choosemusic(this);
    //选曲界面按钮信号的处理

    connect(c->btn1,&musicchoose::clicked,[=](){
        music1->play();
        Dragon->play();
        background->stop();
    });
    connect(c,&choosemusic::closed,Dragon,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,background,&QSoundEffect::play);
    connect(c->btn2,&musicchoose::clicked,[=](){
        music1->play();
        Dragon->stop();
        background->stop();
        QTimer::singleShot(500,c,[=](){
            c->hide();
        });
        music->show();
        emit music->showScene();
    });


    //开始界面，按钮信号的处理3
    connect(c->fanhui,&QPushButton::clicked,[=](){
        music1->play();
        emit c->closed();
        QTimer::singleShot(300,this,[=](){
            this->show();
        });//重新显示
        QTimer::singleShot(400,this,[=](){
            c->hide();
        });
    });
    connect(c,&choosemusic::closed,Dragon,&QSoundEffect::stop);
    //以上没有问题


    connect(btn,&QPushButton::clicked,[=](){
        push->play();
        background->stop();
        QTimer::singleShot(400,music,[=](){
            music->show();
            emit music->showScene();
        });
        this->hide();
    });
    QSoundEffect*b=new QSoundEffect(music);
    b->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
    b->setVolume(1.0);


    connect(btn2,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,choose,[=](){
            choose->show();
        });
    });
    connect(btn3,&QPushButton::clicked,[=](){
        //延时0.5秒后，进入选择场景
        push->play();
        this->hide();
        QTimer::singleShot(500,this,[=](){
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
}

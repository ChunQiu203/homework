#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPushButton>
#include<QSoundEffect>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QLabel>
#include"teach.h"
#include"adjust.h"
#include"sonwindow.h"
#include"game.h"
#include"choosemusic.h"
#include"musicchoose.h"
#include"gameover.h"
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
    background=new QSoundEffect(this);
    background->setSource(QUrl::fromLocalFile(":/久石譲Wiener SymphonikerAntoine Tamestit - Viola Saga：Movement 2 (Pt. 1)-new.wav"));
    background->setLoopCount(QSoundEffect::Infinite);
    background->setVolume(0.2f);
    background->play();
    push=new QSoundEffect(this);
    push->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    push->setVolume(1.0f);
    b=new QSoundEffect(this);
    b->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
    b->setVolume(1.0);

    btn =new QPushButton("开始",this);
    btn->setParent(this);
    btn2=new QPushButton("退出",this);
    btn3=new QPushButton("选曲",this);
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
    teach* te=new teach(this);
    adjust* ad=new adjust(this);
    connect(study,&QAction::triggered,te,&teach::show);
    connect(open,&QAction::triggered,ad,&adjust::show);

    //选曲界面
    choosemusic*c=new choosemusic(this);
    //选曲界面按钮信号的处理
    connectChooseWindow(c);
    //游戏界面
    connectMainWindow(c);
    //游戏结束界面
//开始界面，按钮信号的处理3

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
//链接信号game界面
void MainWindow::connectGameWindow(game *music,choosemusic*c)
{
    connect(music->restart,&QPushButton::clicked,[=](){
        b->play();
        emit music->renew();
        QTimer::singleShot(600,music,[=](){
            music->deleteLater();
        });
        game*music=new game(":/Kirara Magic - Dragonflame.wav");
        connectGameWindow(music,c);
        music->show();
        emit music->showScene();
    });
    connect(music->fanhui,&QPushButton::clicked,[=](){
        b->play();
        emit music->back();
        QTimer::singleShot(1000,background,[=](){
            background->play();
        });
        QTimer::singleShot(600,this,[=](){
            music->deleteLater();
            this->show();
        });
    });
    connect(music->zanting,&QPushButton::clicked,[=](){
        b->play();
        QTimer::singleShot(1000,music,[=](){
            emit music->pause();
        });
        music->num++;
    });

    connect(music,&game::gameOver,[=](){
        push->play();
        gameover*over=new gameover(music->s,this);
        connectGameOver(music,over,c,music->s);
        over->show();
    });

}
void MainWindow::connectMainWindow(choosemusic*c)
{
    connect(btn,&QPushButton::clicked,[=](){
        game* music=new game(":/Kirara Magic - Dragonflame.wav");
        connectGameWindow(music,c);
        push->play();
        background->stop();
        QTimer::singleShot(400,music,[=](){
            music->show();
            emit music->showScene();
        });
        this->hide();
    });

    connect(btn2,&QPushButton::clicked,[=](){
        push->play();
        sonwindow*choose=new sonwindow(this);
        connectSonWindow(choose,this);
        QTimer::singleShot(400,choose,[=](){

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
//选择界面
void MainWindow::connectSonWindow(sonwindow*choose,QMainWindow*parent)
{
    //选择界面，按钮信号的处理
    choose->move(700,400);
    connect(choose->queren,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(600,parent,[=](){
            parent->close();
        });
    });
    connect(choose->quxiao,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,parent,[=](){
            choose->deleteLater();
        });
    });
    choose->show();
}
void MainWindow::connectSonWindow(sonwindow*choose,gameover*parent,game*music1)
{
    //选择界面，按钮信号的处理
    choose->move(700,400);
    choose->show();
    connect(choose->queren,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(600,parent,[=](){
            parent->deleteLater();
        });
        music1->deleteLater();
    });
    connect(choose->quxiao,&QPushButton::clicked,[=](){
        push->play();
        QTimer::singleShot(400,parent,[=](){
            choose->deleteLater();
        });
    });
}

//选曲界面
void MainWindow::connectChooseWindow(choosemusic*c){
    connect(c->btn1,&musicchoose::clicked,[=](){
        b->play();
        c->btn1->m->play();
        background->stop();
    });
    connect(c,&choosemusic::closed, c->btn1->m,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,background,&QSoundEffect::play);
    connect(c->btn2,&musicchoose::clicked,[=](){
        b->play();
        c->btn1->m->stop();
        background->stop();
        game*musiccpy=new game(c->btn1->music);
        emit musiccpy->showScene();
        connectGameWindow(musiccpy,c);
        QTimer::singleShot(500,musiccpy,[=](){
            musiccpy->show();
        });

        QTimer::singleShot(1000,c,[=](){
            c->hide();
        });

    });


    connect(c->btnmusic,&musicchoose::clicked,[=](){
        b->play();
        c->btnmusic->m->play();
        background->stop();
    });
    connect(c,&choosemusic::closed,c->btnmusic->m,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,background,&QSoundEffect::play);
    connect(c->btn3,&musicchoose::clicked,[=](){
        b->play();
        c->btnmusic->m->stop();
        background->stop();
        game*musiccpy=new game(c->btnmusic->music);
        emit musiccpy->showScene();
        connectGameWindow(musiccpy,c);
        QTimer::singleShot(500,musiccpy,[=](){
            musiccpy->show();
        });
        QTimer::singleShot(1000,c,[=](){
            c->hide();
        });

    });

    connect(c->L,&musicchoose::clicked,[=](){
        b->play();
        c->L->m->play();
        background->stop();
    });
    connect(c,&choosemusic::closed,c->L->m,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,background,&QSoundEffect::play);
    connect(c->l1,&musicchoose::clicked,[=](){
        b->play();
        c->L->m->stop();
        background->stop();
        game*musiccpy=new game(c->L->music);
        emit musiccpy->showScene();
        connectGameWindow(musiccpy,c);
        QTimer::singleShot(500,musiccpy,[=](){
            musiccpy->show();
        });

        QTimer::singleShot(1000,c,[=](){
            c->hide();
        });

    });

    connect(c->fanhui,&QPushButton::clicked,[=](){
        b->play();
        emit c->closed();
        QTimer::singleShot(300,this,[=](){
            this->show();
        });//重新显示
        QTimer::singleShot(400,this,[=](){
            c->hide();
        });
    });

    connect(c,&choosemusic::closed,c->btn1->m,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,c->btnmusic->m,&QSoundEffect::stop);
    connect(c,&choosemusic::closed,c->L->m,&QSoundEffect::stop);
}
void MainWindow::connectGameOver(game*music1,gameover*over,choosemusic*c,int score)
{
    connect(over,&gameover::Back,[=](){
        push->play();
        over->deleteLater();
        this->show();
        background->play();
        music1->deleteLater();
    });
    connect(over,&gameover::Restart,[=](){
        push->play();
        emit music1->renew();
        QTimer::singleShot(600,music1,[=](){
            music1->deleteLater();
        });
        game*music=new game(":/Kirara Magic - Dragonflame.wav");
        connectGameWindow(music,c);
        music->show();
        emit music->showScene();
        over->deleteLater();
    });
    connect(over,&gameover::TuiChu,[=](){
        push->play();
        sonwindow*choose=new sonwindow(over);
        connectSonWindow(choose,over,music1);
        choose->show();
    });
}

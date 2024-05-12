#include "game.h"
#include "choosemusic.h"
#include<QPainter>
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QPushButton>
#include"musicchoose.h"
#include<QTimer>
#include<QLabel>
#include"game.h"
#include"teach.h"
#include<QSoundEffect>
#include"adjust.h"
#include"down.h"
#include"evaluate.h"
#include<QRandomGenerator>
#include"timer.h"
#include<QSpinBox>

using namespace std;
game::game(QWidget *parent)
    : QMainWindow{parent}
{}
game::game(QString musicname)
{
    num=-1;
    s=0;

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
    te=new teach(this);
    ad=new adjust(this);
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

    //音符出现时钟
    showtime=new QTimer(this);
    connect(ad,&adjust::chuChanged,[=](){
        showtime->stop();
        showtime->start(ad->chuSpeed);
    });
    connect(this,&game::showScene,[=](){
        showtime->start(ad->chuSpeed);//设定音符出现时间间隔
    });
    connect(showtime,&QTimer::timeout,[=](){
        emit this->showyinfu();
    });
    connect(this,&game::gameOver,showtime,&QTimer::stop);
    music=new QSoundEffect(this);
    music->setSource(QUrl::fromLocalFile(musicname));
    dian=new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/音符.wav"));
    ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/音符miss.wav"));

    connect(this,&game::showScene,music,&QSoundEffect::play);
    connect(this,&game::pause,[=](){
        if(num%2==0)
            {
            music->stop();
            showtime->stop();
            zanting->setText("开始");
        }
        else
            {
            music->play();
            showtime->start(ad->chuSpeed);
            zanting->setText("暂停");
        }
    });
    connect(this,&game::renew,music,&QSoundEffect::play);

    //判定线设定
    QPushButton* panding=new QPushButton(this);
    panding->move(40,500);
    panding->resize(920,10);
    panding->setStyleSheet("QPushButton{border: 0px}");

    QPixmap pix;
    bool ret=pix.load(":/判定.png");
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


    //分数设定
    score=new QPushButton(this);
    score->setText(QString::number(s));
    score->setStyleSheet("QPushButton{border: none;font-family:'Script MT Bold';font-size:40px;color:rgb(84,150,136)}");
    score->resize(100,33);
    score->move(430,40);

    connect(this,&game::showyinfu,[=](){
        this->generateDownObject();
    });
    jieshu=new QPushButton(this);
    jieshu->setText("结束游戏");
    jieshu->resize(80,20);
    jieshu->move(800,40);
    jieshu->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(84,150,136)}");
    connect(jieshu,&QPushButton::clicked,[=](){
        emit gameOver();
    });

}
void game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/选曲背景.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void game::generateDownObject(){
    QSoundEffect* dian=new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/音符.wav"));
    dian->setVolume(1.0f);
    QSoundEffect* ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/音符miss.wav"));
    ba->setVolume(1.0f);

    down* yinfu = new down(this,ad->xiaSpeed,ad->TimeD);
    yinfu->setParent(this);
    yinfu->setVisible(true);
    evaluate*pingjia=new evaluate();
    pingjia->setParent(this);
    pingjia->move(10,50);
    connect(this,&game::gameOver,[=](){
        yinfu->self=yinfu->p->remainingTime();
        emit yinfu->p->Stop();
        emit yinfu->timer->Stop();
        music->stop();
        showtime->stop();
    });

    connect(yinfu,&down::best,[=](){
        s+=3;
        score->setText(QString::number(s));
        if(s<-22)
            {
            emit this->gameOver();
        }
    });
    connect(yinfu,&down::good,[=](){
        s+=2;
        score->setText(QString::number(s));
        if(s<-22)
        {
            emit this->gameOver();
        }
    });
    connect(yinfu,&down::bad,[=](){
        s++;
        score->setText(QString::number(s));
        if(s<-22)
        {
            emit this->gameOver();
        }
    });
    connect(yinfu,&down::miss,[=](){
        s--;
        score->setText(QString::number(s));
        if(s<-22)
        {
            emit this->gameOver();
        }
    });
    connect(yinfu,&down::clicked,[=](){
        yinfu->self=yinfu->p->remainingTime();//获取剩余时间
        if(yinfu->self-ad->xiaSpeed*50<=15*ad->xiaSpeed&&yinfu->self-ad->xiaSpeed*50>=-15*ad->xiaSpeed&&yinfu->flag==0/*BEST*/)
        {
            emit pingjia->e1();
            emit yinfu->best();
            dian->play();
            yinfu->flag=1;
        }
        else if(yinfu->self-ad->xiaSpeed*50<=30*ad->xiaSpeed&&yinfu->self-ad->xiaSpeed*50>=-30*ad->xiaSpeed&&yinfu->flag==0/*GOOD*/)
        {
            emit pingjia->e2();
            emit yinfu->good();
            dian->play();
            yinfu->flag=1;
        }
        else if(yinfu->self-ad->xiaSpeed*50<=ad->xiaSpeed*60&&yinfu->self-ad->xiaSpeed*50>=-60*ad->xiaSpeed&&yinfu->flag==0/*BAD*/)
        {
            emit pingjia->e3();
            emit yinfu->bad();
            dian->play();
            yinfu->flag=1;
        }
        else if(yinfu->flag==0)
        {
            emit pingjia->e4();
            emit yinfu->miss();
            ba->play();
            yinfu->flag=1;
        }
    });
    connect(this,&game::renew,[=](){
        QTimer::singleShot(1000,music,[=](){
            yinfu->timer->deleteLater();
            yinfu->p->deleteLater();
            yinfu->deleteLater();
        });
    });
    connect(this,&game::pause,[=](){
          if(num%2==0)
         {
              //线程
              //QTimer不能跨线程启动和停止定时器
               yinfu->self=yinfu->p->remainingTime();
               emit yinfu->p->Stop();
               emit yinfu->timer->Stop();
          }
         else
         {
              emit yinfu->p->Start(yinfu->self);
              emit yinfu->timer->Start(ad->xiaSpeed);
          }
    });
}

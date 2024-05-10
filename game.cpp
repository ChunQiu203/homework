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
#include<QSoundEffect>
#include"adjust.h"
#include"down.h"
#include"evaluate.h"
#include<QKeyEvent>
#include<QRandomGenerator>
using namespace std;
game::game(QWidget *parent)
    : QMainWindow{parent}
{}
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



    //音符出现时钟
    showtime=new QTimer(this);
    connect(this,&game::showScene,[=](){
        showtime->start(3000);//设定音符出现时间间隔2秒
    });

    connect(showtime,&QTimer::timeout,[=](){
        emit this->showyinfu();
    });
    music=new QSoundEffect(this);
    music->setSource(QUrl::fromLocalFile(":/Kirara Magic - Dragonflame.wav"));
    dian=new QSoundEffect(this);
    dian->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/按键音2.wav"));

    connect(this,&game::showScene,music,&QSoundEffect::play);
    connect(this,&game::pause,music,[=](){
        if(num%2==0)
            {
            music->stop();
            showtime->stop();
        }
        else
            {
            music->play();
            showtime->start(3000);
        }
        if(num%2==0)
        {
            zanting->setText("开始");
        }
        else
        {
            zanting->setText("暂停");
        }
        num++;
    });
    connect(this,&game::renew,music,&QSoundEffect::play);

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


    //分数设定
    score=new QPushButton(this);

    score->setText(QString::number(s));
    score->setStyleSheet("QPushButton{border: none;font-family:'Script MT Bold';font-size:40px;color:rgb(84,150,136)}");
    score->resize(100,33);
    score->move(430,40);
    //先设置音轨吧
    //就是可出现音符的位置
    //如果要跟随音乐的话，只要音符出现就行，位置的话，没有太大关系的
    //所以要设定音符出现的时机
    //音符元素
    //开一个音符数组
    connect(this,&game::showyinfu,[=](){
        this->generateDownObject();
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
    dian->setSource(QUrl::fromLocalFile(":/按键音.wav"));
    QSoundEffect* ba=new QSoundEffect(this);
    ba->setSource(QUrl::fromLocalFile(":/按键音2.wav"));
    down*yinfu=new down(this);
    yinfu->setParent(this);
    yinfu->setVisible(true);
    evaluate*pingjia=new evaluate();
    pingjia->setParent(this);
    pingjia->move(5,50);
    connect(yinfu,&down::best,[=](){
        s+=3;
        score->setText(QString::number(s));
    });
    connect(yinfu,&down::good,[=](){
        s+=2;
        score->setText(QString::number(s));
    });
    connect(yinfu,&down::bad,[=](){
        s++;
        score->setText(QString::number(s));
    });
    connect(yinfu,&down::miss,[=](){
        s--;
        score->setText(QString::number(s));
    });
    connect(yinfu,&down::clicked,[=](){
        if(yinfu->self<=500/*BEST*/)
        {
            emit pingjia->e1();
            emit yinfu->best();
            dian->play();
        }
        else if(yinfu->self<=1000/*GOOD*/)
        {
            emit pingjia->e2();
            emit yinfu->good();
            dian->play();
        }
        else if(yinfu->self<=1500/*BAD*/)
        {
            emit pingjia->e3();
            emit yinfu->bad();
            dian->play();
        }
        else
        {
            emit pingjia->e4();
            emit yinfu->miss();
            ba->play();
        }
    });
    connect(this,&game::pause,[=](){
        if(num%2==1)
        {
            yinfu->timer->stop();
        }
        else
        {
            yinfu->timer->start(100);
        }
    });
}

#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include<QPushButton>
#include<QTimer>
#include<QList>
#include"down.h"
#include"evaluate.h"
#include<QKeyEvent>
#include<QSoundEffect>
#include"teach.h"
#include"adjust.h"
class game : public QMainWindow
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    game(QString musicname=":/music/Maozon - Stasis.mp3");
    QPushButton* fanhui;
    QPushButton* restart;
    QPushButton* zanting;
    QSoundEffect*music;
    QSoundEffect* dian;
    QSoundEffect* ba;
    teach* te;
    adjust* ad;
    QTimer* maintime;//音符移动时钟
    QTimer* showtime;//音符出现时钟
    int a[6]={0,1,2,3,4,5};//统计音符消失数组
    int s;
    int num;//统计按下暂停次数
    QPushButton *score;
signals:
    void pause();
    void renew();
    void showScene();
    void back();
    void change();
    void showyinfu();
    void gameOver();
private slots:
    void generateDownObject();
};



#endif // GAME_H

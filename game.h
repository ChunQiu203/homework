#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include<QPushButton>
#include<QTimer>
#include"down.h"
#include"evaluate.h"
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
    friend class MainWindow;
private:
    QPushButton* fanhui;
    QPushButton* restart;
    QPushButton* zanting;
    QSoundEffect*music;
    QSoundEffect* dian;
    QSoundEffect* ba;
    QPushButton* jieshu;
    teach* te;
    adjust* ad;
    QTimer* showtime;//音符出现时钟
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

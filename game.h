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
#include"basescene.h"
class game : public basescene
{
    Q_OBJECT
public:
    game(QString musicname=":/music/Maozon - Stasis.mp3",QWidget*parent=nullptr);
    friend class MainWindow;
    friend class gametwo;
    template <typename T>void generateDownObject();
private:
    QPushButton* fanhui;
    QPushButton* restart;
    QPushButton* zanting;
    QSoundEffect*music;
    QSoundEffect* dian;
    QSoundEffect* ba;
    QPushButton* jieshu;
    QString musicname;
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

};



#endif // GAME_H

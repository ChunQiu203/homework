#ifndef GAMETWO_H
#define GAMETWO_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QSoundEffect>
#include <QTimer>
#include "adjust.h"
#include "down.h"
#include "downup.h"
#include "evaluate.h"
#include "teach.h"
#include"basescene.h"
namespace Ui {
class gametwo;
}
class gametwo : public basescene
{
    Q_OBJECT
public:
    void generateDownObjecttwo();
    void paintEvent(QPaintEvent *event);
    ~gametwo();
    gametwo(QString musicname,QWidget*parent);
    friend class MainWindow;
    QPushButton *fanhui;
    QPushButton *restart;
    QPushButton *zanting;
    QSoundEffect *music;
    QSoundEffect *dian;
    QSoundEffect *ba;
    QPushButton *jieshu;
    QString musicname;
    QTimer *showtime; //音符出现时钟
    int s;
    int num; //统计按下暂停次数
    QPushButton *score;
signals:
    void pause();
    void renew();
    void showScene();
    void back();
    void change();
    void showyinfu();
    void gameOver();

private:
    Ui::gametwo *ui;
};

#endif // GAMETWO_H

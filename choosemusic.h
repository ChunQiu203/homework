#ifndef CHOOSEMUSIC_H
#define CHOOSEMUSIC_H

#include "basescene.h"
#include"musicchoose.h"

#include<QPushButton>
#include<QMainWindow>
class choosemusic : public basescene
{
    Q_OBJECT
public:
    choosemusic(QWidget *parent);
    QPushButton *fanhui;
    musicchoose *btn1;
    QPushButton *btn2;
signals:
    void closed();
    //void showGame();
};

#endif // CHOOSEMUSIC_H

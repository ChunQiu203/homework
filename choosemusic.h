#ifndef CHOOSEMUSIC_H
#define CHOOSEMUSIC_H

#include "basescene.h"
#include<QPushButton>
class choosemusic : public basescene
{
    Q_OBJECT
public:
    explicit choosemusic(QWidget *parent = nullptr);
    QPushButton *fanhui;
signals:
    //写一个自定义信号，告诉主场景，点击了返回
    void back();
    void newmusic();
};

#endif // CHOOSEMUSIC_H

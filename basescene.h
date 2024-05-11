#ifndef BASESCENE_H
#define BASESCENE_H

#include <QMainWindow>
#include"adjust1.h"
class basescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit basescene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);//画背景图

signals:
};

#endif // BASESCENE_H

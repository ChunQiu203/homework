#ifndef BASESCENE_H
#define BASESCENE_H

#include <QMainWindow>
#include"teach.h"
#include"adjust.h"
class basescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit basescene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    teach* te;
    adjust*ad;
signals:
};

#endif // BASESCENE_H

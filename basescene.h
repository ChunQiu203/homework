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
    virtual~basescene();
    QMenuBar *menu;
    QMenu* jiaoxue;
    QMenu* tiaozheng;
    QAction* study;
    QAction* open;
    teach* te;
    adjust*ad;
signals:
};

#endif // BASESCENE_H

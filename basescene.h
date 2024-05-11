#ifndef BASESCENE_H
#define BASESCENE_H

#include <QMainWindow>

class basescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit basescene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:
};

#endif // BASESCENE_H

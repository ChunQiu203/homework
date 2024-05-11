#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include<QString>
#include<QTimer>
#include<QFile>
#include"click.h"
class game : public QMainWindow
{
    Q_OBJECT
public:
    QString filename;
    //explicit game(QWidget *parent = nullptr);
    game(QString musicname);
    QPushButton* restart;
    QPushButton* fanhui;
    QPushButton* zanting;
    void paintEvent(QPaintEvent *event);
    friend class click;
private:
    QTimer* whole;
    QFile*music;
    QFile*display;
signals:
    void back();
    void pause();
    void over();

};

#endif // GAME_H

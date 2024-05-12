#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"game.h"
#include<QSoundEffect>
#include"choosemusic.h"
#include "sonwindow.h"
#include"gameover.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void connectGameWindow(game*music,choosemusic*c);
private:
    QSoundEffect* background;
    QSoundEffect*b;
    QSoundEffect *push;
    void connectMainWindow(choosemusic*c);
    void connectChooseWindow(choosemusic*c);
    void connectSonWindow(sonwindow*choose,QMainWindow*parent);
    void connectSonWindow(sonwindow*choose,gameover*parent,game*music1);
    void connectGameOver(game*music1,gameover*over,choosemusic*c,int score);
    QPushButton * btn;//开始
    QPushButton * btn2;//退出
    QPushButton *btn3;//选曲

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

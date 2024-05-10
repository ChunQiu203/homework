#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"game.h"
#include<QSoundEffect>
#include"choosemusic.h"
#include "sonwindow.h"
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
    QSoundEffect* background;
    QSoundEffect*music1;
    QSoundEffect*b;
    QSoundEffect*Dragon;
    QSoundEffect *push;
    void connectMainWindow(choosemusic*c);
    void connectChooseWindow(choosemusic*c);
    void connectSonWindow(sonwindow*choose);
    QPushButton * btn;//开始
    QPushButton * btn2;//退出
    QPushButton *btn3;//选曲

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

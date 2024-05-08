#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include<QPushButton>
class game : public QMainWindow
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    game(QString musicname=":/music/Maozon - Stasis.mp3");
    QPushButton* fanhui;
    QPushButton* restart;
    QPushButton* zanting;
    int num=0;
signals:
    void pause();
    void renew();
    void showScene();
    void back();
};

#endif // GAME_H

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
namespace Ui {
class gameover;
}

class gameover : public QDialog
{
    Q_OBJECT

public:
    gameover(int score,QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~gameover();

private:
    Ui::gameover *ui;
signals:
    void Back();
    void Restart();
};

#endif // GAMEOVER_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"sonwindow.h"
#include <QMainWindow>
#include"choosemusic.h"
#include"basescene.h"

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
    void paintEvent(QPaintEvent *event);//画背景图

private:
    Ui::MainWindow *ui;
    sonwindow*choose;
    choosemusic* c;
};
#endif // MAINWINDOW_H

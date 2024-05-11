#include "mainwindow.h"
#include <QApplication>
#include<QPushButton>
#include<QSoundEffect>
#include<QMediaPlayer>
//#include <vld.h>
//#pragma comment(lib,"vld.lib")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSoundEffect* background=new QSoundEffect(&w);
    background->setSource(QUrl::fromLocalFile(":/music/久石譲Wiener SymphonikerAntoine Tamestit - Viola Saga：Movement 2 (Pt. 1)-new.wav"));
    background->setLoopCount(QSoundEffect::Infinite);
    background->setVolume(0.5f);
    background->play();
    w.show();
    return a.exec();
}

#ifndef MUSICCHOOSE_H
#define MUSICCHOOSE_H

#include <QPushButton>
#include<QString>
#include<QSoundEffect>
class musicchoose : public QPushButton
{
public:
    musicchoose();
    musicchoose(QString normalimage,QString musicname="添加更多");
    //成员属性 保存用户传入的默认显示路径 以及按下后显示的默认路径
    QString normalimagepath;
    QString music;
    QSoundEffect*m;
};

#endif // MUSICCHOOSE_H

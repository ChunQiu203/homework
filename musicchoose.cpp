#include "musicchoose.h"
#include<QPixmap>
#include<QString>

musicchoose::musicchoose(QString normalimage,QString musicname)
{
    normalimagepath=normalimage;
    music=musicname;
    m=new QSoundEffect(this);
    m->setSource(QUrl::fromLocalFile(musicname));
    m->setVolume(0.2f);
    QPixmap pix;
    bool ret=pix.load(normalimagepath);
    if(!ret)
    {
        return;
    }
    //设置图片大小
    setFixedSize(220,220);
    //设置不规则图片格式
    setStyleSheet("QPushButton{border: none;}");
    //设置图标
    setIcon(pix);
    //设置图标大小
    setIconSize(QSize(pix.width(),pix.height()));

}

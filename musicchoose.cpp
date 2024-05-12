#include "musicchoose.h"
#include<QPixmap>
#include<QString>
#include<QDebug>
#include<QSize>

musicchoose::musicchoose(QString normalimage,QString pressimage,QString musicname)
{
    normalimagepath=normalimage;
    pressimagepath=pressimage;
    music=musicname;
    QPixmap pix;
    bool ret=pix.load(normalimagepath);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片大小
    setFixedSize(400,400);
    //设置不规则图片格式
    setStyleSheet("QPushButton{border: none;}");
    //设置图标
    setIcon(pix);
    //设置图标大小
    setIconSize(QSize(pix.width(),pix.height()));

}

#include "sonwindow.h"
#include<QLabel>
sonwindow::sonwindow(QWidget *parent)
    : QDialog{parent}
{
    queren =new QPushButton(this);
    quxiao=new QPushButton(this);
    setStyleSheet("color:rgb(187,205,197)");
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(200,100);
    queren->setText("再见");
    queren->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    quxiao->setText("我回来啦");
    quxiao->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:16px;color:rgb(120,146,98)}");
    queren->resize(60,20);
    quxiao->resize(60,20);
    queren->move(10,50);
    quxiao->move(120,50);
    QLabel* a=new QLabel(this);
    a->move(5,10);
    a->setText("你真的确定要退出嘛？");
    a->setStyleSheet("font-family:'楷体';font-size:14px;color:rgb(120,146,98)");
    setWindowTitle("一个重要的选择");
}

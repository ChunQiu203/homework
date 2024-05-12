#ifndef CLICK_H
#define CLICK_H

#include <QPushButton>
#include<QTimer>
class click : public QPushButton
{
    Q_OBJECT
public:
    //explicit click(QWidget *parent = nullptr);
    click(QString normalimage,QString pressimage,int size);
    //成员属性 保存用户传入的默认显示路径 以及按下后显示的默认路径
    void c();
    void check();
signals:
    void good();
    void great();
    void perfect();
    void miss();
private:
    QString normalimagepath;
    QString pressimagepath;
    QTimer*self;
};

#endif // CLICK_H

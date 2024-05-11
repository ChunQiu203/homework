#ifndef SONWINDOW_H
#define SONWINDOW_H

#include <QDialog>

class sonwindow : public QDialog
{
    Q_OBJECT
public:
    //explicit sonwindow(QWidget *parent = nullptr);
    sonwindow(QWidget *parent = nullptr);
    QPushButton* queren;
    QPushButton* quxiao;
private:

signals:
    void sure();

};

#endif // SONWINDOW_H

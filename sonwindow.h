#ifndef SONWINDOW_H
#define SONWINDOW_H

#include <QDialog>
#include<QPushButton>
class sonwindow : public QDialog
{
    Q_OBJECT
public:
    explicit sonwindow(QWidget *parent = nullptr);
    friend class MainWindow;
    ~sonwindow();
private:
    QPushButton* queren;
    QPushButton* quxiao;
signals:
};

#endif // SONWINDOW_H

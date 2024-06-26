#ifndef ADJUST_H
#define ADJUST_H

#include <QMainWindow>

namespace Ui {
class adjust;
}

class adjust : public QMainWindow
{
    Q_OBJECT

public:
    explicit adjust(QWidget *parent = nullptr);
    ~adjust();
    void paintEvent(QPaintEvent *event);
private:
    static int xiaSpeed;
    static int chuSpeed;
    static int TimeD;
    friend class game;
    friend class gametwo;


private:
    Ui::adjust *ui;
signals:
    void chuChanged();
    void xiaChanged();
};

#endif // ADJUST_H

#ifndef ADJUST1_H
#define ADJUST1_H

#include <QWidget>

namespace Ui {
class adjust1;
}

class adjust1 : public QWidget
{
    Q_OBJECT

public:
    explicit adjust1(QWidget *parent = nullptr);
    ~adjust1();
    void paintEvent(QPaintEvent *event);
    int buttonsize;
    int timeDelay;
private:
    Ui::adjust1 *ui;
};

#endif // ADJUST1_H

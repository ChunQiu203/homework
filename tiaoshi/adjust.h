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
    int buttonsize;
    int timeDelay;

private:
    Ui::adjust *ui;
};

#endif // ADJUST_H

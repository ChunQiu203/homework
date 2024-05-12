#ifndef TEACH_H
#define TEACH_H

#include <QMainWindow>

namespace Ui {
class teach;
}

class teach : public QMainWindow
{
    Q_OBJECT

public:
    explicit teach(QWidget *parent = nullptr);
    ~teach();
    void paintEvent(QPaintEvent *event);

private:
    Ui::teach *ui;
};

#endif // TEACH_H

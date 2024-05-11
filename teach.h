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
    void paintEvent(QPaintEvent *event);
    ~teach();

private:
    Ui::teach *ui;
};

#endif // TEACH_H

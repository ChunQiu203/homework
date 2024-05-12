#ifndef EVALUATE_H
#define EVALUATE_H

#include <QPushButton>

class evaluate : public QPushButton
{
    Q_OBJECT
public:
    evaluate();
signals:
    void e1();
    void e2();
    void e3();
    void e4();
};

#endif // EVALUATE_H

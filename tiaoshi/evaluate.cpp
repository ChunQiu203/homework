#include "evaluate.h"
#include<QString>
evaluate::evaluate(QString a) {
    this->setText(a);
    this->setStyleSheet("QPushButton{border: none;font-family:'楷体';font-size:20px;color:rgb(120,146,98)}");
}

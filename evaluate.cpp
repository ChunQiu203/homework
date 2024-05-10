#include "evaluate.h"
#include<QString>
#include<QTimer>
#include"down.h"
evaluate::evaluate() {
    this->resize(200,100);
    this->setStyleSheet("QPushButton{border: none;font-family:'Brush Script MT';font-size:40px;color:rgb(120,146,98)}");
    //连接信号
    connect(this,&evaluate::e1,[=](){
        this->setText("perfect");
        this->show();
        QTimer::singleShot(1000,this,[=](){
            this->deleteLater();
        });
    });
    connect(this,&evaluate::e2,[=](){
        this->setText("good");
        this->show();
        QTimer::singleShot(1000,this,[=](){
            this->deleteLater();
        });
    });
    connect(this,&evaluate::e3,[=](){
        this->setText("bad");
        this->show();
        QTimer::singleShot(1000,this,[=](){
            this->deleteLater();
        });
    });
    connect(this,&evaluate::e4,[=](){
        this->setText("miss");
        this->show();
        QTimer::singleShot(1000,this,[=](){
            this->deleteLater();
        });
    });
}

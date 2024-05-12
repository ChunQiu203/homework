#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include<QThread>
class Timer : public QTimer
{
    Q_OBJECT
public:
    Timer(QObject*parent);

    QThread* m_thread;
public slots:
    void startN(int msec);
    void stopN();
signals:
    void timerTimeout();
    void Start(int msec);
    void Stop();
};

#endif // TIMER_H

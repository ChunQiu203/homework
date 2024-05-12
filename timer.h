#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
class Timer : public QTimer
{
    Q_OBJECT
public:
    Timer(QObject*parent);
public slots:
    void startN(int msec);
    void stopN();
signals:
    void timerTimeout();
    void Start(int msec);
    void Stop();
};

#endif // TIMER_H

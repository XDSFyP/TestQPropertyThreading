#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), testChild(this), timer(this) // testChild to move to m_workerThread
{
    uiThread = QThread::currentThreadId();

    // move this object to a separate thread so does not interrupt UI thread
    moveToThread(&m_workerThread); // commenting this line will make test::timerExpired() run on UI thread and slow down UI

    timer.setInterval(0); // with interval 0, more likely to seg fault due to data race

    connect(&timer, SIGNAL(timeout()), this, SLOT(timerExpired()));
    connect(&m_workerThread, SIGNAL(started()), &timer, SLOT(start()));
    m_workerThread.start();
}

void Controller::timerExpired()
{
    if (uiThread == QThread::currentThreadId())
        qCritical() << "Controller::timerExpired() Controller thread is same as UI thread";

    // prevent UI thread from accessing objects below while they update with a QMutexLocker
    QMutexLocker locker(&mutex);

    QString time;

    time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    qDebug() << "Controller::timerExpired()" << time; // this can impact preformance when usleep is commented out
    QThread::usleep(100000); // long operation

    testChild.setTime(time);
}

#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
//  , testChild(this) // uncommenting this line will cause testChild to move to m_workerThread
{
    uiThread = QThread::currentThreadId();

    // move this object to a separate thread so does not interrupt UI thread
    moveToThread(&m_workerThread); // commenting this line will make test::timerExpired() run on UI thread and slow down UI

    timer.setInterval(0); // with interval 0, more likely to seg fault due to data race

    connect(&timer, SIGNAL(timeout()), this, SLOT(timerExpired()));
    connect(&m_workerThread, SIGNAL(started()), &timer, SLOT(start()));
    m_workerThread.start();
}

void Test::timerExpired()
{
    if (uiThread == QThread::currentThreadId())
        qCritical() << "timerExpired() Controller thread is same as UI thread";

    QMutexLocker locker(&mutex);// prevent UI thread from accessing objects below while they update with a QMutexLocker

    QString time;

    time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");

    QThread::usleep(100000); // long operation

    setTime(time);
    testChild.setTime(time);
}

QString Test::getTime() const
{
    return QString("test  %1").arg(time);
}

void Test::setTime(const QString &value)
{
    time = value;
    emit timeChanged();
}

TestChild *Test::getTestChild()
{
    return &testChild;
}

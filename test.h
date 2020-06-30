#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QDateTime>
#include "testchild.h"

class Test : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString time READ getTime WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(TestChild *testChild READ getTestChild CONSTANT)

public:
    explicit Test(QObject *parent = nullptr);

    QString getTime() const;
    void setTime(const QString &value);

    TestChild testChild;

    TestChild *getTestChild();

public slots:
    void timerExpired();
signals:
    void timeChanged();

private:
    QTimer timer;
    QThread m_workerThread;
    Qt::HANDLE uiThread;
    QMutex mutex;

    QString time;
};

#endif // TEST_H

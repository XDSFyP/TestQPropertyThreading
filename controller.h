#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QDateTime>
#include "controllerchild.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

    ControllerChild testChild;

public slots:
    void timerExpired();

private:
    QTimer timer;
    QThread m_workerThread;
    Qt::HANDLE uiThread;
    QMutex mutex;
};

#endif // TEST_H

#ifndef TESTCHILD_H
#define TESTCHILD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QDateTime>

class ControllerChild : public QObject
{
    Q_OBJECT

public:
    explicit ControllerChild(QObject *parent = nullptr);

    void setTime(const QString &value);

public slots:
    void onButtonPress(const QString &value);

signals:
    void timeChanged(const QString &value);
    void onBoolChanged(QString value);

private:
    QString time;

};

#endif // TESTCHILD_H

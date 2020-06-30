#include "testchild.h"

TestChild::TestChild(QObject *parent) : QObject(parent)
{

}

QString TestChild::getTime() const
{
    return QString("test Child %1").arg(time);
//    return time;
}

void TestChild::setTime(const QString &value)
{
    time = value;
    emit timeChanged();
}

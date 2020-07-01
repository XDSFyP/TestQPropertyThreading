#include "controllerchild.h"

ControllerChild::ControllerChild(QObject *parent) : QObject(parent)
{

}

void ControllerChild::setTime(const QString &value)
{
    time = value;
    emit timeChanged(time);
}

void ControllerChild::onButtonPress(const QString &value)
{
    qDebug() << "ControllerChild::onButtonPress()" << value << QThread::currentThreadId() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    emit onBoolChanged(value); // send value back to UI label
}

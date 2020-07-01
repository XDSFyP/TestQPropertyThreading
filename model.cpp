#include "model.h"

Model::Model(Controller &test, QObject *parent) : QObject(parent), test(test)
{
    connect(&test.testChild, &ControllerChild::timeChanged, this, [=](const QString &time){ this->setTime(time); });
    connect(this, &Model::onButtonPressChanged, &test.testChild, &ControllerChild::onButtonPress);
    connect(&test.testChild, &ControllerChild::onBoolChanged, this, [=](const QString &value){ this->setBoolValue(value); });
}

QString Model::getTime() const
{
    //    return QString("test Child %1").arg(time);
    return time;
}

void Model::setTime(const QString &value)
{
    time = value;
    emit timeChanged();
}

void Model::onButtonPress(const QString &value)
{
    qDebug() << "Model::onButtonPress()" << value << QThread::currentThreadId() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    emit onButtonPressChanged(value);
}

void Model::onBool(const QString &value)
{
    qDebug() << "Model::onBool()" << value << QThread::currentThreadId() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    emit onBoolChanged(value);
}

void Model::setBoolValue(const QString &value)
{
    boolValue = value;
    qDebug() << "Model::setBoolValue()" << value << QThread::currentThreadId() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    emit onBoolChanged(value);
}


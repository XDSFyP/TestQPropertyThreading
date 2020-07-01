#ifndef MODEL_H
#define MODEL_H

#include <QObject>

#include "controller.h"

class Model : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString time READ getTime WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString boolValue MEMBER boolValue NOTIFY onBoolChanged)
public:
    explicit Model(Controller &test, QObject *parent = nullptr);

    QString getTime() const;
    void setTime(const QString &value);

    void setBoolValue(const QString &value);

public slots:
    void onButtonPress(const QString &value);
    void onBool(const QString &value);

signals:
    void timeChanged();
    void onButtonPressChanged(const QString &value);
    void onBoolChanged(const QString &value);

private:
    QString time;
    Controller &test;
    QString boolValue;
};

#endif // MODEL_H

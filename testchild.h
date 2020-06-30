#ifndef TESTCHILD_H
#define TESTCHILD_H

#include <QObject>

class TestChild : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString time READ getTime WRITE setTime NOTIFY timeChanged)

public:
    explicit TestChild(QObject *parent = nullptr);

    QString getTime() const;
    void setTime(const QString &value);

signals:
    void timeChanged();

private:
    QString time;

};

#endif // TESTCHILD_H

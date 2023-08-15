#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QVector>
#include <QFile>
#include <QDir>
#include "user.h"
#include "des.h"

class UserInfo : public QObject
{
    Q_OBJECT
public:
    explicit UserInfo(QObject *parent = 0);

    QVector<User> users ;

    void load();
    void save();
    void show();

    void appendUser(User);

    bool isAuthenticated(User);
    bool isExist(User);
    void deleteUser(QString username) ;

signals:

public slots:

};

#endif // USERINFO_H

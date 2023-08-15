#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>
#include <QStringList>

class User
{
public:
    User();
    User(QString username, QString password, int level) ;

    User getUser(QString userStr);

    // Data
    QString username ;
    QString password ;
    QString avatarPath;
    int level;

    void show() ;

signals:

public slots:


};

#endif // USER_H

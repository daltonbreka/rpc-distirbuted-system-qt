#ifndef LOGGEDINUSERS_H
#define LOGGEDINUSERS_H

#include <QVector>
#include <QString>

class LoggedInUsers
{
public:
    LoggedInUsers();

    QVector<QString> usernames ;
    QVector<QString> addrs ;

    void loggedInNewUser(QString username, QString address);
};

#endif // LOGGEDINUSERS_H

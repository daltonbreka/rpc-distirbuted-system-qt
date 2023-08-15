#include "loggedinusers.h"

LoggedInUsers::LoggedInUsers()
{
}

void LoggedInUsers::loggedInNewUser(QString username, QString address) {
    usernames.push_back(username);
    addrs.push_back(address);
}

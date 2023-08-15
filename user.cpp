#include "user.h"

User::User()
{
    username = "Dalton Chua" ;
    password = "Dalton" ;
    avatarPath = "1.png" ;
    level = 0 ;
}

User::User(QString username, QString password, int level) {
    this->username = username;
    this->password = password;
    this->level = level ;

}


User User::getUser(QString userStr) {
    QStringList userStrList = userStr.split("+s@p@l@i@t+");
    User user = User() ;
    user.username = userStrList[0] ;
    user.password = userStrList[1] ;
    user.avatarPath = userStrList[2] ;
    user.level = userStrList[3].toInt() ;
    return user ;
}

void User::show() {
    qDebug() << "*************************** ";
    qDebug() << "username: " << username ;
    qDebug() << "password: " << password ;
    qDebug() << "avatarPath: " << avatarPath ;
    qDebug() << "level: " << (level==0?"User":"Superuser");
}

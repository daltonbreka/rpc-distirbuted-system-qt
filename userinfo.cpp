#include "userinfo.h"

UserInfo::UserInfo(QObject *parent) :
    QObject(parent)
{
}

void UserInfo::show() {
    for ( int i = 0 ; i < users.size() ; i ++ ) {
        users[i].show() ;
    }
}

void UserInfo::load() {
    if ( !QDir().exists("db") ) {
        appendUser(User("admin","admin",1));
        save() ;
        return ;
    }
    QFile userFile("db/user.db");
    userFile.open(QIODevice::ReadOnly) ;
    if ( userFile.isOpen() ) {
        QByteArray userInfoBytearray = DES().dec(userFile.readAll()) ;
        userFile.close();
        if ( userInfoBytearray.length() ) {
            QString alldata = QString::fromLocal8Bit(userInfoBytearray) ;
            QStringList userList = alldata.split("+u@s@e@r+");
            for ( int i = 0 ; i < userList.size() ; i ++ )
                users.push_back(User().getUser(userList[i]));
        }
    }
}

void UserInfo::save() {
    if ( !QDir().exists("db") )
        QDir().mkdir("db");
    QFile userFile("db/user.db");
    userFile.open(QIODevice::WriteOnly) ;
    QByteArray res ;
    for ( int i = 0 ; i < users.size() ; i ++ ) {
        res += users[i].username.toLocal8Bit();
        res += "+s@p@l@i@t+" ;
        res += users[i].password.toLocal8Bit();
        res += "+s@p@l@i@t+";
        res += users[i].avatarPath.toLocal8Bit();
        res += "+s@p@l@i@t+";
        res += QString::number(users[i].level).toLocal8Bit();
        if ( i < users.size() - 1 )
            res += "+u@s@e@r+";
    }
    userFile.write(DES().enc(res));
    userFile.close();
}

bool UserInfo::isAuthenticated(User user) {
    for ( int i = 0 ; i < users.size() ; i ++ ) {
        if ( users[i].username == user.username &&
             users[i].password == user.password ) return true ;
    }
    return false ;
}

bool UserInfo::isExist(User user) {
    for ( int i = 0 ; i < users.size() ; i ++ ) {
        if ( users[i].username == user.username ) return true ;
    }
    return false ;
}

void UserInfo::appendUser(User user) {
    users.push_back(user);
    save() ;
}

void UserInfo::deleteUser(QString username) {
    for ( int i = 0 ; i < users.size() ; i ++ ) {
        if ( users[i].username == username ) {
            users.remove(i);
            break ;
        }
    }
    save() ;
}

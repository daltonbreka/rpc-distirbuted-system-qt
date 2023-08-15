#ifndef FILEINFOITEM_H
#define FILEINFOITEM_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QStringList>
#include <QDebug>

class FileInfoItem
{
public:
    FileInfoItem();
    FileInfoItem(QString _id, QString _name, QString _username, QString _date, int _size) ;
    FileInfoItem getFileInfoItem(QString str) ;

    void genId();
    void show() ;

    QString id ;
    QString name ;
    QString username ;
    QString date ;
    int size ;
};

#endif // FILEINFOITEM_H

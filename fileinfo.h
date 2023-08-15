#ifndef FILEINFO_H
#define FILEINFO_H

#include "fileinfoitem.h"

#include <QString>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QDebug>

class FileInfo
{
public:
    FileInfo();

    void extract(QString ba);
    void appendFile(FileInfoItem item) ;
    void deleteFile ( QString id) ;
    void save() ;
    void load() ;
    void send(QString id, QString address) ;

    FileInfoItem find(QString id) ;

    void show() ;
    QVector<int> search(QString pattern) ;

    QByteArray dump() ;

    QVector<FileInfoItem> fileItems ;
};

#endif // FILEINFO_H

#include "fileinfo.h"

FileInfo::FileInfo()
{
}

void FileInfo::extract(QString ba) {
    fileItems.clear();
    QStringList alldata = ba.split("@:@") ;
    for ( int i = 0 ; i < alldata.length() ; i ++ ) {
        QStringList tlist = alldata[i].split("@;@") ;
        fileItems.push_back(FileInfoItem(tlist[0], tlist[1], tlist[2], tlist[3], tlist[4].toInt()));
    }
}

void FileInfo::appendFile(FileInfoItem item) {
    fileItems.push_back(item);
    save() ;
}

void FileInfo::deleteFile(QString id) {
    for ( int i = 0 ; i < fileItems.size() ; i++ ) {
        if ( fileItems[i].id == id ) {
            fileItems.remove(i);
            break;
        }
    }
    save() ;
}

void FileInfo::load() {
    if ( !QDir().exists("db") )
        QDir().mkdir("db");
    QFile fileFile("db/file.db");
    fileItems.clear();
    fileFile.open(QIODevice::ReadOnly) ;
    if ( fileFile.isOpen() ) {
        QByteArray fileInfoBytearray = fileFile.readAll() ;
        fileFile.close();
        if ( fileInfoBytearray.length() ) {
            QString alldata = QString::fromLocal8Bit(fileInfoBytearray) ;
            QStringList fileList = alldata.split("+f@i@l@e+");
            for ( int i = 0 ; i < fileList.size() ; i ++ )
                fileItems.push_back(FileInfoItem().getFileInfoItem(fileList[i]));
        }
    }
}

void FileInfo::save() {
    if ( !QDir().exists("db") )
        QDir().mkdir("db");
    QFile fileFile("db/file.db");
    fileFile.open(QIODevice::WriteOnly) ;
    QByteArray res ;
    for ( int i = 0 ; i < fileItems.size() ; i ++ ) {
        res += fileItems[i].id.toLocal8Bit();
        res += "+s@p@l@i@t+" ;
        res += fileItems[i].name.toLocal8Bit();
        res += "+s@p@l@i@t+";
        res += fileItems[i].username.toLocal8Bit();
        res += "+s@p@l@i@t+";
        res += fileItems[i].date.toLocal8Bit();
        res += "+s@p@l@i@t+";
        res += QString::number(fileItems[i].size).toLocal8Bit();
        if ( i < fileItems.size() - 1 )
            res += "+f@i@l@e+";
//        QFile realFile("store/"+fileItems[i].id);
//        realFile.open(QIODevice::WriteOnly);
//        realFile.close();
    }
//    userFile.write(DES().enc(res));
    fileFile.write(res);
    fileFile.close();
}

void FileInfo::show() {
    for ( int i = 0 ; i < fileItems.size() ; i ++ )
        fileItems[i].show() ;
}


QVector<int> FileInfo::search(QString pattern) {
    QVector<int> res ;
    for ( int i = 0 ; i < fileItems.size() ; i ++ ) {
        if ( pattern.length() == 0 ) {
            res.push_back(i);
            continue ;
        }
        if ( fileItems[i].name.contains(pattern) ) {
            res.push_back(i);
            continue ;
        }
        if ( fileItems[i].username.contains(pattern) ) {
            res.push_back(i);
            continue;
        }
        if ( fileItems[i].date.contains(pattern) ) {
            res.push_back(i);
            continue ;
        }
    }
    return res ;
}

QByteArray FileInfo::dump() {
    QByteArray data ;
    for ( int i = 0 ; i < fileItems.size() ; i ++ ) {
        FileInfoItem &item = fileItems[i] ;
        QByteArray temp ;
        temp += item.id.toLocal8Bit() + "@;@" ;
        temp += item.name.toLocal8Bit() + "@;@" ;
        temp += item.username.toLocal8Bit() + "@;@" ;
        temp += item.date.toLocal8Bit() + "@;@" ;
        temp += QString::number(item.size).toLocal8Bit() + "@;@" ;
        data += temp ;
        if ( i < fileItems.size() - 1)
            data += "@:@" ;
    }
    return data ;
}

FileInfoItem FileInfo::find(QString id) {
    FileInfoItem res ;
    for ( int i = 0 ; i < fileItems.size() ; i ++ ) {
        if( fileItems[i].id == id ) {
            res = fileItems[i] ;
        }
    }
    return res ;
}

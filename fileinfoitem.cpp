#include "fileinfoitem.h"

FileInfoItem::FileInfoItem(QString _id, QString _name, QString _username, QString _date, int _size) {
    if ( _id.length() == 0)
        genId();
    else
        this->id = _id ;
    this->name = _name ;
    this->username = _username ;
    this->date = _date ;
    this->size = _size ;
}

FileInfoItem::FileInfoItem()
{
}

FileInfoItem FileInfoItem::getFileInfoItem(QString str) {
    QStringList fileStrList = str.split("+s@p@l@i@t+");
    FileInfoItem fileItem = FileInfoItem() ;
    fileItem.id = fileStrList[0] ;
    fileItem.name= fileStrList[1] ;
    fileItem.username = fileStrList[2] ;
    fileItem.date = fileStrList[3] ;
    fileItem.size = fileStrList[4].toInt() ;
    return fileItem ;
}

void FileInfoItem::genId() {
    QString res ;
    for ( int i = 0 ; i < 20 ; i ++ ) {
        char x[2] = "A" ;
        x[0] = 'A' + qrand() % 26 ;
        res.append(x) ;
    }
    this->id = res ;
}

void FileInfoItem::show() {
    qDebug() << "*******************" ;
    qDebug () << id << "," << name << "," << username << "," << date << "," << size ;
}

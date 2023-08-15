#include "share.h"
#include <QDebug>
Share::Share()
{
}

bool Share::ipIsValid(QString ipStr){
    QByteArray tba = ipStr.toLocal8Bit() ;
    for ( int i = 0 ; i < tba.size() ; i ++ ) {
        if ( ( tba[i] >= '0' && tba[i] <= '9' ) || tba[i] == '.' ) continue ;
        else return false ;
    }
    QStringList list = ipStr.split(".");
    if ( list.size() != 4 ) return false ;
    for ( int i = 0 ; i < 4 ; i ++ ) {
        if ( list[i].length() == 0 ) return false ;
        if ( list[i].toInt() < 0 ) return false ;
        if ( list[i].toInt() > 255 ) return false ;
    }
    return true ;
}

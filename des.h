#ifndef DES_H
#define DES_H

#include <QByteArray>
#include <openssl/des.h>

class DES
{
public:
    DES();
    QByteArray enc(QByteArray in) ;
    QByteArray dec(QByteArray in) ;
    int to8mod(int len);
    QByteArray int2bytearray(int len) ;
    int bytearray2int(QByteArray ba) ;
};

#endif // DES_H

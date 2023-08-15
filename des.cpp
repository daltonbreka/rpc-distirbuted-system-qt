#include "des.h"

DES::DES()
{
}
#include <QDebug>
QByteArray DES::enc(QByteArray in) {
    QByteArray b(to8mod(in.size()), ' ') ;
    DES_key_schedule key ;
    DES_set_key((unsigned char (*)[8])"1234abcd",&key);
    DES_cbc_encrypt((unsigned char*)in.data(),
                    (unsigned char*)b.data(),
                    in.size(),
                    &key,
                    (unsigned char (*)[8])"daltonch",
                    DES_ENCRYPT);
    return b + int2bytearray(in.size()) ;
}

QByteArray DES::dec(QByteArray in) {
    QByteArray length = in.right(8) ;
    in.resize(in.length()-8);
    QByteArray b(in.size(), ' ') ;
    DES_key_schedule key ;
    DES_set_key((unsigned char (*)[8])"1234abcd",&key);
    DES_cbc_encrypt((unsigned char*)in.data(),
                    (unsigned char*)b.data(),
                    in.size(),
                    &key,
                    (unsigned char (*)[8])"daltonch",
                    DES_DECRYPT);
    b.resize(bytearray2int(length));
    return b ;
}

int DES::to8mod(int len) {
    return (len%8?len+8-len%8: len);
}

QByteArray DES::int2bytearray(int len) {
    QByteArray res(8,' ');
    for ( int i = 0 ; i < 8 ; i ++ ) {
        res[i] = len % 100 ;
        len /= 100 ;
    }
    return res ;
}

int DES::bytearray2int(QByteArray ba) {
    int res = 0 ;
    for ( int i = 7 ; i >= 0 ; i -- ) {
        res = res * 100 + ba[i] ;
    }
    return res ;
}


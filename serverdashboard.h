#ifndef SERVERDASHBOARD_H
#define SERVERDASHBOARD_H

#include "userinfo.h"
#include "fileinfo.h"
#include "loggedinusers.h"

#include <QMessageBox>
#include <QWidget>
#include <QVector>
#include <QUdpSocket>
#include <QDebug>

namespace Ui {
    class ServerDashboard;
}

#define CLIENT_PORT 23542
#define SERVER_PORT 19023

#define BLOCKSIZE 20480
#define MAXLEN_OF_HEADER 100
#define ID_LOGIN "@LOGIN@:"
#define ID_LOGIN_SUCCESS "@LOGIN_SUCCESS@:"
#define ID_REGISTER "@REGISTER@:"
#define ID_REGISTER_SUCCESS "@REGISTER_SUCCESS@:"
#define ID_UPLOAD_REQ "@UPLOAD_REQ@:"
#define ID_UPLOAD_START "@UPLOAD_START@:"
#define ID_UPLOAD_BLOCK "@UPLOAD_BLOCK@:"
#define ID_UPLOAD_BLOCK_REQ "@UPLOAD_BLOCK_REQ@:"
#define ID_UPLOAD_BLOCK_LIST_REQ "@UPLOAD_BLOCK_LIST_REQ@:"
#define ID_UPLOAD_FINISH "@UPLOAD_FINISH@:"
#define ID_DOWN_REQ "@DOWN_REQ@:"
#define ID_DOWN_BLOCK "@DOWN_BLOCK@:"
#define ID_DOWN_BLOCK_REQ "@DOWN_BLOCK_REQ@:"
#define ID_FILE_LIST "@FILE_LIST@:"
#define ID_FILE_LIST_REQ "@FILE_LIST_REQ@:"
#define ID_DOWN_BLOCK_LIST_REQ "@DOWN_BLOCK_LIST_REQ@:"
#define TIMER_FILE_LIST_ELLAPSE 1000

class ServerDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit ServerDashboard(QWidget *parent = 0);
    ~ServerDashboard();

    UserInfo userInfo ;
    FileInfo fileInfo ;
    LoggedInUsers loggedInfo ;

    QVector<int> matches ;

    QString pattern ;

    QUdpSocket *udpSocket ;

    int timer ;

private:
    Ui::ServerDashboard *ui;

    void refreshFile() ;
    void refreshUser() ;

    QString fileSizeString(int size) ;
    QByteArray fillHeader(QByteArray in) ;

    void preprocessDatagram(QByteArray ba) ;

    void loginClientCheck(QString username, QString password, QString address);
    void loginClientSuccess(QString address) ;

    void registerClientCheck(QString username, QString password, QString address);
    void registerClientSuccess(QString address) ;

    void sendFileList(QString address) ;

    // download server
    QString downFilepath;
    int downBlockCount ;

    void recvDownloadReq(QString downFileId) ;
    void sendDownload(QString addrs) ;
    void sendDownloadBlock(QString addrs, int blocknumber) ;
    void recvDownloadBlockList(QString addrs,QString numbers);

    // upload server
    FileInfoItem item ;
    int downMaxBlockNumber ;
    QVector<bool> downFlgBlock ;
    QStringList clientAddrs;
    QTime lastReceived ;

    void sendUploadStart() ; // send signal to start
    void sendDownloadBlockRequest(int blocknumber) ; // send request to send back again
    void recvDownloadBlock(int blocknumber, QByteArray data) ; // get block info
    void prepareDownload(QString addrs,QString filename, QString username, int filesize ) ; // before upload start, prepare
    void sendDownloadBlockListRequest(QStringList list); // send file request to the client
    void sendUploadFinish() ; // send upload finish

private slots:
    void on_buttonDeleteUser_clicked();
    void on_buttonRefreshUser_clicked();
    void on_buttonDeleteFile_clicked();
    void on_buttonRefreshFile_clicked();
    void on_buttonSearchFile_clicked();

    void processPendingDatagrams();
protected:
    void timerEvent(QTimerEvent *);
public slots:
};

#endif // SERVERDASHBOARD_H

#ifndef CLIENTDASHBOARD_H
#define CLIENTDASHBOARD_H

#include <QWidget>
#include <QUdpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include "fileinfo.h"

#include "login.h"
#include "register.h"

#include "server.h"
#include "client.h"

#define CLIENT_PORT 23542
#define SERVER_PORT 19023
#define TCP_CLIENT_PORT 23543
#define TCP_SERVER_PORT 19024

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
#define ID_DOWN_BLOCK_LIST_REQ "@DOWN_BLOCK_LIST_REQ@:"
#define ID_FILE_LIST "@FILE_LIST@:"
#define ID_FILE_LIST_REQ "@FILE_LIST_REQ@:"
#define STATUS_FREE 0
#define STATUS_DOWNLOADING 1
#define STATUS_UPLOADING 2
#define TIMER_FILE_LIST_ELLAPSE 1000

namespace Ui {
    class ClientDashboard;
}

class ClientDashboard : public QWidget
{
    Q_OBJECT
public:
    explicit ClientDashboard(QWidget *parent = 0);
    ~ClientDashboard();

    Login *loginWidget;
    Register *registerWidget;

    QUdpSocket *udpSocket;

    QString pattern ;
    QString serverAddress ;
    QString username ;

    QVector<int> matches ;

    FileInfo fileInfo;

    int timer ;
    int status ;

    // Download
    QString downPath ;
    int downFilesize ;
    int downBlockCount ;
    int downMaxBlockNumber ;
    QString downFileId ;
    QVector<bool> downFlgBlock ;
    QTime lastReceived ;

    // Upload

    QString upFilepath;

    Server *server ;
    QString destPath ;

private:
    Ui::ClientDashboard *ui;

    void refreshFile() ;
    void sendDownloadFileListRequest() ;
    void recvDownloadFileList(QByteArray &info);

    QString fileSizeString(int size) ;
    QByteArray fillHeader(QByteArray in) ;

    void preprocessDatagram(QByteArray ba) ;

    QStringList getIps() ;

//     download client
    void sendDownloadRequest();
    void sendDownloadBlockRequest(int blocknumber) ;
    void recvDownloadBlock(int blocknumber, QByteArray data) ;
    void prepareDownload() ;
    void sendDownloadBlockListRequest(QStringList list);

    // upload client ! when you send your packet, add your address
    void sendUploadRequest(); // send fileinfo(filename, username, )
    void sendDownload() ; // when receive start signal, send whole data
    void sendDownloadBlock(int blocknumber) ; // send block
    void recvDownloadBlockList(QString numbers); // get block list to resend and send back
    void recvUploadFinished() ; // get receive finished signal

public slots:
    void toLogin();
    void toRegister();
    void toClientDashboard();

    void loginClient(QString,QString,QString);
    void registerClient(QString,QString,QString);
private slots:

    void on_buttonUpload_clicked();
    void on_buttonUpBrowse_clicked();
    void on_buttonDownload_clicked();
    void on_buttonDownBrowse_clicked();
    void on_buttonSearch_clicked();
    void on_buttonRefresh_clicked();
    void processPendingDatagrams();

    void downloadFinished();

    void startUpload() ;
protected:
    void timerEvent(QTimerEvent *);
};

#endif // CLIENTDASHBOARD_H

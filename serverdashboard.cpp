#include "serverdashboard.h"
#include "ui_serverdashboard.h"

ServerDashboard::ServerDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerDashboard)
{
    ui->setupUi(this);

    fileInfo.load() ;
    refreshFile() ;

    userInfo.load();
    refreshUser();

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(SERVER_PORT);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));

    if ( !QDir().exists("store") )
        QDir().mkdir("store");

}

ServerDashboard::~ServerDashboard()
{
    delete ui;
}

void ServerDashboard::refreshFile() {
    matches = fileInfo.search(ui->editSearchFile->text()) ;
    for ( int i = 0 ; i < ui->tableFile->rowCount() ; i ++ )
        ui->tableFile->removeRow(0);
    ui->tableFile->setRowCount(matches.size());
    for ( int i = 0 ; i < matches.size() ; i ++ ) {
        FileInfoItem &item = fileInfo.fileItems[matches[i]] ;
        ui->tableFile->setItem(i,0, new QTableWidgetItem(item.name)) ;
        ui->tableFile->setItem(i,1, new QTableWidgetItem(item.username)) ;
        ui->tableFile->setItem(i,2, new QTableWidgetItem(item.date)) ;
        ui->tableFile->setItem(i,3, new QTableWidgetItem(fileSizeString(item.size))) ;
    }
}

void ServerDashboard::refreshUser() {
    for ( int i = 0 ; i < ui->tableUser->rowCount() ; i ++ )
        ui->tableUser->removeRow(0);
    ui->tableUser->setRowCount(userInfo.users.size()-1);
    for ( int i = 1 ; i < userInfo.users.size() ; i ++ ) {
        User &item = userInfo.users[i] ;
        ui->tableUser->setItem(i-1,0, new QTableWidgetItem(item.username)) ;
        ui->tableUser->setItem(i-1,1, new QTableWidgetItem(item.password)) ;
        ui->tableUser->setItem(i-1,2, new QTableWidgetItem(item.level?"SuperUser":"User")) ;
    }
}

QString ServerDashboard::fileSizeString(int size) {
    if ( size > 1024 * 1024 * 1024 )
        return QString::number(qRound(size / 102.4 / 1024 / 1024)/10.0) + " GBytes";
    if ( size > 1024 * 1024 )
        return QString::number(qRound(size / 102.4  / 1024)/10.0 ) + " MBytes";
    if ( size > 1024 )
        return QString::number(qRound(size / 102.4 )/10.0) + " KBytes";
    return QString::number(size) + " Bytes";
}

void ServerDashboard::on_buttonSearchFile_clicked()
{
    refreshFile();
}

void ServerDashboard::on_buttonRefreshFile_clicked()
{
    ui->editSearchFile->setText("");
    refreshFile();
}

void ServerDashboard::on_buttonDeleteFile_clicked()
{
    QList<QTableWidgetItem*> tableData = ui->tableFile->selectedItems() ;
    if ( tableData.size() > 0 ) {
        int ret = QMessageBox::question(this,
                                        "Question",
                                        "Are you going to delete?",
                                        QMessageBox::Yes,
                                        QMessageBox::No
                                        ) ;
        if ( ret == QMessageBox::Yes ) {
            for ( int i = 0 ; i < tableData.size() ; i ++ ) {
                fileInfo.deleteFile(fileInfo.fileItems[matches[tableData[i]->row()]].id);
            }
            refreshFile() ;
        }
    }
}

void ServerDashboard::on_buttonRefreshUser_clicked()
{
    refreshUser();
}

void ServerDashboard::on_buttonDeleteUser_clicked()
{
    QList<QTableWidgetItem*> tableData = ui->tableUser->selectedItems() ;
    if ( tableData.size() > 0 ) {
        int ret = QMessageBox::question(this,
                                        "Question",
                                        "Are you going to delete?",
                                        QMessageBox::Yes,
                                        QMessageBox::No
                                        ) ;
        if ( ret == QMessageBox::Yes ) {
            for ( int i = 0 ; i < tableData.size() ; i ++ ) {
                userInfo.deleteUser(userInfo.users[tableData[i]->row()+1].username);
            }
            refreshUser();
        }
    }
}

void ServerDashboard::processPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        preprocessDatagram(datagram);
    }
}

void ServerDashboard::preprocessDatagram(QByteArray ba) {
    QString header = QString::fromLocal8Bit(ba.left(MAXLEN_OF_HEADER)) ;
    QStringList headerList = header.split(":;");
    QByteArray data = ba.right(ba.length()-MAXLEN_OF_HEADER) ;
    QString idStr = headerList[0] ;
    qDebug() << "server " << idStr ;
    if ( idStr == ID_LOGIN ) {
        loginClientCheck(headerList[1], headerList[2], headerList[3]);
    } else if ( idStr == ID_REGISTER ) {
        registerClientCheck(headerList[1], headerList[2], headerList[3]);
    } else if ( idStr == ID_FILE_LIST_REQ ) {
        sendFileList(headerList[1]);
    } else if ( idStr == ID_DOWN_REQ ) {
        recvDownloadReq(headerList[2]);
        sendDownload(headerList[1]);
    } else if ( idStr == ID_DOWN_BLOCK_REQ ) {
        sendDownloadBlock(headerList[1], headerList[2].toInt());
    } else if ( idStr == ID_DOWN_BLOCK_LIST_REQ ) {
        recvDownloadBlockList(headerList[1], headerList[2]);
    } else if ( idStr == ID_UPLOAD_REQ ) {
        prepareDownload(headerList[1],
                        headerList[2],
                        headerList[3],
                        headerList[4].toInt());
        sendUploadStart();
    } else if ( idStr == ID_UPLOAD_BLOCK ) {
        recvDownloadBlock(headerList[1].toInt(), data );
    }
}

void ServerDashboard::loginClientCheck(QString username, QString password, QString address) {
    if ( userInfo.isAuthenticated(User(username, password, 0)) ) {
        QStringList addList = address.split(";@;") ;
        for ( int i = 0 ; i < addList.size() ; i++ ) {
            loggedInfo.loggedInNewUser(username, addList[i]);
           loginClientSuccess(addList[i]);
        }
    }
}

void ServerDashboard::loginClientSuccess(QString address) {
    QByteArray datagram = QByteArray() + ID_LOGIN_SUCCESS + ":;" ;
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(address), CLIENT_PORT);
}

void ServerDashboard::registerClientCheck(QString username, QString password, QString address) {
    if ( !userInfo.isExist(User(username, password, 0)) ) {

        QStringList addList = address.split(";@;") ;
        for ( int i = 0 ; i < addList.size() ; i++ ) {
            loggedInfo.loggedInNewUser(username, addList[i]);
            registerClientSuccess(addList[i]);
        }
        userInfo.appendUser(User(username, password, 0));

        refreshUser();
    }
}

void ServerDashboard::registerClientSuccess(QString address) {
    QByteArray datagram = QByteArray() + ID_REGISTER_SUCCESS + ":;" ;
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(address), CLIENT_PORT);
}

QByteArray ServerDashboard::fillHeader(QByteArray in) {
    if ( in.length() < MAXLEN_OF_HEADER ) {
        in += QByteArray(MAXLEN_OF_HEADER-in.length(), ' ');
    }
    return in;
}

void ServerDashboard::timerEvent(QTimerEvent *){
    if ( lastReceived.msecsTo(QTime::currentTime()) >= 10 ) {
        QStringList list ;
        int recvCount = 0 ;
        for ( int i = 0 ; i < downBlockCount ; i ++ ) {
            if ( !downFlgBlock[i] ) {
                list.push_back(QString::number(i));
            }  else
                recvCount ++ ;
        }
        if ( list.size() == 0 ) {
            killTimer(timer);
            sendUploadFinish() ;
        } else {
            if ( list.size() > 1000 )
                list = list.mid(0,1000);
            sendDownloadBlockListRequest(list);
        }
        lastReceived = QTime::currentTime();
    }
}

void ServerDashboard::sendFileList(QString addresses){
    if ( !fileInfo.fileItems.size() ) return ;
    QByteArray data = fileInfo.dump() ;
    QStringList list = addresses.split(";@;");
    for ( int i = 0 ; i < list.size() ; i ++ ) {

        QByteArray datagram = QByteArray() + ID_FILE_LIST + ":;" ;
        datagram = fillHeader(datagram) ;
        datagram += data ;
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(list[i]), CLIENT_PORT);
    }

}

void ServerDashboard::recvDownloadReq(QString downFileId) {
    FileInfoItem item = fileInfo.find(downFileId) ;
    downFilepath = "store/" + item.id;
    downBlockCount =
            item.size % BLOCKSIZE?
            item.size / BLOCKSIZE + 1:
            item.size / BLOCKSIZE ;
}

void ServerDashboard::sendDownload(QString addrs) {
    for ( int i = 0 ; i < downBlockCount ; i ++ ) {
        sendDownloadBlock(addrs,i);
    }
}

void ServerDashboard::sendDownloadBlock(QString addrs, int blocknumber){
    QFile file(downFilepath) ;
    file.open(QIODevice::ReadOnly) ;
    if ( file.isOpen() ) {
        file.seek((blocknumber)*BLOCKSIZE) ;
        QByteArray data = file.read(BLOCKSIZE);
        file.close();
        QStringList list = addrs.split(";@;") ;
        qDebug() << list ;
        for ( int i = 0 ; i < list.size() ; i ++ ) {
            QByteArray datagram = QByteArray() + ID_DOWN_BLOCK  + ":;"+ QString::number(blocknumber).toLocal8Bit() + ":;";
            datagram = fillHeader(datagram) ;
            datagram += data ;
            udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                     QHostAddress(list[i]), CLIENT_PORT);// ***************
        }
    }
}

void ServerDashboard::recvDownloadBlockList(QString addrs,QString numbers) {
    QStringList numList = numbers.split("***") ;
    for ( int i = 0 ; i < numList.size() ; i ++ ) {
        sendDownloadBlock(addrs,numList[i].toInt());
    }
}

void ServerDashboard::prepareDownload(QString addrs, QString filename, QString username, int filesize ){
    item.genId();
    item.date = QDate::currentDate().toString("yyyy-MM-dd");
    item.name = filename ;
    item.username = username ;
    item.size = filesize ;

    clientAddrs = addrs.split(";@;") ;
    downBlockCount = filesize % BLOCKSIZE ?
                     filesize / BLOCKSIZE + 1 :
                     filesize / BLOCKSIZE ;
    downFlgBlock = QVector<bool>(downBlockCount+1, false);
    downMaxBlockNumber = -1;
    lastReceived = QTime::currentTime() ;

    timer = startTimer(1) ;
}

void ServerDashboard::sendUploadStart() {
    QByteArray datagram = QByteArray() + ID_UPLOAD_START  + ":;" ;
    datagram = fillHeader(datagram) ;
    for ( int i = 0 ; i < clientAddrs.size() ; i ++ ) {
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(clientAddrs[i]), CLIENT_PORT);// ***************
    }
}

void ServerDashboard::sendDownloadBlockRequest(int blocknumber) {
     for ( int i = 0 ; i < clientAddrs.size() ; i ++ ) {
         QByteArray datagram = QByteArray() + ID_UPLOAD_BLOCK_REQ + ":;"
                               + QString::number(blocknumber).toLocal8Bit() + ":;";
        datagram = fillHeader(datagram) ;
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(clientAddrs[i]), CLIENT_PORT);// ***************
    }
}

void ServerDashboard::recvDownloadBlock(int blocknumber, QByteArray data) {
    lastReceived = QTime::currentTime() ;
    if ( blocknumber > downMaxBlockNumber )
        downMaxBlockNumber = blocknumber ;
    if ( !QDir().exists("temp") )
        QDir().mkdir("temp") ;
    QFile file("temp/" + item.id) ;
    file.open(QIODevice::ReadWrite);
    downFlgBlock[blocknumber] = true ;
    file.seek(blocknumber*BLOCKSIZE) ;
    file.write(data) ;
    file.close();
}

void ServerDashboard::sendDownloadBlockListRequest(QStringList list) {
    for ( int i = 0 ; i < clientAddrs.size() ; i ++ ) {
        QByteArray datagram = QByteArray() + ID_UPLOAD_BLOCK_LIST_REQ + ":;"
                              + list.join("***").toLocal8Bit() + ":;";
        datagram = fillHeader(datagram) ;
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(clientAddrs[i]), CLIENT_PORT);
    }
}

void ServerDashboard::sendUploadFinish() {
    QByteArray datagram = QByteArray() + ID_UPLOAD_FINISH  + ":;" ;
    datagram = fillHeader(datagram) ;
    for ( int i = 0 ; i < clientAddrs.size() ; i ++ ) {
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(clientAddrs[i]), CLIENT_PORT);// ***************
    }
    QFile("temp/"+item.id).copy("store/"+item.id);
    QFile::remove("temp/" + item.id);

    fileInfo.appendFile(item);
    refreshFile();
}

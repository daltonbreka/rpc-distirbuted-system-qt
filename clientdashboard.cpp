#include "clientdashboard.h"
#include "ui_clientdashboard.h"

ClientDashboard::ClientDashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientDashboard)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(CLIENT_PORT);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));

    status = STATUS_FREE ;

    loginWidget = new Login(NULL) ;
    loginWidget->show();
    registerWidget = new Register(NULL) ;
    registerWidget->hide();

    connect(loginWidget, SIGNAL(toRegister()),
            this, SLOT(toRegister())) ;
    connect(loginWidget, SIGNAL(loginClient(QString,QString,QString)),
            this, SLOT(loginClient(QString,QString,QString))) ;
    connect(registerWidget, SIGNAL(toLogin()),
            this, SLOT(toLogin()));
    connect(registerWidget, SIGNAL(registerClient(QString,QString,QString)),
            this, SLOT(registerClient(QString,QString,QString)));

    server = new Server();
    server->start(TCP_CLIENT_PORT);

    connect(server, SIGNAL(downloadFinished()),
            this, SLOT(downloadFinished()));
}

void ClientDashboard::toLogin(){
    loginWidget->show();
    registerWidget->hide();
    this->hide();
}

void ClientDashboard::toRegister(){
    loginWidget->hide();
    registerWidget->show();
    this->hide();
}

void ClientDashboard::toClientDashboard(){
    qDebug() << "to client dashboard" ;
    loginWidget->hide();
    registerWidget->hide();
    this->show();
}

void ClientDashboard::loginClient(QString _username,
                                  QString password,
                                  QString serverIp){
    serverAddress = serverIp ;
    this->username = _username ;
    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
    QByteArray datagram = QByteArray() + ID_LOGIN + ":;" +
                            username.toLocal8Bit() + ":;" +
                            password.toLocal8Bit() + ":;" +
                            res.toLocal8Bit() + ":;";
    qDebug() << datagram ;
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);
}

void ClientDashboard::registerClient(QString _username,QString password,QString serverIp){
    serverAddress = serverIp ;
    this->username = _username ;
    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
    QByteArray datagram = QByteArray() + ID_REGISTER + ":;" +
                            username.toLocal8Bit() + ":;" +
                            password.toLocal8Bit() + ":;" +
                            res.toLocal8Bit() + ":;";
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);
}

ClientDashboard::~ClientDashboard()
{
    delete ui;
}

void ClientDashboard::processPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        preprocessDatagram(datagram);
    }
}

void ClientDashboard::preprocessDatagram(QByteArray ba) {
    QString header = QString::fromLocal8Bit(ba.left(MAXLEN_OF_HEADER)) ;
    QStringList headerList = header.split(":;");
    QByteArray data = ba.right(ba.length()-MAXLEN_OF_HEADER) ;
    QString idStr = headerList[0] ;
    qDebug() << "client " << header ;
    if ( idStr == ID_FILE_LIST ) {
        recvDownloadFileList(data);
    } else if ( idStr == ID_DOWN_BLOCK ) {
        recvDownloadBlock(headerList[1].toInt(),
                          data);
    } else if ( idStr == ID_UPLOAD_START ) {
        sendDownload();
    } else if ( idStr == ID_UPLOAD_BLOCK_LIST_REQ) {
        recvDownloadBlockList(headerList[1]);
    } else if ( idStr == ID_UPLOAD_FINISH ) {
        recvUploadFinished();
    } else if ( idStr == ID_LOGIN_SUCCESS ) {
        toClientDashboard();
    } else if ( idStr == ID_REGISTER_SUCCESS ) {
        toClientDashboard();
    }
}

QString ClientDashboard::fileSizeString(int size) {
    if ( size > 1024 * 1024 * 1024 )
        return QString::number(qRound(size / 102.4 / 1024 / 1024)/10.0) + " GBytes";
    if ( size > 1024 * 1024 )
        return QString::number(qRound(size / 102.4  / 1024)/10.0 ) + " MBytes";
    if ( size > 1024 )
        return QString::number(qRound(size / 102.4 )/10.0) + " KBytes";
    return QString::number(size) + " Bytes";
}

QByteArray ClientDashboard::fillHeader(QByteArray in) {
    if ( in.length() < MAXLEN_OF_HEADER ) {
        in += QByteArray(MAXLEN_OF_HEADER-in.length(), ' ');
    }
    return in;
}

void ClientDashboard::refreshFile() {
    matches = fileInfo.search(ui->editSearch->text()) ;
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

void ClientDashboard::sendDownloadFileListRequest() {
    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
     QByteArray datagram = QByteArray() + ID_FILE_LIST_REQ + ":;" + res.toLocal8Bit() + ":;";
     datagram = fillHeader(datagram) ;
     udpSocket->writeDatagram(datagram.data(), datagram.size(),
                              QHostAddress(serverAddress), SERVER_PORT);// ***************
}

void ClientDashboard::recvDownloadFileList(QByteArray &info){
    fileInfo.extract(QString::fromLocal8Bit(info));
    ui->editSearch->setText("");
    refreshFile();
}

void ClientDashboard::on_buttonRefresh_clicked()
{
    sendDownloadFileListRequest();
}

QStringList ClientDashboard::getIps() {
    QStringList ipAddresses ;
     QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
     for (int i = 0; i < ipAddressesList.size(); ++i) {
         if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
             ipAddressesList.at(i).toIPv4Address()) {
             ipAddresses.push_back(ipAddressesList.at(i).toString());
         }
     }
//     ipAddresses.clear();
     if ( ipAddresses.size() == 0 )
         ipAddresses.push_back("127.0.0.1");
     return ipAddresses ;
}

void ClientDashboard::on_buttonSearch_clicked()
{
    refreshFile();
}


void ClientDashboard::prepareDownload() {
    downPath = ui->editDownPath->text() ;
    QList<QTableWidgetItem*> tableData = ui->tableFile->selectedItems() ;
    int selectedRow = tableData[0]->row() ;
    downFileId = fileInfo.fileItems[matches[selectedRow]].id ;
    downFilesize = fileInfo.fileItems[matches[selectedRow]].size ;
    downBlockCount = downFilesize % BLOCKSIZE ?
                     downFilesize / BLOCKSIZE + 1 :
                     downFilesize / BLOCKSIZE ;
    downFlgBlock = QVector<bool>(downBlockCount+1, false);
    downMaxBlockNumber = -1;
    lastReceived = QTime::currentTime() ;

//    timer = startTimer(1) ;
}

void ClientDashboard::sendDownloadRequest() {
    prepareDownload();

    status = STATUS_DOWNLOADING ;

    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
     QByteArray datagram = QByteArray() + ID_DOWN_REQ + ":;" + res.toLocal8Bit() + ":;" + downFileId.toLocal8Bit() + ":;";
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);// ***************
}

void ClientDashboard::sendDownloadBlockRequest(int blocknumber) {
    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
     QByteArray datagram = QByteArray() + ID_DOWN_BLOCK_REQ + ":;" + res.toLocal8Bit() + ":;" + QString::number(blocknumber).toLocal8Bit() + ":;";
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);// ***************
}

void ClientDashboard::recvDownloadBlock(int blocknumber, QByteArray data) {
    lastReceived = QTime::currentTime() ;
    if ( blocknumber > downMaxBlockNumber )
        downMaxBlockNumber = blocknumber ;
    QFile file(downPath) ;
    file.open(QIODevice::ReadWrite);
    downFlgBlock[blocknumber] = true ;
    file.seek(blocknumber*BLOCKSIZE) ;
    file.write(data) ;
    file.close();
}

void ClientDashboard::timerEvent(QTimerEvent *e){
    if ( lastReceived.msecsTo(QTime::currentTime()) >= 10 ) {
        QStringList list ;
        int recvCount = 0 ;
        for ( int i = 0 ; i < downBlockCount ; i ++ ) {
            if ( !downFlgBlock[i] ) {
                list.push_back(QString::number(i));
            }  else
                recvCount ++ ;
        }
        int progressValue = recvCount * 100 / downBlockCount ;
        if ( list.size() == 0 ) {
            killTimer(timer);
            QMessageBox::warning(this,"success","download finished") ;
        } else {
            if ( list.size() > 1000 )
                list = list.mid(0,1000);
            sendDownloadBlockListRequest(list);
        }
        lastReceived = QTime::currentTime();
    }
}

void ClientDashboard::on_buttonDownBrowse_clicked()
{
    if ( ui->tableFile->selectedItems().size() != 1 ) return ;
    QString saveFilePath = QFileDialog::getSaveFileName(this,
                                                        "Save",
                                                        fileInfo.fileItems[matches[ui->tableFile->selectedItems()[0]->row()]].name);
    ui->editDownPath->setText(saveFilePath);
}

void ClientDashboard::on_buttonDownload_clicked()
{
    if ( ui->editDownPath->text().length() == 0 ) {
        ui->labelStatus->setText("Browse file to save");
        return ;
    }
    if ( ui->tableFile->selectedItems().size() != 1 ) {
        ui->labelStatus->setText("Select a file to download");
        return ;
    }
    ui->labelStatus->setText("Downloading started");
    destPath = ui->editDownPath->text() ;
    server->destPath = &destPath ;
    sendDownloadRequest();
}

void ClientDashboard::sendDownloadBlockListRequest(QStringList list) {
    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
    QByteArray datagram = QByteArray() + ID_DOWN_BLOCK_LIST_REQ + ":;" + res.toLocal8Bit() + ":;" + list.join("***").toLocal8Bit() + ":;";
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);// ***************
}


void ClientDashboard::on_buttonUpBrowse_clicked()
{
    QString tpath = QFileDialog::getOpenFileName(this,
                                                 "Open",
                                                 "");
    ui->editUpPath->setText(tpath);
}

void ClientDashboard::startUpload() {
    if ( client().send(serverAddress, TCP_SERVER_PORT, ui->editUpPath->text() , ui->editUpFilename->text(), username ) ) {
        ui->labelStatus->setText("Uploading is finished");
    }else {
        ui->labelStatus->setText("Server is not working");
    }
}

void ClientDashboard::on_buttonUpload_clicked()
{
    if ( ui->editUpPath->text().length() == 0 ) {
        ui->labelStatus->setText("Browse file for uploading");
        return;
    }
    if ( ui->editUpFilename->text().length() == 0 ) {
        ui->labelStatus->setText("Input filename to be displayed in server");
        return ;
    }
    ui->labelStatus->setText("Uploading started");

    QTimer::singleShot(10, this, SLOT(startUpload()));
}

void ClientDashboard::sendUploadRequest() {
    upFilepath = ui->editUpPath->text() ;
    int tsize = QFileInfo(upFilepath).size() ;
    downBlockCount = tsize % BLOCKSIZE ?
                         tsize / BLOCKSIZE + 1:
                         tsize / BLOCKSIZE ;

    QStringList ipAddresses = getIps() ;
    QString res ;
     for ( int i = 0 ; i < ipAddresses.size() ; i ++ ) {
         res += ipAddresses[i] ;
         if ( i < ipAddresses.size() - 1 )
             res += ";@;" ;
     }
    QByteArray datagram = QByteArray() + ID_UPLOAD_REQ + ":;" + res.toLocal8Bit() + ":;" + ui->editUpFilename->text().toLocal8Bit() + ":;"
                          + username.toLocal8Bit() + ":;"
                          + QString::number(tsize).toLocal8Bit() + ":;";
    datagram = fillHeader(datagram) ;
    udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress(serverAddress), SERVER_PORT);// ***************
}

void ClientDashboard::sendDownload() {
    for ( int i = 0 ; i < downBlockCount ; i ++ ) {
        sendDownloadBlock(i);
    }
}

void ClientDashboard::sendDownloadBlock(int blocknumber){
    QFile file(upFilepath) ;
    file.open(QIODevice::ReadOnly) ;
    if ( file.isOpen() ) {
        file.seek((blocknumber)*BLOCKSIZE) ;
        QByteArray data = file.read(BLOCKSIZE);
        file.close();
        QByteArray datagram = QByteArray() + ID_UPLOAD_BLOCK  + ":;" +
                              QString::number(blocknumber).toLocal8Bit() + ":;";
        datagram = fillHeader(datagram) ;
        datagram += data ;
        udpSocket->writeDatagram(datagram.data(), datagram.size(),
                                 QHostAddress(serverAddress), SERVER_PORT);// ***************
    }
}

void ClientDashboard::recvDownloadBlockList(QString numbers) {
    QStringList numList = numbers.split("***") ;
    qDebug () << numList ;
    for ( int i = 0 ; i < numList.size() ; i ++ ) {
        sendDownloadBlock(numList[i].toInt());
    }
}

void ClientDashboard::recvUploadFinished() {
    sendDownloadFileListRequest();
    QMessageBox::warning(this,
                         "Anouncement",
                         "Uploading finished"
                         );
}

void ClientDashboard::downloadFinished() {
    ui->labelStatus->setText("Download finished");
}

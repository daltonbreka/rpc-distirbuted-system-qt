#include "server.h"

Server::Server()
{
    m_host = QHostAddress(QHostAddress::LocalHost);
    m_port = 21312;
    // your settings init there
}

Server::~Server(){

}

void Server::start()
{
    if ( this->listen(m_host, m_port) )
        qDebug() << "Server started at " << m_host.toString() << ":" << m_port;
    else
        qDebug() << "Can't start server";
}

void Server::start(int port){
    m_port = port ;
    start();
}

void Server::incomingConnection(int handle)
{
    qDebug() << "incomingConnection = " << handle;
    SocketThread *thread = new SocketThread(handle);
    thread->destPath = destPath;
    connect(thread, SIGNAL(downloadFinished()),
            this, SLOT(downloadFinished2()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}

void Server::downloadFinished2() {
    downloadFinished();
}

#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QDebug>
#include "socketthread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server();
    ~Server();

    QString *destPath ;
signals:
    void downloadFinished();

public slots:
    void start();
    void start(int port);

    void downloadFinished2();

protected:
    void incomingConnection(int handle);

private:
    QHostAddress m_host;
    int      m_port;

};

#endif // SERVER_H

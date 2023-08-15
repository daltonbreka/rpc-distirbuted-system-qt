#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>

class SocketThread : public QThread
{
    Q_OBJECT
public:
    SocketThread(int descriptor, QObject *parent = 0);
    ~SocketThread();

    QString *destPath ;

protected:
    void run();

signals:
    void onFinishRecieved();
    void downloadFinished();

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    int     m_socketDescriptor;
    QTcpSocket *m_socket;
    qint32      m_blockSize;
};


#endif // SOCKETTHREAD_H

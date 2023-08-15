#include "client.h"

client::client(QObject *parent) :
    QObject(parent)
{
}

bool client::send(QString m_host, int m_port, QString m_filepath, QString m_filename, QString m_username)
{
    QTcpSocket *socket = new QTcpSocket;

    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));

    // specified m_host and m_port to yours
    socket->connectToHost(QHostAddress(m_host), m_port);
    socket->waitForConnected();

    QFile *m_file = new QFile(m_filepath) ;
    if ( (socket->state() != QAbstractSocket::ConnectedState) || (!m_file->open(QIODevice::ReadOnly)) ) {
        qDebug() << "Socket can't connect or can't open file for transfer";
        delete socket;
        return false;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    // This part i  need to send not only file, but file name too
    // Erase it if you needn't it
    out << (quint32)0 << m_filename << m_username ;

    QByteArray q = m_file->readAll();
    block.append(q);
    m_file->close();

    out.device()->seek(0);
    // This difference appear because of we send file name
    out << (quint32)(block.size() - sizeof(quint32));

    qint64 x = 0;
    while (x < block.size()) {
        qint64 y = socket->write(block);
        x += y;
        //qDebug() << x;    // summary size you send, so you can check recieved and replied sizes
    }
    return true ;
}

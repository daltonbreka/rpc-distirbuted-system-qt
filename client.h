#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    bool send(QString host, int port, QString filepath, QString filename, QString);

signals:

public slots:

};

#endif // CLIENT_H

#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>
#include "login.h"
#include "register.h"
#include "clientdashboard.h"
#include "serverdashboard.h"

namespace Ui {
    class Manage;
}

class Manage : public QWidget
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = 0);
    ~Manage();

    Login *loginWidget;
    Register *registerWidget;
    ClientDashboard *clientWidget;
    ServerDashboard *serverWidget;

public slots:
    void loginClient(QString username, QString password, QString serverIp);
    void loginServer(QString username, QString password);
    void registerClient(QString username, QString password, QString serverIp) ;

    void toRegister() ;
    void toLogin() ;

private:
    Ui::Manage *ui;
};

#endif // MANAGE_H

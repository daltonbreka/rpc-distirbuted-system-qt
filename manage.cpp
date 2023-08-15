#include "manage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manage)
{
    ui->setupUi(this);

    loginWidget = new Login(NULL) ;
    registerWidget = new Register(NULL) ;

    connect(loginWidget, SIGNAL(loginClient(QString,QString,QString)),
            this, SLOT(loginClient(QString,QString,QString)));
    connect(loginWidget, SIGNAL(loginServer(QString,QString)),
            this, SLOT(loginServer(QString,QString)));
    connect(loginWidget, SIGNAL(toRegister()),
            this, SLOT(toRegister()));
    connect(registerWidget, SIGNAL(toLogin()),
            this, SLOT(toLogin()));
    connect(registerWidget, SIGNAL(registerClient(QString,QString,QString)),
            this, SLOT(registerClient(QString,QString,QString)));

    toLogin() ;
}

Manage::~Manage()
{
    delete ui;
}

void Manage::toLogin() {
    loginWidget->show();
    registerWidget->hide();
}

void Manage::toRegister() {
    loginWidget->hide();
    registerWidget->show();
}

void Manage::loginClient(QString username, QString password, QString serverIp){
    qDebug() << "loginClient" ;
}

void Manage::registerClient(QString username, QString password, QString serverIp) {
    qDebug() << "registerClient" ;
}

void Manage::loginServer(QString username, QString password){
    qDebug() << "loginServer" ;
}

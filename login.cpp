#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    move(400,200);
    setWindowTitle("Login");
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonLogin_clicked()
{
    QString username = ui->editUsername->text() ;
    QString password = ui->editPassword->text() ;
    QString serverIp = ui->editServer->text() ;
    if ( username.length() == 0 ) return ;
    if ( password.length() == 0 ) return ;
    if ( serverIp.length() == 0 ) return ;
    loginClient(username, password, serverIp);
}

void Login::on_buttonRegister_clicked()
{
    toRegister();
}

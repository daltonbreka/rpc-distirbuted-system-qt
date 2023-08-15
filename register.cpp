#include "register.h"
#include "ui_register.h"
#include <QDebug>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    move(400,200);
    setWindowTitle("Register");
}

Register::~Register()
{
    delete ui;
}

void Register::on_buttonRegister_clicked()
{
    QString username = ui->editUsername->text() ;
    QString password = ui->editPassword->text() ;
    QString confirm = ui->editConfirm->text() ;
    if ( username.length() == 0 ) return ;
    if ( password.length() == 0 ) return ;
    if ( confirm.length() == 0 ) return ;
    if ( password != confirm ) return ;
    if ( !Share().ipIsValid(ui->editServerIp->text()) )
        return ;
    registerClient(username, password, ui->editServerIp->text()) ;
}

void Register::on_buttonLogin_clicked()
{
     toLogin();
}

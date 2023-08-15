#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>

#include "share.h"

namespace Ui {
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private:
    Ui::Login *ui;

private slots:
    void on_buttonRegister_clicked();
    void on_buttonLogin_clicked();

signals:
    void loginClient(QString,QString,QString);
    void toRegister() ;
};

#endif // LOGIN_H

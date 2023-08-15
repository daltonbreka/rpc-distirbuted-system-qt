#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "share.h"

namespace Ui {
    class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private:
    Ui::Register *ui;

signals:
    void toLogin();
    void registerClient(QString, QString, QString);

private slots:

private slots:
    void on_buttonLogin_clicked();
    void on_buttonRegister_clicked();
};

#endif // REGISTER_H

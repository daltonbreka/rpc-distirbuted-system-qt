/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Wed Jul 19 17:12:52 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *editUsername;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *editPassword;
    QPushButton *buttonLogin;
    QLineEdit *editServer;
    QLabel *label_3;
    QPushButton *buttonRegister;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 600);
        Login->setStyleSheet(QString::fromUtf8("background-color: \"white\";"));
        editUsername = new QLineEdit(Login);
        editUsername->setObjectName(QString::fromUtf8("editUsername"));
        editUsername->setGeometry(QRect(130, 265, 191, 41));
        editUsername->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 265, 41, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/user);"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 328, 41, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/password);"));
        editPassword = new QLineEdit(Login);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setGeometry(QRect(130, 325, 191, 41));
        editPassword->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        editPassword->setEchoMode(QLineEdit::Password);
        buttonLogin = new QPushButton(Login);
        buttonLogin->setObjectName(QString::fromUtf8("buttonLogin"));
        buttonLogin->setGeometry(QRect(100, 490, 201, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gadugi"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        buttonLogin->setFont(font1);
        buttonLogin->setStyleSheet(QString::fromUtf8("#buttonLogin{\n"
"border-radius: 13px;\n"
"border-width: 3px;\n"
"background-color: rgb(224, 226, 226);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"}\n"
"#buttonLogin:hover{\n"
"background-color: rgb(244, 244, 244);\n"
"}"));
        editServer = new QLineEdit(Login);
        editServer->setObjectName(QString::fromUtf8("editServer"));
        editServer->setEnabled(true);
        editServer->setGeometry(QRect(130, 380, 191, 41));
        editServer->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        editServer->setEchoMode(QLineEdit::Normal);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(75, 385, 31, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/server);"));
        buttonRegister = new QPushButton(Login);
        buttonRegister->setObjectName(QString::fromUtf8("buttonRegister"));
        buttonRegister->setGeometry(QRect(260, 540, 71, 41));
        QFont font2;
        font2.setPointSize(11);
        buttonRegister->setFont(font2);
        buttonRegister->setStyleSheet(QString::fromUtf8("#buttonRegister{\n"
"color: rgb(0, 85, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"}\n"
"#buttonRegister:hover{\n"
"color: rgb(0,0,255);\n"
"}"));
        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 80, 271, 111));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI Black"));
        font3.setPointSize(40);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(10);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("font: 87 40pt \"Segoe UI Black\";"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 230, 341, 16));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/diff);"));
        label_6 = new QLabel(Login);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 450, 341, 16));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/diff);"));
        label_7 = new QLabel(Login);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 550, 171, 21));
        QFont font4;
        font4.setPointSize(13);
        label_7->setFont(font4);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0, QApplication::UnicodeUTF8));
        editUsername->setText(QApplication::translate("Login", "Username", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        editPassword->setText(QApplication::translate("Login", "Password", 0, QApplication::UnicodeUTF8));
        buttonLogin->setText(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        editServer->setText(QApplication::translate("Login", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        buttonRegister->setText(QApplication::translate("Login", "Register", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login", "Welcome!", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QApplication::translate("Login", "Don't have an account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

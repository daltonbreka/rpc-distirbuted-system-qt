/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created: Wed Jul 19 17:12:52 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QPushButton *buttonRegister;
    QPushButton *buttonLogin;
    QLineEdit *editUsername;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *editPassword;
    QLabel *label_7;
    QLineEdit *editServerIp;
    QLabel *label_8;
    QLineEdit *editConfirm;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(400, 649);
        Register->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 318, 41, 31));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/password);"));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 255, 41, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/user);"));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 220, 341, 16));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/diff);"));
        buttonRegister = new QPushButton(Register);
        buttonRegister->setObjectName(QString::fromUtf8("buttonRegister"));
        buttonRegister->setGeometry(QRect(100, 530, 201, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gadugi"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        buttonRegister->setFont(font1);
        buttonRegister->setStyleSheet(QString::fromUtf8("#buttonRegister{\n"
"border-radius: 13px;\n"
"border-width: 3px;\n"
"background-color: rgb(224, 226, 226);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;\n"
"}\n"
"#buttonRegister:hover{\n"
"background-color: rgb(244, 244, 244);\n"
"}"));
        buttonLogin = new QPushButton(Register);
        buttonLogin->setObjectName(QString::fromUtf8("buttonLogin"));
        buttonLogin->setGeometry(QRect(260, 580, 71, 41));
        QFont font2;
        font2.setPointSize(11);
        buttonLogin->setFont(font2);
        buttonLogin->setStyleSheet(QString::fromUtf8("#buttonLogin{\n"
"color: rgb(0, 85, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"border: none;\n"
"}\n"
"#buttonLogin:hover{\n"
"color: rgb(0,0,255);\n"
"}"));
        editUsername = new QLineEdit(Register);
        editUsername->setObjectName(QString::fromUtf8("editUsername"));
        editUsername->setGeometry(QRect(130, 255, 191, 41));
        editUsername->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(75, 435, 31, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/server);"));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 490, 341, 16));
        label_6->setStyleSheet(QString::fromUtf8("border-image: url(:/diff);"));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 70, 271, 111));
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
        editPassword = new QLineEdit(Register);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setGeometry(QRect(130, 315, 191, 41));
        editPassword->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        editPassword->setEchoMode(QLineEdit::Password);
        label_7 = new QLabel(Register);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 590, 171, 21));
        QFont font4;
        font4.setPointSize(13);
        label_7->setFont(font4);
        editServerIp = new QLineEdit(Register);
        editServerIp->setObjectName(QString::fromUtf8("editServerIp"));
        editServerIp->setEnabled(true);
        editServerIp->setGeometry(QRect(130, 430, 191, 41));
        editServerIp->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        editServerIp->setEchoMode(QLineEdit::Normal);
        label_8 = new QLabel(Register);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 370, 41, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/password);"));
        editConfirm = new QLineEdit(Register);
        editConfirm->setObjectName(QString::fromUtf8("editConfirm"));
        editConfirm->setGeometry(QRect(130, 370, 191, 41));
        editConfirm->setStyleSheet(QString::fromUtf8("border-radius: 13px;\n"
"background-color: rgb(234, 234, 234);\n"
"text-align: center;\n"
"font-size: 20px;\n"
"font: 14pt \"Gadugi\";\n"
"padding-left: 10px;\n"
"padding-right: 10px;"));
        editConfirm->setEchoMode(QLineEdit::Password);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label->setText(QString());
        label_5->setText(QString());
        buttonRegister->setText(QApplication::translate("Register", "Register", 0, QApplication::UnicodeUTF8));
        buttonLogin->setText(QApplication::translate("Register", "Login", 0, QApplication::UnicodeUTF8));
        editUsername->setText(QApplication::translate("Register", "Username", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_6->setText(QString());
        label_4->setText(QApplication::translate("Register", "Welcome!", 0, QApplication::UnicodeUTF8));
        editPassword->setText(QApplication::translate("Register", "Password", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Register", "Have you an account", 0, QApplication::UnicodeUTF8));
        editServerIp->setText(QApplication::translate("Register", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        editConfirm->setText(QApplication::translate("Register", "Password", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

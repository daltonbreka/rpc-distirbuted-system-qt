/********************************************************************************
** Form generated from reading UI file 'serverdashboard.ui'
**
** Created: Mon Jul 17 15:25:35 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDASHBOARD_H
#define UI_SERVERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerDashboard
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *buttonSearchFile;
    QLabel *label;
    QTableWidget *tableFile;
    QLabel *label_2;
    QPushButton *buttonDeleteFile;
    QLineEdit *editSearchFile;
    QPushButton *buttonRefreshFile;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab_2;
    QPushButton *buttonRefreshUser;
    QTableWidget *tableUser;
    QPushButton *buttonDeleteUser;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_3;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_5;

    void setupUi(QWidget *ServerDashboard)
    {
        if (ServerDashboard->objectName().isEmpty())
            ServerDashboard->setObjectName(QString::fromUtf8("ServerDashboard"));
        ServerDashboard->resize(883, 769);
        ServerDashboard->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tabWidget = new QTabWidget(ServerDashboard);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 130, 861, 621));
        tabWidget->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(240, 241, 241);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        buttonSearchFile = new QPushButton(tab);
        buttonSearchFile->setObjectName(QString::fromUtf8("buttonSearchFile"));
        buttonSearchFile->setGeometry(QRect(720, 470, 121, 41));
        buttonSearchFile->setStyleSheet(QString::fromUtf8("#buttonSearchFile{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonSearchFile:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 31, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/filelist);"));
        tableFile = new QTableWidget(tab);
        if (tableFile->columnCount() < 4)
            tableFile->setColumnCount(4);
        QFont font1;
        font1.setPointSize(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableFile->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableFile->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableFile->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableFile->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableFile->setObjectName(QString::fromUtf8("tableFile"));
        tableFile->setGeometry(QRect(20, 70, 821, 321));
        tableFile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"QTableWidgetItem{\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
"}"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 400, 101, 51));
        label_2->setFont(font);
        buttonDeleteFile = new QPushButton(tab);
        buttonDeleteFile->setObjectName(QString::fromUtf8("buttonDeleteFile"));
        buttonDeleteFile->setGeometry(QRect(210, 530, 181, 41));
        buttonDeleteFile->setStyleSheet(QString::fromUtf8("#buttonDeleteFile{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonDeleteFile:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        editSearchFile = new QLineEdit(tab);
        editSearchFile->setObjectName(QString::fromUtf8("editSearchFile"));
        editSearchFile->setGeometry(QRect(30, 470, 671, 41));
        editSearchFile->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 20px;\n"
"padding-left: 20px;\n"
"padding-right: 20px;"));
        buttonRefreshFile = new QPushButton(tab);
        buttonRefreshFile->setObjectName(QString::fromUtf8("buttonRefreshFile"));
        buttonRefreshFile->setGeometry(QRect(470, 530, 181, 41));
        buttonRefreshFile->setStyleSheet(QString::fromUtf8("#buttonRefreshFile{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonRefreshFile:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 20, 121, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 55, 151, 5));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 450, 151, 5));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 400, 41, 51));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/control);"));
        tabWidget->addTab(tab, QString());
        buttonSearchFile->raise();
        label->raise();
        tableFile->raise();
        label_2->raise();
        buttonDeleteFile->raise();
        editSearchFile->raise();
        buttonRefreshFile->raise();
        label_6->raise();
        label_7->raise();
        label_9->raise();
        label_8->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        buttonRefreshUser = new QPushButton(tab_2);
        buttonRefreshUser->setObjectName(QString::fromUtf8("buttonRefreshUser"));
        buttonRefreshUser->setGeometry(QRect(460, 480, 191, 41));
        buttonRefreshUser->setStyleSheet(QString::fromUtf8("#buttonRefreshUser{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonRefreshUser:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        tableUser = new QTableWidget(tab_2);
        if (tableUser->columnCount() < 2)
            tableUser->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableUser->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableUser->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableUser->setObjectName(QString::fromUtf8("tableUser"));
        tableUser->setGeometry(QRect(20, 70, 821, 321));
        tableUser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buttonDeleteUser = new QPushButton(tab_2);
        buttonDeleteUser->setObjectName(QString::fromUtf8("buttonDeleteUser"));
        buttonDeleteUser->setGeometry(QRect(150, 480, 191, 41));
        buttonDeleteUser->setStyleSheet(QString::fromUtf8("#buttonDeleteUser{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonDeleteUser:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 20, 31, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/filelist);"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 55, 151, 5));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(90, 20, 121, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 400, 101, 51));
        label_3->setFont(font);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(50, 400, 41, 51));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/control);"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(40, 450, 151, 5));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        tabWidget->addTab(tab_2, QString());
        label_5 = new QLabel(ServerDashboard);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 30, 641, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI Black"));
        font2.setPointSize(40);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(10);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("font: 87 40pt \"Segoe UI Black\";"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignCenter);

        retranslateUi(ServerDashboard);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ServerDashboard);
    } // setupUi

    void retranslateUi(QWidget *ServerDashboard)
    {
        ServerDashboard->setWindowTitle(QApplication::translate("ServerDashboard", "Form", 0, QApplication::UnicodeUTF8));
        buttonSearchFile->setText(QApplication::translate("ServerDashboard", "Search", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableFile->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ServerDashboard", "File Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableFile->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ServerDashboard", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableFile->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ServerDashboard", "Upload Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableFile->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ServerDashboard", "File Size", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerDashboard", "Control", 0, QApplication::UnicodeUTF8));
        buttonDeleteFile->setText(QApplication::translate("ServerDashboard", "Delete", 0, QApplication::UnicodeUTF8));
        buttonRefreshFile->setText(QApplication::translate("ServerDashboard", "Refresh", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ServerDashboard", "File Table", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ServerDashboard", "Tab 1", 0, QApplication::UnicodeUTF8));
        buttonRefreshUser->setText(QApplication::translate("ServerDashboard", "Refresh", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableUser->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("ServerDashboard", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableUser->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("ServerDashboard", "Password", 0, QApplication::UnicodeUTF8));
        buttonDeleteUser->setText(QApplication::translate("ServerDashboard", "Delete", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QApplication::translate("ServerDashboard", "User Table", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ServerDashboard", "Control", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        label_14->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ServerDashboard", "Tab 2", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ServerDashboard", "RPC SERVER", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerDashboard: public Ui_ServerDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDASHBOARD_H

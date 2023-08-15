/********************************************************************************
** Form generated from reading UI file 'clientdashboard.ui'
**
** Created: Wed Jul 19 17:12:52 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDASHBOARD_H
#define UI_CLIENTDASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDashboard
{
public:
    QTableWidget *tableFile;
    QLineEdit *editDownPath;
    QPushButton *buttonDownBrowse;
    QPushButton *buttonDownload;
    QLineEdit *editUpFilename;
    QPushButton *buttonUpBrowse;
    QLineEdit *editUpPath;
    QPushButton *buttonUpload;
    QLabel *label_3;
    QLineEdit *editSearch;
    QPushButton *buttonSearch;
    QPushButton *buttonRefresh;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_7;
    QLabel *label_18;
    QLabel *labelStatus;

    void setupUi(QWidget *ClientDashboard)
    {
        if (ClientDashboard->objectName().isEmpty())
            ClientDashboard->setObjectName(QString::fromUtf8("ClientDashboard"));
        ClientDashboard->resize(861, 734);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ClientDashboard->setFont(font);
        ClientDashboard->setStyleSheet(QString::fromUtf8("font: 16pt \"MS Shell Dlg 2\";"));
        tableFile = new QTableWidget(ClientDashboard);
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
        tableFile->setGeometry(QRect(30, 70, 801, 261));
        editDownPath = new QLineEdit(ClientDashboard);
        editDownPath->setObjectName(QString::fromUtf8("editDownPath"));
        editDownPath->setGeometry(QRect(70, 500, 201, 41));
        editDownPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); \n"
"border-radius: 20px;\n"
"padding-left: 20px;\n"
"padding-right: 20px;"));
        editDownPath->setReadOnly(true);
        buttonDownBrowse = new QPushButton(ClientDashboard);
        buttonDownBrowse->setObjectName(QString::fromUtf8("buttonDownBrowse"));
        buttonDownBrowse->setGeometry(QRect(280, 500, 111, 41));
        buttonDownBrowse->setStyleSheet(QString::fromUtf8("#buttonDownBrowse{ \n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonDownBrowse:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        buttonDownload = new QPushButton(ClientDashboard);
        buttonDownload->setObjectName(QString::fromUtf8("buttonDownload"));
        buttonDownload->setGeometry(QRect(70, 560, 321, 41));
        buttonDownload->setStyleSheet(QString::fromUtf8("#buttonDownload{ \n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonDownload:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        editUpFilename = new QLineEdit(ClientDashboard);
        editUpFilename->setObjectName(QString::fromUtf8("editUpFilename"));
        editUpFilename->setGeometry(QRect(480, 560, 171, 41));
        editUpFilename->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); \n"
"border-radius: 20px;\n"
"padding-left: 20px;\n"
"padding-right: 20px;"));
        buttonUpBrowse = new QPushButton(ClientDashboard);
        buttonUpBrowse->setObjectName(QString::fromUtf8("buttonUpBrowse"));
        buttonUpBrowse->setGeometry(QRect(670, 500, 101, 41));
        buttonUpBrowse->setStyleSheet(QString::fromUtf8("#buttonUpBrowse{ \n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonUpBrowse:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        editUpPath = new QLineEdit(ClientDashboard);
        editUpPath->setObjectName(QString::fromUtf8("editUpPath"));
        editUpPath->setGeometry(QRect(480, 500, 171, 41));
        editUpPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); \n"
"border-radius: 20px;\n"
"padding-left: 20px;\n"
"padding-right: 20px;"));
        editUpPath->setReadOnly(true);
        buttonUpload = new QPushButton(ClientDashboard);
        buttonUpload->setObjectName(QString::fromUtf8("buttonUpload"));
        buttonUpload->setGeometry(QRect(480, 620, 291, 41));
        buttonUpload->setStyleSheet(QString::fromUtf8("#buttonUpload{\n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonUpload:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        label_3 = new QLabel(ClientDashboard);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(710, 570, 61, 31));
        editSearch = new QLineEdit(ClientDashboard);
        editSearch->setObjectName(QString::fromUtf8("editSearch"));
        editSearch->setGeometry(QRect(30, 400, 491, 41));
        editSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); \n"
"border-radius: 20px;\n"
"padding-left: 20px;\n"
"padding-right: 20px;"));
        buttonSearch = new QPushButton(ClientDashboard);
        buttonSearch->setObjectName(QString::fromUtf8("buttonSearch"));
        buttonSearch->setGeometry(QRect(550, 400, 111, 41));
        buttonSearch->setStyleSheet(QString::fromUtf8("#buttonSearch{ \n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonSearch:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        buttonRefresh = new QPushButton(ClientDashboard);
        buttonRefresh->setObjectName(QString::fromUtf8("buttonRefresh"));
        buttonRefresh->setGeometry(QRect(690, 400, 121, 41));
        buttonRefresh->setStyleSheet(QString::fromUtf8("#buttonRefresh{ \n"
"border-radius: 20%;\n"
"background-color: white;\n"
"}\n"
"#buttonRefresh:hover{\n"
"border-radius: 20%;\n"
"background-color: rgb(177,177,177);\n"
"}\n"
""));
        label_10 = new QLabel(ClientDashboard);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(80, 15, 31, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/filelist);"));
        label_12 = new QLabel(ClientDashboard);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 15, 121, 31));
        label_11 = new QLabel(ClientDashboard);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 50, 151, 5));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_14 = new QLabel(ClientDashboard);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(60, 380, 151, 5));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_13 = new QLabel(ClientDashboard);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(70, 330, 41, 51));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("border-image: url(:/control);"));
        label_4 = new QLabel(ClientDashboard);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 330, 101, 51));
        label_4->setFont(font);
        label_5 = new QLabel(ClientDashboard);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(670, 570, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/file);"));
        label_6 = new QLabel(ClientDashboard);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 440, 101, 51));
        label_6->setFont(font);
        label_15 = new QLabel(ClientDashboard);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(70, 450, 41, 31));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("border-image: url(:/download);"));
        label_16 = new QLabel(ClientDashboard);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(60, 485, 168, 5));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_17 = new QLabel(ClientDashboard);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(470, 450, 41, 31));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("border-image: url(:/upload);"));
        label_7 = new QLabel(ClientDashboard);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 440, 101, 51));
        label_7->setFont(font);
        label_18 = new QLabel(ClientDashboard);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(460, 485, 151, 5));
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        labelStatus = new QLabel(ClientDashboard);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(10, 700, 831, 31));

        retranslateUi(ClientDashboard);

        QMetaObject::connectSlotsByName(ClientDashboard);
    } // setupUi

    void retranslateUi(QWidget *ClientDashboard)
    {
        ClientDashboard->setWindowTitle(QApplication::translate("ClientDashboard", "ClientDashboard", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableFile->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ClientDashboard", "File Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableFile->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ClientDashboard", "Username", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableFile->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ClientDashboard", "Upload Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableFile->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ClientDashboard", "File Size", 0, QApplication::UnicodeUTF8));
        buttonDownBrowse->setText(QApplication::translate("ClientDashboard", "Browse", 0, QApplication::UnicodeUTF8));
        buttonDownload->setText(QApplication::translate("ClientDashboard", "Download", 0, QApplication::UnicodeUTF8));
        buttonUpBrowse->setText(QApplication::translate("ClientDashboard", "Browse", 0, QApplication::UnicodeUTF8));
        buttonUpload->setText(QApplication::translate("ClientDashboard", "Upload", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClientDashboard", "name", 0, QApplication::UnicodeUTF8));
        buttonSearch->setText(QApplication::translate("ClientDashboard", "Search", 0, QApplication::UnicodeUTF8));
        buttonRefresh->setText(QApplication::translate("ClientDashboard", "Refresh", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        label_12->setText(QApplication::translate("ClientDashboard", "User Table", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_14->setText(QString());
        label_13->setText(QString());
        label_4->setText(QApplication::translate("ClientDashboard", "Control", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("ClientDashboard", "Download", 0, QApplication::UnicodeUTF8));
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_7->setText(QApplication::translate("ClientDashboard", "Upload", 0, QApplication::UnicodeUTF8));
        label_18->setText(QString());
        labelStatus->setText(QApplication::translate("ClientDashboard", "Status...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientDashboard: public Ui_ClientDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDASHBOARD_H

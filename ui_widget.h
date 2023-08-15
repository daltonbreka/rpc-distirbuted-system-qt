/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Jul 6 23:14:32 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelWelcome;
    QPushButton *buttonLogout;
    QPushButton *buttonSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(679, 455);
        labelWelcome = new QLabel(Widget);
        labelWelcome->setObjectName(QString::fromUtf8("labelWelcome"));
        labelWelcome->setGeometry(QRect(80, 130, 511, 81));
        QFont font;
        font.setPointSize(18);
        labelWelcome->setFont(font);
        buttonLogout = new QPushButton(Widget);
        buttonLogout->setObjectName(QString::fromUtf8("buttonLogout"));
        buttonLogout->setGeometry(QRect(240, 300, 201, 51));
        QFont font1;
        font1.setPointSize(16);
        buttonLogout->setFont(font1);
        buttonSend = new QPushButton(Widget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setGeometry(QRect(250, 40, 141, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        labelWelcome->setText(QApplication::translate("Widget", "Welcome, ", 0, QApplication::UnicodeUTF8));
        buttonLogout->setText(QApplication::translate("Widget", "Log out", 0, QApplication::UnicodeUTF8));
        buttonSend->setText(QApplication::translate("Widget", "Send Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

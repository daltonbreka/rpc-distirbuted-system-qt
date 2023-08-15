/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created: Wed Jul 19 17:12:52 2023
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manage
{
public:

    void setupUi(QWidget *Manage)
    {
        if (Manage->objectName().isEmpty())
            Manage->setObjectName(QString::fromUtf8("Manage"));
        Manage->resize(614, 381);

        retranslateUi(Manage);

        QMetaObject::connectSlotsByName(Manage);
    } // setupUi

    void retranslateUi(QWidget *Manage)
    {
        Manage->setWindowTitle(QApplication::translate("Manage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Manage: public Ui_Manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H

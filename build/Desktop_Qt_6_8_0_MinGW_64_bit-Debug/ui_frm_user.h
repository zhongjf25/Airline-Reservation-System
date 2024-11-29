/********************************************************************************
** Form generated from reading UI file 'frm_user.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_USER_H
#define UI_FRM_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_User
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Frm_User)
    {
        if (Frm_User->objectName().isEmpty())
            Frm_User->setObjectName("Frm_User");
        Frm_User->resize(800, 600);
        centralwidget = new QWidget(Frm_User);
        centralwidget->setObjectName("centralwidget");
        Frm_User->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frm_User);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Frm_User->setMenuBar(menubar);
        statusbar = new QStatusBar(Frm_User);
        statusbar->setObjectName("statusbar");
        Frm_User->setStatusBar(statusbar);

        retranslateUi(Frm_User);

        QMetaObject::connectSlotsByName(Frm_User);
    } // setupUi

    void retranslateUi(QMainWindow *Frm_User)
    {
        Frm_User->setWindowTitle(QCoreApplication::translate("Frm_User", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_User: public Ui_Frm_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_USER_H

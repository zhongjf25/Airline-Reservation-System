/********************************************************************************
** Form generated from reading UI file 'frm_admin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_ADMIN_H
#define UI_FRM_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Admin
{
public:
    QWidget *centralwidget;
    QPushButton *btn_Logout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Frm_Admin)
    {
        if (Frm_Admin->objectName().isEmpty())
            Frm_Admin->setObjectName("Frm_Admin");
        Frm_Admin->resize(800, 600);
        centralwidget = new QWidget(Frm_Admin);
        centralwidget->setObjectName("centralwidget");
        btn_Logout = new QPushButton(centralwidget);
        btn_Logout->setObjectName("btn_Logout");
        btn_Logout->setGeometry(QRect(210, 290, 75, 24));
        Frm_Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frm_Admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Frm_Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Frm_Admin);
        statusbar->setObjectName("statusbar");
        Frm_Admin->setStatusBar(statusbar);

        retranslateUi(Frm_Admin);

        QMetaObject::connectSlotsByName(Frm_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Frm_Admin)
    {
        Frm_Admin->setWindowTitle(QCoreApplication::translate("Frm_Admin", "MainWindow", nullptr));
        btn_Logout->setText(QCoreApplication::translate("Frm_Admin", "\347\231\273\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Admin: public Ui_Frm_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_ADMIN_H

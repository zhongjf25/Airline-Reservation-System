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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Admin
{
public:
    QAction *act_exit;
    QAction *act_logout;
    QWidget *centralwidget;
    QPushButton *btn_add;
    QPushButton *btn_delete;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menu_S;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Frm_Admin)
    {
        if (Frm_Admin->objectName().isEmpty())
            Frm_Admin->setObjectName("Frm_Admin");
        Frm_Admin->resize(1200, 800);
        act_exit = new QAction(Frm_Admin);
        act_exit->setObjectName("act_exit");
        act_logout = new QAction(Frm_Admin);
        act_logout->setObjectName("act_logout");
        centralwidget = new QWidget(Frm_Admin);
        centralwidget->setObjectName("centralwidget");
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(970, 10, 92, 28));
        btn_delete = new QPushButton(centralwidget);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setGeometry(QRect(1080, 10, 92, 28));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(15, 80, 181, 671));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(210, 80, 951, 671));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        Frm_Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frm_Admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 17));
        menu_S = new QMenu(menubar);
        menu_S->setObjectName("menu_S");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        Frm_Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Frm_Admin);
        statusbar->setObjectName("statusbar");
        Frm_Admin->setStatusBar(statusbar);

        menubar->addAction(menu_S->menuAction());
        menubar->addAction(menu->menuAction());
        menu_S->addAction(act_exit);
        menu->addAction(act_logout);

        retranslateUi(Frm_Admin);

        QMetaObject::connectSlotsByName(Frm_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Frm_Admin)
    {
        Frm_Admin->setWindowTitle(QCoreApplication::translate("Frm_Admin", "MainWindow", nullptr));
        act_exit->setText(QCoreApplication::translate("Frm_Admin", "\351\200\200\345\207\272", nullptr));
        act_logout->setText(QCoreApplication::translate("Frm_Admin", "\347\231\273\345\207\272", nullptr));
        btn_add->setText(QCoreApplication::translate("Frm_Admin", "\346\267\273\345\212\240", nullptr));
        btn_delete->setText(QCoreApplication::translate("Frm_Admin", "\345\210\240\351\231\244", nullptr));
        menu_S->setTitle(QCoreApplication::translate("Frm_Admin", "\347\263\273\347\273\237(&S)", nullptr));
        menu->setTitle(QCoreApplication::translate("Frm_Admin", "\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Admin: public Ui_Frm_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_ADMIN_H

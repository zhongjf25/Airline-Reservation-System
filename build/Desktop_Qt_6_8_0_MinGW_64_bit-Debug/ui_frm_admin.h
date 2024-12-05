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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLineEdit>
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
    QPushButton *btn_search;
    QPushButton *btn_delete;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLineEdit *lineEdit_flightNumber;
    QLineEdit *lineEdit_flightCompany;
    QLineEdit *lineEdit_departure;
    QLineEdit *lineEdit_destination;
    QLineEdit *lineEdit_deleteId;
    QDateEdit *dateEdit_departureDate;
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
        btn_add->setGeometry(QRect(840, 10, 92, 28));
        btn_search = new QPushButton(centralwidget);
        btn_search->setObjectName("btn_search");
        btn_search->setGeometry(QRect(945, 10, 92, 28));
        btn_delete = new QPushButton(centralwidget);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setGeometry(QRect(840, 40, 92, 28));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(15, 80, 181, 671));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(230, 80, 951, 671));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        lineEdit_flightNumber = new QLineEdit(centralwidget);
        lineEdit_flightNumber->setObjectName("lineEdit_flightNumber");
        lineEdit_flightNumber->setGeometry(QRect(15, 10, 150, 28));
        lineEdit_flightCompany = new QLineEdit(centralwidget);
        lineEdit_flightCompany->setObjectName("lineEdit_flightCompany");
        lineEdit_flightCompany->setGeometry(QRect(180, 10, 150, 28));
        lineEdit_departure = new QLineEdit(centralwidget);
        lineEdit_departure->setObjectName("lineEdit_departure");
        lineEdit_departure->setGeometry(QRect(345, 10, 150, 28));
        lineEdit_destination = new QLineEdit(centralwidget);
        lineEdit_destination->setObjectName("lineEdit_destination");
        lineEdit_destination->setGeometry(QRect(510, 10, 150, 28));
        lineEdit_deleteId = new QLineEdit(centralwidget);
        lineEdit_deleteId->setObjectName("lineEdit_deleteId");
        lineEdit_deleteId->setGeometry(QRect(675, 40, 150, 28));
        dateEdit_departureDate = new QDateEdit(centralwidget);
        dateEdit_departureDate->setObjectName("dateEdit_departureDate");
        dateEdit_departureDate->setGeometry(QRect(675, 10, 150, 28));
        dateEdit_departureDate->setCalendarPopup(true);
        Frm_Admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frm_Admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 24));
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
        Frm_Admin->setWindowTitle(QCoreApplication::translate("Frm_Admin", "Admin - Flight Information", nullptr));
        act_exit->setText(QCoreApplication::translate("Frm_Admin", "\351\200\200\345\207\272", nullptr));
        act_logout->setText(QCoreApplication::translate("Frm_Admin", "\347\231\273\345\207\272", nullptr));
        btn_add->setText(QCoreApplication::translate("Frm_Admin", "\346\267\273\345\212\240", nullptr));
        btn_search->setText(QCoreApplication::translate("Frm_Admin", "\346\220\234\347\264\242", nullptr));
        btn_delete->setText(QCoreApplication::translate("Frm_Admin", "\345\210\240\351\231\244", nullptr));
        lineEdit_flightNumber->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        lineEdit_flightCompany->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\345\217\270", nullptr));
        lineEdit_departure->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\265\267\351\243\236\345\234\260\347\202\271", nullptr));
        lineEdit_destination->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\347\233\256\347\232\204\345\234\260", nullptr));
        lineEdit_deleteId->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\246\201\345\210\240\351\231\244\347\232\204\350\210\252\347\217\255\347\232\204ID", nullptr));
        menu_S->setTitle(QCoreApplication::translate("Frm_Admin", "\347\263\273\347\273\237(&S)", nullptr));
        menu->setTitle(QCoreApplication::translate("Frm_Admin", "\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Admin: public Ui_Frm_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_ADMIN_H

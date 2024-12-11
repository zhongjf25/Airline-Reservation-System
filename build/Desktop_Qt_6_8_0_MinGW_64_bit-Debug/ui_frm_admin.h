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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Admin
{
public:
    QAction *act_exit;
    QAction *act_logout;
    QWidget *centralwidget;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QLineEdit *lineEdit_addNumber;
    QLineEdit *lineEdit_addCompany;
    QLineEdit *lineEdit_addDeparture;
    QLineEdit *lineEdit_addDestination;
    QDateEdit *dateEdit_addDate;
    QPushButton *btn_add;
    QTimeEdit *timeEdit_Departure_time;
    QTimeEdit *timeEdit_Destination_time;
    QLabel *lbl_Departure_time;
    QLabel *lbl_Destination_time;
    QLineEdit *lineEdit_eco_tickets;
    QLineEdit *lineEdit_eco_price;
    QLineEdit *lineEdit_bus_tickets;
    QLineEdit *lineEdit_fst_tickets;
    QLineEdit *lineEdit_bus_price;
    QLineEdit *lineEdit_fst_price;
    QLabel *lbl_eco;
    QLabel *lbl_bus;
    QLabel *lbl_fst;
    QWidget *page2;
    QPushButton *btn_delete;
    QLineEdit *lineEdit_deleteId;
    QWidget *page3;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_flightNumber;
    QLineEdit *lineEdit_flightCompany;
    QLineEdit *lineEdit_departure;
    QLineEdit *lineEdit_destination;
    QDateEdit *dateEdit_departureDate;
    QPushButton *btn_search;
    QPushButton *btn_reset;
    QPushButton *btn_del;
    QLabel *titile;
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
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(15, 80, 181, 671));
        QFont font;
        font.setPointSize(12);
        listWidget->setFont(font);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(210, 80, 981, 671));
        page1 = new QWidget();
        page1->setObjectName("page1");
        lineEdit_addNumber = new QLineEdit(page1);
        lineEdit_addNumber->setObjectName("lineEdit_addNumber");
        lineEdit_addNumber->setGeometry(QRect(90, 110, 150, 28));
        lineEdit_addCompany = new QLineEdit(page1);
        lineEdit_addCompany->setObjectName("lineEdit_addCompany");
        lineEdit_addCompany->setGeometry(QRect(260, 110, 150, 28));
        lineEdit_addDeparture = new QLineEdit(page1);
        lineEdit_addDeparture->setObjectName("lineEdit_addDeparture");
        lineEdit_addDeparture->setGeometry(QRect(260, 160, 150, 28));
        lineEdit_addDestination = new QLineEdit(page1);
        lineEdit_addDestination->setObjectName("lineEdit_addDestination");
        lineEdit_addDestination->setGeometry(QRect(430, 160, 150, 28));
        dateEdit_addDate = new QDateEdit(page1);
        dateEdit_addDate->setObjectName("dateEdit_addDate");
        dateEdit_addDate->setGeometry(QRect(90, 160, 150, 28));
        dateEdit_addDate->setDateTime(QDateTime(QDate(2024, 11, 30), QTime(0, 0, 0)));
        dateEdit_addDate->setCalendarPopup(true);
        btn_add = new QPushButton(page1);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(630, 260, 92, 28));
        timeEdit_Departure_time = new QTimeEdit(page1);
        timeEdit_Departure_time->setObjectName("timeEdit_Departure_time");
        timeEdit_Departure_time->setGeometry(QRect(100, 250, 118, 22));
        timeEdit_Destination_time = new QTimeEdit(page1);
        timeEdit_Destination_time->setObjectName("timeEdit_Destination_time");
        timeEdit_Destination_time->setGeometry(QRect(270, 250, 118, 22));
        lbl_Departure_time = new QLabel(page1);
        lbl_Departure_time->setObjectName("lbl_Departure_time");
        lbl_Departure_time->setGeometry(QRect(120, 220, 54, 16));
        lbl_Destination_time = new QLabel(page1);
        lbl_Destination_time->setObjectName("lbl_Destination_time");
        lbl_Destination_time->setGeometry(QRect(300, 220, 54, 16));
        lineEdit_eco_tickets = new QLineEdit(page1);
        lineEdit_eco_tickets->setObjectName("lineEdit_eco_tickets");
        lineEdit_eco_tickets->setGeometry(QRect(210, 350, 61, 28));
        lineEdit_eco_price = new QLineEdit(page1);
        lineEdit_eco_price->setObjectName("lineEdit_eco_price");
        lineEdit_eco_price->setGeometry(QRect(330, 350, 61, 28));
        lineEdit_bus_tickets = new QLineEdit(page1);
        lineEdit_bus_tickets->setObjectName("lineEdit_bus_tickets");
        lineEdit_bus_tickets->setGeometry(QRect(210, 410, 61, 28));
        lineEdit_fst_tickets = new QLineEdit(page1);
        lineEdit_fst_tickets->setObjectName("lineEdit_fst_tickets");
        lineEdit_fst_tickets->setGeometry(QRect(210, 460, 61, 28));
        lineEdit_bus_price = new QLineEdit(page1);
        lineEdit_bus_price->setObjectName("lineEdit_bus_price");
        lineEdit_bus_price->setGeometry(QRect(330, 410, 61, 28));
        lineEdit_fst_price = new QLineEdit(page1);
        lineEdit_fst_price->setObjectName("lineEdit_fst_price");
        lineEdit_fst_price->setGeometry(QRect(330, 460, 61, 28));
        lbl_eco = new QLabel(page1);
        lbl_eco->setObjectName("lbl_eco");
        lbl_eco->setGeometry(QRect(130, 360, 54, 16));
        lbl_bus = new QLabel(page1);
        lbl_bus->setObjectName("lbl_bus");
        lbl_bus->setGeometry(QRect(130, 420, 54, 16));
        lbl_fst = new QLabel(page1);
        lbl_fst->setObjectName("lbl_fst");
        lbl_fst->setGeometry(QRect(130, 470, 54, 16));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        btn_delete = new QPushButton(page2);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setGeometry(QRect(470, 130, 92, 28));
        lineEdit_deleteId = new QLineEdit(page2);
        lineEdit_deleteId->setObjectName("lineEdit_deleteId");
        lineEdit_deleteId->setGeometry(QRect(310, 130, 150, 28));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        tableWidget = new QTableWidget(page3);
        if (tableWidget->columnCount() < 14)
            tableWidget->setColumnCount(14);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 60, 971, 611));
        lineEdit_flightNumber = new QLineEdit(page3);
        lineEdit_flightNumber->setObjectName("lineEdit_flightNumber");
        lineEdit_flightNumber->setGeometry(QRect(0, 0, 150, 28));
        lineEdit_flightCompany = new QLineEdit(page3);
        lineEdit_flightCompany->setObjectName("lineEdit_flightCompany");
        lineEdit_flightCompany->setGeometry(QRect(160, 0, 150, 28));
        lineEdit_departure = new QLineEdit(page3);
        lineEdit_departure->setObjectName("lineEdit_departure");
        lineEdit_departure->setGeometry(QRect(320, 0, 150, 28));
        lineEdit_destination = new QLineEdit(page3);
        lineEdit_destination->setObjectName("lineEdit_destination");
        lineEdit_destination->setGeometry(QRect(480, 0, 150, 28));
        dateEdit_departureDate = new QDateEdit(page3);
        dateEdit_departureDate->setObjectName("dateEdit_departureDate");
        dateEdit_departureDate->setGeometry(QRect(640, 0, 150, 28));
        dateEdit_departureDate->setDateTime(QDateTime(QDate(2024, 11, 30), QTime(8, 0, 0)));
        dateEdit_departureDate->setCalendarPopup(true);
        btn_search = new QPushButton(page3);
        btn_search->setObjectName("btn_search");
        btn_search->setGeometry(QRect(800, 0, 41, 28));
        btn_reset = new QPushButton(page3);
        btn_reset->setObjectName("btn_reset");
        btn_reset->setGeometry(QRect(850, 0, 41, 28));
        btn_del = new QPushButton(page3);
        btn_del->setObjectName("btn_del");
        btn_del->setGeometry(QRect(900, 0, 41, 28));
        stackedWidget->addWidget(page3);
        titile = new QLabel(centralwidget);
        titile->setObjectName("titile");
        titile->setGeometry(QRect(450, 10, 321, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        titile->setFont(font1);
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

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Frm_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Frm_Admin)
    {
        Frm_Admin->setWindowTitle(QCoreApplication::translate("Frm_Admin", "Admin - Flight Information", nullptr));
        act_exit->setText(QCoreApplication::translate("Frm_Admin", "\351\200\200\345\207\272", nullptr));
        act_logout->setText(QCoreApplication::translate("Frm_Admin", "\347\231\273\345\207\272", nullptr));
        lineEdit_addNumber->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        lineEdit_addCompany->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\345\217\270", nullptr));
        lineEdit_addDeparture->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\345\207\272\345\217\221\345\234\260", nullptr));
        lineEdit_addDestination->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\347\233\256\347\232\204\345\234\260", nullptr));
        btn_add->setText(QCoreApplication::translate("Frm_Admin", "\346\267\273\345\212\240", nullptr));
        lbl_Departure_time->setText(QCoreApplication::translate("Frm_Admin", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        lbl_Destination_time->setText(QCoreApplication::translate("Frm_Admin", "\351\231\215\350\220\275\346\227\266\351\227\264", nullptr));
        lineEdit_eco_tickets->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\346\200\273\347\245\250\346\225\260", nullptr));
        lineEdit_eco_price->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\345\256\232\344\273\267", nullptr));
        lineEdit_bus_tickets->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\346\200\273\347\245\250\346\225\260", nullptr));
        lineEdit_fst_tickets->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\346\200\273\347\245\250\346\225\260", nullptr));
        lineEdit_bus_price->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\345\256\232\344\273\267", nullptr));
        lineEdit_fst_price->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\345\256\232\344\273\267", nullptr));
        lbl_eco->setText(QCoreApplication::translate("Frm_Admin", "\347\273\217\346\265\216\350\210\261", nullptr));
        lbl_bus->setText(QCoreApplication::translate("Frm_Admin", "\345\225\206\345\212\241\350\210\261", nullptr));
        lbl_fst->setText(QCoreApplication::translate("Frm_Admin", "\345\244\264\347\255\211\350\210\261", nullptr));
        btn_delete->setText(QCoreApplication::translate("Frm_Admin", "\345\210\240\351\231\244", nullptr));
        lineEdit_deleteId->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\246\201\345\210\240\351\231\244\347\232\204\350\210\252\347\217\255\347\232\204ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Frm_Admin", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Frm_Admin", "\350\210\252\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Frm_Admin", "\345\207\272\345\217\221\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Frm_Admin", "\347\233\256\347\232\204\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Frm_Admin", "\347\273\217\346\265\216\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Frm_Admin", "\345\225\206\345\212\241\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Frm_Admin", "\345\244\264\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Frm_Admin", "\347\273\217\346\265\216\350\210\261\345\256\232\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Frm_Admin", "\345\225\206\345\212\241\350\210\261\345\256\232\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Frm_Admin", "\345\244\264\347\255\211\350\210\261\345\256\232\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Frm_Admin", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Frm_Admin", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        lineEdit_flightNumber->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        lineEdit_flightCompany->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\350\210\252\345\217\270", nullptr));
        lineEdit_departure->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\345\207\272\345\217\221\345\234\260", nullptr));
        lineEdit_destination->setPlaceholderText(QCoreApplication::translate("Frm_Admin", "\347\233\256\347\232\204\345\234\260", nullptr));
        btn_search->setText(QCoreApplication::translate("Frm_Admin", "\346\220\234\347\264\242", nullptr));
        btn_reset->setText(QCoreApplication::translate("Frm_Admin", "\351\207\215\347\275\256", nullptr));
        btn_del->setText(QCoreApplication::translate("Frm_Admin", "\345\210\240\351\231\244", nullptr));
        titile->setText(QCoreApplication::translate("Frm_Admin", "\350\210\252\347\217\255\351\242\204\350\256\242\347\263\273\347\273\237\357\274\210\345\220\216\345\217\260\357\274\211", nullptr));
        menu_S->setTitle(QCoreApplication::translate("Frm_Admin", "\347\263\273\347\273\237(&S)", nullptr));
        menu->setTitle(QCoreApplication::translate("Frm_Admin", "\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Admin: public Ui_Frm_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_ADMIN_H

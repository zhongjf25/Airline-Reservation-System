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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_User
{
public:
    QAction *act_logout;
    QAction *act_del;
    QAction *act_exit;
    QAction *act_change_pwd;
    QAction *lbl_username;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QTableWidget *search_airline;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QPushButton *btn_search;
    QComboBox *comboBox_departure;
    QComboBox *comboBox_destination;
    QLabel *labelArrow;
    QPushButton *btn_reset;
    QLineEdit *bookEdit;
    QPushButton *btn_book;
    QWidget *page2;
    QLabel *Image;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *self_airline;
    QLabel *username_txt;
    QLabel *laccount_txt;
    QPushButton *return_page1;
    QWidget *page3;
    QPushButton *btn_purchase;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *name;
    QLabel *humanID;
    QLabel *rank;
    QComboBox *comboBox;
    QLabel *date;
    QLabel *flyNum;
    QLabel *departure_label;
    QLabel *mon;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *btn_toSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QMenuBar *menubar1;
    QMenu *menu;
    QMenu *menu_S;
    QStatusBar *statusbar1;

    void setupUi(QMainWindow *Frm_User)
    {
        if (Frm_User->objectName().isEmpty())
            Frm_User->setObjectName("Frm_User");
        Frm_User->resize(1200, 800);
        act_logout = new QAction(Frm_User);
        act_logout->setObjectName("act_logout");
        act_del = new QAction(Frm_User);
        act_del->setObjectName("act_del");
        act_exit = new QAction(Frm_User);
        act_exit->setObjectName("act_exit");
        act_change_pwd = new QAction(Frm_User);
        act_change_pwd->setObjectName("act_change_pwd");
        lbl_username = new QAction(Frm_User);
        lbl_username->setObjectName("lbl_username");
        centralwidget = new QWidget(Frm_User);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 20, 1171, 611));
        page1 = new QWidget();
        page1->setObjectName("page1");
        search_airline = new QTableWidget(page1);
        if (search_airline->columnCount() < 11)
            search_airline->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        search_airline->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (search_airline->rowCount() < 2)
            search_airline->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        search_airline->setItem(1, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        search_airline->setItem(1, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        search_airline->setItem(1, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        search_airline->setItem(1, 5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        search_airline->setItem(1, 6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        search_airline->setItem(1, 7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        search_airline->setItem(1, 8, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        search_airline->setItem(1, 9, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        search_airline->setItem(1, 10, __qtablewidgetitem19);
        search_airline->setObjectName("search_airline");
        search_airline->setGeometry(QRect(40, 190, 1021, 281));
        groupBox = new QGroupBox(page1);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(270, 70, 581, 80));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(310, 30, 110, 22));
        dateEdit->setDateTime(QDateTime(QDate(2024, 11, 29), QTime(8, 0, 0)));
        dateEdit->setCalendarPopup(true);
        btn_search = new QPushButton(groupBox);
        btn_search->setObjectName("btn_search");
        btn_search->setGeometry(QRect(430, 30, 61, 25));
        comboBox_departure = new QComboBox(groupBox);
        comboBox_departure->addItem(QString());
        comboBox_departure->addItem(QString());
        comboBox_departure->addItem(QString());
        comboBox_departure->addItem(QString());
        comboBox_departure->addItem(QString());
        comboBox_departure->setObjectName("comboBox_departure");
        comboBox_departure->setGeometry(QRect(40, 30, 100, 22));
        comboBox_departure->setEditable(true);
        comboBox_destination = new QComboBox(groupBox);
        comboBox_destination->addItem(QString());
        comboBox_destination->addItem(QString());
        comboBox_destination->addItem(QString());
        comboBox_destination->addItem(QString());
        comboBox_destination->addItem(QString());
        comboBox_destination->setObjectName("comboBox_destination");
        comboBox_destination->setGeometry(QRect(200, 30, 100, 22));
        comboBox_destination->setEditable(true);
        labelArrow = new QLabel(groupBox);
        labelArrow->setObjectName("labelArrow");
        labelArrow->setGeometry(QRect(155, 30, 31, 21));
        labelArrow->setPixmap(QPixmap(QString::fromUtf8(":/img/arrow.png")));
        labelArrow->setScaledContents(true);
        btn_reset = new QPushButton(groupBox);
        btn_reset->setObjectName("btn_reset");
        btn_reset->setGeometry(QRect(500, 30, 61, 25));
        bookEdit = new QLineEdit(page1);
        bookEdit->setObjectName("bookEdit");
        bookEdit->setGeometry(QRect(440, 510, 111, 31));
        btn_book = new QPushButton(page1);
        btn_book->setObjectName("btn_book");
        btn_book->setGeometry(QRect(560, 510, 61, 31));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        Image = new QLabel(page2);
        Image->setObjectName("Image");
        Image->setGeometry(QRect(130, 100, 40, 41));
        label_2 = new QLabel(page2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 120, 40, 12));
        label_3 = new QLabel(page2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 150, 40, 12));
        self_airline = new QTableWidget(page2);
        if (self_airline->columnCount() < 6)
            self_airline->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        self_airline->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        if (self_airline->rowCount() < 1)
            self_airline->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        self_airline->setItem(0, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        self_airline->setItem(0, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        self_airline->setItem(0, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        self_airline->setItem(0, 4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        self_airline->setItem(0, 5, __qtablewidgetitem30);
        self_airline->setObjectName("self_airline");
        self_airline->setGeometry(QRect(40, 190, 1021, 192));
        username_txt = new QLabel(page2);
        username_txt->setObjectName("username_txt");
        username_txt->setGeometry(QRect(280, 120, 40, 12));
        laccount_txt = new QLabel(page2);
        laccount_txt->setObjectName("laccount_txt");
        laccount_txt->setGeometry(QRect(280, 150, 40, 12));
        return_page1 = new QPushButton(page2);
        return_page1->setObjectName("return_page1");
        return_page1->setGeometry(QRect(50, 20, 92, 28));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        btn_purchase = new QPushButton(page3);
        btn_purchase->setObjectName("btn_purchase");
        btn_purchase->setGeometry(QRect(950, 70, 91, 41));
        lineEdit = new QLineEdit(page3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(930, 130, 121, 31));
        lineEdit_2 = new QLineEdit(page3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(930, 180, 121, 31));
        name = new QLabel(page3);
        name->setObjectName("name");
        name->setGeometry(QRect(840, 120, 61, 31));
        humanID = new QLabel(page3);
        humanID->setObjectName("humanID");
        humanID->setGeometry(QRect(830, 170, 61, 51));
        rank = new QLabel(page3);
        rank->setObjectName("rank");
        rank->setGeometry(QRect(510, 250, 91, 41));
        comboBox = new QComboBox(page3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(640, 260, 91, 31));
        date = new QLabel(page3);
        date->setObjectName("date");
        date->setGeometry(QRect(240, 90, 51, 31));
        flyNum = new QLabel(page3);
        flyNum->setObjectName("flyNum");
        flyNum->setGeometry(QRect(240, 140, 71, 41));
        departure_label = new QLabel(page3);
        departure_label->setObjectName("departure_label");
        departure_label->setGeometry(QRect(240, 190, 61, 31));
        mon = new QLabel(page3);
        mon->setObjectName("mon");
        mon->setGeometry(QRect(240, 250, 61, 41));
        label_5 = new QLabel(page3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(530, 90, 51, 31));
        label_6 = new QLabel(page3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(520, 130, 71, 41));
        label_7 = new QLabel(page3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(530, 180, 61, 41));
        lineEdit_3 = new QLineEdit(page3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 90, 111, 31));
        lineEdit_4 = new QLineEdit(page3);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(640, 100, 121, 31));
        lineEdit_5 = new QLineEdit(page3);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(350, 140, 111, 31));
        lineEdit_6 = new QLineEdit(page3);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(640, 140, 121, 31));
        lineEdit_7 = new QLineEdit(page3);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(350, 180, 111, 31));
        lineEdit_8 = new QLineEdit(page3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(640, 180, 121, 31));
        btn_toSearch = new QPushButton(page3);
        btn_toSearch->setObjectName("btn_toSearch");
        btn_toSearch->setGeometry(QRect(30, 10, 61, 31));
        stackedWidget->addWidget(page3);
        menubar = new QMenuBar();
        menubar->setObjectName("menubar");
        stackedWidget->addWidget(menubar);
        statusbar = new QStatusBar();
        statusbar->setObjectName("statusbar");
        stackedWidget->addWidget(statusbar);
        Frm_User->setCentralWidget(centralwidget);
        menubar1 = new QMenuBar(Frm_User);
        menubar1->setObjectName("menubar1");
        menubar1->setGeometry(QRect(0, 0, 1200, 25));
        menu = new QMenu(menubar1);
        menu->setObjectName("menu");
        menu_S = new QMenu(menubar1);
        menu_S->setObjectName("menu_S");
        Frm_User->setMenuBar(menubar1);
        statusbar1 = new QStatusBar(Frm_User);
        statusbar1->setObjectName("statusbar1");
        Frm_User->setStatusBar(statusbar1);

        menubar1->addAction(menu_S->menuAction());
        menubar1->addAction(menu->menuAction());
        menu->addAction(lbl_username);
        menu->addSeparator();
        menu->addAction(act_logout);
        menu->addAction(act_change_pwd);
        menu->addSeparator();
        menu->addAction(act_del);
        menu_S->addAction(act_exit);

        retranslateUi(Frm_User);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Frm_User);
    } // setupUi

    void retranslateUi(QMainWindow *Frm_User)
    {
        Frm_User->setWindowTitle(QCoreApplication::translate("Frm_User", "MainWindow", nullptr));
        act_logout->setText(QCoreApplication::translate("Frm_User", "\347\231\273\345\207\272", nullptr));
        act_del->setText(QCoreApplication::translate("Frm_User", "\345\210\240\351\231\244\350\264\246\346\210\267", nullptr));
        act_exit->setText(QCoreApplication::translate("Frm_User", "\351\200\200\345\207\272", nullptr));
        act_change_pwd->setText(QCoreApplication::translate("Frm_User", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        lbl_username->setText(QCoreApplication::translate("Frm_User", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem = search_airline->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Frm_User", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = search_airline->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Frm_User", "\350\210\252\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = search_airline->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Frm_User", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = search_airline->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Frm_User", "\345\207\272\345\217\221\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = search_airline->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Frm_User", "\346\212\265\350\276\276\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = search_airline->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Frm_User", "\347\273\217\346\265\216\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = search_airline->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Frm_User", "\345\225\206\345\212\241\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = search_airline->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Frm_User", "\345\244\264\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = search_airline->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Frm_User", "\347\273\217\346\265\216\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = search_airline->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Frm_User", "\345\225\206\345\212\241\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = search_airline->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Frm_User", "\345\244\264\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));

        const bool __sortingEnabled = search_airline->isSortingEnabled();
        search_airline->setSortingEnabled(false);
        search_airline->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QCoreApplication::translate("Frm_User", " \350\210\252\347\217\255\346\220\234\347\264\242", nullptr));
        btn_search->setText(QCoreApplication::translate("Frm_User", "\346\220\234\347\264\242", nullptr));
        comboBox_departure->setItemText(0, QCoreApplication::translate("Frm_User", "\345\214\227\344\272\254", nullptr));
        comboBox_departure->setItemText(1, QCoreApplication::translate("Frm_User", "\344\270\212\346\265\267", nullptr));
        comboBox_departure->setItemText(2, QCoreApplication::translate("Frm_User", "\345\271\277\345\267\236", nullptr));
        comboBox_departure->setItemText(3, QCoreApplication::translate("Frm_User", "\346\267\261\345\234\263", nullptr));
        comboBox_departure->setItemText(4, QCoreApplication::translate("Frm_User", "\346\210\220\351\203\275", nullptr));

        comboBox_destination->setItemText(0, QCoreApplication::translate("Frm_User", "\345\214\227\344\272\254", nullptr));
        comboBox_destination->setItemText(1, QCoreApplication::translate("Frm_User", "\344\270\212\346\265\267", nullptr));
        comboBox_destination->setItemText(2, QCoreApplication::translate("Frm_User", "\345\271\277\345\267\236", nullptr));
        comboBox_destination->setItemText(3, QCoreApplication::translate("Frm_User", "\346\267\261\345\234\263", nullptr));
        comboBox_destination->setItemText(4, QCoreApplication::translate("Frm_User", "\346\210\220\351\203\275", nullptr));

        labelArrow->setText(QString());
        btn_reset->setText(QCoreApplication::translate("Frm_User", "\351\207\215\347\275\256", nullptr));
        btn_book->setText(QCoreApplication::translate("Frm_User", "\350\256\242\347\245\250", nullptr));
        Image->setText(QCoreApplication::translate("Frm_User", "\345\244\264\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("Frm_User", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Frm_User", "\350\264\246\345\217\267\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = self_airline->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Frm_User", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = self_airline->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Frm_User", "\350\210\252\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = self_airline->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Frm_User", "\350\265\267\345\247\213\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = self_airline->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Frm_User", "\347\233\256\347\232\204\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = self_airline->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Frm_User", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = self_airline->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Frm_User", "\344\273\267\346\240\274", nullptr));

        const bool __sortingEnabled1 = self_airline->isSortingEnabled();
        self_airline->setSortingEnabled(false);
        self_airline->setSortingEnabled(__sortingEnabled1);

        username_txt->setText(QCoreApplication::translate("Frm_User", "xtttttt", nullptr));
        laccount_txt->setText(QCoreApplication::translate("Frm_User", "TextLabel", nullptr));
        return_page1->setText(QCoreApplication::translate("Frm_User", "\350\277\224\345\233\236", nullptr));
        btn_purchase->setText(QCoreApplication::translate("Frm_User", "\347\241\256\350\256\244\350\264\255\347\245\250", nullptr));
        name->setText(QCoreApplication::translate("Frm_User", "\345\247\223\345\220\215\357\274\232", nullptr));
        humanID->setText(QCoreApplication::translate("Frm_User", "\350\257\201\344\273\266\345\217\267\357\274\232", nullptr));
        rank->setText(QCoreApplication::translate("Frm_User", "\345\272\247\344\275\215\347\255\211\347\272\247\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Frm_User", "\345\244\264\347\255\211\350\210\261", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Frm_User", "\345\225\206\345\212\241\350\210\261", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Frm_User", "\347\273\217\346\265\216\350\210\261", nullptr));

        date->setText(QCoreApplication::translate("Frm_User", "\346\227\245\346\234\237", nullptr));
        flyNum->setText(QCoreApplication::translate("Frm_User", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        departure_label->setText(QCoreApplication::translate("Frm_User", "\345\207\272\345\217\221\345\234\260", nullptr));
        mon->setText(QCoreApplication::translate("Frm_User", "\344\273\267\346\240\274\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Frm_User", "\350\210\252\347\217\255\345\217\267", nullptr));
        label_6->setText(QCoreApplication::translate("Frm_User", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        label_7->setText(QCoreApplication::translate("Frm_User", "\345\210\260\350\276\276\345\234\260", nullptr));
        btn_toSearch->setText(QCoreApplication::translate("Frm_User", "\350\277\224\345\233\236", nullptr));
        menu->setTitle(QCoreApplication::translate("Frm_User", "\347\224\250\346\210\267(&U)", nullptr));
        menu_S->setTitle(QCoreApplication::translate("Frm_User", "\347\263\273\347\273\237(&S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_User: public Ui_Frm_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_USER_H

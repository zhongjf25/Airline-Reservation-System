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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QPushButton *back;
    QPushButton *to_home;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QFrame *line;
    QPushButton *pushButton;
    QLabel *graph;
    QComboBox *comboBox;
    QLabel *graph_2;
    QComboBox *comboBox_2;
    QLabel *graph_3;
    QPushButton *change;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_S;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Frm_User)
    {
        if (Frm_User->objectName().isEmpty())
            Frm_User->setObjectName("Frm_User");
        Frm_User->resize(800, 600);
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
        back = new QPushButton(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 20, 56, 18));
        to_home = new QPushButton(centralwidget);
        to_home->setObjectName("to_home");
        to_home->setGeometry(QRect(90, 20, 56, 18));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(80, 100, 501, 80));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(310, 30, 110, 22));
        line = new QFrame(groupBox);
        line->setObjectName("line");
        line->setGeometry(QRect(250, 23, 20, 35));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(430, 30, 61, 25));
        graph = new QLabel(groupBox);
        graph->setObjectName("graph");
        graph->setGeometry(QRect(10, 30, 20, 20));
        graph->setAutoFillBackground(true);
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(40, 30, 60, 22));
        graph_2 = new QLabel(groupBox);
        graph_2->setObjectName("graph_2");
        graph_2->setGeometry(QRect(160, 30, 20, 20));
        graph_2->setAutoFillBackground(true);
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(190, 30, 60, 22));
        graph_3 = new QLabel(groupBox);
        graph_3->setObjectName("graph_3");
        graph_3->setGeometry(QRect(280, 30, 20, 20));
        graph_3->setAutoFillBackground(true);
        change = new QPushButton(groupBox);
        change->setObjectName("change");
        change->setGeometry(QRect(120, 30, 20, 20));
        change->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        change->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none; \n"
"    background-image: url(:/change.jpg); \n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover; \n"
"}"));
        Frm_User->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Frm_User);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_S = new QMenu(menubar);
        menu_S->setObjectName("menu_S");
        Frm_User->setMenuBar(menubar);
        statusbar = new QStatusBar(Frm_User);
        statusbar->setObjectName("statusbar");
        Frm_User->setStatusBar(statusbar);

        menubar->addAction(menu_S->menuAction());
        menubar->addAction(menu->menuAction());
        menu->addAction(lbl_username);
        menu->addSeparator();
        menu->addAction(act_logout);
        menu->addAction(act_change_pwd);
        menu->addSeparator();
        menu->addAction(act_del);
        menu_S->addAction(act_exit);

        retranslateUi(Frm_User);

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
        back->setText(QCoreApplication::translate("Frm_User", "<- \350\277\224\345\233\236", nullptr));
        to_home->setText(QCoreApplication::translate("Frm_User", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Frm_User", " \350\210\252\347\217\255\346\220\234\347\264\242", nullptr));
        pushButton->setText(QCoreApplication::translate("Frm_User", "\346\220\234\347\264\242", nullptr));
        graph->setText(QString());
        graph_2->setText(QString());
        graph_3->setText(QString());
        change->setText(QString());
        menu->setTitle(QCoreApplication::translate("Frm_User", "\347\224\250\346\210\267(&U)", nullptr));
        menu_S->setTitle(QCoreApplication::translate("Frm_User", "\347\263\273\347\273\237(&S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_User: public Ui_Frm_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_USER_H

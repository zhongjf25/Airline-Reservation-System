/********************************************************************************
** Form generated from reading UI file 'frm_login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_LOGIN_H
#define UI_FRM_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Login
{
public:
    QPushButton *btn_Login;
    QPushButton *btn_Exit;
    QLabel *lbl_user;
    QLabel *lbl_pwd;
    QLineEdit *txt_user;
    QLineEdit *txt_pwd;
    QPushButton *btn_register;
    QCheckBox *chk_remb_pwd;

    void setupUi(QWidget *Frm_Login)
    {
        if (Frm_Login->objectName().isEmpty())
            Frm_Login->setObjectName("Frm_Login");
        Frm_Login->resize(600, 450);
        btn_Login = new QPushButton(Frm_Login);
        btn_Login->setObjectName("btn_Login");
        btn_Login->setGeometry(QRect(140, 290, 75, 24));
        btn_Exit = new QPushButton(Frm_Login);
        btn_Exit->setObjectName("btn_Exit");
        btn_Exit->setGeometry(QRect(360, 290, 75, 24));
        lbl_user = new QLabel(Frm_Login);
        lbl_user->setObjectName("lbl_user");
        lbl_user->setGeometry(QRect(110, 110, 54, 16));
        lbl_pwd = new QLabel(Frm_Login);
        lbl_pwd->setObjectName("lbl_pwd");
        lbl_pwd->setGeometry(QRect(110, 180, 54, 16));
        txt_user = new QLineEdit(Frm_Login);
        txt_user->setObjectName("txt_user");
        txt_user->setGeometry(QRect(210, 110, 181, 21));
        txt_pwd = new QLineEdit(Frm_Login);
        txt_pwd->setObjectName("txt_pwd");
        txt_pwd->setGeometry(QRect(210, 180, 181, 21));
        txt_pwd->setEchoMode(QLineEdit::EchoMode::Password);
        btn_register = new QPushButton(Frm_Login);
        btn_register->setObjectName("btn_register");
        btn_register->setGeometry(QRect(220, 290, 75, 24));
        chk_remb_pwd = new QCheckBox(Frm_Login);
        chk_remb_pwd->setObjectName("chk_remb_pwd");
        chk_remb_pwd->setGeometry(QRect(170, 230, 79, 20));

        retranslateUi(Frm_Login);

        QMetaObject::connectSlotsByName(Frm_Login);
    } // setupUi

    void retranslateUi(QWidget *Frm_Login)
    {
        Frm_Login->setWindowTitle(QCoreApplication::translate("Frm_Login", "Frm_Login", nullptr));
        btn_Login->setText(QCoreApplication::translate("Frm_Login", "\347\231\273\345\275\225", nullptr));
        btn_Exit->setText(QCoreApplication::translate("Frm_Login", "\351\200\200\345\207\272", nullptr));
        lbl_user->setText(QCoreApplication::translate("Frm_Login", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215\357\274\232</p></body></html>", nullptr));
        lbl_pwd->setText(QCoreApplication::translate("Frm_Login", "<html><head/><body><p>\345\257\206   \347\240\201\357\274\232</p></body></html>", nullptr));
        btn_register->setText(QCoreApplication::translate("Frm_Login", "\346\263\250\345\206\214", nullptr));
        chk_remb_pwd->setText(QCoreApplication::translate("Frm_Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Login: public Ui_Frm_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_LOGIN_H

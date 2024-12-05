/********************************************************************************
** Form generated from reading UI file 'frm_register.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_REGISTER_H
#define UI_FRM_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_Register
{
public:
    QLabel *lbl_name;
    QLabel *lbl_pwd;
    QLabel *lbl_pwd2;
    QLineEdit *txt_name;
    QLineEdit *txt_pwd;
    QLineEdit *txt_pwd2;
    QPushButton *btn_register;
    QPushButton *btn_cancel;

    void setupUi(QWidget *Frm_Register)
    {
        if (Frm_Register->objectName().isEmpty())
            Frm_Register->setObjectName("Frm_Register");
        Frm_Register->resize(369, 582);
        lbl_name = new QLabel(Frm_Register);
        lbl_name->setObjectName("lbl_name");
        lbl_name->setGeometry(QRect(30, 160, 54, 16));
        lbl_pwd = new QLabel(Frm_Register);
        lbl_pwd->setObjectName("lbl_pwd");
        lbl_pwd->setGeometry(QRect(30, 210, 54, 16));
        lbl_pwd2 = new QLabel(Frm_Register);
        lbl_pwd2->setObjectName("lbl_pwd2");
        lbl_pwd2->setGeometry(QRect(30, 270, 54, 16));
        txt_name = new QLineEdit(Frm_Register);
        txt_name->setObjectName("txt_name");
        txt_name->setGeometry(QRect(102, 160, 161, 21));
        txt_pwd = new QLineEdit(Frm_Register);
        txt_pwd->setObjectName("txt_pwd");
        txt_pwd->setGeometry(QRect(102, 210, 161, 21));
        txt_pwd->setEchoMode(QLineEdit::EchoMode::Password);
        txt_pwd2 = new QLineEdit(Frm_Register);
        txt_pwd2->setObjectName("txt_pwd2");
        txt_pwd2->setGeometry(QRect(102, 270, 161, 21));
        txt_pwd2->setEchoMode(QLineEdit::EchoMode::Password);
        btn_register = new QPushButton(Frm_Register);
        btn_register->setObjectName("btn_register");
        btn_register->setGeometry(QRect(60, 390, 75, 24));
        btn_cancel = new QPushButton(Frm_Register);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(190, 390, 75, 24));

        retranslateUi(Frm_Register);

        QMetaObject::connectSlotsByName(Frm_Register);
    } // setupUi

    void retranslateUi(QWidget *Frm_Register)
    {
        Frm_Register->setWindowTitle(QCoreApplication::translate("Frm_Register", "Form", nullptr));
        lbl_name->setText(QCoreApplication::translate("Frm_Register", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        lbl_pwd->setText(QCoreApplication::translate("Frm_Register", "\345\257\206\347\240\201\357\274\232", nullptr));
        lbl_pwd2->setText(QCoreApplication::translate("Frm_Register", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        btn_register->setText(QCoreApplication::translate("Frm_Register", "\346\263\250\345\206\214", nullptr));
        btn_cancel->setText(QCoreApplication::translate("Frm_Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_Register: public Ui_Frm_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_REGISTER_H

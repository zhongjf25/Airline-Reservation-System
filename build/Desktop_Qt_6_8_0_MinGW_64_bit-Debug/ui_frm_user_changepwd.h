/********************************************************************************
** Form generated from reading UI file 'frm_user_changepwd.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_USER_CHANGEPWD_H
#define UI_FRM_USER_CHANGEPWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frm_User_ChangePwd
{
public:
    QLabel *lbl_pwd0;
    QLabel *lbl_pwd1;
    QLabel *lbl_pwd2;
    QLineEdit *txt_pwd0;
    QLineEdit *txt_pwd1;
    QLineEdit *txt_pwd2;
    QPushButton *button_yes;
    QPushButton *button_no;

    void setupUi(QDialog *Frm_User_ChangePwd)
    {
        if (Frm_User_ChangePwd->objectName().isEmpty())
            Frm_User_ChangePwd->setObjectName("Frm_User_ChangePwd");
        Frm_User_ChangePwd->resize(400, 300);
        lbl_pwd0 = new QLabel(Frm_User_ChangePwd);
        lbl_pwd0->setObjectName("lbl_pwd0");
        lbl_pwd0->setGeometry(QRect(50, 70, 54, 16));
        lbl_pwd1 = new QLabel(Frm_User_ChangePwd);
        lbl_pwd1->setObjectName("lbl_pwd1");
        lbl_pwd1->setGeometry(QRect(50, 120, 54, 16));
        lbl_pwd2 = new QLabel(Frm_User_ChangePwd);
        lbl_pwd2->setObjectName("lbl_pwd2");
        lbl_pwd2->setGeometry(QRect(50, 180, 54, 16));
        txt_pwd0 = new QLineEdit(Frm_User_ChangePwd);
        txt_pwd0->setObjectName("txt_pwd0");
        txt_pwd0->setGeometry(QRect(160, 70, 171, 20));
        txt_pwd0->setEchoMode(QLineEdit::EchoMode::Password);
        txt_pwd1 = new QLineEdit(Frm_User_ChangePwd);
        txt_pwd1->setObjectName("txt_pwd1");
        txt_pwd1->setGeometry(QRect(160, 120, 171, 20));
        txt_pwd1->setEchoMode(QLineEdit::EchoMode::Password);
        txt_pwd2 = new QLineEdit(Frm_User_ChangePwd);
        txt_pwd2->setObjectName("txt_pwd2");
        txt_pwd2->setGeometry(QRect(160, 180, 171, 20));
        txt_pwd2->setEchoMode(QLineEdit::EchoMode::Password);
        button_yes = new QPushButton(Frm_User_ChangePwd);
        button_yes->setObjectName("button_yes");
        button_yes->setGeometry(QRect(90, 240, 75, 24));
        button_no = new QPushButton(Frm_User_ChangePwd);
        button_no->setObjectName("button_no");
        button_no->setGeometry(QRect(210, 240, 75, 24));

        retranslateUi(Frm_User_ChangePwd);

        QMetaObject::connectSlotsByName(Frm_User_ChangePwd);
    } // setupUi

    void retranslateUi(QDialog *Frm_User_ChangePwd)
    {
        Frm_User_ChangePwd->setWindowTitle(QCoreApplication::translate("Frm_User_ChangePwd", "Dialog", nullptr));
        lbl_pwd0->setText(QCoreApplication::translate("Frm_User_ChangePwd", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        lbl_pwd1->setText(QCoreApplication::translate("Frm_User_ChangePwd", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        lbl_pwd2->setText(QCoreApplication::translate("Frm_User_ChangePwd", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        button_yes->setText(QCoreApplication::translate("Frm_User_ChangePwd", "\347\241\256\345\256\232", nullptr));
        button_no->setText(QCoreApplication::translate("Frm_User_ChangePwd", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_User_ChangePwd: public Ui_Frm_User_ChangePwd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_USER_CHANGEPWD_H

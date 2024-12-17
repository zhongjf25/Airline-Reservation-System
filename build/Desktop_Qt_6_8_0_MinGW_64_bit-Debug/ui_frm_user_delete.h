/********************************************************************************
** Form generated from reading UI file 'frm_user_delete.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_USER_DELETE_H
#define UI_FRM_USER_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frm_User_Delete
{
public:
    QLabel *lbl_pwd;
    QLineEdit *txt_pwd;
    QPushButton *btn_del;
    QPushButton *btn_cancel;

    void setupUi(QWidget *Frm_User_Delete)
    {
        if (Frm_User_Delete->objectName().isEmpty())
            Frm_User_Delete->setObjectName("Frm_User_Delete");
        Frm_User_Delete->resize(1200, 800);
        Frm_User_Delete->setMinimumSize(QSize(1200, 800));
        Frm_User_Delete->setMaximumSize(QSize(1200, 800));
        lbl_pwd = new QLabel(Frm_User_Delete);
        lbl_pwd->setObjectName("lbl_pwd");
        lbl_pwd->setGeometry(QRect(540, 380, 54, 16));
        txt_pwd = new QLineEdit(Frm_User_Delete);
        txt_pwd->setObjectName("txt_pwd");
        txt_pwd->setGeometry(QRect(600, 380, 113, 20));
        txt_pwd->setEchoMode(QLineEdit::EchoMode::Password);
        btn_del = new QPushButton(Frm_User_Delete);
        btn_del->setObjectName("btn_del");
        btn_del->setGeometry(QRect(530, 470, 75, 24));
        btn_cancel = new QPushButton(Frm_User_Delete);
        btn_cancel->setObjectName("btn_cancel");
        btn_cancel->setGeometry(QRect(630, 470, 75, 24));

        retranslateUi(Frm_User_Delete);

        QMetaObject::connectSlotsByName(Frm_User_Delete);
    } // setupUi

    void retranslateUi(QWidget *Frm_User_Delete)
    {
        Frm_User_Delete->setWindowTitle(QCoreApplication::translate("Frm_User_Delete", "Form", nullptr));
        lbl_pwd->setText(QCoreApplication::translate("Frm_User_Delete", "\345\257\206\347\240\201\357\274\232", nullptr));
        btn_del->setText(QCoreApplication::translate("Frm_User_Delete", "\347\241\256\350\256\244", nullptr));
        btn_cancel->setText(QCoreApplication::translate("Frm_User_Delete", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frm_User_Delete: public Ui_Frm_User_Delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_USER_DELETE_H

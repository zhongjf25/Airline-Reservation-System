#ifndef FRM_USER_CHANGEPWD_H
#define FRM_USER_CHANGEPWD_H

#include <QWidget>
#include <QDialog>
#include "frm_user.h"   //勿删

namespace Ui {
class Frm_User_ChangePwd;
}

class Frm_User_ChangePwd : public QDialog
{
    Q_OBJECT

public:
    explicit Frm_User_ChangePwd(QWidget *parent = nullptr, QString n = "");
    ~Frm_User_ChangePwd();


private slots:
    void on_button_no_clicked();

    void on_button_yes_clicked();

private:
    Ui::Frm_User_ChangePwd *ui;
    QString username;
};

#endif // FRM_USER_CHANGEPWD_H

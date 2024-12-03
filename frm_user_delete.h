#ifndef FRM_USER_DELETE_H
#define FRM_USER_DELETE_H

#include <QWidget>
#include <QDialog>
#include "frm_user.h"

namespace Ui {
class Frm_User_Delete;
}

class Frm_User_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Frm_User_Delete(QWidget *parent = nullptr, QString n = "", Frm_User *p = nullptr);
    ~Frm_User_Delete();

private slots:
    void on_btn_cancel_clicked();

    void on_btn_del_clicked();

private:
    Ui::Frm_User_Delete *ui;
    QString username;
    Frm_User *pg_user;
};

#endif // FRM_USER_DELETE_H

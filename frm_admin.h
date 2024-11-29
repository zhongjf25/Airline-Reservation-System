#ifndef FRM_ADMIN_H
#define FRM_ADMIN_H

#include <QMainWindow>
#include "frm_login.h"

namespace Ui {
class Frm_Admin;
}

class Frm_Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Frm_Admin(QWidget *parent = nullptr, Frm_Login *l=nullptr);
    ~Frm_Admin();

private slots:
    void on_btn_Logout_clicked();

private:
    Ui::Frm_Admin *ui;
    Frm_Login *pg_login;
};

#endif // FRM_ADMIN_H

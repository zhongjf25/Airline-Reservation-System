#ifndef FRM_REGISTER_H
#define FRM_REGISTER_H

#include <QWidget>
#include "frm_login.h"

namespace Ui {
class Frm_Register;
}

class Frm_Register : public QWidget
{
    Q_OBJECT

public:
    explicit Frm_Register(QWidget *parent = nullptr, Frm_Login *l = nullptr);
    ~Frm_Register();

private slots:
    void on_btn_cancel_clicked();

private:
    Ui::Frm_Register *ui;
    Frm_Login *pg_login;
};

#endif // FRM_REGISTER_H

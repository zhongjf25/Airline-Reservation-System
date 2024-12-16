#ifndef FRM_REGISTER_H
#define FRM_REGISTER_H

#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QMainWindow>
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

    void on_btn_register_clicked();

private:
    Ui::Frm_Register *ui;
    Frm_Login *pg_login;
};

#endif // FRM_REGISTER_H
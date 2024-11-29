#include "frm_admin.h"
#include "ui_frm_admin.h"

Frm_Admin::Frm_Admin(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_Admin)
{
    ui->setupUi(this);
    pg_login = l;
}

Frm_Admin::~Frm_Admin()
{
    delete ui;
}

void Frm_Admin::on_btn_Logout_clicked()
{
    pg_login->show();
    // this->close();
    delete this;
}


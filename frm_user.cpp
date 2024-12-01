#include "frm_user.h"
#include "ui_frm_user.h"

Frm_User::Frm_User(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
    pg_login = l;

    connect(ui->act_logout, &QAction::triggered, this, &Frm_User::logout);  //登出

}

Frm_User::~Frm_User()
{
    delete ui;
}

void Frm_User::logout() {
    pg_login->show();
    delete this;
}

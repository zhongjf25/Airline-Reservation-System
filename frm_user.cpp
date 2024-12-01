#include "frm_user.h"
#include "ui_frm_user.h"

Frm_User::Frm_User(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
    pg_login = l;
}

Frm_User::~Frm_User()
{
    delete ui;
}

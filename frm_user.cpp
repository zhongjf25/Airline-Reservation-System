#include "frm_user.h"
#include "ui_frm_user.h"

Frm_User::Frm_User(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
}

Frm_User::~Frm_User()
{
    delete ui;
}

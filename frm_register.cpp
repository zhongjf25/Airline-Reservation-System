#include "frm_register.h"
#include "ui_frm_register.h"

Frm_Register::Frm_Register(QWidget *parent, Frm_Login *l)
    : QWidget(parent)
    , ui(new Ui::Frm_Register)
{
    ui->setupUi(this);
    pg_login = l;
    qDebug() << "Frm_Register constructed";
    // this->show();
}

Frm_Register::~Frm_Register()
{
    delete ui;
    qDebug() << "Frm_Register deleted";
}

void Frm_Register::on_btn_cancel_clicked()
{
    pg_login->show();
    delete this;
}


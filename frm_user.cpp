#include "frm_user.h"
#include "ui_frm_user.h"

Frm_User::Frm_User(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
    pg_login = l;

    connect(ui->act_logout, &QAction::triggered, this, &Frm_User::logout);  //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_User::exit);      //退出系统

}


void Frm_User::closeEvent(QCloseEvent *event) {
    if(sender() == ui->act_exit) {      //跳过exit(),如果已经通过退出系统键完成退出
        event->accept();
    }
    else {
        exit();
    }
}


Frm_User::~Frm_User()
{
    delete ui;
}

void Frm_User::logout() {
    pg_login->show();
    delete this;
}

void Frm_User::exit() {
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
}

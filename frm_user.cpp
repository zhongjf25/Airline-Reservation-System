#include "frm_user.h"
#include "ui_frm_user.h"

#include "frm_user_changepwd.h"
#include "frm_user_delete.h"


Frm_User::Frm_User(QWidget *parent, Frm_Login *l, QString n)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
    pg_login = l;
    username = n;   //传入用户名

    ui->lbl_username->setText(n);

    connect(ui->act_logout, &QAction::triggered, this, &Frm_User::logout);  //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_User::exit);      //退出系统
    connect(ui->act_change_pwd, &QAction::triggered, this, &Frm_User::change_pwd);   //修改密码
    connect(ui->act_del, &QAction::triggered, this, &Frm_User::del_user);   //删除账户

}


void Frm_User::closeEvent(QCloseEvent *event) {
    if(sender() == ui->act_exit) {      //跳过exit(),如果已经通过退出系统键完成退出
        event->accept();
    }
    else {
        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
            QApplication::quit();
        else {
            event->ignore();
            return;
        }
    }
}


Frm_User::~Frm_User()
{
    pg_login->show();
    delete ui;
}

void Frm_User::logout() {
    // pg_login->show();
    delete this;
}

void Frm_User::exit() {
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else {
        return;
    }
}



void Frm_User::change_pwd() {
    Frm_User_ChangePwd *frm = new Frm_User_ChangePwd(this, username);
    frm->exec();
}


void Frm_User::del_user() {
    Frm_User_Delete *frm = new Frm_User_Delete(this, username, this);
    frm->exec();
}

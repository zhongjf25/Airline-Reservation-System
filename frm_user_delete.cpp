#include "frm_user_delete.h"
#include "ui_frm_user_delete.h"
#include <QMessageBox>

Frm_User_Delete::Frm_User_Delete(QWidget *parent, QString n, Frm_User *p)
    : QDialog(parent)
    , ui(new Ui::Frm_User_Delete)
{
    ui->setupUi(this);
    username = n;
    pg_user = p;
    setWindowTitle("删除账户");
}

Frm_User_Delete::~Frm_User_Delete()
{
    delete ui;
}

void Frm_User_Delete::on_btn_cancel_clicked()
{
    delete this;
}


void Frm_User_Delete::on_btn_del_clicked()
{
    QString pwd = ui->txt_pwd->text();
    if(pwd == "") {
        QMessageBox::warning(this, "提示", "请输入密码");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "警告", "确定要删除账户？所有订单将会消失", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::No) {
        return;
    }

    QSqlQuery q;
    q.prepare("delete from Userinfo where UserName=:username and UserPwd=:password");
    q.bindValue(":username", username);
    q.bindValue(":password", pwd);

    if(q.exec()) {
        int cnt = q.numRowsAffected();
        if(cnt == 0) {
            QMessageBox::warning(this, "删除失败", "密码错误");
            return;
        }
        QMessageBox::information(this, "提示", "账户已成功删除，即将返回登录界面");
        delete pg_user;
    } else {
        QMessageBox::warning(this, "删除失败", "数据库连接错误");
    }
}


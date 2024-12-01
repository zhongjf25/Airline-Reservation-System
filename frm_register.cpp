#include "frm_register.h"
#include "ui_frm_register.h"

Frm_Register::Frm_Register(QWidget *parent, Frm_Login *l)
    : QWidget(parent)
    , ui(new Ui::Frm_Register)
{
    ui->setupUi(this);
    pg_login = l;

    setWindowTitle("注册");

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


void Frm_Register::on_btn_register_clicked()
{
    QString Username = ui->txt_name->text();
    QString pwd = ui->txt_pwd->text();
    QString pwd2 = ui->txt_pwd2->text();

    if(Username == "") {
        QMessageBox::warning(this, "注册失败", "用户名不能为空！");
        return;
    } else if(pwd == "") {
        QMessageBox::warning(this, "注册失败", "用户密码不能为空！");
        return;
    } else if(pwd != pwd2) {
        QMessageBox::warning(this, "警告", "密码不一致，请重新输入！");
        return;
    }

    QSqlQuery query;
    QString cmd = QString("select count(*) from UserInfo where UserName='%1'").arg(Username);
    query.exec(cmd);
    query.next();
    int cnt = query.value(0).toInt();

    if(Username == "admin") {
        QMessageBox::warning(this, "注册失败", "用户名已存在！");
        return;
    }
    if(cnt > 0) {
        QMessageBox::warning(this, "注册失败", "用户名已存在！");
        return;
    }else {
        query.prepare("insert into UserInfo (UserName, UserPwd) values (:username, :password);");
        // cmd = QString("insert into UserInfo (UserName, UserPwd) values ('%1', '%2');").arg(Username).arg(pwd);

        query.bindValue(":username", Username);
        query.bindValue(":password", pwd);

        if(query.exec()) {
            QMessageBox::information(this, "提示", "注册成功！即将返回登陆界面");
            on_btn_cancel_clicked();
        } else {
            QMessageBox::warning(this, "未知错误", "注册失败！请重试");
        }

    }
}


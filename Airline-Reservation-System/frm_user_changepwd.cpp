#include "frm_user_changepwd.h"
#include "ui_frm_user_changepwd.h"

Frm_User_ChangePwd::Frm_User_ChangePwd(QWidget *parent, QString n)
    : QDialog(parent)
    , ui(new Ui::Frm_User_ChangePwd)
{
    ui->setupUi(this);
    setWindowTitle("修改密码");
    username = n;

    // connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &Frm_User_ChangePwd::on_buttonBox_accepted);
    // connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &Frm_User_ChangePwd::on_buttonBox_rejected);
}

Frm_User_ChangePwd::~Frm_User_ChangePwd()
{
    delete ui;
}

void Frm_User_ChangePwd::on_button_no_clicked()
{
    delete this;
}


void Frm_User_ChangePwd::on_button_yes_clicked()
{
    QString pwd0 = ui->txt_pwd0->text();
    QString pwd1 = ui->txt_pwd1->text();
    QString pwd2 = ui->txt_pwd2->text();

    if(pwd0 == "") {
        QMessageBox::warning(this, "修改失败", "请输入原密码");
        return;
    } else if(pwd1 == "") {
        QMessageBox::warning(this, "修改失败", "新密码不能为空");
        return;
    } else if(pwd2 != pwd1) {
        QMessageBox::warning(this, "修改失败", "新密码不一致");
        return;
    }

    QSqlQuery q;
    q.prepare("select count(*) from UserInfo where Username=:username and UserPwd=:password");

    q.bindValue(":username", username);
    q.bindValue(":password", pwd0);

    if(q.exec()) {
        q.next();
        int cnt = q.value(0).toInt();
        if(cnt == 0) {
            QMessageBox::warning(this, "修改失败", "密码错误");
            return;
        }


        q.prepare("update UserInfo set UserPwd = :pwd where UserName = :username");
        q.bindValue(":pwd", pwd1);
        q.bindValue(":username", username);

        if(q.exec()) {
            QMessageBox::information(this, "提示", "修改成功");
            delete this;
        } else {
            QMessageBox::warning(this, "修改失败", "未知错误");
            return;
        }
    }
    else {
        QMessageBox::warning(this, "修改失败", "未知错误");
        return;
    }

}


#include "frm_login.h"
#include "ui_frm_login.h"
#include "frm_admin.h"
#include "frm_register.h"
#include "frm_user.h"



Frm_Login::Frm_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Frm_Login)
{
    ui->setupUi(this);

    //连接数据库
    db = QSqlDatabase::addDatabase("QODBC");   //加载ODBC数据库驱动


    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("airline_database");

    if(db.open()) {
        qDebug() << "连接数据库成功";
        QString SET_SATYMODE = "SET SQL_SAFE_UPDATES = 0;";

        QSqlQuery q;
        if(q.exec(SET_SATYMODE)) {
            qDebug() << "安全模式设置成功";
        }

    }
    else {
        QMessageBox::warning(this, "连接提示", "数据库连接失败，部分功能可能无法使用");
    }

}

Frm_Login::~Frm_Login()
{
    delete ui;
}

void Frm_Login::on_btn_Login_clicked()
{

    QString username = ui->txt_user->text();
    QString pwd = ui->txt_pwd->text();

    if(username == "") {
        QMessageBox::warning(this, "登录错误", "请输入用户名");
        return;
    } else if(pwd == "") {
        QMessageBox::warning(this, "登录错误", "请输入密码");
        return;
    }

    if(username == "admin" && pwd == "admin") {
        this->hide();
        Frm_Admin *frm_admin = new Frm_Admin(nullptr, this);
        frm_admin->show();
        return;
    }

    QSqlQuery q;
    QString cmd = QString("select count(*) from UserInfo where Username='%1' and UserPwd='%2'").arg(username).arg(pwd);
    if(q.exec(cmd)) {
        q.next();
        int cnt = q.value(0).toInt();
        if(cnt == 0) {
            QMessageBox::warning(this, "登陆失败", "用户名或密码错误");
            return;
        }

        //登陆成功
        this->hide();
        Frm_User *frm_user = new Frm_User(this, this);
        frm_user->show();
        return;
    } else {
        QMessageBox::warning(this, "登陆失败", "未知错误");
    }
}


void Frm_Login::on_btn_Exit_clicked()
{
    QApplication::quit();
}


void Frm_Login::on_btn_register_clicked()
{
    this->hide();
    Frm_Register *frm_register = new Frm_Register(nullptr, this);
    frm_register->show();

    // qDebug() << "registered";
}


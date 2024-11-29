#include "frm_login.h"
#include "ui_frm_login.h"
#include "frm_admin.h"
#include "frm_register.h"



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
    this->hide();
    Frm_Admin *frm_admin = new Frm_Admin(nullptr, this);
    frm_admin->show();
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


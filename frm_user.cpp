#include "frm_user.h"
#include "ui_frm_user.h"

#include "frm_user_changepwd.h"
#include "frm_user_delete.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>


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

    QPushButton *back = ui->back; // 获取 UI 中的按钮
    back->setStyleSheet("QPushButton {"
                              "border: none;"          // 去除边框
                              "background: transparent;" // 背景透明
                              "color: black;"  // 设置文字颜色
                              "text-decoration: underline;" // 添加下划线
                              "font-style: italic;"       // 文字斜体
                              "}"
                              "QPushButton:hover {"
                            "font-weight: bold;"        // 鼠标悬停时文字加粗
                              "}");

    QPushButton *to_home = ui->to_home; // 获取 UI 中的按钮
    to_home->setStyleSheet("QPushButton {"
                        "border: none;"          // 去除边框
                        "background: transparent;" // 背景透明
                        "color: black;"  // 设置文字颜色
                        "text-decoration: underline;" // 添加下划线
                        "font-style: italic;"       // 文字斜体
                        "}"
                        "QPushButton:hover {"
                        "font-weight: bold;"        // 鼠标悬停时文字加粗
                        "}");

    QLabel *graph = ui->graph;
    QPixmap pixmap("location.jpg");  // 替换为你的图片路径
    graph->setPixmap(pixmap);
    graph->setScaledContents(true);

    QLabel *graph_2 = ui->graph_2;
    graph_2->setScaledContents(true);
    graph_2->setPixmap(pixmap);

    QLabel *graph_3 = ui->graph_3;
    QPixmap pixmap_2("date.jpg");  // 替换为你的图片路径
    graph_3->setPixmap(pixmap_2);
    graph_3->setScaledContents(true);

    QPushButton *change = ui->change;

    QPixmap pixmap_3("change.jpg");
    QPixmap scaledPixmap = pixmap_3.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 设置缩放图片为按钮图标
    change->setIcon(QIcon(scaledPixmap));
    change->setIconSize(QSize(20, 20));

    change->setFixedSize(20, 20);
    change->show();

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
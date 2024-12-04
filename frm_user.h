#ifndef FRM_USER_H
#define FRM_USER_H

#include <QMainWindow>
#include "frm_login.h"
#include <QCloseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class Frm_User;
}

class Frm_User : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit Frm_User(QWidget *parent = nullptr, Frm_Login *l = nullptr, QString n = "");
    ~Frm_User();

private:
    Ui::Frm_User *ui;
    Frm_Login *pg_login;
    QString username;

private slots:
    void logout();  //登出
    void exit();    //退出程序
    void change_pwd();  //修改密码
    void del_user();    //删除账户
};

#endif // FRM_USER_H
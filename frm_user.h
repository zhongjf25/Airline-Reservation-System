#ifndef FRM_USER_H
#define FRM_USER_H

#include <QMainWindow>
#include "frm_login.h"
#include <QCloseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "frm_user_personpage.h"
#include "frm_ueser_reservetion.h"
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
    frm_user_personpage *p;
    frm_ueser_reservetion *r;

private slots:
    void logout();  //登出
    void exit();    //退出程序
    void change_pwd();  //修改密码
    void del_user();    //删除账户
    void on_to_home_clicked();
    void on_dingpiao_clicked();
};

#endif // FRM_USER_H

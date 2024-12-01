#ifndef FRM_USER_H
#define FRM_USER_H

#include <QMainWindow>
#include "frm_login.h"
#include <QCloseEvent>

namespace Ui {
class Frm_User;
}

class Frm_User : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit Frm_User(QWidget *parent = nullptr, Frm_Login *l = nullptr);
    ~Frm_User();

private:
    Ui::Frm_User *ui;
    Frm_Login *pg_login;

private slots:
    void logout();  //登出
    void exit();    //退出程序
};

#endif // FRM_USER_H

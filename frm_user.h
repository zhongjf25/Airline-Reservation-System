#ifndef FRM_USER_H
#define FRM_USER_H

#include <QMainWindow>
#include "frm_login.h"

namespace Ui {
class Frm_User;
}

class Frm_User : public QMainWindow
{
    Q_OBJECT

public:
    explicit Frm_User(QWidget *parent = nullptr, Frm_Login *l = nullptr);
    ~Frm_User();

private:
    Ui::Frm_User *ui;
    Frm_Login *pg_login;
};

#endif // FRM_USER_H

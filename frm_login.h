#ifndef FRM_LOGIN_H
#define FRM_LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Frm_Login;
}
QT_END_NAMESPACE

class Frm_Login : public QWidget
{
    Q_OBJECT

public:
    Frm_Login(QWidget *parent = nullptr);
    ~Frm_Login();

private slots:
    void on_btn_Login_clicked();

    void on_btn_Exit_clicked();

    void on_btn_register_clicked();

private:
    Ui::Frm_Login *ui;
    QSqlDatabase db;
};
#endif // FRM_LOGIN_H

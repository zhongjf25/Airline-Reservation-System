#ifndef FRM_ADMIN_H
#define FRM_ADMIN_H

#include <QMainWindow>
#include "frm_login.h"
#include <QStandardItemModel>
#include <QListWidget>
#include <QTableView>
#include <QStackedWidget>

namespace Ui {
class Frm_Admin;
}

class Frm_Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Frm_Admin(QWidget *parent = nullptr, Frm_Login *l=nullptr);
    ~Frm_Admin();

private slots:
    void exit();    //退出程序
    void logout(); //登出
    void onListWidgetClicked(int index); // 处理侧边栏切换
    // void on_btn_Logout_clicked();

private:
    Ui::Frm_Admin *ui;
    Frm_Login *pg_login;

    QStandardItemModel *model1;
    QStandardItemModel *model2;

    void setupTables(); // 初始化表格数据
};

#endif // FRM_ADMIN_H

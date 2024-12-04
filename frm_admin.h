#ifndef FRM_ADMIN_H
#define FRM_ADMIN_H

#include <QMainWindow>
#include "frm_login.h"
#include "flight_info.h"
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
    void on_btn_add_clicked(); // 添加航班按钮
    // void on_btn_Logout_clicked();

    void on_btn_delete_clicked();

private:
    Ui::Frm_Admin *ui;
    Frm_Login *pg_login;

    QStandardItemModel *model1;
    QStandardItemModel *model2;

    void setupTables(); // 初始化表格数据
    void addNewFlightInfo(flight_info* new_flight_info); // 新增flight_info
    void loadAllFlightInfoData(); // 加载全部flight_info数据
};

#endif // FRM_ADMIN_H

#ifndef FRM_ADMIN_H
#define FRM_ADMIN_H

#include <QMainWindow>
#include "frm_login.h"
#include "flight_info.h"
#include <QStandardItemModel>
#include <QListWidget>
#include <QStackedWidget>
#include <QHeaderView>
#include <QTableWidget>

namespace Ui {
class Frm_Admin;
}

class Frm_Admin : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;


public:
    explicit Frm_Admin(QWidget *parent = nullptr, Frm_Login *l=nullptr);

    ~Frm_Admin();

private slots:
    void exit();    //退出程序
    void logout(); //登出
    void onListWidgetClicked(int index); // 处理侧边栏切换
    void on_btn_add_clicked(); // 添加航班按钮
    void on_btn_search_clicked(); // 搜索航班按钮
    void on_btn_reset_clicked(); // 重置按钮

    void on_btn_del_clicked(); // 删除航班按钮

private:
    Ui::Frm_Admin *ui;
    Frm_Login *pg_login;
    QTableWidget* table;
    QTableWidget* purchaseInfoTable;

    void setupTables(); // 初始化表格数据
    void addNewFlightInfo(flight_info* new_flight_info); // 新增flight_info
    void loadAllFlightInfoData(); // 加载全部flight_info数据
    void loadCertainFlightInfoData(QString _Flt_Number,QString _company, QString _departure,
                                   QString _destination, QString _departure_date); // 根据信息查询相关flight_info数据
    void deleteFlight(); // 删除选中的航班
    void loadAllPurchaseInfoData(); // 加载全部订单信息
};

#endif // FRM_ADMIN_H

#ifndef FRM_ADMIN_H
#define FRM_ADMIN_H

#include <QMainWindow>
#include "frm_login.h"
#include "flight_info.h"
#include <QStandardItemModel>
#include <QListWidget>
#include <QTableView>
#include <QStackedWidget>
#include <QHeaderView>

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
    void on_btn_delete_clicked(); // 删除航班按钮
    void on_btn_search_clicked(); // 搜索航班按钮

    void on_btn_reset_clicked();

private:
    Ui::Frm_Admin *ui;
    Frm_Login *pg_login;

    QStandardItemModel *model1;
    QStandardItemModel *model2;
    QTableView *tableView1;
    QTableView *tableView2;

    void setupTables(); // 初始化表格数据
    void addNewFlightInfo(flight_info* new_flight_info); // 新增flight_info
    void loadAllFlightInfoData(); // 加载全部flight_info数据
    void deleteFlightInfoById(qint64 deleteFlightInfoId); // 根据id删除对应航班
    void loadCertainFlightInfoData(QString _Flt_Number,QString _company, QString _departure,
                                   QString _destination, QString _departure_date); // 根据信息查询相关flight_info数据
};

#endif // FRM_ADMIN_H

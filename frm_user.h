#ifndef FRM_USER_H
#define FRM_USER_H

#include <QMainWindow>
#include "frm_login.h"
#include <QCloseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPixmap>
#include <QPalette>
#include <QMainWindow>

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
    QTableWidget* search_table;
    QTableWidget* self_table;

    void setupTables(); // 初始化表格数据
    void loadAllFlightInfoData(); // 搜索所有数据
    void loadCertainFlightInfoData(QString _departure, QString _destination, QString _departure_date); // 搜索航班
    void displayBookedFlightInfoOnBookPage(QString flightId); // 根据id显示flightInfo到book页面
    void getSelectedFlightId();     //用户选中航班时获取ID
    void displayUserPurchasedFlightInfoOnUserPage(); // 显示购买航班信息到个人中心页面
    void updateAirlineByFlightId(QString flightId, QString flightType); // 更新购买后对应航班票数的变化

private slots:
    void logout();  //登出
    void exit();    //退出程序
    void change_pwd();  //修改密码
    void del_user();    //删除账户
    void goToUserPage(); // 跳转到个人主页
    void on_btn_return_page1_clicked();
    void on_btn_search_clicked();
    void on_btn_reset_clicked();
    void on_btn_purchase_clicked();
    void on_btn_book_clicked();
    void on_btn_toSearch_clicked();
    void on_type_comboBox_currentTextChanged(const QString &arg1);
    void on_btn_refund_clicked();
};

#endif // FRM_USER_H
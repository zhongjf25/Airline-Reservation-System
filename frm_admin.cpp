#include "frm_admin.h"
#include "ui_frm_admin.h"
#include <QMessageBox>

Frm_Admin::Frm_Admin(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_Admin)
{
    ui->setupUi(this);
    pg_login = l;

    // 初始化表格数据
    setupTables();

    // 添加新航班
    flight_info* new_flight_info = new flight_info(
        QString("AAAAA"), QString("Air USA"), QString("2024-12-04"),
        QString("Los Angles"), QString("Tokyo"), 1, 100, 20, 5, 1000, 2000, 3000);
    addNewFlightInfo(new_flight_info);

    // 初始化列表项
    ui->listWidget->addItem("所有航班信息");
    ui->listWidget->addItem("表格 2");

    connect(ui->act_logout, &QAction::triggered, this, &Frm_Admin::logout);   //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_Admin::exit);      //退出系统
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Frm_Admin::onListWidgetClicked);  // 处理侧边栏切换

}

Frm_Admin::~Frm_Admin()
{
    delete ui;
    delete model1;
    delete model2;
}

void Frm_Admin::addNewFlightInfo(flight_info* new_flight_info)
{
    QSqlQuery q;

    // 假设你要插入一条航班信息
    q.prepare("insert into flightinfo (Flt_Number, Flt_Company, "
              "Flt_Date, Departure, Destination, Type, EcoSeats, BusSeats, "
              "FstSeats, price_eco, price_bus, price_fst) "
              "values (:_Flt_Number, :_Flt_Company, :_Flt_Date, :_Departure, :_Destination, "
              ":_Type, :_EcoSeats, :_BusSeats, :_FstSeats, :_price_eco, :_price_bus, :_price_fst)");
    q.bindValue(":_Flt_Number", new_flight_info->getFltNumber());
    q.bindValue(":_Flt_Company", new_flight_info->getFltCompany());
    q.bindValue(":_Flt_Date", new_flight_info->getFltDate());
    q.bindValue(":_Departure", new_flight_info->getDeparture());
    q.bindValue(":_Destination", new_flight_info->getDestination());
    q.bindValue(":_Type", new_flight_info->getType());
    q.bindValue(":_EcoSeats", new_flight_info->getEcoSeats());
    q.bindValue(":_BusSeats", new_flight_info->getBusSeats());
    q.bindValue(":_FstSeats", new_flight_info->getFstSeats());
    q.bindValue(":_price_eco", new_flight_info->getPriceEco());
    q.bindValue(":_price_bus", new_flight_info->getPriceBus());
    q.bindValue(":_price_fst", new_flight_info->getPriceFst());

    // 执行插入操作
    if (!q.exec()) {
        qDebug() << "Error inserting data";
    } else {
        qDebug() << "Data inserted successfully";
    }
}

void Frm_Admin::setupTables()
{
    // 表格 1 数据模型
    model1 = new QStandardItemModel(this); // 5 行 13 列
    model1->setItem(0, 0, new QStandardItem(QString("航班ID")));
    model1->setItem(0, 1, new QStandardItem(QString("航班编号")));
    model1->setItem(0, 2, new QStandardItem(QString("航班公司")));
    model1->setItem(0, 3, new QStandardItem(QString("航班日期")));
    model1->setItem(0, 4, new QStandardItem(QString("航班起点")));
    model1->setItem(0, 5, new QStandardItem(QString("航班终点")));
    model1->setItem(0, 6, new QStandardItem(QString("航班种类")));
    model1->setItem(0, 7, new QStandardItem(QString("EcoSeats")));
    model1->setItem(0, 8, new QStandardItem(QString("BusSeats")));
    model1->setItem(0, 9, new QStandardItem(QString("FstSeats")));
    model1->setItem(0, 10, new QStandardItem(QString("price_eco")));
    model1->setItem(0, 11, new QStandardItem(QString("price_bus")));
    model1->setItem(0, 12, new QStandardItem(QString("price_fst")));

    // 表格 2 数据模型
    model2 = new QStandardItemModel(4, 4, this); // 4 行 4 列
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            model2->setItem(i, j, new QStandardItem(QString("表格2: %1-%2").arg(i).arg(j)));


    // 将模型绑定到 QTableView
    QTableView *tableView1 = new QTableView(this);
    tableView1->setModel(model1);
    QTableView *tableView2 = new QTableView(this);
    tableView2->setModel(model2);


    // 将表格添加到 QStackedWidget
    ui->stackedWidget->addWidget(tableView1);
    ui->stackedWidget->addWidget(tableView2);
}

void Frm_Admin::onListWidgetClicked(int index)
{
    int offset = ui->stackedWidget->count() - 2; // 动态计算偏移量 其中2为表格数量
    ui->stackedWidget->setCurrentIndex(index + offset);
    qDebug() << "index: " << index << ", effective index: " << index + offset;

}


void Frm_Admin::exit() {
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else {
        return;
    }
}

void Frm_Admin::logout() {
    pg_login->show(); // 展示出登录页面 然后销毁本页面
    delete this;
}

// 登出button
// void Frm_Admin::on_btn_Logout_clicked()
// {
//     pg_login->show();
//     // this->close();
//     delete this;
// }


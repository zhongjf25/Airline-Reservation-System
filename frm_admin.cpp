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
    addNewFlightInfo(l->getDatabase()); // 传入database 进行新增数据操作

    // 初始化列表项
    ui->listWidget->addItem("表格 1");
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

void Frm_Admin::addNewFlightInfo(QSqlDatabase _db)
{
    // 使用传入的数据库对象执行 SQL 语句
    QSqlQuery q(_db);

    // 假设你要插入一条航班信息
    q.prepare("insert into flightinfo (Flt_Number, Flt_Company, "
              "Flt_Date, Departure, Destination, Type, EcoSeats, BusSeats, "
              "FstSeats, price_eco, price_bus, price_fst) "
              "values ('CA1123', 'Air China', '2019-12-01', 'Beijing', 'Shanghai', "
              "'1', 100, 20, 5, 1000, 2000, 3000)");

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
    model1 = new QStandardItemModel(5, 3, this); // 5 行 3 列
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j)
            model1->setItem(i, j, new QStandardItem(QString("表格1: %1-%2").arg(i).arg(j)));

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


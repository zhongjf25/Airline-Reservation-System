#include "frm_admin.h"
#include "ui_frm_admin.h"
#include <QMessageBox>
#include <QCloseEvent>

Frm_Admin::Frm_Admin(QWidget *parent, Frm_Login *l)
    : QMainWindow(parent)
    , ui(new Ui::Frm_Admin)
{
    ui->setupUi(this);
    pg_login = l;

    // 初始化表格数据
    setupTables();

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

    q.prepare("insert into flightinfo (Flt_Number, Flt_Company, "
              "Flt_Date, Departure, Destination, EcoSeats, BusSeats, "
              "FstSeats, price_eco, price_bus, price_fst) "
              "values (:_Flt_Number, :_Flt_Company, :_Flt_Date, :_Departure, :_Destination, "
              ":_EcoSeats, :_BusSeats, :_FstSeats, :_price_eco, :_price_bus, :_price_fst)");
    q.bindValue(":_Flt_Number", new_flight_info->getFltNumber());
    q.bindValue(":_Flt_Company", new_flight_info->getFltCompany());
    q.bindValue(":_Flt_Date",  new_flight_info->getFltDate());
    q.bindValue(":_Departure", new_flight_info->getDeparture());
    q.bindValue(":_Destination", new_flight_info->getDestination());
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
    // Load the flight data once after insertion
    loadAllFlightInfoData();
}

void Frm_Admin::loadAllFlightInfoData()
{
    QSqlQuery query;
    query.prepare("select Flt_ID, Flt_Number, Flt_Company, "
                  "Flt_Date, Departure, Destination, EcoSeats, BusSeats, "
                  "FstSeats, price_eco, price_bus, price_fst from flightinfo");

    if (!query.exec()) {
        qDebug() << "Error executing query: ";
        return;
    }

    // 清空现有数据
    model1->removeRows(0, model1->rowCount());

    int row = 0;
    while (query.next()) {
        model1->insertRow(row); // 插入新行
        model1->setData(model1->index(row, 0), query.value(0).toInt()); // id
        model1->setData(model1->index(row, 1), query.value(1).toString()); // number
        model1->setData(model1->index(row, 2), query.value(2).toString()); // company
        model1->setData(model1->index(row, 3), query.value(3).toString()); // date
        model1->setData(model1->index(row, 4), query.value(4).toString()); // departure
        model1->setData(model1->index(row, 5), query.value(5).toString()); // destination
        model1->setData(model1->index(row, 6), query.value(6).toInt()); // ecoseats
        model1->setData(model1->index(row, 7), query.value(7).toInt()); // busseats
        model1->setData(model1->index(row, 8), query.value(8).toInt()); // fstseats
        model1->setData(model1->index(row, 9), query.value(9).toInt()); // priceeco
        model1->setData(model1->index(row, 10), query.value(10).toInt()); // pricebus
        model1->setData(model1->index(row, 11), query.value(11).toInt()); // pricefst
        row++;
    }
}


void Frm_Admin::setupTables()
{
    // 表格 1 数据模型
    model1 = new QStandardItemModel(this);
    model1->setHorizontalHeaderLabels({"ID", "航班号", "航司", "航班日期",
                                       "出发地", "目的地", "经济舱余票",
                                       "商务舱余票", "头等舱余票", "经济舱定价", "商务舱定价", "头等舱定价"});


    // 表格 2 数据模型
    model2 = new QStandardItemModel(this);
    model2->setHorizontalHeaderLabels({"ID", "航班号", "航司", "航班日期",
                                       "出发地", "目的地", "经济舱余票",
                                       "商务舱余票", "头等舱余票", "经济舱定价", "商务舱定价", "头等舱定价"});



    // 将模型绑定到 QTableView
    QTableView *tableView1 = new QTableView(this);
    tableView1->setModel(model1);
    QTableView *tableView2 = new QTableView(this);
    tableView2->setModel(model2);


    // 将表格添加到 QStackedWidget
    ui->stackedWidget->addWidget(tableView1);
    ui->stackedWidget->addWidget(tableView2);

    // 加载数据
    loadAllFlightInfoData();
}

void Frm_Admin::onListWidgetClicked(int index)
{
    int offset = ui->stackedWidget->count() - 2; // 动态计算偏移量 其中2为表格数量
    ui->stackedWidget->setCurrentIndex(index + offset);
}

void Frm_Admin::on_btn_add_clicked()
{
    // 获取用户输入的数据
    QString flightNumber = ui->lineEdit_flightNumber->text();
    QString departure = ui->lineEdit_departure->text();
    QString destination = ui->lineEdit_destination->text();
    QDate departureDate = ui->dateEdit_departureDate->date();

    if (flightNumber.isEmpty() || departure.isEmpty() || destination.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields!");
        return;
        qDebug() << "ccc";
    }

    flight_info* new_flight_info = new flight_info();
    new_flight_info->setFltNumber(flightNumber);
    new_flight_info->setFltCompany(QString("Air China"));
    new_flight_info->setFltDate(departureDate.toString("yyyy-MM-dd"));
    new_flight_info->setDeparture(departure);
    new_flight_info->setDestination(destination);
    new_flight_info->setEcoSeats(100); // 设置经济舱座位数
    new_flight_info->setBusSeats(50); // 设置商务舱座位数
    new_flight_info->setFstSeats(20); // 设置头等舱座位数
    new_flight_info->setPriceEco(1000); // 设置经济舱票价
    new_flight_info->setPriceBus(2000); // 设置商务舱票价
    new_flight_info->setPriceFst(3000); // 设置头等舱票价

    // 将数据插入到数据库
    addNewFlightInfo(new_flight_info);

    delete new_flight_info;
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


void Frm_Admin::closeEvent(QCloseEvent *event) {
    if(sender() == ui->act_exit) {      //跳过exit(),如果已经通过退出系统键完成退出
        event->accept();
    }
    else {
        QMessageBox::StandardButton reply;

        reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes)
            QApplication::quit();
        else {
            event->ignore();
            return;
        }
    }
}


// 登出button
// void Frm_Admin::on_btn_Logout_clicked()
// {
//     pg_login->show();
//     // this->close();
//     delete this;
// }




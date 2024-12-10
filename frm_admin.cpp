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
    ui->listWidget->addItem("增加航班");
    ui->listWidget->addItem("删除航班");
    ui->listWidget->addItem("航班信息");


    // 默认显示数据table页面（可选）
    ui->stackedWidget->setCurrentIndex(2);

    connect(ui->act_logout, &QAction::triggered, this, &Frm_Admin::logout);   //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_Admin::exit);      //退出系统
    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Frm_Admin::onListWidgetClicked);  // 处理侧边栏切换
}

Frm_Admin::~Frm_Admin()
{
    delete ui;
}

void Frm_Admin::addNewFlightInfo(flight_info* new_flight_info)
{
    QSqlQuery q;

    q.prepare("insert into flightinfo (Flt_Number, Flt_Company, "
              "Flt_Date, Departure, Destination, EcoSeats, BusSeats, "
              "FstSeats, price_eco, price_bus, price_fst, time_dep, time_arr) "
              "values (:_Flt_Number, :_Flt_Company, :_Flt_Date, :_Departure, :_Destination, "
              ":_EcoSeats, :_BusSeats, :_FstSeats, :_price_eco, :_price_bus, :_price_fst, :_time_dep, :_time_arr)");
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
    q.bindValue(":_time_dep", new_flight_info->getDepTime());
    q.bindValue(":_time_arr", new_flight_info->getArrTime());

    // 执行插入操作
    if (!q.exec()) {
        qDebug() << "Error inserting data";
    } else {
        qDebug() << "Data inserted successfully";
    }
    // Load the flight data once after insertion
    loadAllFlightInfoData();
}

void Frm_Admin::deleteFlightInfoById(qint64 deleteFlightInfoId)
{
    QSqlQuery q;
    q.prepare("delete from flightinfo where Flt_ID =:_deleteFlightInfoId");
    q.bindValue(":_deleteFlightInfoId", deleteFlightInfoId);

    if (q.exec()) {
        qDebug() << "delete flightInfo which id = " << deleteFlightInfoId << " successfully!";
    } else {
        qDebug() << "Error deleting data";
    }

    loadAllFlightInfoData();
}

void Frm_Admin::loadAllFlightInfoData()
{
    QSqlQuery query;
    query.prepare("select Flt_ID, Flt_Number, Flt_Company, "
                  "Flt_Date, Departure, Destination, EcoSeats, BusSeats, "
                  "FstSeats, price_eco, price_bus, price_fst, date_format(time_dep, '%H:%i') as time_dep, "
                  "date_format(time_arr, '%H:%i') as time_arr from flightinfo");

    if (!query.exec()) {
        qDebug() << "Error executing query: ";
        return;
    }

    // Clear existing rows before adding new data
    table->clearContents();
    table->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Insert a new row in the table for each record
        table->insertRow(row);

        // Set the data for each column in the current row
        table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Flt_ID
        table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Flt_Number
        table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Flt_Company
        table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Flt_Date
        table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Departure
        table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Destination
        table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // EcoSeats
        table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // BusSeats
        table->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // FstSeats
        table->setItem(row, 9, new QTableWidgetItem(query.value(9).toString())); // PriceEco
        table->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // PriceBus
        table->setItem(row, 11, new QTableWidgetItem(query.value(11).toString())); // PriceFst
        table->setItem(row, 12, new QTableWidgetItem(query.value(12).toString()));
        table->setItem(row, 13, new QTableWidgetItem(query.value(13).toString()));

        row++;
    }

}

void Frm_Admin::loadCertainFlightInfoData(QString _Flt_Number,QString _company, QString _departure,
                                          QString _destination, QString _departure_date)
{
    QSqlQuery query;
    QString queryStr = "select Flt_ID, Flt_Number, Flt_Company, Flt_Date, Departure, "
                       "Destination, EcoSeats, BusSeats, FstSeats, price_eco, "
                       "price_bus, price_fst, date_format(time_dep, '%H:%i') as time_dep, "
                       "date_format(time_arr, '%H:%i') as time_arr from flightinfo where 1=1";

    if (!_Flt_Number.isEmpty()) {
        queryStr += " and Flt_Number = '" + _Flt_Number + "'";
    }
    if (!_company.isEmpty()) {
        queryStr += " and Flt_Company = '" + _company + "'";
    }
    if (!_departure.isEmpty()) {
        queryStr += " and Departure = '" + _departure + "'";
    }
    if (!_destination.isEmpty()) {
        queryStr += " and Destination = '" + _destination + "'";
    }
    if (!_departure_date.isEmpty()) {
        queryStr += " and Flt_Date = '" + _departure_date + "'";
    }

    qDebug() << queryStr;

    query.prepare(queryStr);
    if (!query.exec()) {
        qDebug() << "Error executing query";
        return;
    }

    // Clear existing rows before adding new data
    table->clearContents();
    table->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Insert a new row in the table for each record
        table->insertRow(row);

        // Set the data for each column in the current row
        table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Flt_ID
        table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Flt_Number
        table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Flt_Company
        table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Flt_Date
        table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Departure
        table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // Destination
        table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // EcoSeats
        table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // BusSeats
        table->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // FstSeats
        table->setItem(row, 9, new QTableWidgetItem(query.value(9).toString())); // PriceEco
        table->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // PriceBus
        table->setItem(row, 11, new QTableWidgetItem(query.value(11).toString())); // PriceFst
        table->setItem(row, 12, new QTableWidgetItem(query.value(12).toString()));
        table->setItem(row, 13, new QTableWidgetItem(query.value(13).toString()));

        row++;
    }
}


void Frm_Admin::setupTables()
{
    table = ui->tableWidget;

    table->verticalHeader()->setVisible(false);  // Hide the vertical header (row numbers)

    // Clear existing rows before adding new data
    table->clearContents();
    table->setRowCount(0);

    // 设置列宽相同，平均占满一行
    int columnCount = table->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    // 加载数据
    loadAllFlightInfoData();
}

void Frm_Admin::onListWidgetClicked(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void Frm_Admin::on_btn_add_clicked()
{
    // 获取用户输入的数据
    QString flightNumber = ui->lineEdit_addNumber->text();
    QString company = ui->lineEdit_addCompany->text();
    QString departure = ui->lineEdit_addDeparture->text();
    QString destination = ui->lineEdit_addDestination->text();
    QDate departureDate = ui->dateEdit_addDate->date();
    QString dep_time = ui->timeEdit_Departure_time->time().toString("HH:mm");
    QString arr_time = ui->timeEdit_Destination_time->time().toString("HH:mm");

    if (flightNumber.isEmpty() || departure.isEmpty() || destination.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields!");
        return;
    }

    if(dep_time == arr_time) {
        QMessageBox::warning(this, "警告", "起飞和降落时间不能相同");
    }

    flight_info* new_flight_info = new flight_info();
    new_flight_info->setFltNumber(flightNumber);
    new_flight_info->setFltCompany(company);
    new_flight_info->setFltDate(departureDate.toString("yyyy-MM-dd"));
    new_flight_info->setDeparture(departure);
    new_flight_info->setDestination(destination);
    new_flight_info->setEcoSeats(100); // 设置经济舱座位数
    new_flight_info->setBusSeats(50); // 设置商务舱座位数
    new_flight_info->setFstSeats(20); // 设置头等舱座位数
    new_flight_info->setPriceEco(1000); // 设置经济舱票价
    new_flight_info->setPriceBus(2000); // 设置商务舱票价
    new_flight_info->setPriceFst(3000); // 设置头等舱票价
    new_flight_info->setDepTime(dep_time);  //设置起飞时间
    new_flight_info->setArrTime(arr_time);  //设置降落时间

    // 将数据插入到数据库
    addNewFlightInfo(new_flight_info);

    delete new_flight_info;
}

void Frm_Admin::on_btn_delete_clicked()
{
    QString flightId = ui->lineEdit_deleteId->text();
    if (flightId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill id!");
        return;
    }

    qint64 flightIdInt = flightId.toInt();

    deleteFlightInfoById(flightIdInt);
}

void Frm_Admin::on_btn_search_clicked()
{
    // 获取用户输入的数据
    QString flightNumber = ui->lineEdit_flightNumber->text();
    QString company = ui->lineEdit_flightCompany->text();
    QString departure = ui->lineEdit_departure->text();
    QString destination = ui->lineEdit_destination->text();
    QDate departureDate = ui->dateEdit_departureDate->date();

    qDebug() << flightNumber << " " << company << " " << departure << " " << destination << " " << departureDate;
    loadCertainFlightInfoData(flightNumber, company, departure, destination, departureDate.toString("yyyy-MM-dd"));

}

void Frm_Admin::on_btn_reset_clicked()
{
    loadAllFlightInfoData();
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















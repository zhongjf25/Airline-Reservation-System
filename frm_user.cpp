#include "frm_user.h"
#include "ui_frm_user.h"

#include "frm_user_changepwd.h"
#include "frm_user_delete.h"

#include <QApplication>


Frm_User::Frm_User(QWidget *parent, Frm_Login *l, QString n)
    : QMainWindow(parent)
    , ui(new Ui::Frm_User)
{
    ui->setupUi(this);
    pg_login = l;
    username = n;   //传入用户名

    ui->lbl_username->setText(n);

    setupTables();

    connect(ui->act_logout, &QAction::triggered, this, &Frm_User::logout);  //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_User::exit);      //退出系统
    connect(ui->act_change_pwd, &QAction::triggered, this, &Frm_User::change_pwd);   //修改密码
    connect(ui->act_del, &QAction::triggered, this, &Frm_User::del_user);   //删除账户
    connect(ui->lbl_username, &QAction::triggered, this, &Frm_User::goToUserPage); //跳转到用户界面
}

void Frm_User::setupTables()
{
    search_table = ui->search_airline;
    // 设置列宽相同，平均占满一行
    int columnCount = search_table->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        search_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    self_table = ui->self_airline;
    // 设置列宽相同，平均占满一行
    int columnCount2 = self_table->columnCount();
    for (int i = 0; i < columnCount2; ++i) {
        self_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    search_table->verticalHeader()->setVisible(false);  // Hide the vertical header (row numbers)
    self_table->verticalHeader()->setVisible(false);  // Hide the vertical header (row numbers)

    ui->search_airline->setEditTriggers(QAbstractItemView::NoEditTriggers);     //设置为只读
    ui->search_airline->setSelectionBehavior(QAbstractItemView::SelectRows); // 选择整行
    ui->search_airline->setSelectionMode(QAbstractItemView::SingleSelection); // 只允许单行选择
    ui->self_airline->setEditTriggers(QAbstractItemView::NoEditTriggers);     //设置为只读
    ui->self_airline->setSelectionBehavior(QAbstractItemView::SelectRows); // 选择整行
    ui->self_airline->setSelectionMode(QAbstractItemView::SingleSelection); // 只允许单行选择

    loadAllFlightInfoData();
}

void Frm_User::loadAllFlightInfoData()
{
    QSqlQuery query;
    query.prepare("select Flt_ID, Flt_Number, Flt_Company, "
                  "Flt_Date, Departure, Destination, EcoSeats, BusSeats, "
                  "FstSeats, price_eco, price_bus, price_fst from flightinfo");

    if (!query.exec()) {
        qDebug() << "Error executing query: ";
        return;
    }

    // Clear existing rows before adding new data
    search_table->clearContents();
    search_table->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Insert a new row in the table for each record
        search_table->insertRow(row);

        // Set the data for each column in the current row
        search_table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Flt_Number
        search_table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Flt_Company
        search_table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Flt_Date
        search_table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Departure
        search_table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Destination
        search_table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // EcoSeats
        search_table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // BusSeats
        search_table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // FstSeats
        search_table->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // PriceEco
        search_table->setItem(row, 9, new QTableWidgetItem(query.value(9).toString())); // PriceBus
        search_table->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // PriceFst
        search_table->setItem(row, 11, new QTableWidgetItem(query.value(11).toString())); // PriceFst

        row++;
    }

}

void Frm_User::loadCertainFlightInfoData(QString _departure, QString _destination, QString _departure_date)
{
    QSqlQuery query;
    QString queryStr = "select Flt_ID, Flt_Number, Flt_Company, Flt_Date, Departure,"
                       "Destination, EcoSeats, BusSeats, FstSeats, price_eco, "
                       "price_bus, price_fst from flightinfo where 1=1";

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
    search_table->clearContents();
    search_table->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Insert a new row in the table for each record
        search_table->insertRow(row);

        // Set the data for each column in the current row
        search_table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Flt_Number
        search_table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Flt_Company
        search_table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Flt_Date
        search_table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Departure
        search_table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Destination
        search_table->setItem(row, 5, new QTableWidgetItem(query.value(5).toString())); // EcoSeats
        search_table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // BusSeats
        search_table->setItem(row, 7, new QTableWidgetItem(query.value(7).toString())); // FstSeats
        search_table->setItem(row, 8, new QTableWidgetItem(query.value(8).toString())); // PriceEco
        search_table->setItem(row, 9, new QTableWidgetItem(query.value(9).toString())); // PriceBus
        search_table->setItem(row, 10, new QTableWidgetItem(query.value(10).toString())); // PriceFst
        search_table->setItem(row, 11, new QTableWidgetItem(query.value(11).toString())); // PriceFst

        row++;
    }
}

void Frm_User::displayBookedFlightInfoOnBookPage(QString flightId)
{
    QSqlQuery query;
    query.prepare("select Flt_ID, Flt_Number, Flt_Company, Flt_Date, Departure,"
                  "Destination, EcoSeats, BusSeats, FstSeats, price_eco, "
                  "price_bus, price_fst from flightinfo where Flt_ID =:flightId");
    query.bindValue(":flightId", flightId);
    if (query.exec()) {
        if (query.next()) {  // Ensure that data exists
            ui->book_numberEdit->setText(query.value(1).toString());
            ui->book_dateEdit->setText(query.value(3).toString());
            ui->book_departureEdit->setText(query.value(4).toString());
            ui->book_destinationEdit->setText(query.value(5).toString());

            // Set fields to be read-only after setting the data
            ui->book_numberEdit->setReadOnly(true);
            ui->book_dateEdit->setReadOnly(true);
            ui->book_departureEdit->setReadOnly(true);
            ui->book_destinationEdit->setReadOnly(true);
        } else {
            QMessageBox::information(this, "No Results", "No flight found with the entered flight id.");
        }
    } else {
        QMessageBox::information(this, "Query Error", "Error executing query.");
    }
}


void Frm_User::closeEvent(QCloseEvent *event)
{
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


Frm_User::~Frm_User()
{
    pg_login->show();
    delete ui;
}

void Frm_User::logout() {
    // pg_login->show();
    delete this;
}

void Frm_User::exit() {
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "提示", "是否确定要退出系统？", QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else {
        return;
    }
}

void Frm_User::goToUserPage() {
    ui->stackedWidget->setCurrentIndex(1);  // 切换到user页面
}



void Frm_User::change_pwd() {
    Frm_User_ChangePwd *frm = new Frm_User_ChangePwd(this, username);
    frm->exec();
}


void Frm_User::del_user() {
    Frm_User_Delete *frm = new Frm_User_Delete(this, username, this);
    frm->exec();
}

void Frm_User::on_btn_return_page1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  // 切换到搜索页面
}

void Frm_User::on_btn_search_clicked()
{
    // 获取用户输入的数据
    QString departure = ui->comboBox_departure->currentText();
    QString destination = ui->comboBox_destination->currentText();
    QDate departureDate = ui->dateEdit->date();

    loadCertainFlightInfoData(departure, destination, departureDate.toString("yyyy-MM-dd"));
}


void Frm_User::on_btn_reset_clicked()
{
    // Clear existing rows before adding new data
    search_table->clearContents();
    search_table->setRowCount(0);

    loadAllFlightInfoData();
}


void Frm_User::on_btn_purchase_clicked()
{

}


void Frm_User::on_btn_book_clicked()
{
    QString flightId = ui->bookEdit->text();
    if (flightId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a flight id.");
        return;
    }

    // 将搜索到的数据显示到购票页面
    displayBookedFlightInfoOnBookPage(flightId);

    ui->stackedWidget->setCurrentIndex(2);
}


void Frm_User::on_btn_toSearch_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


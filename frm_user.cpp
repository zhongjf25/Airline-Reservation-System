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

    ui->bookEdit->hide();

    setupTables();

    connect(ui->act_logout, &QAction::triggered, this, &Frm_User::logout);  //登出
    connect(ui->act_exit, &QAction::triggered, this, &Frm_User::exit);      //退出系统
    connect(ui->act_change_pwd, &QAction::triggered, this, &Frm_User::change_pwd);   //修改密码
    connect(ui->act_del, &QAction::triggered, this, &Frm_User::del_user);   //删除账户
    connect(ui->lbl_username, &QAction::triggered, this, &Frm_User::goToUserPage); //跳转到用户界面
    connect(ui->type_comboBox, &QComboBox::currentTextChanged,
            this, &Frm_User::on_type_comboBox_currentTextChanged); //连接舱位选择
    connect(ui->search_airline, &QTableWidget::itemClicked, this, &Frm_User::getSelectedFlightId);  //自动获取选中行ID

}

void Frm_User::setupTables()
{
    search_table = ui->search_airline;
    // 设置列宽相同，平均占满一行 同时隐藏id列
    search_table->setColumnHidden(0, true);
    int columnCount = search_table->columnCount();
    for (int i = 0; i < columnCount; ++i) {
        if (i != 0) search_table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
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

    // 设置购票页面航班id隐藏
    ui->flightId_label->setVisible(false);
    ui->book_idEdit->setVisible(false);

    //设置购票页面不可选中信息
    ui->book_numberEdit->setEnabled(false);
    ui->book_dateEdit->setEnabled(false);
    ui->book_departureDateEdit->setEnabled(false);
    ui->book_departureEdit->setEnabled(false);
    ui->book_destinationEdit->setEnabled(false);
    ui->book_destinationDateEdit->setEnabled(false);
    ui->book_priceEdit->setEnabled(false);

    // 默认显示第一个page
    ui->stackedWidget->setCurrentIndex(0);

    // 设置comboBox为空
    ui->type_comboBox->setCurrentIndex(-1);

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
    ui->book_idEdit->setText(flightId);

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
    //获取信息
    QString userId;
    QString userName = ui->book_userNameEdit->text();
    QSqlQuery q;
    q.prepare("select UserID from userinfo where UserName =:userName");
    q.bindValue(":userName", userName);
    if (q.exec()) {
        if (q.next()) userId = q.value(0).toString();
    }
    QString flightId = ui->book_idEdit->text();
    qint64 purchaseQuantity = 1;
    QString orderPrice = ui->book_priceEdit->text();
    QString flightType = ui->type_comboBox->currentText();
    // 判断
    if (flightType == "经济舱") flightType = "0";
    else if (flightType == "商务舱") flightType = "1";
    else if (flightType == "头等舱") flightType = "2";

    q.prepare("insert into purchaseinfo (UserID, FlightID, PurchaseQuantity, OrderPrice, FlightType) "
              "values (:userId, :flightId, :purchaseQuantity, :orderPrice, :flightType)");
    q.bindValue(":userId", userId.toInt());
    q.bindValue(":flightId", flightId.toInt());
    q.bindValue(":purchaseQuantity", purchaseQuantity);
    q.bindValue(":orderPrice", orderPrice.toInt());
    q.bindValue(":flightType", flightType.toInt());
    if (!q.exec()) {
        QMessageBox::information(this, "Failed!", "purchase failed!");
    } else {
        QMessageBox::information(this, "Success!", "Successful Purchase");
    }
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


void Frm_User::on_type_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << "Selected Seat Class: " << arg1;

    QString price;
    QString flightId = ui->book_idEdit->text();
    qDebug() << "Flight ID: " << flightId;

    if (flightId.isEmpty()) {
        qDebug() << "Flight ID is empty!";
        return;
    }

    QString eco_price;
    QString bus_price;
    QString fst_price;

    // Query to get the prices for all seat types
    QSqlQuery q;
    q.prepare("select price_eco, price_bus, price_fst from flightinfo where Flt_ID =:flightId");
    q.bindValue(":flightId", flightId);

    if (q.exec()) {
        if (q.next()) {
            eco_price = q.value(0).toString();
            bus_price = q.value(1).toString();
            fst_price = q.value(2).toString();
            qDebug() << "Eco Price: " << eco_price << " Bus Price: " << bus_price << " Fst Price: " << fst_price;
        }
    }

    // Set the price based on the selected seat class
    if (arg1 == "经济舱") {
        price = eco_price;  // Economy class price
    }
    else if (arg1 == "商务舱") {
        price = bus_price;  // Business class price
    }
    else if (arg1 == "头等舱") {
        price = fst_price;  // First class price
    }

    // Update the price displayed in the UI
    ui->book_priceEdit->setText(price);

    qDebug() << "Updated Price: " << price;
}




void Frm_User::getSelectedFlightId()    //获取选中航班ID
{
    // 获取当前选中的行的索引
    int currentRow = ui->search_airline->currentRow();

    // 检查是否选中了有效的行
    if (currentRow >= 0) {
        // 获取选中行的 Flt_ID 数据（假设 Flt_ID 在第一列）
        QString flightId = ui->search_airline->item(currentRow, 0)->text(); // 列索引 0
        // qDebug() << "Selected Flt_ID:" << flightId;
        ui->bookEdit->setText(flightId);
    } else {
        qDebug() << "No row selected.";
    }
}

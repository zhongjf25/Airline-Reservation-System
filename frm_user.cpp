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
    setWindowTitle("航班订购系统");

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
                  "FstSeats, price_eco, price_bus, price_fst, date_format(time_dep, '%H:%i') as time_dep, "
                  "date_format(time_arr, '%H:%i') as time_arr from flightinfo");

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
        search_table->setItem(row, 12, new QTableWidgetItem(query.value(12).toString()));
        search_table->setItem(row, 13, new QTableWidgetItem(query.value(13).toString()));

        row++;

        //加载出发目的地下拉框
        if(ui->comboBox_departure->findText(query.value(4).toString()) == -1) {
            ui->comboBox_departure->addItem(query.value(4).toString());
        }
        if(ui->comboBox_destination->findText(query.value(5).toString()) == -1) {
            ui->comboBox_destination->addItem(query.value(5).toString());
        }
    }

}

void Frm_User::loadCertainFlightInfoData(QString _departure, QString _destination, QString _departure_date)
{
    QSqlQuery query;
    QString queryStr = "select Flt_ID, Flt_Number, Flt_Company, Flt_Date, Departure,"
                       "Destination, EcoSeats, BusSeats, FstSeats, price_eco, "
                       "price_bus, price_fst, date_format(time_dep, '%H:%i') as time_dep, "
                       "date_format(time_arr, '%H:%i') as time_arr from flightinfo where 1=1";

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
        search_table->setItem(row, 12, new QTableWidgetItem(query.value(12).toString()));
        search_table->setItem(row, 13, new QTableWidgetItem(query.value(13).toString()));

        row++;
    }
}

void Frm_User::displayBookedFlightInfoOnBookPage(QString flightId)
{
    QSqlQuery query;
    query.prepare("select Flt_ID, Flt_Number, Flt_Company, Flt_Date, Departure,"
                  "Destination, EcoSeats, BusSeats, FstSeats, price_eco, "
                  "price_bus, price_fst, date_format(time_dep, '%H:%i') as time_dep, "
                  "date_format(time_arr, '%H:%i') as time_arr from flightinfo where Flt_ID =:flightId");
    query.bindValue(":flightId", flightId);
    ui->book_idEdit->setText(flightId);

    if (query.exec()) {
        if (query.next()) {  // Ensure that data exists
            ui->book_numberEdit->setText(query.value(1).toString());
            ui->book_dateEdit->setText(query.value(3).toString());
            ui->book_departureEdit->setText(query.value(4).toString());
            ui->book_destinationEdit->setText(query.value(5).toString());
            ui->book_departureDateEdit->setText(query.value(12).toString());
            ui->book_destinationDateEdit->setText(query.value(13).toString());

            // Set fields to be read-only after setting the data
            ui->book_numberEdit->setReadOnly(true);
            ui->book_dateEdit->setReadOnly(true);
            ui->book_departureEdit->setReadOnly(true);
            ui->book_destinationEdit->setReadOnly(true);
            ui->book_departureDateEdit->setReadOnly(true);
            ui->book_destinationDateEdit->setReadOnly(true);
        } else {
            QMessageBox::information(this, "No Results", "No flight found with the entered flight id.");
        }
    } else {
        QMessageBox::information(this, "Query Error", "Error executing query.");
    }
}

void Frm_User::displayUserPurchasedFlightInfoOnUserPage() {
    QString username = ui->lbl_username->text();
    ui->username_txt->setText(username);
    QSqlQuery query;
    query.prepare("select UserID from userinfo where UserName=:username");
    query.bindValue(":username", username);
    QString userid;
    if (query.exec()) {
        if (query.next()) {
            userid = query.value(0).toString();
        }
    } else {
        QMessageBox::information(this, "Query Error", "Error executing query.");
        return;
    }


    query.prepare("select OrderID, UserID, FlightID, PurchaseQuantity, OrderPrice, "
                  "FlightType, passenger_name from purchaseinfo where UserID =:userid");
    query.bindValue(":userid", userid);


    if (!query.exec()) {
        QMessageBox::information(this, "Query Error", "Error executing query.");
        return;
    }

    // Clear existing rows before adding new ones
    self_table->clearContents();
    self_table->setRowCount(0);

    // Iterate over all records in purchaseinfo
    while (query.next()) {
        QString orderId = query.value(0).toString();
        QString flightType = query.value(5).toString();
        if (flightType == "0") {
            flightType = "经济舱";
        } else if (flightType == "1") {
            flightType = "商务舱";
        } else if (flightType == "2") {
            flightType = "头等舱";
        }
        QString flightId = query.value(2).toString();
        QString orderPrice = query.value(4).toString();

        // Fetch flight details for each FlightID
        QSqlQuery flightQuery;
        flightQuery.prepare("select Flt_Number, Flt_Company, Flt_Date, Departure, "
                            "Destination, date_format(time_dep, '%H:%i') as time_dep,"
                            " date_format(time_arr, '%H:%i') as time_arr"
                            " from flightinfo where Flt_ID = :flightId");
        flightQuery.bindValue(":flightId", flightId);

        if (flightQuery.exec() && flightQuery.next()) {
            QString flightNumber = flightQuery.value(0).toString();
            QString flightCompany = flightQuery.value(1).toString();
            QString date = flightQuery.value(2).toString();
            QString departure = flightQuery.value(3).toString();
            QString destination = flightQuery.value(4).toString();
            QString time_dep = flightQuery.value(5).toString();
            QString time_arr = flightQuery.value(6).toString();

            // Insert the data into the table
            int row = self_table->rowCount();
            self_table->insertRow(row);

            self_table->setItem(row, 0, new QTableWidgetItem(orderId));
            self_table->setItem(row, 1, new QTableWidgetItem(flightNumber));             // Flight Number
            self_table->setItem(row, 2, new QTableWidgetItem(flightCompany));            // Flight Company
            self_table->setItem(row, 3, new QTableWidgetItem(flightType));
            self_table->setItem(row, 4, new QTableWidgetItem(departure));               // Departure
            self_table->setItem(row, 5, new QTableWidgetItem(destination));             // Destination
            self_table->setItem(row, 6, new QTableWidgetItem(date));                    // Date
            self_table->setItem(row, 7, new QTableWidgetItem(time_dep));                // Departure Time
            self_table->setItem(row, 8, new QTableWidgetItem(time_arr));                // Arrival Time
            self_table->setItem(row, 9, new QTableWidgetItem(orderPrice));              // Order Price

        } else {
            // If no flight details are found, you can choose to log or display a message
            qDebug() << "No flight found for FlightID: " << flightId;
        }
    }
}

void Frm_User::updateAirlineByFlightId(QString flightId, QString flightType)
{
    QSqlQuery query;
    query.prepare("select EcoSeats, BusSeats, FstSeats from flightinfo where Flt_ID =:flightId");
    query.bindValue(":flightId", flightId);
    qint64 ecoseats = 0, busseats = 0, fstseats = 0;
    if (query.exec()) {
        if (query.next()) {
            ecoseats = query.value(0).toInt();
            busseats = query.value(1).toInt();
            fstseats = query.value(2).toInt();
        }
    } else {
        QMessageBox::information(this, "Query Error", "Error executing query.");
        return;
    }
    if (flightType == "0") {
        ecoseats -= 1;
    } else if (flightType == "1") {
        busseats -= 1;
    } else if (flightType == "2") {
        fstseats -= 1;
    } else {
        QMessageBox::information(this, "FlightType error", "out of range.");
        return;
    }
    query.prepare("update flightinfo set EcoSeats =:ecoseats, BusSeats =:busseats,"
                  " FstSeats =:fstseats where Flt_ID =:flightId");
    query.bindValue(":ecoseats", ecoseats);
    query.bindValue(":busseats", busseats);
    query.bindValue(":fstseats", fstseats);
    query.bindValue(":flightId", flightId);
    if (query.exec()) {
        if (query.next()) {
            QMessageBox::information(this, "Success!", "Successful Update FlightInfo");
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
    displayUserPurchasedFlightInfoOnUserPage();
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

    QString userName = ui->lbl_username->text();
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
    QString passenger_name = username;
    // 判断
    if (flightType == "经济舱") flightType = "0";
    else if (flightType == "商务舱") flightType = "1";
    else if (flightType == "头等舱") flightType = "2";

    q.prepare("insert into purchaseinfo (UserID, FlightID, PurchaseQuantity, OrderPrice, FlightType, passenger_name) "
              "values (:userId, :flightId, :purchaseQuantity, :orderPrice, :flightType, :passenger_name)");
    q.bindValue(":userId", userId.toInt());
    q.bindValue(":flightId", flightId.toInt());
    q.bindValue(":purchaseQuantity", purchaseQuantity);
    q.bindValue(":orderPrice", orderPrice.toInt());
    q.bindValue(":flightType", flightType.toInt());
    q.bindValue(":passenger_name", passenger_name);

    if (userId.isEmpty() || flightId.isEmpty() || !purchaseQuantity ||
        orderPrice.isEmpty() || flightType.isEmpty() || passenger_name.isEmpty()) {
        QMessageBox::information(this, "Warn!", "please fill all info!");
        return;
    }

    if (!q.exec()) {
        QMessageBox::information(this, "Failed!", "purchase failed!");
    } else {
        // 更新票数
        updateAirlineByFlightId(flightId, flightType);
        loadAllFlightInfoData();

        QMessageBox::information(this, "Success!", "Successful Purchase");

        on_btn_return_page1_clicked();
    }
}


void Frm_User::on_btn_book_clicked()
{
    QString flightId = ui->bookEdit->text();
    if (flightId.isEmpty()) {
        QMessageBox::warning(this, "错误", "未选择航班");
        return;
    }

    int cur = ui->search_airline->currentRow();
    QTableWidgetItem *item1 = ui->search_airline->item(cur, 6);
    QTableWidgetItem *item2 = ui->search_airline->item(cur, 7);
    QTableWidgetItem *item3 = ui->search_airline->item(cur, 8);
    if(item1->text()=="0" && item2->text()=="0" && item3->text()=="0") {
        QMessageBox::warning(this, "无法购买", "该航班已售罄");
        return;
    }

    // 将搜索到的数据显示到购票页面
    displayBookedFlightInfoOnBookPage(flightId);

    ui->stackedWidget->setCurrentIndex(2);
    ui->btn_purchase->setEnabled(false);
    ui->type_comboBox->setCurrentIndex(-1);
    ui->lbl_warning->setText("");
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
    int eco_num=0;
    int bus_num=0;
    int fst_num=0;

    // Query to get the prices for all seat types
    QSqlQuery q;
    q.prepare("select price_eco, price_bus, price_fst, EcoSeats, BusSeats, FstSeats from flightinfo where Flt_ID =:flightId");
    q.bindValue(":flightId", flightId);

    if (q.exec()) {
        if (q.next()) {
            eco_price = q.value(0).toString();
            bus_price = q.value(1).toString();
            fst_price = q.value(2).toString();
            eco_num = q.value(3).toInt();
            bus_num = q.value(4).toInt();
            fst_num = q.value(5).toInt();
            qDebug() << "Eco Price: " << eco_price << " Bus Price: " << bus_price << " Fst Price: " << fst_price;
        }
    }

    // Set the price based on the selected seat class
    if (arg1 == "经济舱") {
        price = eco_price;  // Economy class price
        if(eco_num <= 0) {
            ui->btn_purchase->setEnabled(false);
            ui->lbl_warning->setText("该舱位已售罄");
        } else {
            ui->btn_purchase->setEnabled(true);
            ui->lbl_warning->setText("");
        }
    }
    else if (arg1 == "商务舱") {
        price = bus_price;  // Business class price
        if(bus_num <= 0) {
            ui->btn_purchase->setEnabled(false);
            ui->lbl_warning->setText("该舱位已售罄");
        } else {
            ui->btn_purchase->setEnabled(true);
            ui->lbl_warning->setText("");
        }
    }
    else if (arg1 == "头等舱") {
        price = fst_price;  // First class price
        if(fst_num <= 0) {
            ui->btn_purchase->setEnabled(false);
            ui->lbl_warning->setText("该舱位已售罄");
        } else {
            ui->btn_purchase->setEnabled(true);
            ui->lbl_warning->setText("");
        }
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
        ui->bookEdit->setText(flightId);

        //设置搜索框的城市和日期
        ui->comboBox_departure->setCurrentText(ui->search_airline->item(currentRow, 4)->text());
        ui->comboBox_destination->setCurrentText(ui->search_airline->item(currentRow, 5)->text());
        QDate date = QDate::fromString(ui->search_airline->item(currentRow, 3)->text(), "yyyy-MM-dd");
        ui->dateEdit->setDate(date);

    }
    else {
        qDebug() << "No row selected.";
    }
}

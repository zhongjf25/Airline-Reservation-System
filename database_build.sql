create database airline_database;
use airline_database;

CREATE TABLE UserInfo (
    UserID INT AUTO_INCREMENT PRIMARY KEY,
    UserName VARCHAR(30) NOT NULL,
    UserPwd VARCHAR(30) NOT NULL
);


CREATE TABLE FlightInfo (
    Flt_ID INT AUTO_INCREMENT PRIMARY KEY,
    Flt_Number VARCHAR(10),
    Flt_Company VARCHAR(20),
    Flt_Date DATE,  -- 日期格式为 yyyy-mm-dd
    Departure VARCHAR(10),  -- 出发地
    Destination VARCHAR(10),  -- 目的地
    EcoSeats INT,  -- 经济舱余票
    BusSeats INT,  -- 商务舱余票
    FstSeats INT,   -- 头等舱余票
    price_eco INT,  -- 经济舱价格
    price_bus INT, -- 商务舱价格
    price_fst INT  -- 头等舱价格
);


CREATE TABLE PurchaseInfo (
    OrderID INT AUTO_INCREMENT PRIMARY KEY,
    UserID INT,  -- 购买用户 (外键，关联到 UserInfo)
    FlightID INT,  -- 购买班次 (外键，关联到 FlightInfo)
    PurchaseQuantity INT,  -- 购买数量
    OrderPrice INT,  -- 订单价格
    FOREIGN KEY (UserID) REFERENCES UserInfo(UserID),
    FOREIGN KEY (FlightID) REFERENCES FlightInfo(Flt_ID),
    FlightType INT  -- 0-经济 1-商务 2-头等
);
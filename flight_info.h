#ifndef FLIGHT_INFO_H
#define FLIGHT_INFO_H

#include <QObject>
#include <QDateTime>

class flight_info : public QObject
{
    Q_OBJECT
public:
    explicit flight_info(QObject *parent = nullptr);
    flight_info(QString _Flt_Number,
                QString _Flt_Company,
                QString _Flt_Date,
                QString _Departure,
                QString _Destination,
                qint64 _Eco_Seats,
                qint64 _Bus_Seats,
                qint64 _Fst_Seats,
                qint64 _price_eco,
                qint64 _price_bus,
                qint64 _price_fst,
                QString _time_dep,
                QString _time_arr);
    // getter
    QString getFltNumber() { return this->Flt_Number; }
    QString getFltCompany() { return this->Flt_Company; }
    QString getFltDate() { return this->Flt_Date; }
    QString getDeparture() { return this->Departure; }
    QString getDestination() { return this->Destination; }
    qint64 getEcoSeats() { return this->Eco_Seats; }
    qint64 getBusSeats() { return this->Bus_Seats; }
    qint64 getFstSeats() { return this->Fst_Seats; }
    qint64 getPriceEco() { return this->price_eco; }
    qint64 getPriceBus() { return this->price_bus; }
    qint64 getPriceFst() { return this->price_fst; }
    QString getDepTime() { return this->time_dep;  }
    QString getArrTime() { return this->time_arr;  }
    // setter
    void setFltNumber(QString _Flt_Number) { this->Flt_Number = _Flt_Number; }
    void setFltCompany(QString _Flt_Company) { this->Flt_Company = _Flt_Company; }
    void setFltDate(QString _Flt_Date) { this->Flt_Date = _Flt_Date; }
    void setDeparture(QString _Departure) { this->Departure = _Departure; }
    void setDestination(QString _Destination) { this->Destination = _Destination; }
    void setEcoSeats(qint64 _Eco_Seats) { this->Eco_Seats = _Eco_Seats; }
    void setBusSeats(qint64 _Bus_Seats) { this->Bus_Seats = _Bus_Seats; }
    void setFstSeats(qint64 _Fst_Seats) { this->Fst_Seats = _Fst_Seats; }
    void setPriceEco(qint64 _price_eco) { this->price_eco = _price_eco; }
    void setPriceBus(qint64 _price_bus) { this->price_bus = _price_bus; }
    void setPriceFst(qint64 _price_fst) { this->price_fst = _price_fst; }
    void setDepTime(QString _time_dep) {this->time_dep = _time_dep; }
    void setArrTime(QString _time_arr) {this->time_arr = _time_arr; }

private:
    qint64 Flt_ID;
    QString Flt_Number;
    QString Flt_Company;
    QString Flt_Date;
    QString Departure;
    QString Destination;
    qint64 Eco_Seats;
    qint64 Bus_Seats;
    qint64 Fst_Seats;
    qint64 price_eco;
    qint64 price_bus;
    qint64 price_fst;
    QString time_dep;
    QString time_arr;

signals:
};

#endif // FLIGHT_INFO_H

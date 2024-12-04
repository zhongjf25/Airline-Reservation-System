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
                qint64 _Type,
                qint64 _Eco_Seats,
                qint64 _Bus_Seats,
                qint64 _Fst_Seats,
                qint64 _price_eco,
                qint64 _price_bus,
                qint64 _price_fst);
    QString getFltNumber() { return this->Flt_Number; }
    QString getFltCompany() { return this->Flt_Company; }
    QString getFltDate() { return this->Flt_Date; }
    QString getDeparture() { return this->Departure; }
    QString getDestination() { return this->Destination; }
    qint64 getType() { return this->Type; }
    qint64 getEcoSeats() { return this->Eco_Seats; }
    qint64 getBusSeats() { return this->Bus_Seats; }
    qint64 getFstSeats() { return this->Fst_Seats; }
    qint64 getPriceEco() { return this->price_eco; }
    qint64 getPriceBus() { return this->price_bus; }
    qint64 getPriceFst() { return this->price_fst; }

private:
    qint64 Flt_ID;
    QString Flt_Number;
    QString Flt_Company;
    QString Flt_Date;
    QString Departure;
    QString Destination;
    qint64 Type;
    qint64 Eco_Seats;
    qint64 Bus_Seats;
    qint64 Fst_Seats;
    qint64 price_eco;
    qint64 price_bus;
    qint64 price_fst;

signals:
};

#endif // FLIGHT_INFO_H

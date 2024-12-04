#include "flight_info.h"

flight_info::flight_info(QObject *parent)
    : QObject{parent}
{}


flight_info::flight_info(QString _Flt_Number,
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
                         qint64 _price_fst)
{
    this->Flt_Number = _Flt_Number;
    this->Flt_Company = _Flt_Company;
    this->Flt_Date = _Flt_Date;
    this->Departure = _Departure;
    this->Destination = _Destination;
    this->Type = _Type;
    this->Eco_Seats = _Eco_Seats;
    this->Bus_Seats = _Bus_Seats;
    this->Fst_Seats = _Fst_Seats;
    this->price_eco = _price_eco;
    this->price_bus = _price_bus;
    this->price_fst = _price_fst;
}

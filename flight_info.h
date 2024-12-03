#ifndef FLIGHT_INFO_H
#define FLIGHT_INFO_H

#include <QObject>
#include <QDateTime>

class flight_info : public QObject
{
    Q_OBJECT
public:
    explicit flight_info(QObject *parent = nullptr);

private:
    qint64 Flt_ID;
    QString Flt_Number;
    QString Flt_Company;
    QDateTime Flt_Date;
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

#ifndef BROKER_H
#define BROKER_H
#include <QString>

class broker
{
private:
    int id;
    QString name;
    QString pas;
    QString phone_number;
    int number_of_sales;
public:
    broker();
    broker(int id, QString name, QString pas, QString phone_number, int number_of_sales);
    int get_id() const;
    QString get_name() const;
    QString get_pas() const;
    QString get_phone_number() const;
    int get_number_of_sales() const;
    void plus_number_of_sales();
};

#endif // BROKER_H

#include "broker.h"

broker::broker(int id, QString name, QString pas, QString phone_number, int number_of_sales)
{
    this->id = id;
    this->name = name;
    this->pas = pas;
    this->phone_number = phone_number;
    this->number_of_sales = number_of_sales;
}


int broker::get_id()  const
{
    return id;
}


QString broker::get_name()  const
{
    return name;
}


QString broker::get_pas()  const
{
    return pas;
}


QString broker::get_phone_number()  const
{
    return phone_number;
}


int broker::get_number_of_sales()  const
{
    return number_of_sales;
}


void broker::plus_number_of_sales()
{
    number_of_sales = number_of_sales + 1;
}

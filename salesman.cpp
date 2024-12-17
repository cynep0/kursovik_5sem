#include "salesman.h"

int salesman::get_id()  const
{
    return id;
}


QString salesman::get_name()  const
{
    return name;
}


QString salesman::get_pas()  const
{
    return pas;
}


QString salesman::get_phone_number()  const
{
    return phone_number;
}


salesman::salesman(int id, QString name, QString pas, QString phone_number)
{
    this->id = id;
    this->name = name;
    this->pas = pas;
    this->phone_number = phone_number;
}


salesman::salesman() {}

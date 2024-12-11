#include "buyer.h"


buyer::buyer(int id, QString name, QString pas)
{
    this->id = id;
    this->name = name;
    this->pas = pas;
}


int buyer::get_id() const
{
    return id;
}


QString buyer::get_name() const
{
    return name;
}


QString buyer::get_pas() const
{
    return pas;
}

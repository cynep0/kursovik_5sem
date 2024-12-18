#include "buyer.h"

buyer::buyer(){}


buyer::buyer(int id, QString name, QString pas, QString phone_number, int credit_rating)
{
    this->id = id;
    this->name = name;
    this->pas = pas;
    this->phone_number = phone_number;
    this->credit_rating = credit_rating;
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


QString buyer::get_phone_number() const
{
    return phone_number;
}


int buyer::get_credit_rating() const
{
    return credit_rating;
}

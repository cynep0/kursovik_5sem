#include "flat.h"

flat::flat(){}


flat::flat(int id, QString adres, estate_type type, int area, int cost,  bool is_ins, bool is_sold, int rate, salesman &seller)
{
    this->id = id;
    this->adres = adres;
    this->type = type;
    this->area = area;
    this->cost = cost;
    this->is_ins = is_ins;
    this->is_sold = is_sold;
    this->rate = rate;
    this->seller = seller;
}


int flat::get_id() const
{
    return id;
}


QString flat::get_adres() const
{
    return adres;
}


flat::estate_type flat::get_type() const
{
    return type;
}


int flat::get_area() const
{
    return area;
};


int flat::get_cost() const
{
    return cost;
}


bool flat::get_is_ins() const
{
    return is_ins;
}


bool flat::get_is_sold() const
{
    return is_sold;
}


int flat::get_rate() const
{
    return rate;
}


const salesman& flat::get_salesman() const
{
    return seller;
}


void flat::change_sold(bool sb)
{
    this->is_sold = sb;
    if(sb)
        qDebug("s+");
    else
        qDebug("s-");
}



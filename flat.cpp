#include "flat.h"


flat::flat(int id, QString adres, int area, bool is_ins, bool is_sold)
{
    this->id = id;
    this->adres = adres;
    this->area = area;
    this->is_ins = is_ins;
    this->is_sold = is_sold;
}


int flat::get_id() const
{
    return id;
}


QString flat::get_adres() const
{
    return adres;
}


int flat::get_area() const
{
    return area;
};


bool flat::get_is_ins() const
{
    return is_ins;
}


bool flat::get_is_sold() const
{
    return is_sold;
}


void flat::change_sold(bool sb)
{
    this->is_sold = sb;
    if(sb)
        qDebug("s+");
    else
        qDebug("s-");
}



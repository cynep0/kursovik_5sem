#include "sale.h"

sale::sale(int id, int id_flat, int id_buyer)
{
    this->id = id;
    this->id_flat = id_flat;
    this->id_buyer = id_buyer;
}


int sale::get_id() const
{
    return id;
}


int sale::get_id_flat() const
{
    return id_flat;
}


int sale::get_id_buyer() const
{
    return id_buyer;
}



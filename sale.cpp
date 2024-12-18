#include "sale.h"

sale::sale(int id, flat flat, buyer buyer, broker broker)
{
    this->id = id;
    flat1 = flat;
    buyer1 = buyer;
    broker1 = broker;
}


int sale::get_id() const
{
    return id;
}


const flat& sale::get_flat() const
{
    return flat1;
}


const buyer& sale::get_buyer() const
{
    return buyer1;
}


const broker& sale::get_broker() const
{
    return broker1;
}


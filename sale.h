#ifndef SALE_H
#define SALE_H

#include "flat.h"
#include "buyer.h"
#include "broker.h"

class sale
{
private:
    int id;
    flat flat1;
    buyer buyer1;
    broker broker1;
public:
    sale(int id, flat flat, buyer buyer, broker broker);
    int get_id() const;
    const flat& get_flat() const;
    const buyer& get_buyer() const;
    const broker& get_broker() const;
};

#endif // SALE_H

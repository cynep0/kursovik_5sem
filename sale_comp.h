#ifndef SALE_COMP_H
#define SALE_COMP_H

#include "subject.h"
#include "sale.h"
#include <list>
#include "flat_comp.h"
#include "buyer_comp.h"
#include "broker_comp.h"


class sale_comp : public subject
{
private:
    std::list<sale> list_sales;
public:
    bool find(int id);
    bool find_by_buyer(int id_b);
    bool find_by_broker(int id_broker);
    bool find_by_seller(int id_seller);
    void add_sale(sale sale, flat_comp& flat_comp, buyer_comp& buyer_comp, broker_comp& broker_comp);
    void remove_sale(int id, flat_comp& flat_comp);
    void remove_sale_by_flat(int id_flat);
    void remove_sale_by_buyer(int id_buyer);
    void remove_sale_by_broker(int id_broker);
    void remove_sale_by_seller(int id_seller);
    std::list<sale> get_sales();
};

#endif // SALE_COMP_H

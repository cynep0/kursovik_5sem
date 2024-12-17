#ifndef BUYER_COMP_H
#define BUYER_COMP_H

#include "subject.h"
#include "buyer.h"
#include <list>


class buyer_comp: public subject
{
private:
    std::list<buyer> list_buyers;
public:
    bool find(int id);
    buyer get_buyer(int id);
    void add_buyer(buyer buyer);
    void remove_buyer(int id);
    std::list<buyer> get_buyers();
};

#endif // BUYER_COMP_H

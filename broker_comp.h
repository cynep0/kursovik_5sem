#ifndef BROKER_COMP_H
#define BROKER_COMP_H

#include "subject.h"
#include "broker.h"
#include <list>


class broker_comp: public subject
{
private:
    std::list<broker> list_brokers;
public:
    bool find(int id);
    broker get_broker(int id);
    void add_broker(broker broker);
    void remove_broker(int id);
    std::list<broker> get_brokers();
};

#endif // BROKER_COMP_H

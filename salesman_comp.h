#ifndef SALESMAN_COMP_H
#define SALESMAN_COMP_H

#include "subject.h"
#include "salesman.h"
#include <list>


class salesman_comp: public subject
{
private:
    std::list<salesman> list_salesmans;
public:
    bool find(int id);
    salesman get_salesman(int id);
    void add_salesman(salesman salesman);
    void remove_salesman(int id);
    std::list<salesman> get_salesmans();
};

#endif // SALESMAN_COMP_H

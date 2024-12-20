#ifndef FLAT_COMP_H
#define FLAT_COMP_H

#include "subject.h"
#include "flat.h"
#include <list>


class flat_comp : public subject
{
private:
    std::list<flat> list_flats;
public:
    bool find(int id);
    flat get_flat(int id);
    bool find_by_seller(int id_seller);
    void change_sold(int id, bool sb);
    bool is_sold(int id);
    void add_flat(flat flat);
    void remove_flat(int id);
    void remove_flat_by_seller(int id_seller);
    std::list<flat> get_flats();
};

#endif // FLAT_COMP_H

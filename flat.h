#ifndef FLAT_H
#define FLAT_H
#include <QString>
#include "salesman.h"

class flat
{
public:
    enum estate_type {
        FLAT,
        OFFICE,
        COTTAGE
    };
private:
    int id;
    QString adres;
    estate_type type;
    int area;
    int cost;
    bool is_ins;
    bool is_sold;
    int rate;
    salesman seller;
public:
    flat(int id, QString adres, estate_type type, int area, int cost, bool is_ins, bool is_sold, int rate, salesman &seller);
    int get_id() const;
    QString get_adres() const;
    estate_type get_type() const;
    int get_area() const;
    int get_cost() const;
    bool get_is_ins() const;
    bool get_is_sold() const;
    int get_rate() const;
    const salesman& get_salesman() const;
    void change_sold(bool sb);
};

#endif // FLAT_H

#ifndef FLAT_H
#define FLAT_H
#include <QString>
#include "salesman.h"

class flat
{
public:
    enum estate_type {
        FLATE,
        OFFICE,
        COTTAGE
    };
private:
    int id;
    QString adres;
    int postal_address;
    estate_type type;
    int area;
    int cost;
    bool is_ins;
    bool is_sold;
    int rate;
    salesman seller;
public:
    flat(int id, QString adres, int area, bool is_ins, bool is_sold);
    int get_id() const;
    QString get_adres() const;
    int get_area() const;
    bool get_is_ins() const;
    bool get_is_sold() const;
    void change_sold(bool sb);
};

#endif // FLAT_H

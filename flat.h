#ifndef FLAT_H
#define FLAT_H
#include <QString>

class flat
{
private:
    int id;
    QString adres;
    int area;
    bool is_ins;
    bool is_sold;
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

#ifndef SALE_H
#define SALE_H

class sale
{
private:
    int id;
    int id_flat;
    int id_buyer;
public:
    sale(int id, int id_flat, int id_buyer);
    int get_id() const;
    int get_id_flat() const;
    int get_id_buyer() const;
};

#endif // SALE_H

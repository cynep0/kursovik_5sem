#ifndef BUYER_H
#define BUYER_H
#include <QString>

class buyer
{
private:
    int id;
    QString name;
    QString pas;
    QString phone_number;
    int credit_rating;
public:
    buyer(int id, QString name, QString pas, QString phone_number, int credit_rating);
    int get_id() const;
    QString get_name() const;
    QString get_pas() const;
    QString get_phone_number() const;
    int get_credit_rating() const;
};

#endif // BUYER_H

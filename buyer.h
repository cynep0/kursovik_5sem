#ifndef BUYER_H
#define BUYER_H
#include <QString>

class buyer
{
private:
    int id;
    QString name;
    QString pas;
public:
    buyer(int id, QString name, QString pas);
    int get_id() const;
    QString get_name() const;
    QString get_pas() const;
};

#endif // BUYER_H

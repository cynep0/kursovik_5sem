#ifndef SALESMAN_H
#define SALESMAN_H
#include <QString>

class salesman
{
private:
    int id;
    QString name;
    QString pas;
    QString phone_number;
public:
    salesman();
    salesman(int id, QString name, QString pas, QString phone_number);
    int get_id()  const;
    QString get_name()  const;
    QString get_pas()  const;
    QString get_phone_number()  const;
};

#endif // SALESMAN_H

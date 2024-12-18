#ifndef ADD_SALESMAN_H
#define ADD_SALESMAN_H

#include <QWidget>

#include "salesman_comp.h"

namespace Ui {
class add_salesman;
}

class add_salesman : public QWidget
{
    Q_OBJECT

public:
    add_salesman(salesman_comp *salesman_comp);
    ~add_salesman();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_salesman *ui;
    salesman_comp *salesman_comp1;
};

#endif // ADD_SALESMAN_H

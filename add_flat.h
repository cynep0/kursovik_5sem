#ifndef ADD_FLAT_H
#define ADD_FLAT_H

#include <QWidget>

#include "flat_comp.h"
#include "salesman_comp.h"

namespace Ui {
class add_flat;
}

class add_flat : public QWidget
{
    Q_OBJECT

public:
    add_flat(flat_comp *flat_comp, salesman_comp *salesman_comp);
    ~add_flat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_flat *ui;
    flat_comp *flat_comp1;
    salesman_comp *salesman_comp1;
};

#endif // ADD_FLAT_H

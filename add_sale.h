#ifndef ADD_SALE_H
#define ADD_SALE_H

#include <QWidget>
#include "buyer_comp.h"
#include "flat_comp.h"
#include "sale_comp.h"
#include "broker_comp.h"

namespace Ui {
class add_sale;
}

class add_sale : public QWidget
{
    Q_OBJECT

public:
    add_sale(flat_comp *flat_comp, buyer_comp *buyer_comp, sale_comp *sale_comp);
    ~add_sale();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_sale *ui;
    flat_comp *flat_comp1;
    buyer_comp *buyer_comp1;
    sale_comp *sale_comp1;
};

#endif // ADD_SALE_H

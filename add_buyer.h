#ifndef ADD_BUYER_H
#define ADD_BUYER_H

#include <QWidget>

#include "buyer_comp.h"

namespace Ui {
class add_buyer;
}

class add_buyer : public QWidget
{
    Q_OBJECT

public:
    add_buyer(buyer_comp *buyer_comp);
    ~add_buyer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_buyer *ui;
    buyer_comp *buyer_comp1;
};

#endif // ADD_BUYER_H

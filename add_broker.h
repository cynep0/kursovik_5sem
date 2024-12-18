#ifndef ADD_BROKER_H
#define ADD_BROKER_H

#include <QWidget>

#include "broker_comp.h"

namespace Ui {
class add_broker;
}

class add_broker : public QWidget
{
    Q_OBJECT

public:
    add_broker(broker_comp *broker_comp);
    ~add_broker();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_broker *ui;
    broker_comp *broker_comp1;
};

#endif // ADD_BROKER_H

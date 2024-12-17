#ifndef ADD_BROKER_H
#define ADD_BROKER_H

#include <QWidget>

#include "broker.h"

namespace Ui {
class add_broker;
}

class add_broker : public QWidget
{
    Q_OBJECT

public:
    explicit add_broker(QWidget *parent = nullptr);
    ~add_broker();

private:
    Ui::add_broker *ui;
};

#endif // ADD_BROKER_H

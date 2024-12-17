#include "add_broker.h"
#include "ui_add_broker.h"

add_broker::add_broker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_broker)
{
    ui->setupUi(this);
}

add_broker::~add_broker()
{
    delete ui;
}

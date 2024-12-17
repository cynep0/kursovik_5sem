#include "add_salesman.h"
#include "ui_add_salesman.h"

add_salesman::add_salesman(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_salesman)
{
    ui->setupUi(this);
}

add_salesman::~add_salesman()
{
    delete ui;
}

#include "add_flat.h"
#include "ui_add_flat.h"
#include <QMessageBox>
#include <QIntValidator>

add_flat::add_flat(flat_comp *flat_comp, salesman_comp *salesman_comp)
    :ui(new Ui::add_flat)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_area->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_cost->setValidator( new QIntValidator(1, 500000000, this));
    ui->lineEdit_rate->setValidator( new QIntValidator(1, 10, this));
    flat_comp1 = flat_comp;
    salesman_comp1 = salesman_comp;

    ui->comboBox_seller->clear();
    for (const salesman& seller : salesman_comp1->get_salesmans())
    {
        ui->comboBox_seller->addItem(QString::number(seller.get_id()));
    }
}

add_flat::~add_flat()
{
    delete ui;
}

void add_flat::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_adres->text() != "" && ui->lineEdit_area->text() != "" && ui->lineEdit_cost->text() != "" && ui->lineEdit_rate->text() != "" && ui->comboBox_seller->currentText() != "")
    {
        int seller_id = ui->comboBox_seller->currentText().toInt();
        flat::estate_type type = flat::FLAT;
        switch (ui->comboBox_type->currentIndex()) {
        case 0:
            type = flat::FLAT;
            break;
        case 1:
            type = flat::OFFICE;
            break;
        case 2:
            type = flat::COTTAGE;
            break;
        }
        salesman seller = salesman_comp1->get_salesman(seller_id);
        flat flat1(ui->lineEdit_id->text().toInt(), ui->lineEdit_adres->text(), type, ui->lineEdit_area->text().toInt(), ui->lineEdit_cost->text().toInt(), ui->checkBox_ins->isChecked(), false, ui->lineEdit_rate->text().toInt(), seller);
        flat_comp1->add_flat(flat1);
        this->close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("заполните все поля");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
}


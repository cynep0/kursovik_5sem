#include "add_sale.h"
#include "ui_add_sale.h"
#include <QMessageBox>
#include <QIntValidator>

add_sale::add_sale(flat_comp *flat_comp, buyer_comp *buyer_comp, sale_comp *sale_comp)
    :ui(new Ui::add_sale)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_id_buyer->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_id_flat->setValidator( new QIntValidator(1, 10000, this));
    flat_comp1 = flat_comp;
    buyer_comp1 = buyer_comp;
    sale_comp1 = sale_comp;
}

add_sale::~add_sale()
{
    delete ui;
}

void add_sale::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_id_buyer->text() != "" && ui->lineEdit_id_flat->text() != "")
    {
        buyer buyer4(4, "Проверкин Проверяльщик Проверялков", "1234 567890", "8 611 666 61 66", 1000);
        salesman salesman2(2, "Ковалева Анна Александровна", "4002 112345", "8 911 127 43 73");
        flat flat4(4, "ул. Пушкина д.Колотушкина", flat::estate_type::COTTAGE, 60, 17000000, false, false, 10, salesman2);
        broker broker3(3, "Алатырев Данила Артемович", "4018 274642", "8 933 575 54 34", 0);
        sale sale1(ui->lineEdit_id->text().toInt(), flat4, buyer4, broker3);
        sale_comp1->add_sale(sale1, *flat_comp1, *buyer_comp1);
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


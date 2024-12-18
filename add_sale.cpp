#include "add_sale.h"
#include "ui_add_sale.h"
#include <QMessageBox>
#include <QIntValidator>

add_sale::add_sale(flat_comp *flat_comp, buyer_comp *buyer_comp, sale_comp *sale_comp, broker_comp *broker_comp)
    :ui(new Ui::add_sale)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));
    flat_comp1 = flat_comp;
    buyer_comp1 = buyer_comp;
    sale_comp1 = sale_comp;
    broker_comp1 = broker_comp;

    ui->comboBox_buyer->clear();
    for (const buyer& b : buyer_comp1->get_buyers())
    {
        ui->comboBox_buyer->addItem(QString::number(b.get_id()));
    }
    ui->comboBox_flat->clear();
    for (const flat& f : flat_comp1->get_flats())
    {
        if (!f.get_is_sold())
            ui->comboBox_flat->addItem(QString::number(f.get_id()));
    }
    ui->comboBox_broker->clear();
    for (const broker& b : broker_comp1->get_brokers())
    {
        ui->comboBox_broker->addItem(QString::number(b.get_id()));
    }
}

add_sale::~add_sale()
{
    delete ui;
}

void add_sale::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->comboBox_buyer->currentText() != "" && ui->comboBox_flat->currentText() != ""  && ui->comboBox_broker->currentText() != "")
    {
        buyer buyer1 = buyer_comp1->get_buyer(ui->comboBox_buyer->currentText().toInt());
        flat flat1 = flat_comp1->get_flat(ui->comboBox_flat->currentText().toInt());
        broker broker1 = broker_comp1->get_broker(ui->comboBox_broker->currentText().toInt());
        sale sale1(ui->lineEdit_id->text().toInt(), flat1, buyer1, broker1);
        sale_comp1->add_sale(sale1, *flat_comp1, *buyer_comp1, *broker_comp1);
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


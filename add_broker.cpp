#include "add_broker.h"
#include "ui_add_broker.h"
#include <QMessageBox>
#include <QIntValidator>


add_broker::add_broker(broker_comp *broker_comp)
    : ui(new Ui::add_broker)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));

    broker_comp1 = broker_comp;
}

add_broker::~add_broker()
{
    delete ui;
}


void add_broker::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_fio->text() != "" && ui->lineEdit_pas->text() != "" && ui->lineEdit_phone->text() != "")
    {
        broker broker1(ui->lineEdit_id->text().toInt(), ui->lineEdit_fio->text(), ui->lineEdit_pas->text(), ui->lineEdit_phone->text(), 0);
        broker_comp1->add_broker(broker1);
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


#include "add_buyer.h"
#include "buyer_comp.h"
#include "ui_add_buyer.h"
#include <QMessageBox>
#include <QIntValidator>


add_buyer::add_buyer(buyer_comp *buyer_comp)
    : ui(new Ui::add_buyer)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));

    buyer_comp1 = buyer_comp;
}

add_buyer::~add_buyer()
{
    delete ui;
}


void add_buyer::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_fio->text() != "" && ui->lineEdit_pas->text() != "" && ui->lineEdit_phone->text() != "" && ui->lineEdit_credit->text() != "")
    {
        buyer buyer1(ui->lineEdit_id->text().toInt(), ui->lineEdit_fio->text(), ui->lineEdit_pas->text(), ui->lineEdit_phone->text(), ui->lineEdit_credit->text().toInt());
        buyer_comp1->add_buyer(buyer1);
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


#include "add_salesman.h"
#include "ui_add_salesman.h"
#include <QMessageBox>
#include <QIntValidator>


add_salesman::add_salesman(salesman_comp *salesman_comp)
    : ui(new Ui::add_salesman)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));

    salesman_comp1 = salesman_comp;
}

add_salesman::~add_salesman()
{
    delete ui;
}


void add_salesman::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_fio->text() != "" && ui->lineEdit_pas->text() != "" && ui->lineEdit_phone->text() != "")
    {
        salesman salesman1(ui->lineEdit_id->text().toInt(), ui->lineEdit_fio->text(), ui->lineEdit_pas->text(), ui->lineEdit_phone->text());
        salesman_comp1->add_salesman(salesman1);
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


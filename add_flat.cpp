#include "add_flat.h"
#include "ui_add_flat.h"
#include <QMessageBox>
#include <QIntValidator>

add_flat::add_flat(flat_comp *flat_comp)
    :ui(new Ui::add_flat)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_area->setValidator( new QIntValidator(1, 10000, this));
    flat_comp1 = flat_comp;
}

add_flat::~add_flat()
{
    delete ui;
}

void add_flat::on_pushButton_clicked()
{
    if (ui->lineEdit_id->text() != "" && ui->lineEdit_adres->text() != "" && ui->lineEdit_area->text() != "")
    {
        flat flat1(ui->lineEdit_id->text().toInt(), ui->lineEdit_adres->text(), ui->lineEdit_area->text().toInt(), ui->checkBox_ins->isChecked(), false);
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


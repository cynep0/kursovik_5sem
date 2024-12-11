#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //валидаторы
    ui->lineEdit_del_buyer->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_del_flat->setValidator( new QIntValidator(1, 10000, this));
    ui->lineEdit_del_sale->setValidator( new QIntValidator(1, 10000, this));


    buyer_comp.add_observer(this);
    flat_comp.add_observer(this);
    sale_comp.add_observer(this);

     // Инициализируем модели для таблиц
    model_flat = new QStandardItemModel(this);
    ui->tableView_flat->setModel(model_flat);

    model_buyer = new QStandardItemModel(this);
    ui->tableView_buyer->setModel(model_buyer);

    model_sale = new QStandardItemModel(this);
    ui->tableView_sale->setModel(model_sale);

    model_flat->setHorizontalHeaderLabels(QStringList() << "id квартиры" << "адрес" << "площадь" << "наличие страховки" << "состояние продажи");
    model_buyer->setHorizontalHeaderLabels(QStringList() << "id покупателя" << "ФИО" << "паспорт");
    model_sale->setHorizontalHeaderLabels(QStringList() << "id договора" << "id покупателя" << "id квартиры");


    //задаем значения
    buyer buyer1(1, "Инюшин Михаил Андреевич", "4018 049013");
    buyer buyer2(2, "Козлов Никита Александрович", "4018 198263");
    buyer buyer3(3, "Ивонов Ивон Иванович", "1111 111111");
    buyer buyer4(4, "Проверкин Проверяльщик Проверялков", "1234 567890");

    buyer_comp.add_buyer(buyer1);
    buyer_comp.add_buyer(buyer2);
    buyer_comp.add_buyer(buyer3);
    buyer_comp.add_buyer(buyer4);

    flat flat1(1, "ул. Коломенская д.15-17 кв.93", 60, true, false);
    flat flat2(2, "ул. Коломенская д.15-17 кв.90", 60, false, false);
    flat flat3(3, "ул. Ивановская д.57 кв.6", 60, false, false);
    flat flat4(4, "ул. Пукина д.Колотушкина кв.37", 60, false, false);
    flat flat5(5, "Ленинский д.6 кв.226", 60, false, false);


    flat_comp.add_flat(flat1);
    flat_comp.add_flat(flat2);
    flat_comp.add_flat(flat3);
    flat_comp.add_flat(flat4);
    flat_comp.add_flat(flat5);


    sale sale1(1, 1, 1);
    sale sale2(2, 2, 3);
    sale sale3(3, 3, 3);

    sale_comp.add_sale(sale1, flat_comp, buyer_comp);
    sale_comp.add_sale(sale2, flat_comp, buyer_comp);
    sale_comp.add_sale(sale3, flat_comp, buyer_comp);

    ui->tableView_flat->resizeColumnsToContents();
    ui->tableView_buyer->resizeColumnsToContents();
    ui->tableView_sale->resizeColumnsToContents();
}


void MainWindow::update() {
    model_buyer->removeRows(0, model_buyer->rowCount());
    for (const buyer& buyer : buyer_comp.get_buyers()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(buyer.get_id()));
        row << new QStandardItem(buyer.get_name());
        row << new QStandardItem(buyer.get_pas());
        model_buyer->appendRow(row);
    }

    model_flat->removeRows(0, model_flat->rowCount());
    for (const flat& flat : flat_comp.get_flats()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(flat.get_id()));
        row << new QStandardItem(flat.get_adres());
        row << new QStandardItem(QString::number(flat.get_area()));
        row << new QStandardItem(flat.get_is_ins() ? "застрахована" : "не застрахована");
        row << new QStandardItem(flat.get_is_sold() ? "куплена" : "продается");
        model_flat->appendRow(row);
    }

    model_sale->removeRows(0, model_sale->rowCount());
    for (const sale& sale : sale_comp.get_sales()) {
        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(sale.get_id()));
        row << new QStandardItem(QString::number(sale.get_id_buyer()));
        row << new QStandardItem(QString::number(sale.get_id_flat()));
        model_sale->appendRow(row);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_add_buyer_clicked()
{
    add_buyer *b_form = new add_buyer(&buyer_comp);
    b_form->show();
}


void MainWindow::on_btn_del_buyer_clicked()
{
    while(sale_comp.find_by_buyer(ui->lineEdit_del_buyer->text().toInt()))
        sale_comp.remove_sale_by_buyer(ui->lineEdit_del_buyer->text().toInt(), flat_comp);
    buyer_comp.remove_buyer(ui->lineEdit_del_buyer->text().toInt());
}


void MainWindow::on_btn_add_flat_clicked()
{
    add_flat *f_form = new add_flat(&flat_comp);
    f_form->show();
}


void MainWindow::on_btn_del_flat_clicked()
{
    sale_comp.remove_sale_by_flat(ui->lineEdit_del_flat->text().toInt());
    flat_comp.remove_flat(ui->lineEdit_del_flat->text().toInt());
}


void MainWindow::on_btn_add_sale_clicked()
{
    add_sale *s_form = new add_sale(&flat_comp, &buyer_comp, &sale_comp);
    s_form->show();
}


void MainWindow::on_btn_del_sale_clicked()
{
    sale_comp.remove_sale(ui->lineEdit_del_sale->text().toInt(), flat_comp);
}


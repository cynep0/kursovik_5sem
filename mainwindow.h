#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "observer.h"
#include "ui_mainwindow.h"

#include "buyer_comp.h"
#include "flat_comp.h"
#include "sale_comp.h"
#include "salesman_comp.h"
#include "broker_comp.h"

#include "add_buyer.h"
#include "add_flat.h"
#include "add_sale.h"


class MainWindow : public QMainWindow, public observer
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update();

private slots:
    void on_btn_add_buyer_clicked();
    void on_btn_del_buyer_clicked();
    void on_btn_add_flat_clicked();
    void on_btn_del_flat_clicked();
    void on_btn_add_sale_clicked();
    void on_btn_del_sale_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model_flat;
    QStandardItemModel* model_buyer;
    QStandardItemModel* model_sale;
    QStandardItemModel* model_salesman;
    QStandardItemModel* model_broker;
    buyer_comp buyer_comp;
    flat_comp flat_comp;
    sale_comp sale_comp;
    salesman_comp salesman_comp;
    broker_comp broker_comp;
};
#endif // MAINWINDOW_H

#include "sale_comp.h"
#include <QMessageBox>


bool sale_comp::find(int id)
{
    for (sale b: list_sales) {
        if (b.get_id() == id)
            return true;
    }
    return false;
}


bool sale_comp::find_by_buyer(int id_b)
{
    for (sale b: list_sales) {
        if (b.get_buyer().get_id() == id_b)
            return true;
    }
    return false;
}


void sale_comp::add_sale(sale sale, flat_comp& flat_comp, buyer_comp& buyer_comp)
{
    if (find(sale.get_id()))
    {
        QMessageBox msgBox;
        msgBox.setText("такой id договора уже занят");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }
    if (!flat_comp.find(sale.get_flat().get_id()))
    {
        QMessageBox msgBox;
        msgBox.setText("такого id квартиры не существует");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }
    if (sale.get_flat().get_is_sold())
    {
        QMessageBox msgBox;
        msgBox.setText("квартира уже продана");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }
    if (!buyer_comp.find(sale.get_buyer().get_id()))
    {
        QMessageBox msgBox;
        msgBox.setText("такоео id покупателя не существует");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
        return;
    }
    flat_comp.change_sold(sale.get_flat().get_id(), true);
    list_sales.push_back(sale);
    notify_observers();
}

void sale_comp::remove_sale(int id, flat_comp& flat_comp)
{
    for (auto iter = list_sales.begin(); iter != list_sales.end(); iter++)
    {
        qDebug() << (*iter).get_id();
        if ((*iter).get_id() == id)
        {
            qDebug("------");
            flat_comp.change_sold(iter->get_flat().get_id(), false);
            list_sales.erase(iter);
            notify_observers();
            return;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("нет такого id");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

}


void sale_comp::remove_sale_by_flat(int id_flat)
{
    qDebug("d");
    for (auto iter = list_sales.begin(); iter != list_sales.end(); iter++)
    {
        if ((*iter).get_flat().get_id() == id_flat)
        {
            qDebug("deleted");
            list_sales.erase(iter);
        }
    }
}


void sale_comp::remove_sale_by_buyer(int id_buyer, flat_comp& flat_comp)
{
    for (auto iter = list_sales.begin(); iter != list_sales.end(); iter++)
    {
        if ((*iter).get_buyer().get_id() == id_buyer)
        {
            flat_comp.remove_flat(iter->get_flat().get_id());
            list_sales.erase(iter);
        }
    }
}


std::list<sale> sale_comp::get_sales()
{
    return list_sales;
}


#include "buyer_comp.h"
#include <QMessageBox>


bool buyer_comp::find(int id)
{
    for (buyer b: list_buyers) {
        if (b.get_id() == id)
            return true;
    }
    return false;
}


void buyer_comp::add_buyer(buyer buyer)
{
    if (!find(buyer.get_id()))
    {
        list_buyers.push_back(buyer);
        notify_observers();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("такой id уже занят");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
}

void buyer_comp::remove_buyer(int id)
{
    for (auto iter = list_buyers.begin(); iter != list_buyers.end(); iter++)
    {
        qDebug() <<(*iter).get_id();
        if ((*iter).get_id() == id)
        {
            qDebug("------");
            list_buyers.erase(iter);
            notify_observers();
            return;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("нет такого id");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

}

std::list<buyer> buyer_comp::get_buyers()
{
    return list_buyers;
}

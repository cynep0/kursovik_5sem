#include "broker_comp.h"

#include <QMessageBox>


bool broker_comp::find(int id)
{
    for (broker b: list_brokers) {
        if (b.get_id() == id)
            return true;
    }
    return false;
}


broker broker_comp::get_broker(int id) {
    for (broker& b: list_brokers) {
        if (b.get_id() == id) {
            return b;
        }
    }
    return broker(0, "", "", "", 0);
}


void broker_comp::plus_number_of_sales(int id)
{
    for (auto iter = list_brokers.begin(); iter != list_brokers.end(); iter++){
        if (iter->get_id() == id)
            iter->plus_number_of_sales();
    }
}


void broker_comp::add_broker(broker broker)
{
    if (!find(broker.get_id()))
    {
        list_brokers.push_back(broker);
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

void broker_comp::remove_broker(int id)
{
    for (auto iter = list_brokers.begin(); iter != list_brokers.end(); iter++)
    {
        qDebug() <<(*iter).get_id();
        if ((*iter).get_id() == id)
        {
            qDebug("------");
            list_brokers.erase(iter);
            notify_observers();
            return;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("нет такого id");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

}

std::list<broker> broker_comp::get_brokers()
{
    return list_brokers;
}


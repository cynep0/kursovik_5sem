#include "salesman_comp.h"
#include <QMessageBox>


bool salesman_comp::find(int id)
{
    for (salesman b: list_salesmans) {
        if (b.get_id() == id)
            return true;
    }
    return false;
}


salesman salesman_comp::get_salesman(int id) {
    for (salesman& b: list_salesmans) {
        if (b.get_id() == id) {
            return b;
        }
    }
    return salesman(0, "", "", "");
}


void salesman_comp::add_salesman(salesman salesman)
{
    if (!find(salesman.get_id()))
    {
        list_salesmans.push_back(salesman);
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

void salesman_comp::remove_salesman(int id)
{
    for (auto iter = list_salesmans.begin(); iter != list_salesmans.end(); iter++)
    {
        qDebug() <<(*iter).get_id();
        if ((*iter).get_id() == id)
        {
            qDebug("------");
            list_salesmans.erase(iter);
            notify_observers();
            return;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("нет такого id");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

}

std::list<salesman> salesman_comp::get_salesmans()
{
    return list_salesmans;
}

#include "flat_comp.h"
#include <QMessageBox>


bool flat_comp::find(int id)
{
    for (flat b: list_flats) {
        if (b.get_id() == id)
            return true;
    }
    return false;
}


flat flat_comp::get_flat(int id) {
    for (flat& f: list_flats) {
        if (f.get_id() == id) {
            return f;
        }
    }
    salesman salesman0(0, "", "", "");
    return flat(0, "", flat::FLAT, 0, 0, false, false, 0, salesman0);
}


void flat_comp::change_sold(int id, bool sb)
{
    for (auto iter = list_flats.begin(); iter != list_flats.end(); iter++){
        if (iter->get_id() == id)
            iter->change_sold(sb);
    }
}


bool flat_comp::is_sold(int id)
{
    for (flat b: list_flats) {
        if (b.get_id() == id)
            return b.get_is_sold();
    }
}


void flat_comp::add_flat(flat flat)
{
    if (!find(flat.get_id()))
    {
        qDebug("f+");
        list_flats.push_back(flat);
        notify_observers();
    }
    else
    {
        qDebug("fh");
        QMessageBox msgBox;
        msgBox.setText("такой id уже занят");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
}

void flat_comp::remove_flat(int id)
{
    for (auto iter = list_flats.begin(); iter != list_flats.end(); iter++)
    {
        qDebug() << (*iter).get_id();
        if ((*iter).get_id() == id)
        {
            qDebug("------");
            list_flats.erase(iter);
            notify_observers();
            return;
        }
    }
    QMessageBox msgBox;
    msgBox.setText("нет такого id");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

}

std::list<flat> flat_comp::get_flats()
{
    return list_flats;
}

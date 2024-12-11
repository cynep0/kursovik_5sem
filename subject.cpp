#include "subject.h"
#include <algorithm>


void subject::add_observer(observer* observer)
{
    observers.push_back(observer);
}


void subject::remove_observer(observer* observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}


void subject::notify_observers()
{
    for (observer* observer : observers)
        observer->update();
}




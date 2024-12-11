#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>

class subject
{
public:
    void add_observer(observer* observer);
    void remove_observer(observer* observer);
    void notify_observers();
private:
    std::vector<observer*> observers;
};

#endif // SUBJECT_H

#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

#include <iostream>

using namespace std;

//Gold Class
class Gold : public Event {
    public:
    Gold();
    Gold& operator=(const Gold&);
    Gold(const Gold&);

    void percept();
    void encounter(bool&);
    Event* clone();
};

#endif
#ifndef POOL_H
#define POOL_H 

#include "event.h"

#include <iostream>

using namespace std;
//Pool Interface
class Pool : public Event {
    public:
    Pool();
    Pool& operator=(const Pool&);
    Pool(const Pool&);

    void percept();
    void encounter(bool&);
    Event* clone();   

};

#endif
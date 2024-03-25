#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

#include <iostream>

using namespace std;

//Stalactites Interface
class Stalactites : public Event {
    private:
        // bool falling;

    public:
        Stalactites();
        Stalactites& operator=(const Stalactites&);
        Stalactites(const Stalactites&);
        
        void percept();
        void encounter(bool&);
        Event* clone();
};
#endif

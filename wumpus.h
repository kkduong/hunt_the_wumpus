#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"
#include <iostream>

using namespace std;

//Wumpus Interface
class Wumpus : public Event {
    private:

    public:
    Wumpus();
    Wumpus& operator=(const Wumpus&);
    Wumpus(const Wumpus&);

    void percept();
    void encounter(bool&);
    Event* clone();

};

#endif
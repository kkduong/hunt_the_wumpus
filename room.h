#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    Event* event;
    bool has_adventurer;
    bool has_rope;

public:
    Room();
    Room& operator=(const Room&);
    Room(const Room&);
    ~Room();

    bool get_has_adventurer() const;
    bool get_has_rope() const;

    void set_has_rope(const bool);

    bool is_empty() const;

    void assign_event(Event*);
    void switch_adventurer_status();
    void print_event_symbol() const;
    string get_event_symbol() const;
    void encounter(bool&, bool&, bool&);
    void percept();
	

};

#endif
#ifndef EVENT_H
#define EVENT_H 

using namespace std;

#include <iostream>

//Event Class

class Event
{

protected:
    string symbol;
   
public:
	void print_symbol();

    string get_symbol() const;

    virtual void percept() = 0;
    virtual Event* clone() = 0;
    virtual void encounter(bool&) = 0;
	
};
#endif
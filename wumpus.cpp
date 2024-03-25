/******************************************************
** Program: pool.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the Wumpus class derived
                from the Event class
** Input: N/A
** Output: N/A
******************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation

/*********************************************************************
** Function: Wumpus()
** Description: constructor for the Wumpus class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Wumpus object is created
*********************************************************************/
Wumpus::Wumpus() {
    this->symbol = "W";
}

/*********************************************************************
** Function: operator=()
** Description: assignment operator overload for the Wumpus class
** Parameters: const Wumpus& - reference to other Wumpus object
** Pre-Conditions: Wumpus class has a copy constructor
** Post-Conditions: member variables of this Wumpus object have been set
                    to some values
*********************************************************************/
Wumpus& Wumpus::operator=(const Wumpus& w) {
	this->symbol = w.symbol;

    return *this;
}

/*********************************************************************
** Function: Wumpus()
** Description: copy constructor for the Wumpus class
** Parameters: const Wumpus& - reference to other Wumpus object
** Pre-Conditions: Wumpus class has an assignment operator overload
** Post-Conditions: member variables of this Wumpus object have been initialized
                    to some values
*********************************************************************/
Wumpus::Wumpus(const Wumpus& w) {
	this->symbol = w.symbol;
}

/*********************************************************************
** Function: percept()
** Description: prints the percept for the Wumpus class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: percept is printed to screen
*********************************************************************/
void Wumpus::percept() {
    cout << "You smell a terrrible stench." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: kills the adventurer as they encounter the Wumpus
** Parameters: bool& - reference to variable that determines whether
                       the adventurer is alive
** Pre-Conditions: N/A
** Post-Conditions: player is dead
*********************************************************************/
void Wumpus::encounter(bool& p_alive) {
    // you woke the wumpus, so player dies
    cout << "You woke up the Wumpus and got eaten." << endl;
    p_alive = false;
}

/*********************************************************************
** Function: clone()
** Description: creates a clone(copy) of the current event
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns a deep copy of this event
*********************************************************************/
Event* Wumpus::clone() {
    // returns a clone of this event
    return new Wumpus(*this);
}
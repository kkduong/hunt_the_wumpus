/******************************************************
** Program: pool.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the Stalactites class derived
                from the Event class
** Input: N/A
** Output: N/A
******************************************************/
#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation

/*********************************************************************
** Function: Stalactites()
** Description: constructor for the Stalactites class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Stalactites object is created
*********************************************************************/
Stalactites::Stalactites() {
    this->symbol = "S";
}

/*********************************************************************
** Function: operator=()
** Description: assignment operator overload for the Stalactites class
** Parameters: const Stalactites& - reference to other Stalactites object
** Pre-Conditions: Stalactites class has a copy constructor
** Post-Conditions: member variables of this Stalactites object have been set
                    to some values
*********************************************************************/
Stalactites& Stalactites::operator=(const Stalactites& s) {
	this->symbol = s.symbol;

    return *this;
}

/*********************************************************************
** Function: Stalactites()
** Description: copy constructor for the Stalactites class
** Parameters: const Stalactites& - reference to other Stalactites object
** Pre-Conditions: Stalactites class has an assignment operator overload
** Post-Conditions: member variables of this Stalactites object have been initialized
                    to some values
*********************************************************************/
Stalactites::Stalactites(const Stalactites& s) {
	this->symbol = s.symbol;
}

/*********************************************************************
** Function: percept()
** Description: prints the percept for the Stalactites class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: percept is printed to screen
*********************************************************************/
void Stalactites::percept() {
    cout << "You hear water dripping." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: 50% chance of the stalactites falling on the adventurer
                and killing them when they enter a room with stalactites
** Parameters: bool& - reference to variable that determines if the 
               adventurer is alive
** Pre-Conditions: N/A
** Post-Conditions: player is either alive or dead
*********************************************************************/
void Stalactites::encounter(bool& p_alive) {
    cout << "You have entered a room full of stalactites." << endl;

    // generate a number that is either 1 or 0
    int fall = rand() % 2;

    // if the number is 1 (50% chance)
    if(fall == 1) {
        cout << "The stalactites fell and killed you!" << endl;
        p_alive = false;
    }
    // if not player lives
    else {
        cout << "The stalactites stay intact." << endl;
    }
}

/*********************************************************************
** Function: clone()
** Description: creates a clone(copy) of the current event
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns a deep copy of this event
*********************************************************************/
Event* Stalactites::clone() {
    // returns a clone of this event
    return new Stalactites(*this);
}


/******************************************************
** Program: pool.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the Pool class derived
                from the Event class
** Input: N/A
** Output: N/A
******************************************************/
#include "pool.h"

#include <iostream>

using namespace std;

//Pool Implementation

/*********************************************************************
** Function: Pool()
** Description: constructor for the Pool class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Pool object is created
*********************************************************************/
Pool::Pool() {
    this->symbol = "P";
}

/*********************************************************************
** Function: operator=()
** Description: assignment operator overload for the Pool class
** Parameters: const Pool& - reference to other Pool object
** Pre-Conditions: Pool class has a copy constructor
** Post-Conditions: member variables of this Pool object have been set
                    to some values
*********************************************************************/
Pool& Pool::operator=(const Pool& p) {
	this->symbol = p.symbol;

    return *this;
}

/*********************************************************************
** Function: Pool()
** Description: copy constructor for the Pool class
** Parameters: const Gold& - reference to other Pool object
** Pre-Conditions: Pool class has an assignment operator overload
** Post-Conditions: member variables of this Pool object have been initialized
                    to some values
*********************************************************************/
Pool::Pool(const Pool& p) {
	this->symbol = p.symbol;
}

/*********************************************************************
** Function: percept()
** Description: prints the percept for the Pool class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: percept is printed to screen
*********************************************************************/
void Pool::percept() {
    cout << "You hear wind blowing." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: switches the user's underwater status depending on if
                they are underwater or not
** Parameters: bool& - reference to variable keeping track of if the
                       adventurer is underwater
** Pre-Conditions: N/A
** Post-Conditions: underwater variable is either true or false
*********************************************************************/
void Pool::encounter(bool& underwater) {
    // if the player was already underwater, have them resurface
    if (underwater == true) {
        cout << "You have resurfaced from the pool system." << endl;
        underwater = false;
    }
    // if not, have them enter the pool system
    else {
        cout << "You dive into the pool system." << endl;
        underwater = true;
    }
}

/*********************************************************************
** Function: clone()
** Description: creates a clone(copy) of the current event
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns a deep copy of this event
*********************************************************************/
Event* Pool::clone() {
    // returns a clone of this event
    return new Pool(*this);
}

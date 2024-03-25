/******************************************************
** Program: gold.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the Gold class derived
                from the Event class
** Input: N/A
** Output: N/A
******************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Gold()
** Description: constructor for the Gold class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Gold object is created
*********************************************************************/
Gold::Gold() {
    this->symbol = "G";
}

/*********************************************************************
** Function: operator=()
** Description: assignment operator overload for the Gold class
** Parameters: const Gold& - reference to other Gold object
** Pre-Conditions: Gold class has a copy constructor
** Post-Conditions: member variables of this Gold object have been set
                    to some values
*********************************************************************/
Gold& Gold::operator=(const Gold& g) {
	this->symbol = g.symbol;

    return *this;
}

/*********************************************************************
** Function: Gold()
** Description: copy constructor for the Gold class
** Parameters: const Gold& - reference to other Gold object
** Pre-Conditions: Gold class has an assignment operator overload
** Post-Conditions: member variables of this Gold object have been initialized
                    to some values
*********************************************************************/
Gold::Gold(const Gold& g) {
	this->symbol = g.symbol;
}

/*********************************************************************
** Function: percept()
** Description: prints the percept for the Gold class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: percept is printed to screen
*********************************************************************/
void Gold::percept() {
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: encounter()
** Description: allows the user to pick up the gold needed to win the game
** Parameters: bool& - reference to the variable keeping track of whether
                       the adventurer has the gold or not
** Pre-Conditions: N/A
** Post-Conditions: gold variable is set to true 
*********************************************************************/
void Gold::encounter(bool& gold) {
    cout << "You have found the gold and picked it up!" << endl;
    // since gold was found set variable to true
    gold = true;
}

/*********************************************************************
** Function: clone()
** Description: creates a clone(copy) of the current event
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns a deep copy of this event
*********************************************************************/
Event* Gold::clone() {
    // returns a clone of the current event
    return new Gold(*this);
}
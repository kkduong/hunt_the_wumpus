/******************************************************
** Program: event.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the abstract Event class
** Input: N/A
** Output: N/A
******************************************************/
#include "event.h"

#include <iostream>

using namespace std;

//Event Implementation

/*********************************************************************
** Function: get_symbol()
** Description: gets the event symbol
** Parameters: N/A
** Pre-Conditions: symbol variable has been initialized
** Post-Conditions: returns the event symbol
*********************************************************************/
string Event::get_symbol() const {
    // return the symbol
    return this->symbol;
}

/*********************************************************************
** Function: print_symbol()
** Description: prints the event symbol to screen
** Parameters: N/A
** Pre-Conditions: symbol variable has been initialized
** Post-Conditions: event symbol is printed to screen
*********************************************************************/
void Event::print_symbol() {
    // print the symbol
    cout << this->symbol;
}
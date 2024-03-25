/******************************************************
** Program: room.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: implementation of the Room class 
** Input: N/A
** Output: N/A
******************************************************/
#include "room.h"

using namespace std;

//Room Implementation

/*********************************************************************
** Function: Room()
** Description: constructor for the Room class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Room object is created and member variables are 
                    initialized
*********************************************************************/
Room::Room() {
    this->event = nullptr;
    this->has_adventurer = false;
    this->has_rope = false;
}

/*********************************************************************
** Function: operator=()
** Description: assignment operator overload for the Room class
** Parameters: const Room& - reference to other Pool object
** Pre-Conditions: Room class has a copy constructor
** Post-Conditions: member variables of this Room object have been set
                    to some values
*********************************************************************/
Room& Room::operator=(const Room& r) {
	this->has_adventurer = r.has_adventurer;
	this->has_rope = r.has_rope;

    // if the event pointer is not null, delete it
	if (this->event != nullptr) {
		delete this->event;
	}

    // if this room is not the same as the other room
	if (this != &r) {
        // if the other room has an event
        if(r.event) {
            // set this event to a clone of the other event
            this->event = r.event->clone();
        }
        // if not set to nullptr
        else {
            this->event = nullptr;
        }
    }
	return *this;
}

/*********************************************************************
** Function: Room()
** Description: copy constructor for the Room class
** Parameters: const Room& - reference to other Gold object
** Pre-Conditions: Room class has an assignment operator overload
** Post-Conditions: member variables of this Room object have been initialized
                    to some values
*********************************************************************/
Room::Room(const Room& r) {
	this->has_adventurer = r.has_adventurer;
	this->has_rope = r.has_rope;
    
    // if the the other room has an event
	if(r.event) {
        // set this event to a clone of the other room's event
        this->event = r.event->clone();
    }
    // if not set to nullptr
    else {
        this->event = nullptr;
    }
}

/*********************************************************************
** Function: ~Room()
** Description: destructor for the Room class
** Parameters: N/A
** Pre-Conditions: Room has not been destructed
** Post-Conditions: Room object is destructed and dynamic memory is
                    deleted
*********************************************************************/
Room::~Room() {
    // if the event pointer is not pointing to nullptr, delete
    if (this->event != nullptr) {
        delete this->event;
        this->event = nullptr;
    }
}

/*********************************************************************
** Function: get_has_adventurer()
** Description: getter for has_adventurer variable
** Parameters: N/A
** Pre-Conditions: variable has been initialized
** Post-Conditions: returns has_adventurer
*********************************************************************/
bool Room::get_has_adventurer() const {
    return this->has_adventurer;
}

bool Room::get_has_rope() const {
    return this->has_rope;
}

void Room::set_has_rope(const bool b) {
    this->has_rope = b;
}

/*********************************************************************
** Function: is_empty()
** Description: checks if the room is empty
** Parameters: N/A
** Pre-Conditions: event pointer points to something
** Post-Conditions: returns true or false depending on if the room is empty
*********************************************************************/
bool Room::is_empty() const {
    // if the event pointer is not pointing to nullptr:
    if (this->event != nullptr) {
        return false;
    }
    // else, it is empty so return true
    return true;
}

/*********************************************************************
** Function: assign_event()
** Description: assigns a new event to the event pointer variable
** Parameters: Event* - pointer to the new event
** Pre-Conditions: N/A
** Post-Conditions: old event has been deleted, new one is stored
*********************************************************************/
void Room::assign_event(Event* e) {
    // delete the current event, assign new event
    delete this->event;
    this->event = e;
}

/*********************************************************************
** Function: switch_adventurer_status()
** Description: switches whether the adventurer is in the room or not
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: if the adventurer is in the room, switch so it
                    no longer is and vise versa
*********************************************************************/
void Room::switch_adventurer_status() {
    // if the room already has the adventurer, switch to false
    if (this->has_adventurer) {
        this->has_adventurer = false;
    }
    // if not, switch to true
    else {
        this->has_adventurer = true;
    }
}

/*********************************************************************
** Function: print_event_symbol()
** Description: prints the event symbol to screen
** Parameters: N/A
** Pre-Conditions: symbol variable has been initialized
** Post-Conditions: event symbol is printed to screen
*********************************************************************/
void Room::print_event_symbol() const {
    this->event->print_symbol();
}

/*********************************************************************
** Function: get_event_symbol()
** Description: gets the event symbol
** Parameters: N/A
** Pre-Conditions: symbol variable has been initialized
** Post-Conditions: returns the event symbol
*********************************************************************/
string Room::get_event_symbol() const {
    return this->event->get_symbol();
}

/*********************************************************************
** Function: encounter()
** Description: runs the encounter for the event in the room
** Parameters: bool& - reference to variable that determines if the
                       adventurer is alive
               bool& - reference to variable that keeps track of if
                       the adventurer is underwat
               bool& - reference to variable that keeps track of if
                       the adventurer has the gold
** Pre-Conditions: N/A
** Post-Conditions: variables are manipulated depending on the event
*********************************************************************/
void Room::encounter(bool& p_alive, bool& underwater, bool& gold) {
    string e = event->get_symbol();

    // if the event is the Wumpus
    if(e == "W") {
        cout << endl;
        cout << "-------------------------------------" << endl;
        event->encounter(p_alive);
        cout << "-------------------------------------" << endl;
    }
    // if the event is a Pool
    else if (e == "P") {
        cout << endl;
        cout << "-------------------------------------" << endl;
        event->encounter(underwater);
        cout << "-------------------------------------" << endl;
    }
    // if the event is Stalactites
    else if (e == "S") {
        cout << endl;
        cout << "-------------------------------------" << endl;
        event->encounter(p_alive);
        cout << "-------------------------------------" << endl;
    }
    // if the event is the Gold
    else {
        cout << endl;
        cout << "-------------------------------------" << endl;
        event->encounter(gold);
        cout << "-------------------------------------" << endl;
    }
    
}

/*********************************************************************
** Function: percept()
** Description: prints the percept for the event in the room (if any)
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: percept is printed to screen
*********************************************************************/
void Room::percept() {
    this->event->percept();
}


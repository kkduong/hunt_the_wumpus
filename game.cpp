/******************************************************
** Program: game.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: contains the functionalities and playthrough 
				of the Hunt the Wumpus game.
** Input: actions of adventurer (moving or firing arrow), 
		  whether they would like to play again, and side
		  length of cave should they want to play with a
		  different cave
** Output: board printed to screen based on game status and
		   debug view
******************************************************/
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"

#include <iostream>
#include <vector>

using namespace std;

//Game Implementation

/*********************************************************************
** Function: Game()
** Description: constructor for the Game class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: variables initialized, play and config with values
*********************************************************************/ 
Game::Game(){
	//initalizes play and configuration variables for the first run of the game
	this->play = 2;
	this->config = 0;

}

/*********************************************************************
** Function: ~Game()
** Description: destructor for the Game class
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Game instance has been destructed
*********************************************************************/ 
Game::~Game(){
	//Game destructor

}

/*********************************************************************
** Function: two_random_num()
** Description: generates two random numbers that are used as coordinates
				in the cave
** Parameters: int& - reference to variable holding the row coord
			   int& - reference to variable holding the column coord
** Pre-Conditions: row and column variables exist
** Post-Conditions: row and column variables have some coordinates
*********************************************************************/ 
void Game::two_random_num(int& r, int& c) {
	// generates two random numbers between 0 and side for assigning coordinates
	r = rand() % this->side;
	c = rand() % this->side;
}

/*********************************************************************
** Function: insert_adventurer()
** Description: inserts the adventurer into their starting position
				in the cave 
** Parameters:	N/A
** Pre-Conditions: Events have already been inserted into the board
** Post-Conditions: a bool variable in the Room should be true for 
					currently holding the adventurer, and another 
					should be true for the escape rope being in this
					first room
*********************************************************************/ 
void Game::insert_adventurer() {
	int row, col;

	//stores random row and column coords for assigning
	Game::two_random_num(row, col);

	// check to make sure the room at said coords is empty
	while(!this->board[row][col].is_empty()) {
		Game::two_random_num(row, col);
	}

	// insert the adventurer at this point and record where the escape rope is
	this->board[row][col].switch_adventurer_status();
	this->board[row][col].set_has_rope(true);

}

/*********************************************************************
** Function: insert_event()
** Description: inserts an event into an empty Room in the cave
** Parameters: Event* - pointer to the event that is being inserted
** Pre-Conditions: board has already been created
** Post-Conditions: the event pointer is stored in a Room
*********************************************************************/
void Game::insert_event(Event* e) {
	int row, col;

	//stores random row and column coords for assigning
	Game::two_random_num(row, col);

	// check to make sure the room at said coords is empty
	while(!(this->board[row][col].is_empty())) {
		Game::two_random_num(row, col);
	}

	// assign the event pointer to a new pointer
	this->board[row][col].assign_event(e);
}

/*********************************************************************
** Function: insert()
** Description: inserts all events and the adventurer into the cave
** Parameters: N/A
** Pre-Conditions: board has been created
** Post-Conditions: all events and adventurer as in their starting places
*********************************************************************/
void Game::insert() {
	// insert all events
	Game::insert_event(new Pool);
	Game::insert_event(new Pool);
	Game::insert_event(new Stalactites);
	Game::insert_event(new Stalactites);
	Game::insert_event(new Wumpus);
	Game::insert_event(new Gold);

	//insert adventurer starting spot
	Game::insert_adventurer();
}

/*********************************************************************
** Function: set_up()
** Description: sets up the board(cave) for the game
** Parameters: int - side length of the cave
			   int - 1 or 2 depending on which configuration of the
			   		 cave the user wants to play
** Pre-Conditions: N/A
** Post-Conditions: 2D vector of Rooms is created and other member 
					variables have been assigned
*********************************************************************/
void Game::set_up(int s, int same){
	//set up the game
	this->side = s;
	this->oxygen = s*2;
	this->has_gold = false;
	this->num_arrows = 3;
	this->underwater = false;
	this->alive = true;

	// if the user wants to play the same board
	if (same == 1) {
		this->board = this->copy;
	}
	else {
	// Create the game board: 2D vector of Room objects
	this->board = vector<vector<Room> >(s, vector<Room>(s));

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			board[i][j] = Room();
		}
	}

	// randomly insert events (2 pool accesses, 2 stalactites, 1 wumpus, 1 gold)
	Game::insert();

	// store a copy of this board in case the user wants to play again
	this->copy = this->board;
	}
}

/*********************************************************************
** Function: display_game()
** Description: displays the cave and other information to the user
** Parameters: N/A
** Pre-Conditions: board has been created, events and adventurer have
				   been inserted into the board
** Post-Conditions: the cave is printed to screen with symbols if
					in debug mode
*********************************************************************/
void Game::display_game() const{
	// print arrows remaining:
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	//print oxygen level:
	cout << "Oxygen level: " << this->oxygen << endl;
	
	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";

	for (int i = 0; i < this->side; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->side; ++j)
		{
			//if the room does not have the player, print space " "
			if (board[i][j].get_has_adventurer()) {
				cout << "*";
			} 
			//else, print "*"
			else {
				cout << " ";	
			}

			//if the room does not have an event:
			if (board[i][j].is_empty()) {
				// check if the room has the escape rope or not
				if (this->debug_view && board[i][j].get_has_rope()) {
					cout <<"~ ||";
				}
				// else print "  ||" (2 spaces + ||)
				else {
					cout << "  ||";
				}
			}
			//else, 
			else {
				//if debug_view is true
				if(this->debug_view) {
					//print the corresponding char of the event
					board[i][j].print_event_symbol();
				}
				//else
				else {
					//print " " (1 space)
					cout << " ";
				}
				// print " ||" (1 space + ||)
				cout << " ||";
			}

		}
		cout << endl;
	}
	cout << line << endl;
}

/*********************************************************************
** Function: find_wumpus()
** Description: finds the coordinates of the Wumpus on the board
** Parameters: int& - reference to row coordinate variable
			   int& - reference to column coordinate variable
** Pre-Conditions: the Wumpus event has been added to the board
** Post-Conditions: row and column variables are assigned with the
					coordinates of the Wumpus
*********************************************************************/
void Game::find_wumpus(int& r, int& c) {
	// search through every room in the vector
	for(int i = 0; i < this->side; i++) {
		for (int j = 0; j < this->side; j++) {
			// if the room is not empty:
			if(!this->board[i][j].is_empty()) {
				// if the room has the Wumpus event
				if(this->board[i][j].get_event_symbol() == "W") {
					// store the coords in two int variables
					r = i;
					c = j;
					return;
				}
			}
		}
	}

	return;
}

/*********************************************************************
** Function: find_adventurer()
** Description: finds the current coordinates of the adventurer
** Parameters: int& - reference to row coordinate variable
			   int& - reference to column coordinate variable
** Pre-Conditions: adventurer has been inserted into the board
** Post-Conditions: row and column variables are assigned with the
					coordinates of the adventurer
*********************************************************************/
void Game::find_adventurer(int& r, int& c) {
	// search through every room in the vector
	for(int i = 0; i < this->side; i++) {
		for (int j = 0; j < this->side; j++) {
			// if the room contains the adventurer
			if(this->board[i][j].get_has_adventurer()) {
				// store the coords in two int variables
				r = i;
				c = j;
				return;
			}
		}
	}

	return;
}

/*********************************************************************
** Function: check_win()
** Description: checks if the user has won the game or if they have died
				or neither
** Parameters: N/A
** Pre-Conditions: adventurer exists and a Room holds the escape rope
** Post-Conditions: returns true or false based on if the user has won
					or died or neither
*********************************************************************/
bool Game::check_win() {
	//check if the adventurer is alive or not
	if (!alive) {
		cout << "You are dead. Game over." << endl;
		return true;
	}

	// check if the adventurer has the gold
	if (this->has_gold) {
		int row, col;

		// find the adventurer and store coords
		Game::find_adventurer(row, col);

		// if the room the adventurer is in has the escape rope, player wins
		if(board[row][col].get_has_rope()) {
			cout << "You have escaped with the gold and win the game!" << endl;
			return true;
		}
	}

	// else, return false (game not over yet)
	return false;
}

/*********************************************************************
** Function: check_input()
** Description: checks if the user's input is valid or not
** Parameters: char - user's input
** Pre-Conditions: N/A
** Post-Conditions:	returns true or false based on if the user input
					was valid or not
*********************************************************************/
bool Game::check_input(char c) {
	// check if the input is valid and return true if yes
	if (c == 'w') {
		return true;
	}
	if (c == 'a') {
		return true;
	}
	if (c == 's') {
		return true;
	}
	if (c == 'd') {
		return true;
	}

	// return false otherwise
	return false;
}

/*********************************************************************
** Function: move_up()
** Description: moves the adventurer up a space if there is room to do so
** Parameters: N/A
** Pre-Conditions: adventurer has been inserted to the board
** Post-Conditions: adventurer has been moved to the room directly to 
					the north
*********************************************************************/
void Game::move_up() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// check if you are at the edge of the vector
	if (row - 1 < 0) {
		cout << "You are at a wall and cannot move north." << endl;
		return;
	}

	// change the has_adventurer variable in both the new and old rooms
	board[row][col].switch_adventurer_status();
	board[row - 1][col].switch_adventurer_status();
	
	return;

}

/*********************************************************************
** Function: move_down()
** Description: moves the adventurer down a space if there is room to do so
** Parameters: N/A
** Pre-Conditions: adventurer has been inserted to the board
** Post-Conditions: adventurer has been moved to the room directly to 
					the south
*********************************************************************/
void Game::move_down() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// check if you are at the edge of the vector
	if (row + 1 > this->side - 1) {
		cout << "You are at a wall and cannot move south." << endl;
		return;
	}

	// change the has_adventurer variable in both the new and old rooms
	board[row][col].switch_adventurer_status();
	board[row + 1][col].switch_adventurer_status();
	return;
}

/*********************************************************************
** Function: move_left()
** Description: moves the adventurer left a space if there is room to do so
** Parameters: N/A
** Pre-Conditions: adventurer has been inserted to the board
** Post-Conditions: adventurer has been moved to the room directly to 
					the west
*********************************************************************/
void Game::move_left() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// check if you are at the edge of the vector
	if (col - 1 < 0) {
		cout << "You are at a wall and cannot move west." << endl;
		return;
	}

	// change the has_adventurer variable in both the new and old rooms
	board[row][col].switch_adventurer_status();
	board[row][col - 1].switch_adventurer_status();
	return;

}

/*********************************************************************
** Function: move_right()
** Description: moves the adventurer right a space if there is room to do so
** Parameters: N/A
** Pre-Conditions: adventurer has been inserted to the board
** Post-Conditions: adventurer has been moved to the room directly to 
					the east
*********************************************************************/
void Game::move_right() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// check if you are at the edge of the vector
	if (col + 1 > this->side - 1) {
		cout << "You are at a wall and cannot move east." << endl;
		return;
	}

	// change the has_adventurer variable in both the new and old rooms
	board[row][col].switch_adventurer_status();
	board[row][col + 1].switch_adventurer_status();
	return;
}

/*********************************************************************
** Function: get_dir()
** Description: gets the direction that the user wants to fire an arrow
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: the character representing the user's desired firing
					direction is returned
*********************************************************************/
char Game::get_dir(){
	char dir;

	// display where you can fire the arrow
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	// store the user input and ignore all chars that are not the first one
	cin >> dir;
	cin.ignore(256, '\n');

	// check that the input is one of the desired ones
	while (!(Game::check_input(dir))) {
		cout << "Enter valid input: ";
		cin >> dir;
		cin.ignore(256, '\n');
	}

	return dir;
}

/*********************************************************************
** Function: wumpus_move()
** Description: 75% chance of moving the Wumpus to a different
				location in the cave
** Parameters: N/A
** Pre-Conditions: Wumpus has been inserted into the cave
** Post-Conditions: if not in that 25%, the Wumpus is moved to a new
					Room in the cave and removed from its previous
					position
*********************************************************************/
void Game::wumpus_move(){
	//generate a random number between 0-3
	int chance = rand() % 4;

	// if the number is not 0 (75% chance)
	if (chance != 0) {
		cout << "The Wumpus has moved." << endl;

		// find the wumpus' current location
		int row, col;
		Game::find_wumpus(row, col);

		// assign a new wumpus event pointer to a new place
		Game::insert_event(new Wumpus);

		// delete the wumpus event from its old position
		this->board[row][col].assign_event(nullptr);
	}
	
	return;
}

/*********************************************************************
** Function: arrow_up()
** Description: shoots an arrow through all rooms north of the adventurer
** Parameters: N/A
** Pre-Conditions: Wumpus and adventurer have been inserted into board
** Post-Conditions: arrow has been shot through all rooms north of 
					adventurer and if Wumpus is hit, it is killed and is
					removed from board. if arrow misses, there is a
					chance the Wumpus moved in the cave.
*********************************************************************/
void Game::arrow_up() {
	// find adventurers current coords and store them
	int row, col;
	Game::find_adventurer(row, col);

	// for every row above the adventurer such that it is not out of bounds
	for (int i = row - 1; i >= 0; i--) {
		// if the room is not empty:
		if (!(this->board[i][col].is_empty())) {
			// check if the room has the Wumpus event;
			if (this->board[i][col].get_event_symbol() == "W") {
				// delete the wumpus event from the board to kill it
				this->board[i][col].assign_event(nullptr);
				cout << "You have hit and killed the Wumpus!" << endl;
				return;
			}
			
		}
	}

	// if the arrow misses, see if the wumpus will move
	cout << "Your arrow missed." << endl;
	Game::wumpus_move();

	return;
}

/*********************************************************************
** Function: arrow_left()
** Description: shoots an arrow through all rooms west of the adventurer
** Parameters: N/A
** Pre-Conditions: Wumpus and adventurer have been inserted into board
** Post-Conditions: arrow has been shot through all rooms west of 
					adventurer and if Wumpus is hit, it is killed and is
					removed from board. if arrow misses, there is a
					chance the Wumpus moved in the cave.
*********************************************************************/
void Game::arrow_left() {
	// find adventurers current coords and store them
	int row, col;
	Game::find_adventurer(row, col);

	// for every column to the left of the adventurer such that it is not out of bounds
	for (int i = col - 1; i >= 0; i--) {
		// if the room is not empty:
		if (!(this->board[row][i].is_empty())) {
			// check if the room has the Wumpus event;
			if (this->board[row][i].get_event_symbol() == "W") {
				// delete the wumpus event from the board to kill it
				this->board[row][i].assign_event(nullptr);
				cout << "You have hit and killed the Wumpus!" << endl;
				return;
			}
			
		}
	}

	// if the arrow misses, see if the wumpus will move
	cout << "Your arrow missed." << endl;
	Game::wumpus_move();

	return;
}

/*********************************************************************
** Function: arrow_down()
** Description: shoots an arrow through all rooms south of the adventurer
** Parameters: N/A
** Pre-Conditions: Wumpus and adventurer have been inserted into board
** Post-Conditions: arrow has been shot through all rooms south of 
					adventurer and if Wumpus is hit, it is killed and is
					removed from board. if arrow misses, there is a
					chance the Wumpus moved in the cave.
*********************************************************************/
void Game::arrow_down() {
	// find adventurers current coords and store them
	int row, col;
	Game::find_adventurer(row, col);

	// for every row below the adventurer such that it is not out of bounds
	for (int i = row + 1; i < this->side; i++) {
		// if the room is not empty:
		if (!(this->board[i][col].is_empty())) {
			// check if the room has the Wumpus event;
			if (this->board[i][col].get_event_symbol() == "W") {
				// delete the wumpus event from the board to kill it
				this->board[i][col].assign_event(nullptr);
				cout << "You have hit and killed the Wumpus!" << endl;
				return;
			}
			
		}
	}

	// if the arrow misses, see if the wumpus will move
	cout << "Your arrow missed." << endl;
	Game::wumpus_move();
	

	return;
}

/*********************************************************************
** Function: arrow_right()
** Description: shoots an arrow through all rooms east of the adventurer
** Parameters: N/A
** Pre-Conditions: Wumpus and adventurer have been inserted into board
** Post-Conditions: arrow has been shot through all rooms east of 
					adventurer and if Wumpus is hit, it is killed and is
					removed from board. if arrow misses, there is a
					chance the Wumpus moved in the cave.
*********************************************************************/
void Game::arrow_right() {
	// find adventurers current coords and store them
	int row, col;
	Game::find_adventurer(row, col);
	
	// for every column to the right of the adventurer such that it is not out of bounds
	for (int i = col + 1; i < this->side; i++) {
		// if the room is not empty:
		if (!(this->board[row][i].is_empty())) {
			// check if the room has the Wumpus event;
			if (this->board[row][i].get_event_symbol() == "W") {
				// delete the wumpus event from the board to kill it
				this->board[row][i].assign_event(nullptr);
				cout << "You have hit and killed the Wumpus!" << endl;
				return;
			}
			
		}
	}

	// if the arrow misses, see if the wumpus will move
	cout << "Your arrow missed." << endl;
	Game::wumpus_move();

	return;
}

/*********************************************************************
** Function: fire_arrow()
** Description: fires an arrow in whatever direction the user would
				like (north, east, south, west)
** Parameters:	N/A
** Pre-Conditions: number of arrows is > 0
** Post-Conditions: an arrow is fired in one of the four directions
					and Wumpus is moved or killed accordingly
*********************************************************************/
void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();

	// decrement the number of arrows
	num_arrows--;

	// depending on the user choie
	switch(dir){
		case 'w':
			// shoot arrow up
			Game::arrow_up();
			break;
		case 'a':
			// shoot arrow left
			Game::arrow_left();
			break;
		case 's':
			// shoot arrow down
			Game::arrow_down();
			break;
		case 'd':
			// shoot arrow right
			Game::arrow_right();
			break;
	}

	return;

}

/*********************************************************************
** Function: move()
** Description: either moves the adventurer or fires an arrow depending
				on the user's input
** Parameters:	char - user's input
** Pre-Conditions: adventurer has been inserted onto the board
** Post-Conditions: character has either moved or fired an arrow, and
					Wumpus is moved or killed accordingly
*********************************************************************/
void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		// if player is out of arrows, do not fire one
		if (num_arrows == 0) {
			cout << "You are out of arrows and cannot fire another." << endl;
			return;
		}
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			// move player up
			Game::move_up();
			break;
		case 'a':
			// move player left
			Game::move_left();
			break;
		case 's':
			// move player down
			Game::move_down();
			break;
		case 'd':
			// move player right
			Game::move_right();
			break;
	}
}

/*********************************************************************
** Function: get_input()
** Description: gets the user's input regarding what action they would
				like to perform
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: returns the user's desired action
*********************************************************************/
char Game::get_input(){
	//get action, move direction or firing an arrow
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	// store user input and ignore all characters but the first
	cin >> c;
	cin.ignore(256, '\n');

	// check if the input is one of the 5 choices
	while (!(Game::check_input(c)) && c != 'f') {
		cout << "Enter valid input: ";
		cin >> c;
		cin.ignore(256, '\n');
	}

	
	return c;
}

/*********************************************************************
** Function: print_percept()
** Description: prints the percepts of the rooms around the adventurer's
				location if any
** Parameters: N/A
** Pre-Conditions: adventurer has been inserted into the board
** Post-Conditions: all percepts (if any) of rooms adjacent (not diagonally)
					to the adventurer's location are printed to the screen
*********************************************************************/
void Game::print_percepts() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// check if there is a wall to the north of the adventurer:
	if(row - 1 >= 0) {
		// if the room to the north is not empty, print percept 
		if(!board[row-1][col].is_empty()) {
			board[row-1][col].percept();
		}
	}
	
	// check if there is a wall to the south of the adventurer:
	if(row + 1 < side) {
		// if the room to the south is not empty, print percept 
		if(!board[row+1][col].is_empty()) {
			board[row+1][col].percept();
		}
	}

	// check if there is a wall to the east of the adventurer:
	if(col - 1 >= 0) {
		// if the room to the east is not empty, print percept 
		if(!board[row][col-1].is_empty()) {
			board[row][col-1].percept();
		}
	}

	// check if there is a wall to the west of the adventurer:
	if(col + 1 < side) {
		// if the room to the west is not empty, print percept 
		if(!board[row][col+1].is_empty()) {
			board[row][col+1].percept();
		}
	}

}

/*********************************************************************
** Function: play_above_water()
** Description: plays a round with the player in the main cave system
** Parameters: N/A
** Pre-Conditions: adventurer is not underwater
** Post-Conditions: if the adventurer encounters any event, run the event
*********************************************************************/
void Game::play_above_water() {
	// find the adventurers current coords
	int row, col;
	Game::find_adventurer(row, col);

	// if the room isnt empty, run the encounter
	if (!board[row][col].is_empty()) {
		board[row][col].encounter(alive, underwater, has_gold);

		// if the adventurer has the gold and the current event is the Gold event, delete it from the board
		if(has_gold && board[row][col].get_event_symbol() == "G") {
			board[row][col].assign_event(nullptr);
		}
	}
}

/*********************************************************************
** Function: play_underwater()
** Description: plays a round with the player in the pool system
** Parameters: N/A
** Pre-Conditions: adventurer is underwater
** Post-Conditions: if the adventurer encounters a pool event, resurface
					into the main cave system (basically no encounters except pools)
					if not continue to reduce oxygen while they explore
*********************************************************************/
void Game::play_underwater() {
	// find the adventurers current coords
	int row, col;
	find_adventurer(row, col);

	// decrement the oxygen while underwater
	oxygen--;

	// check if the player is out of oxygen
	if(oxygen == 0) {
		cout << "You run out of oxygen and drown." << endl;
		alive = false;
		return;
	}

	// check if the board isnt empty:
	if(!board[row][col].is_empty()) {
		// if the event is the Pool event, run the encounter
		if(board[row][col].get_event_symbol() == "P") {
			board[row][col].encounter(alive, underwater, has_gold);

			// if the player is no longer underwater, reset the oxygen
			if(!underwater) {
				oxygen = side*2;
			}
		}
	}
}

/*********************************************************************
** Function: play_again()
** Description: asks the user if they would like to continue to play or
				quit the game
** Parameters: int& - reference to variable used to keep game in play
			   int& - reference to variable used to determine the 
			   		  configuration of the cave
			   int& - reference to variable used to initialize side length
** Pre-Conditions: game has been played all the way through
** Post-Conditions: variables are assigned to values used to end or keep
					the game in play
*********************************************************************/
void Game::play_again(int& play, int& config, int& side) {
	int temp;
	cout << endl;
	cout << "Would you like to: " << endl;
	cout << "1: play in the same cave" << endl;
	cout << "2: play with a different cave" << endl;
	cout << "3: quit the game entirely" << endl;

	cout << endl;
	cout << "Enter your choice (1-3): "; 
	cin >> temp;

	// while user input is not valid, ask for a new value
	while(temp < 1 || temp > 3) {
		cout << "Enter a valid value: ";
		cin >> temp;
	}

	play = temp;

	// the user wants to play on the same board:
	if (temp == 1) {
		config = 1;
	}
	// if the user wants to play on a different board:
	else if (temp == 2) {
		config = 0;
		cout << "Enter the side length of your cave (4-50, inclusive): ";
		cin >> temp;

		// error handling for side length of cave
		while (temp < 4 || temp > 50) {
			cout << "Enter a valid value: ";
			cin >> temp;
		}

		side = temp;
	}
	


}

/*********************************************************************
** Function: action()
** Description: performs an action based on user input
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: the adventurer has been moved or has fired an arrow
*********************************************************************/
void Game::action() {
	// gets the users desrired action
	char input = Game::get_input();
	Game::move(input);
}

/*********************************************************************
** Function: play_game()
** Description: plays through the Hunt the Wumpus game
** Parameters: int - initial side length
			   bool - debug mode
** Pre-Conditions: user has inputed initial side length and debug mode choice
** Post-Conditions: game is played until user decides to quit
*********************************************************************/
void Game::play_game(int s, bool d){
	// initializes a variable with the starting length from the driver file
	this-> side = s;

	// do while the user wants to play
	do {
	
	// set up the game based on the side length and configuration
	Game::set_up(side, config);
	this->debug_view = d;

	// while the user has not died or won
	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		cout << endl;
		Game::print_percepts();

		//Player move...
		Game::action();

		//3. may or may not encounter events
		if(underwater) {
			Game::play_underwater();

		}
		else {
			Game::play_above_water();
		}

	}

	// see if user would like to play again and mainpulate the variables accordingly
	Game::play_again(play, config, side);

	} while (play != 3);
	
	return;

}
/******************************************************
** Program: main.cpp
** Author: Kaelee Duong
** Date: 3/15/2024
** Description: driver file for the Hunt the Wumpus game
** Input: initial side length of cave, and debug mode
** Output: game runs smoothly
******************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/*********************************************************************
** Function: main()
** Description: runs the Hunt the Wumpus game
** Parameters: N/A
** Pre-Conditions: all classes used have been implemented
** Post-Conditions: game exits smoothly
*********************************************************************/
int main()
{
	//set the random seed
	srand(time(NULL));
	int side_len;
	bool debug;
	int input;
	Game g;

	//get one input: side length of the cave
	cout << "Enter the side length of your cave (4-50, inclusive): ";
	cin >> side_len;

	// error handling for user input
	while (side_len < 4 || side_len > 50) {
		cout << "Enter a valid value: ";
		cin >> side_len;
	}


	//get the 2nd input --> debug mode or not
	cout << "Would you like to be in debug mode? (1 - yes, 0 - no) ";
	cin >> input;

	// error handling for user input
	while(input < 0 || input > 1) {
			cout << "Please enter a valid input: ";
			cin >> input;

	}

	// if input is 1, turn debug mode on
	if(input == 1) {
		debug = true;
	}
	// else keep it off
	else {
		debug = false;
	}

	//Play game
	g.play_game(side_len, debug);

	cout << "Thanks for playing!" << endl;

	return 0;
}
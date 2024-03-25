#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game Class 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	vector <vector<Room> > board;
	vector <vector<Room> > copy;

	//other member variables:
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not

	int oxygen;
	bool has_gold;
	bool underwater;
	bool alive;

	int play;
	int config;


	//feel free to add more variables...

public:
	Game();
	~Game();
	
	void insert_event(Event*);
	void insert_adventurer();
	void two_random_num(int&, int&);
	void insert();
	void set_up(int, int);

	void display_game() const;

	bool check_win();
	bool check_input(char);
	void find_adventurer(int&, int&);
	void find_wumpus(int&, int&);

	char get_dir();
	void wumpus_move();
	void arrow_up();
	void arrow_down();
	void arrow_left();
	void arrow_right();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();

	void print_percepts();
	void play_above_water();
	void play_underwater();
	void play_again(int&, int&, int&);
	void action();
	void play_game(int, bool);

};
#endif
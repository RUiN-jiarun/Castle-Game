/* Header file: Game.h */
/* Including the basic operation of the game and the initialization part */


#include <vector>
#include <ctime>
#include <cstdlib>
#include "Room.h"
#include "Key.h"
#include "Monster.h"
#include "Princess.h"
#include "Sword.h"

#ifndef GAME_H
#define GAME_H
/* Self-define random number generator */
#define random(a,b) (rand()%(b-a)+a)


/* Playerstate: Record the items that the player have */
struct Playerstate {
	bool sword = false;
	bool princess = false;
	bool key = false;
	bool cheat = false;
};

/* Global variables */
extern int no_prin, no_mon_1, no_mon_2, no_swo, no_key;
extern Room cur;
extern map<int, string> Map;

/* Functions associated with the game operation and others */

void Initialization();					// Generating the map 
void Help();							// Show hints
Room* Move(Room* cur, string dir);		// Operation
bool Check(Room* p);					// The checking system of the game (whether is the end of the game)
void Cheat();							// Cheating!!!

#endif
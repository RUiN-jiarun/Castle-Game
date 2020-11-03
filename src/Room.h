/* Header file: Room.h */
/* Including the Room class */

#include <map>
#include <string>
#include <iostream>
#include <Windows.h>
#ifndef ROOM_H
#define ROOM_H
using namespace std;

class Room
{
protected:
	bool win;									// Whether you're win
	string name;								// The name of the room
	map<string, Room*> exits;					// Record the direction and the room pointer. The map is linked by the data structure
public:
	Room();										// Default C'tor
	Room(string name);							// C'tor
	string getName();							// Get the name of the room
	bool operator < (const Room& cmp) const;	// Operator overidden to build the map
	void setExit(string dir, Room* room);		// Insert pairs in the map structure
	void setWin();								// Confirm the winning condition
	bool getWin();								// Get the winnning condition
	string getExit();							// Get the legal moving 
	Room* go(string dir);						// Moving to the next room
	virtual void foo();							// Used for polymorphism and dynamic casting
};

#endif

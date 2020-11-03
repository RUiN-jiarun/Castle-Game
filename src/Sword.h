/* Header file: Sword.h */
/* Including the Sword class, which is a public inheritant class of Room */

#include "Room.h"
#ifndef SWORD_H
#define SWORD_H
using namespace std;

class Sword : public Room
{
protected:
	bool sword;				// Whether there's a sword in this room
	bool flag;				// Whether this is the first time you entering this room
public:
	Sword(string name);		// C'tor
	bool getSword();		// Get the item

};

#endif

/* Header file: Monster.h */
/* Including the Monster class, which is a public inheritant class of Room */

#include "Room.h"
#ifndef MONSTER_H
#define MONSTER_H


class Monster : public Room
{
protected:
	bool monster;					// Whether there's a monster in the room
	bool flag;						// Whether this is the first time you entering this room
public:
	Monster(string name);			// C'tor
	bool battle(bool sword);		// Checking whether you are still alive after fighting against the monster

};

#endif

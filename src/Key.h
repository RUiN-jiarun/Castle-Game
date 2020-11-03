/* Header file: Key.h */
/* Including the Key class, which is a public inheritant class of Room */

#include "Room.h"
#ifndef KEY_H
#define KEY_H
using namespace std;

class Key : public Room
{
protected:
	bool key;				// Whether there's a key in this room
	bool flag;				// Whether this is your first time entering this room
public:
	Key(string name);		// C'tor
	bool getKey();			// Get the item

};

#endif


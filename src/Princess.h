/* Header file: Princess.h */
/* Including the Princess class, which is a public inheritant class of Room */

#include "Room.h"
#ifndef PRINCESS_H
#define PRINCESS_H


class Princess : public Room
{
protected:
	bool princess;				// Whether the princess is in this room
	bool flag;					// Whether the princess has been rescued yet
public:
	Princess(string name);		// C'tor
	void rescue(bool key);		// Checking whether you can rescue the princess

};

#endif

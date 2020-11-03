#include "Monster.h"
using namespace std;

Monster::Monster(string name)
{
	this->name = name;
	this->monster = true;
	this->flag = true;
}

bool Monster::battle(bool sword)
{
	if (this->flag && this->monster)
	{
		cout << "---OHHH!!! There's a monster in this room!!!!!" << endl;
		Sleep(500);
		if (sword)
		{
			this->monster = false;
			this->flag = false;
			cout << "---You killed the monster with the sword!" << endl;
			Sleep(500);
			cout << "---Your sword is broken, you cannot use it anymore..." << endl;
			return true;
		}
		else
		{
			cout << "---You have no weapon!" << endl;
			Sleep(500);
			cout << "---The monster killed you!" << endl;
			return false;
		}
	}
	else
	{
		cout << "---The monster in this room has been killed already." << endl;
		return true;
	}	
}


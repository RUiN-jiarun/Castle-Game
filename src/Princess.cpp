#include "Princess.h"
using namespace std;

Princess::Princess(string name)
{
	this->name = name;
	this->princess = true;
	this->flag = true;
}

void Princess::rescue(bool key)
{
	if (this->flag && this->princess)
	{
		cout << "---You found that the princess is locked up in this room!" << endl;
		Sleep(500);
		if (key)
		{
			cout << "---You free the princess." << endl;
			Sleep(500);
			cout << "---You took the princess with you, and promised that you'll make her safe." << endl;
			Sleep(500);
			cout << "---The princess is with you now!" << endl;
			this->princess = false;
			this->flag = false;
			return;
		}
		else
		{
			cout << "---...but there's no key to open the door..." << endl;
			Sleep(500);
			cout << "---Go to find the key!" << endl;
			return;
		}
	}
	else
	{
		cout << "---The princess in this room has been rescued." << endl;
		return;
	}
}


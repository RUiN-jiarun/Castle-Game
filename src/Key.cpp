#include "Key.h"
using namespace std;

Key::Key(string name)
{
	this->name = name;
	this->key = true;
	this->flag = true;
}

bool Key::getKey()
{
	Sleep(500);
	if (this->flag && this->key)
	{
		cout << "---Oops, you found a rusty key in the corner of this room." << endl;
		Sleep(500);
		cout << "---You picked up the key." << endl;
		Sleep(500);
		cout << "---The key may help you unlock the door." << endl;
		this->key = false;
		this->flag = false;
		return true;
	}
	else
	{
		cout << "---There's nothing in this room now." << endl;
		return false;
	}
}


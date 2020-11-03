#include "Sword.h"
using namespace std;

Sword::Sword(string name)
{
	this->name = name;
	this->sword = true;
	this->flag = true;
}

bool Sword::getSword()
{
	Sleep(500);
	if (this->flag && this->sword)
	{
		cout << "---There's a big stone in the middle of this room." << endl;
		Sleep(500);
		cout << "---A sword stuck in the stone." << endl;
		Sleep(500);
		cout << "---You pulled out this sword!" << endl;
		Sleep(500);
		cout << "---You are not afraid of the monster any more!" << endl;
		this->sword = false;
		this->flag = false;
		return true;
	}
	else
	{
		cout << "---There's nothing in this room now." << endl;
		return false;
	}
}


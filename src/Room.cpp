#include <map>
#include <iostream>
#include <string>
#include "Room.h"
using namespace std;

Room::Room()
{
	this->name = "NULL";
	this->win = false;
}

Room::Room(string name)
{
	this->name = name;
	this->win = false;
}

string Room::getName()
{
	return this->name;
}

bool Room::operator < (const Room& cmp) const
{
	return this->name < cmp.name;
}

void Room::setExit(string dir, Room* room) 
{
	this->exits.insert(map<string, Room*>::value_type(dir, room)); 
}

void Room::setWin()
{
	this->win = true;
}

bool Room::getWin()
{
	return this->win;
}

string Room::getExit()
{
	string s;
	map<string, Room*>::iterator iter = this->exits.begin();
	for (; iter != this->exits.end(); iter++)
	{
		s.append(iter->first);
		s.append(", ");
	}
	return s;
}

Room* Room::go(string dir)
{
	map<string, Room*>::iterator iter;
	iter = this->exits.find(dir);
	if (iter != this->exits.end())
		return iter->second;
	else
	{
		Sleep(500);
		cout << "---There's no door." << endl;
		return this;
	}
}

void Room::foo(){	}

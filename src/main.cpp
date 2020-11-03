#include "Game.h" 
using namespace std;

int main() 
{
	cout << "*Welcome to THE CASTLE*" << endl;
	Sleep(800);
	cout << "*Input BYE to end the game*" << endl;
	Sleep(800);
	cout << "*Input HELP to see some hints*" << endl;
	
	Initialization();
	Room* p = &cur;

	while (1)
	{
		string dir;
		getline(cin, dir);
		if (dir == "BYE")
			break;
		else if (dir == "HELP")
			Help();
		else if (dir == "20010308")
			Cheat();
		else
		{
			Room *tmp = new Room();
			tmp = (Move(p, dir));
			p = tmp;
			if (!Check(p))
				return 0;
		}
	}

	Sleep(800);
	cout << "*BYE*" << endl;
	Sleep(1000);
	 
	return 0;
}


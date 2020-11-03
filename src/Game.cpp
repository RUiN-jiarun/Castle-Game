#include "Game.h"

struct Playerstate Player;	
int no_prin, no_mon_1, no_mon_2, no_swo, no_key;	// The  number of the special room
Room cur;						
map<int, string> Map;				// The original map

/* Initialize the map of the game */
void Initialization()
{

	// Level 1
	Map[0] = "Yard";
	Map[1] = "Lobby";
	Map[2] = "Hall";
	Map[3] = "Dinning Room";
	Map[4] = "Bedroom";
	Map[5] = "Corridor";
	Map[6] = "Warehouse";
	Map[7] = "Living Room";
	Map[8] = "Kitchen";
	Map[9] = "North Chamber";
	Map[10] = "South Chamber";
	// Level 2
	Map[11] = "Attic";
	Map[12] = "Small Bedroom";
	Map[13] = "Storeroom";
	Map[14] = "Balcony";
	// Underground
	Map[15] = "Basement";
	Map[16] = "Aisle";
	Map[17] = "Dungeon";
	Map[18] = "Slaugterhouse";
	Map[19] = "????";
	Map[20] = "North Prison";
	Map[21] = "South Prison";

	// Set the special room
	srand((int)time(0));
	no_prin = random(17, 22);
	no_mon_1 = random(5, 11);
	no_mon_2 = random(11, 22);
	no_swo = random(1, 11);
	no_key = random(11, 15);
	if (no_key == no_mon_2)
	{
		if (no_key = 14)
			no_key--;
		else
			no_key++;
	}
	if (no_prin == no_mon_2)
	{
		if (no_prin = 21)
			no_prin--;
		else
			no_prin++;
	}



	vector<Room*> r;
	for (int i = 0; i < 22; i++)
	{
		if (i == no_prin)
		{
			Princess* tmp = new Princess(Map[i]);
			r.push_back(tmp);
		}
		else if (i == no_mon_1 || i == no_mon_2)
		{
			Monster* tmp = new Monster(Map[i]);
			r.push_back(tmp);
		}
		else if (i == no_swo)
		{
			Sword* tmp = new Sword(Map[i]);
			r.push_back(tmp);
		}
		else if (i == no_key)
		{
			Key* tmp = new Key(Map[i]);
			r.push_back(tmp);
		}
		else
		{
			Room* tmp = new Room(Map[i]);
			r.push_back(tmp);
		}


	}
	r[0]->setExit("east", r[1]);
	r[1]->setExit("west", r[0]);
	r[1]->setExit("east", r[2]);
	r[2]->setExit("west", r[1]);
	r[2]->setExit("north", r[7]);
	r[2]->setExit("east", r[3]);
	r[3]->setExit("west", r[2]);
	r[3]->setExit("north", r[8]);
	r[3]->setExit("east", r[4]);
	r[3]->setExit("south", r[10]);
	r[4]->setExit("west", r[3]);
	r[4]->setExit("north", r[6]);
	r[4]->setExit("east", r[5]);
	r[5]->setExit("west", r[4]);
	r[5]->setExit("downstairs", r[15]);
	r[6]->setExit("south", r[4]);
	r[6]->setExit("upstairs", r[11]);
	r[7]->setExit("south", r[2]);
	r[7]->setExit("east", r[8]);
	r[8]->setExit("west", r[7]);
	r[8]->setExit("north", r[9]);
	r[8]->setExit("south", r[3]);
	r[9]->setExit("south", r[8]);
	r[10]->setExit("north", r[3]);
	r[11]->setExit("downstairs", r[6]);
	r[11]->setExit("west", r[12]);
	r[12]->setExit("west", r[13]);
	r[12]->setExit("east", r[11]);
	r[13]->setExit("west", r[14]);
	r[13]->setExit("east", r[12]);
	r[14]->setExit("east", r[13]);
	r[15]->setExit("upstairs", r[5]);
	r[15]->setExit("west", r[16]);
	r[16]->setExit("west", r[17]);
	r[16]->setExit("east", r[15]);
	r[17]->setExit("west", r[18]);
	r[17]->setExit("north", r[20]);
	r[17]->setExit("east", r[16]);
	r[17]->setExit("south", r[21]);
	r[18]->setExit("west", r[19]);
	r[18]->setExit("east", r[17]);
	r[19]->setExit("east", r[18]);
	r[20]->setExit("south", r[17]);
	r[21]->setExit("north", r[17]);


	cur = *r[0];
	Sleep(800);
	cout << "*You're at the " << cur.getName() << ".*" << endl;
	Sleep(800);
	cout << "*You can go " << cur.getExit() << "*" << endl;


}

/* Show hints */
void Help()
{
	cout << "***This game is written & designed by Liu Jiarun.***" << endl;
	Sleep(500);
	cout << "***You can input the name of the direction to move in this map.***" << endl;
	Sleep(500);
	cout << "***For example, you can input 'north' to go north.***" << endl;
	Sleep(500);
	cout << "***Princess: There's a princess lost in this castle. Your task is to find her and take her out.***" << endl;
	Sleep(500);
	cout << "***Monster: There're several monsters living in this castle. If you have a sword with you, you can defeat it. Oterwise,....***" << endl;
	Sleep(500);
	cout << "***Sword: You can find one sword in the castle, which can help you defeat the monster. However, the sword seems to be very weak...***" << endl;
	Sleep(500);
	cout << "***That's all. Have fun!***" << endl;
}

/* Operate the player to move on the map */
Room* Move(Room* cur, string dir)
{
	Room *next = new Room();
	next = cur->go(dir);


	Sleep(500);
	cout << "*You're at the " << next->getName() << ".*" << endl;
	Sleep(500);
	cout << "*You can go " << next->getExit() << "*" << endl;

	return next;
}

/* The certain event will happen when the player enter the room */
bool Check(Room* p)
{
	if (p->getName() == Map[no_mon_1] || p->getName() == Map[no_mon_2])
	{
		Monster* q = static_cast<Monster*>(p);
		if (q != NULL)
		{
			bool survive = q->battle(Player.sword);
			if (!survive)
			{
				cout << "*************************************************************************************" << endl;
				cout << "*******@@@@@@@@@@@@@**************@@@@@**************@@@@@@@@@***********************" << endl;
				cout << "*******@@***********@@***********@@***@@*************@@*******@@@********************" << endl;
				cout << "*******@@***********@@**********@@*****@@************@@*********@@@******************" << endl;
				cout << "*******@@***********@@*********@@*******@@***********@@**********@@@*****************" << endl;
				cout << "*******@@@@@@@@@@@@@**********@@@@@@@@@@@@@**********@@***********@@*****************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@***********@@*****************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@*********@@@******************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@********@@@*******************" << endl;
				cout << "*******@@@@@@@@@@@@@**********@@*********@@**********@@@@@@@@@@**********************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@@*********@@**********@@@@@@@@@***********************" << endl;
				cout << "*******@@********************@@@@@*******@@**********@@*******@@@********************" << endl;
				cout << "*******@@********************@@*@@*******@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@**@@******@@**********@@**********@@@*****************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@***@@*****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@****@@****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@******@@**@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@*******@@@@@**********@@********@@@*******************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@*********@@@**********@@@@@@@@@@**********************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				Sleep(1000);
				cout << "*You've lost... your life.....*" << endl;
				Sleep(1000);
				cout << "*...but don't give up!!*" << endl;
				Sleep(1000);
				return false;			
			}
			else
			{
				Player.sword = false;
			}
		}
	}
	if (p->getName() == Map[no_prin])
	{
		Princess* q = static_cast<Princess*>(p);
		if (q != NULL)
		{
			q->rescue(Player.key);
			Player.princess = true;
		}
	}
	if (p->getName() == Map[no_swo])
	{
		Sword* q = static_cast<Sword*>(p);
		if (q != NULL)
		{
			bool itemget = q->getSword();
			if (itemget)
				Player.sword = true;
		}

	}
	if (p->getName() == Map[no_key])
	{
		Key* q = static_cast<Key*>(p);
		if (q != NULL)
		{
			bool itemget = q->getKey();
			if (itemget)
				Player.key = true;
		}

	}
	if (p->getName() == Map[0])
	{
		if (Player.princess)
		{
			p->setWin();
		}
		if (p->getWin())
		{
			Sleep(1000);
			cout << "*You successfully take the princess out of this horrible castle!*" << endl;
			Sleep(1000);
			if (Player.cheat)
			{
				cout << "*But you've cheated, you bad ass.*" << endl;
				Sleep(500);
				cout << "*************************************************************************************" << endl;
				cout << "*******@@@@@@@@@@@@@**************@@@@@**************@@@@@@@@@***********************" << endl;
				cout << "*******@@***********@@***********@@***@@*************@@*******@@@********************" << endl;
				cout << "*******@@***********@@**********@@*****@@************@@*********@@@******************" << endl;
				cout << "*******@@***********@@*********@@*******@@***********@@**********@@@*****************" << endl;
				cout << "*******@@@@@@@@@@@@@**********@@@@@@@@@@@@@**********@@***********@@*****************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@***********@@*****************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@*********@@@******************" << endl;
				cout << "*******@@***********@@********@@*********@@**********@@********@@@*******************" << endl;
				cout << "*******@@@@@@@@@@@@@**********@@*********@@**********@@@@@@@@@@**********************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@@*********@@**********@@@@@@@@@***********************" << endl;
				cout << "*******@@********************@@@@@*******@@**********@@*******@@@********************" << endl;
				cout << "*******@@********************@@*@@*******@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@**@@******@@**********@@**********@@@*****************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@***@@*****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@****@@****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@******@@**@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@*******@@@@@**********@@********@@@*******************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@*********@@@**********@@@@@@@@@@**********************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
			}
			else
			{
				cout << "*Well done!*" << endl;
				Sleep(500);
				cout << "*************************************************************************************" << endl;
				cout << "**********@@@@@@@@@@**********@@@@@@@@@**********@@@@@@@@@**********@@@@@@@@@********" << endl;
				cout << "********@@******************@@*********@@******@@*********@@********@@*******@@@*****" << endl;
				cout << "*******@@*******************@@*********@@******@@*********@@********@@*********@@@***" << endl;
				cout << "*******@@*******************@@*********@@******@@*********@@********@@**********@@@**" << endl;
				cout << "*******@@*****@@@@@@@*******@@*********@@******@@*********@@********@@***********@@**" << endl;
				cout << "*******@@*****@*****@@******@@*********@@******@@*********@@********@@***********@@**" << endl;
				cout << "*******@@***********@@******@@*********@@******@@*********@@********@@*********@@@***" << endl;
				cout << "********@@**********@@******@@*********@@******@@*********@@********@@********@@@****" << endl;
				cout << "**********@@@@@@@@@@**********@@@@@@@@@**********@@@@@@@@@**********@@@@@@@@@@*******" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@@*********@@**********@@@@@@@@@***********************" << endl;
				cout << "*******@@********************@@@@@*******@@**********@@*******@@@********************" << endl;
				cout << "*******@@********************@@*@@*******@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@**@@******@@**********@@**********@@@*****************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@***@@*****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@****@@****@@**********@@***********@@*****************" << endl;
				cout << "*******@@********************@@******@@**@@**********@@*********@@@******************" << endl;
				cout << "*******@@********************@@*******@@@@@**********@@********@@@*******************" << endl;
				cout << "*******@@@@@@@@@@@@@@@*******@@*********@@@**********@@@@@@@@@@**********************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
				cout << "*************************************************************************************" << endl;
			}
			Sleep(1000);
			return false;
		}
	}
	return true;
}

void Cheat()
{
	Sleep(500);
	cout << "***You are such a bad ass.***" << endl;
	Sleep(500);
	cout << "***Well, I'm sick of you.***" << endl;
	Sleep(500);
	cout << "***Here are the room number of the princess, monster1, monster2, sword and key.***" << endl;
	Sleep(500);
	cout << "***" << no_prin << "," << no_mon_1 << "," << no_mon_2 << "," << no_swo << "," << no_key << ".***" << endl;
	Sleep(500);
	cout << "***I feel very upset.***" << endl;
	Sleep(500);
	cout << "***You'd better end this game right now and retry it since the rooms are random each time.***" << endl;
	Sleep(500);
	cout << "***If you keep on playing, you may not reach the good end.***" << endl;
	Player.cheat = true;
}
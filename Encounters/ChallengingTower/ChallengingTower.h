// Maciej ¯ak, EiT gr.3   276624
//skala trudnoœci 3
//czy nadaje siê do gry ? chyba tak ;-d (3)
// pasuje do ka¿dej lokacji...



#pragma once
#include "..\..\Character.h"
#include "..\..\Encounter.h"
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

class ChallengingTower : public Encounter
{
public:
	ChallengingTower();
	~ChallengingTower();

	bool Proceed(Character* a)
	{
		wait();
		cout << "Walking around, you can see something very little laying on the ground...\n\n";
		Sleep(5000);
		cout << "Stepping up closer, you can tell it is... a ring. Not an usual one though...\n\n";
		Sleep(5000);
		cout << "You can literally hear the ring talking, whispering strange words to itself...\n\n";
		Sleep(5000);
		cout << "Sounds like it has been taken from its owner, and wants to go back...\n\n\n";
		Sleep(5000);
		cout << "Do you want to pick up the RING ? [yes/no] ...\n";
		string choice;
		cin >> choice;
		if (choice == "yes")
		{
			cout << "\nThe moment you touch the Ring, something strange begins to happen...\n\n";
			Sleep(5000);
			cout << "Dark fog covers all around you, and you can tell that you've just been moved...\n\n";
			Sleep(5000);
			cout << "         ...moved to another place.\n\n";
			Sleep(4000);

			firstfloor(a);
			wait();
			secondfloor(a);
			wait();
			thirdfloor(a);
			wait();
			meeting(a);
			
			return false;
		}
		else
		{
			cout << "\nRING makes it's final scream and disappears immidiately  ! ....\n";
			Sleep(4000);
			cout << "But you have this strange feeling that your roads might cross again...\n\n";
			Sleep(4000);
			return true;
		}
		
	}


	void firstfloor(Character* a);

	void secondfloor(Character* a);

	void thirdfloor(Character* a);

	void meeting(Character* a);

	void wait();
	
};


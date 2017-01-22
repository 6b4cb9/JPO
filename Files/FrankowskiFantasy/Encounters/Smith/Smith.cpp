#include "Elementy.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;



bool Smith::Proceed(Postac * ch)
{
	int choice = 0;
	int exit = 0;
	while (exit == 0)
	{
		int c;
		int a1 = 0;
		int a2 = 0;
		int a3 = 0;
		cout << string(50, '\n');
		cout << "You entered an smith's shop" << endl;
		cout << "What would you like to buy?" << endl;
		while (exit == 0)
		{
			cout << "1. Weapons  2. Exit" << endl;
			cin >> choice;
			cout << string(50, '\n');

			if (choice == 1)
			{

				cout << "1. Copper Dagger   - 200g - +1 Strength" << endl;
				cout << "2. Silver Cord     - 600g - +1 Toughness  +3 Strength" << endl;
				cout << "3 .Iron Sword      - 300g - +2 Toughness" << endl;
				cout << "4. Exit" << endl;
				cin >> c;
				cout << string(50, '\n');
				
				if (c == 1)
				{
					if (a1 == 0)
					{
						cout << "You bought Copper Dagger for 200g Strength increased by 1." << endl;
						a1 = 1;
						ch->SetGold(ch->GetGold() - 200);
						ch->SetStrength(ch->GetStrength() + 1);
						Sleep(3000);
					}
					else
					{
						cout << "You already have that weapon" << endl;
						Sleep(3000);
					}
				}
				if (c == 2)
				{
					if (a2 == 0)
					{
						cout << "You bought Silver Cord for 600g. Strength increased by 3 and Toughness by 1" << endl;
						a2 = 1;
						ch->SetGold(ch->GetGold() - 200);
						ch->SetStrength(ch->GetStrength() + 3);
						ch->SetToughness(ch->GetToughness() + 1);
						Sleep(3000);
					}
					else
					{
						cout << "You already have that weapon" << endl;
					}

				}
				if (c == 3)
				{
					if (a3 == 0)
					{
						cout << "You bought Iron Sword for 300g. Strength increased by 1." << endl;
						a3 = 1;
						ch->SetGold(ch->GetGold() - 200);
						ch->SetStrength(ch->GetStrength() + 1);
						Sleep(3000);
					}
					else
					{
						cout << "You already have that weapon" << endl;
						Sleep(3000);
					}
				}
				if (c == 4)
				{
					cout << "You exit the shop." << endl;
					exit = 1;
					Sleep(3000);
					return false;
				}
			}

			if (choice == 2)
			{
				cout << "You exit the shop." << endl;
				exit = 1;
				Sleep(3000);
				return false;
			}

		}
	}
}
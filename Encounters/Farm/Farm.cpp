#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stdio.h>
#include "Farm.h"


using namespace std;
/////////////////////////////////////////////////////////
/*
	Event FARM has difficulty level 2, it suits to road
	Event TAVERN has difficulty level 3, it suits to village, city or maybe countryside
	Both of them have priority level 3
*/
/////////////////////////////////////////////////////////
bool Farm::Proceed(Character * Adventurer)
{
	cout << "Going to the farm, you meet a rude mecenary. ";
	cout << "He blocks you and challanges you in javelin throw." << endl;
	cout << "'If you throw a javelin for a longer distance than me, I will let you go to the farm.' ";
	cout << "'Otherwise, I will kill you, if you try to pass me!' ";
	cout << "'MAKE YOUR STAND, YOU FOOL!!!'" << endl;
	cout << endl;
	cout << endl;
	cout << "What you want to do?" << endl;
	cout << "1. Try convince him to let you go" << endl;
	cout << "2. Accept challange and make a stand" << endl;
	
	cin >> choice;
	cout << endl;

	while (choice != '1' || choice != '2')
	{
		switch (choice)
		{
		case '1':
		{
					if (Adventurer->GetCharisma() >= 14) 
					{
						cout << "High level of charisma lets you convince mecenary, so you can go to the farm!";
						system("cls");
						exit(0);
					}
					else
					{
						cout << "It didn't worked! He gets mad and throws his javelin much stronger! ";
						cout << "You need to be very strong to beat him..." << endl;
						cout << endl;
						if (Adventurer->GetStrength() >= 14)
						{
							cout << "You did it! The mecenary goes away with shame and you can go to the farm";
							getchar();
							getchar();
							system("cls");
							return true;
						}
						else
						{
							cout << "You have lost, and as it was said, the mecenary kills you!" << endl;
							cout << "GAME OVER!!!";
							getchar();
							getchar();
							system("cls");
							return false;
						}
					}
					break;
		}
		case '2':
		{
					if (Adventurer->GetStrength() >= 11)
					{
						cout << "You did it! The mecenary goes away with shame and you can go to the farm";
						getchar();
						getchar();
						system("cls");
						return true;
					}
					else
					{
						cout << "You have lost, and as it was said, the mecenary kills you!" << endl;
						cout << "GAME OVER!!!";
						getchar();
						getchar();
						system("cls");
						return false;
					}
					break;
		}
		default:
		{
				   cout << "Choose available decision!!!";
				   system("cls");

				   cout << "What you want to do?" << endl;
				   cout << "1. Try convince him to let you go" << endl;
				   cout << "2. Accept challange and make a stand" << endl;

				   cin >> choice;
				   break;
		}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
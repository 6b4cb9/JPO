/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1

#include <iostream>
#include <cstdlib>
#include "windows.h"
#include <time.h>
#include <vector>
#include "ImprisonmentDungeons.h"

#include "Load_from_file.h"
#include "Labyrinth.h"

using namespace std;

bool ImprisonmentDungeons::Proceed(Character * Character)
{
	Text1 text1;
	text1.load("beginning.txt");
	
	cout << endl;
	Character->SetHP((Character->GetHP()) - 5);
	Character->SetGold((Character->GetGold()) - 5);
	Character->SetStrength((Character->GetStrength()) - 2);
	text1.show_stats(Character);
		
	text1.press_any();
	system("cls");
	///***************************************************************************
	
	text1.load("prison.txt");
	char choice = '0';
	while (1)
	{
		cin >> choice;
		if (choice == '1')
		{
			system("cls");
			text1.load("labyrinth.txt");
			text1.show_stats(Character);
			text1.press_any();
			///*******************************************************************
			
			system("cls");
			double time1 = GetTickCount();
			Labyrinth l1;
			l1.create_first();
			///*******************************************************************
			double time2 = GetTickCount();
			double diff = (time2 - time1) / 1000;
			system("cls");
			cout << "The passage of the labyrinth took you: " << diff;
			if (diff > 6 && diff <12)
			{
				Character->SetAgility((Character->GetAgility()) + 2);
				cout << endl<<"You gain:\n +2 AGILITY" << endl;
			}
			else if (diff < 6 )
			{
				Character->SetAgility((Character->GetAgility()) + 4);
				cout << endl<<"You gain:\n +4 AGILITY" << endl;
			}
			else
			{
				cout << endl << "Too slow: +0 AGILITY" << endl;
			}


			text1.load("after_labyrinth.txt");
			int choice1 = 0;

			while (1)
			{
				cin >> choice1;
				if (choice1 == 1)
				{

					cout << "You decided to take magic book" << endl;
					Character->SetIntelligence((Character->GetIntelligence()) + 3);
					Character->SetWisdom((Character->GetWisdom()) + 3);
					Character->SetStrength((Character->GetStrength()) - 1);
					break;
				}
				else if (choice1 == 2)
				{
					cout << "You didn't decide to take magic book" << endl;
					Character->SetWisdom((Character->GetWisdom()) - 1);
					Character->SetIntelligence((Character->GetIntelligence()) - 1);

					break;
				}
				else 
				{
					cout << "endl<<Wrong choice. Again!";
					break;
				}
				
			}
			
			text1.show_stats(Character);
			text1.press_any();

			text1.load("next_labyrinth.txt");
			text1.press_any();
			///*******************************************************************
			
			
			time1 = GetTickCount();
			l1.create_second();
			time2 = GetTickCount();
			diff = (time2 - time1) / 1000;
			system("cls");
			cout << "The passage of the labyrinth took you: " << diff;
			if (diff > 7 && diff <15)
			{
				Character->SetAgility((Character->GetAgility()) + 2);
				cout << endl << "You gain:\n +2 AGILITY" << endl;
			}
			else if (diff < 7)
			{
				Character->SetAgility((Character->GetAgility()) + 8);
				cout << endl << "You gain:\n +8 AGILITY" << endl;
			}
			else
			{
				cout << endl << "Too slow: +0 AGILITY" << endl;
			}
			
			srand(time(NULL));
			if (rand() % 10 == 4)
			{
				text1.load("no_fall.txt");
				text1.show_stats(Character);
				text1.press_any();
				cout << "You are FREE now. YOU FINISHED MY ENCOUNTER" << endl;
				Sleep(3000);
			
				return true;
				break;
			}
			else
			{
				text1.load("dungeons_fall.txt");
				text1.show_stats(Character);
				text1.press_any();
				system("cls");

				if ((Character->GetAgility()) > 18)
				{
					cout << "The dungeons are totally ruined now. Thanks you high AGILITY, you don't lose any points from stats.\n\nAll thing considered you are FREE now.\n";
					text1.show_stats(Character);
					text1.press_any();
					system("cls");
					cout << "YOU FINISHED MY ENCOUNTER" << endl;
					Sleep(3000);
					
					return true;
					break;
				}
				else if ((Character->GetAgility()) >12 && (Character->GetAgility())<18)
				{
					cout << "The dungeons are totally ruined now. Your AGILITY wasn't good enough, so you lose some points.\nHP -8\nStrength -2\nAll thing considered you are FREE now\n\n";
					Character->SetHP((Character->GetHP()) - 8);
					Character->SetStrength((Character->GetStrength()) - 2);
					text1.show_stats(Character);
					text1.press_any();
					system("cls");
					cout << "YOU FINISHED MY ENCOUNTER" << endl;
					Sleep(3000);
					
					return true;
					break;
				}
				else if (((Character->GetAgility()) < 11))
				{
					cout << "The dungeons are totally ruined now. Your AGILITY wasn't good enough, so you lose some points.\nHP -15\nStrength -5\nAll thing considered you are FREE now\n\n";
					Character->SetHP((Character->GetHP()) - 15);
					Character->SetStrength((Character->GetStrength()) - 5);
					text1.show_stats(Character);
					text1.press_any();
					system("cls");
					cout << "YOU FINISHED MY ENCOUNTER" << endl;
					Sleep(3000);
				}
				return true;
				break;
				
			}
		
		}
		else if (choice == '2')
		{
			system("cls");
			text1.load("no_escape.txt");
			
			Character->SetHP((Character->GetHP()) - 25);
			Character->SetGold((Character->GetGold()) - 5);
			Character->SetStrength((Character->GetStrength()) - 4);
			text1.show_stats(Character);
			text1.press_any();
			return true;
			break;
			
			system("PAUSE");
		}
		else
		{
			cin >> choice;
		}
	}

}



/////*************************************************
////**********************************************
///***********************************************

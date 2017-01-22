#include "encounter_1.h"



void DwarfDiceGame::SetBet(int b)
{
	bet = b;
}

int DwarfBetDialogs::EncounterIntro(Character *Adventurer) //wstêp do spotkania + pierwsze wybory i sytuacje w zale¿noœci
{
	int gold = 0;
	int choose;
	int choose2;

	system("CLS");
	cout << "You've been accosted by drunk, fishy dwarf. " << endl;
	cout << "- Hey Stranger ! Do you need gold ? Would you like to bet with me ?  - he asked\n\n\n\n\n" << endl;
	cout << "Answers:" << endl;
	cout << "1. What is the deal ?" << endl;
	cout << "2. No, leave me alone !" << endl;
	cin >> choose;
	if (choose == 1)
	{
		if (Adventurer->GetCharisma() < 11)
		{
			system("CLS");
			cout << "- I can't show you the details unless u get in\n\n\n\n\n" << endl;
			cout << "Answers:" << endl;
			cout << "1. I'm in" << endl;
			cout << "2. Get off you crafty dwarf !" << endl;
			while (true)
			{
				cin >> choose2;
				if (choose2 == 1)
				{
					gold = DwarfBetDialogs::EncounterBetRules(Adventurer);
					break;
				}
				if (choose2 == 2)
				{
					system("CLS"); //end
					DwarfBetDialogs::EncounterFight(Adventurer);
					break;
				}
			}

		}
		else
		{
			system("CLS");
			cout << "- Do you like gambling, huh ?" << endl;
			cout << "	We gonna throw with my wooden dices and... let's let luck decide !\n\n\n\n\n" << endl;
			cout << "Answers:" << endl;
			cout << "1. Go on" << endl;
			cout << "2. Get off you crafty dwarf !" << endl;
			while (true)
			{
				cin >> choose2;
				if (choose2 == 1)
				{
					gold = DwarfBetDialogs::EncounterBetRules(Adventurer);
					break;
				}
				if (choose2 == 2)
				{
					system("CLS"); //end
					break;
				}
			}
		}
	}
	else if (choose == 2)
	{
		system("CLS");
		cout << "- Tough luck, your loss !!!\n" << endl;
	}
	else
	{
		DwarfBetDialogs::EncounterIntro(Adventurer);
	}
	return gold;
}

int DwarfBetDialogs::EncounterBetRules(Character *Adventurer)
{
	int gold;

	system("CLS");
	cout << "- Let's begin !!! ... \n	Well, each of us got 3 throws with a dice - thats simple" << endl;
	cout << "	One of us who wins two of three times gets the money ... " << endl;
	cout << "	By the way, how much gold do you want to get into the bet ?\n\n\n" << endl;
	while (1)
	{
		cout << "Your gold:" << endl << Adventurer->GetGold() << endl;
		cout << "\nType in your bet:" << endl;
		cin >> gold;
		if (gold > Adventurer->GetGold())
		{
			system("CLS");
			cout << "You do not have enaugh gold !!! \n\n" << endl;
		}
		else
		{
			break;
		}
	}
	return gold;
}

bool DwarfBetEncounter::Proceed(Character *Adventurer)
{
	int bet = DwarfBetDialogs::EncounterIntro(Adventurer);
	if (bet != 0)
	{
		DwarfDiceGame *Game = new DwarfDiceGame;
		Game->SetBet(bet);
		Game->Play();
		Game->Results(Adventurer);
	}
	return true;
	system("PAUSE");
}

void DwarfDiceGame::Play()
{
	winner = 0;
	srand(time(NULL));
	DwarfBetDialogs::FirstThrow();
	int throws1, throws2, throws3, throws4, throws5, throws6;
	throws1 = rand();
	for (int i = 0; i < 30000; i++);
	throws2 = rand();
	cout << "    " << 1 + (throws1 % 5) << "                                           " << 1 + (throws2 % 5) << "\n\n\n\n\n";
	system("PAUSE");
	system("CLS");
	DwarfBetDialogs::SecondThrow();
	throws3 = rand();
	for (int i = 0; i < 30000; i++);
	throws4 = rand();
	cout << "    " << 1 + (throws1 % 5) << "                                           " << 1 + (throws2 % 5) << endl;
	cout << "    " << 1 + (throws3 % 5) << "                                           " << 1 + (throws4 % 5) << "\n\n\n\n";
	system("PAUSE");
	system("CLS");
	DwarfBetDialogs::ThirdThrow();
	throws5 = rand();
	for (int i = 0; i < 30000; i++);
	throws6 = rand();
	cout << "    " << 1 + (throws1 % 5) << "                                           " << 1 + (throws2 % 5) << endl;
	cout << "    " << 1 + (throws3 % 5) << "                                           " << 1 + (throws4 % 5) << endl;
	cout << "    " << 1 + (throws5 % 5) << "                                           " << 1 + (throws6 % 5) << "\n\n\n";
	system("PAUSE");
	if (throws1 > throws2)
	{
		winner = 1;
	}
	if (throws3 > throws4)
	{
		winner = 2;
	}
	if (throws5 > throws6)
	{
		winner = 3;
	}
}

void DwarfBetDialogs::FirstThrow()
{
	system("CLS");
	cout << "First throw !\n\n\n\n\n" << endl;
	cout << "You:                            Stranger Dwarf:" << endl;
}

void DwarfBetDialogs::SecondThrow()
{
	system("CLS");
	cout << "Second throw !\n\n\n\n\n" << endl;
	cout << "You:                            Stranger Dwarf:" << endl;
}

void DwarfBetDialogs::ThirdThrow()
{
	system("CLS");
	cout << "Third throw !\n\n\n\n\n" << endl;
	cout << "You:                           Stranger Dwarf:" << endl;
}

void DwarfDiceGame::Results(Character *Adventurer)
{
	if (winner == 2 || winner == 3)
	{
		system("CLS");
		cout << "You have won !" << endl;
		cout << bet << "  gold added" << endl;
		Adventurer->SetGold(Adventurer->GetGold() + bet);
		cout << "\n\nYour actual gold: \n\n" << endl;
		cout << "          " << Adventurer->GetGold();
	}
	else
	{
		system("CLS");
		cout << "You lost !" << endl;
		cout << bet << "  gold taken" << endl;
		Adventurer->SetGold(Adventurer->GetGold() - bet);
		cout << "\n\nYour actual gold: \n\n" << endl;
		cout << "          " << Adventurer->GetGold() << endl << endl;
	}
}


void DwarfBetDialogs::EncounterFight(Character* Adventurer)
{
	cout << "BOOM !!!" << endl;
	cout << "You have just woke up under taverns doors with broken head" << endl;
	cout << "Pain is insane ! wait... what ???" << endl;
	cout << "You had a fight with a bunch of drunk dwarfs and looks like somebody stole your wallet..." << endl;
	Adventurer->SetGold(0);
	cout << "\n\nYour actual gold: \n\n" << endl;
	cout << "          " << Adventurer->GetGold() << endl << endl;
}
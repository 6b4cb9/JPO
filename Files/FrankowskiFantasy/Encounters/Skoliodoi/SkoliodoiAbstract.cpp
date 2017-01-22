#include "stdafx.h"
#include "SkoliodoiAbstract.h"


SkoliodoiAbstract::SkoliodoiAbstract()
{
}


SkoliodoiAbstract::~SkoliodoiAbstract()
{
}

void SkoliodoiAbstract::Wait(int a)
{
	time_t start, koniec;
	double diff = 0;
	time(&start);
	while (diff < a)
	{
		time(&koniec);
		diff = difftime(koniec, start);
	}
}

int SkoliodoiAbstract::Read(int nr)
{
	int signnr;
	bool ok = false;
	char sign;
	do
	{
		sign = _getch();
		if (sign >= '1' && sign <= ('0' + nr))
		{
			ok = true;
		}
	} while (!ok);
	signnr = sign - '0';
	cout << signnr << endl;
	return signnr;
}

void SkoliodoiAbstract::End(Character *Hero)
{
	int choice;
	cout << endl;
	Wait(4);
	cout << "STORY:\tThe world around you is getting stronger and stronger. The air is dense, colors changes, the sun is green and grass is red. ";
	Wait(2);
	cout << "The river flows fire, trees look like huge monkeys. Everyone, even aristocrats, changes. Some people have additional limbs, ";
	Wait(2);
	cout << "the others start walking on their hands or have fire on head.\n";
	Wait(2);
	cout << "STORY:\tIn this chaos you accidently see a woman. She looks oddly normal, just an old woman. Only her hair shines like a moon. ";
	Wait(2);
	cout << "You don't ask her about anything, you just watch.\n";
	Wait(2);
	cout << "Woman:\tYou shouldn't get into this forest. It isn't a place for people. I can help you to survive and get back to your world, ";
	Wait(2);
	cout << "but you must solve a riddle.\n";
	Wait(2);
	cout << "Woman:\tA mother is 21 years older then her child. In 6 years the child will be 5 times younger then mother. Where is the father?\n";
	Wait(2);
	cout << "YOUR ANSWER\n";
	cout << "1) He's unknown.\n2) With the mother.\n3) He's dead.\n4) In a pub.\n5) At work.\n";
	choice = Read(5);
	switch (choice)
	{
	case 2:
		Hero->SetHP(Hero->GetHP() + 30);
		Hero->SetToughness(Hero->GetToughness() + 2);
		cout << "You guessed. I make you tougher. Don't waste my gift and run!\n";
		break;
	default:
		cout << "Wrong!\n";
	}

	cout << endl;
	Wait(4);
	cout << "STORY:\tYou open your eyes. The woman has gone. Have you ever seen her?\n";
	Wait(2);
	cout << "STORY:\tYou look around. You see only a few members of a team. Njute has become a tree, Omixos is on fire. ";
	Wait(2);
	cout << "STORY:\tThe only man who seems to be conscious is Berbelek. You show him you should go back.\n";
	Wait(2);
	cout << ".\n";
	Wait(2);
	cout << ".\n";
	Wait(2);
	cout << ".\n";
	Wait(2);
	cout << ".\n";
	Wait(2);
	cout << ".\n";
	if ((Hero->GetCharisma() >= 19) && (Hero->GetIntelligence() >= 17) && (Hero->GetToughness() >= 12) && (Hero->GetHP() >= 30))
	{
		cout << "STORY:\t After a few days, you reached the edge of the forest. You win, you get out on your own.\n";
		Hero->SetGold(Hero->GetGold() + 50);
		Hero->SetCharisma(Hero->GetCharisma() + 3);
		Hero->SetToughness(Hero->GetToughness() + 2);
	}
	else
	{
		cout << "STORY:\t After a few days, you wake up. You have survived only thanks to Berbelek.\n";
		Hero->SetHP(Hero->GetHP() - 30);
	}
	if (Hero->GetHP() <= 0)
	{
		Hero->SetHP(1);
		Hero->SetGold(Hero->GetGold() - 20);
	}
}
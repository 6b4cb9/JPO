#include "Elementy.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;



bool Robbery::Proceed(Postac * ch)
{
	int drunk = 0;
	int choice = 0;;
	int geld = 0;
	int liczba1;
	int liczba2;
	int sleep = 0;
	int asked = 0;
	cout << string(50, '\n');
	cout << "After wandering alone on the trail for three days, you finally met a group of merchants" << endl;
	cout << "You found out, that they are going in the same direction as you, so you decide to join them." << endl << endl;
	Sleep(7000);
	if (ch->GetIntelligence() + ch->GetIntelligence() + ch->GetCharisma() > 34)
	{
		cout << "After walking few hours, you notice that four of your companions are not carrying any merchandise on their horses" << endl;
		cout << "and are different race, probably Elves." << endl;
		cout << "'Isn't it strange for a vendor to travel with an empty sacks?' - you think" << endl << endl;
		Sleep(14000);
		cout << string(50, '\n');
	}
	cout << " 'It's getting dark' said one of your companions. Your company decided to light the campfire and rest" << endl;
	cout << "You sit next to the fire and prepare a rabbit leg for supper, then one of the merchants joins you" << endl;
	cout << "-'Rabbit huh? It tastes like a shoe... You should taste some of my Northern Islands shrimps... These are perfect' - said Samir" << endl;
	cout << "-'Maybe other time' - you answered" << endl << endl;
	cout << "What do you want to do?" << endl;
	cout << "1. Drink with Samir  2. Ask about rest of company  3. Play dices (gambling) " << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << string(50, '\n');
		drunk++;
		cout << "'Ahhh, that is what we call 'Devils Breath', quite strong isn't it?' - said Samir" << endl;
		cout << "You cannot disagree with your twisted expression on face..." << endl;
		Sleep(6000);
		cout << string(50, '\n');
	}
	if (choice == 2)
	{
		cout << string(50, '\n');
		cout << "Most of them are poor vendors from a southern provinces, just look at their stuff - pure garbage." << endl;
		cout << "Oh, and these four Elfish scums, I have never seen them, but they don't look trustful" << endl;
		Sleep(10000);
		cout << string(50, '\n');
		asked = 1;

	}
	if (choice == 3)
	{
		cout << string(50, '\n');
		cout << "Okay, rules are simple: who dice the highest number wins." << endl;
		cout << "How much you gold throw to stake?" << endl << endl;
		cin >> geld;
		if (geld <= ch->GetGold())
		{
			liczba1 = rand() % 12;
			Sleep(2000);
			liczba2 = rand() % 12;
			cout << "Your throw:  " << liczba1 << " " << "Samir throw:  " << liczba2 << endl;
			Sleep(3000);
			if (liczba1 > liczba2)
			{
				cout << "You have won" << " " << geld << " " << "gold." << endl;
				ch->SetGold(ch->GetGold() + geld);
			}
			if (liczba1 < liczba2)
			{
				cout << "You have lost" << " " << geld << " " << "gold." << endl;
				ch->SetGold(ch->GetGold() - geld);
			}
			if (liczba1 == liczba2) cout << "It's a draw! Nobody wins." << endl;
		}
		else
		{
			cout << "You dont even have this much..." << endl;
		}
		Sleep(5000);
		cout << string(50, '\n');
	}

	while ((sleep == 0 && drunk < 3))
	{
		cout << "What you want to do?" << endl;
		cout << "1. Drink with Samir   2. Ask about rest of company   3. Play dices  4. Go Rest" << endl;
		cin >> choice;
		if (choice == 1)
		{
			drunk++;
			cout << "'I knew that you're gonna love it, like i do' - said Samir" << endl;
			cout << "I'm not feeling well..." << endl;
			Sleep(5000);
			cout << string(50, '\n');
		}
		if (choice == 2 && asked == 1)
		{
			cout << "'You have already asked, do not trust these Elvish scums..." << endl;
			Sleep(5000);
			cout << string(50, '\n');

		}
		if (choice == 2 && asked == 0)
		{
			cout << "Most of them are poor vendors from a southern provinces, just look at their stuff - pure garbage." << endl;
			cout << "Oh, and these four Elfish scums, I have never seen them, but they don't look trustful" << endl;
			asked = 1;
			Sleep(8000);
			cout << string(50, '\n');

		}
		if (choice == 3)
		{
			cout << "Okay, rules are simple: who dice the highest number wins. How much gold throw to stake?" << endl;
			cin >> geld;
			if (geld <= ch->GetGold())
			{
				liczba1 = rand() % 12;
				liczba2 = rand() % 12;
				cout << "Your throw:  " << liczba1 << " " << "Samir throw:  " << liczba2 << endl;
				Sleep(3000);
				if (liczba1 > liczba2)
				{
					cout << "You have won" << " " << geld << " " << "gold." << endl;
					ch->SetGold(ch->GetGold() + geld);
				}
				if (liczba1 < liczba2)
				{
					cout << "You have lost" << " " << geld << " " << "gold." << endl;
					ch->SetGold(ch->GetGold() - geld);
				}
				if (liczba1 == liczba2) cout << "It's a draw! Nobody wins." << endl;
			}
			else
			{
				cout << "You dont even have this much..." << endl;
			}
			Sleep(5000);
			cout << string(50, '\n');
		}

		if (choice == 4) sleep = 1;
	}

	if (drunk >= 3)
	{
		cout << "You are drunk really hard. You left Samir and went sleep to your camp..." << endl;
		cout << "At night you hear some screams and sound of fighting... But you were too drunk, and you thought that it is only a dream..." << endl;
		cout << "You woke up the next day, by Samir. 'I knew it, these bastards, they robbed us, fu***ing Elves...' he yelled." << endl;
		cout << "'Why didn't you helped us? We were helpless... And we lost our horses and whole stuff" << endl;
		cout << "You notice, that half of your gold is gone, four elves also has stole your gold..." << endl;
		ch->SetGold(round(ch->GetGold()*0.5));
		cout << "You have now " << " " << ch->GetGold() << " " << "gold." << endl;
		cout << "With great pain in back of your head, you decide to leave your company, and go back on the trail...." << endl;
		Sleep(10000);
		cin >> choice;
		return true;
	}
	while (sleep == 1)
	{
		if (ch->GetCharisma() > 9 && asked == 1)
		{
			cout << "You are not a trustful person. With your persuasion skill, you convince all your companions to store the weapons in your hideout. " << endl;
			cout << "It was a good move, all of those Elvish Vendors had a weapons, who knows what they planned" << endl;
			cout << "As a reward you received 300 gold from the merchants. And you charisma skill is increased by 2" << endl;
			cout << "Now you can sleep safely, and return on the trail at the morning...." << endl;
			cout << "You gained 10hp for an good sleep" << endl;
			cin >> choice;
			ch->SetGold(ch->GetGold() + 300);
			ch->SetCharisma(ch->GetCharisma() + 2);
			ch->SetHp(ch->GetHp() + 10);
			return true;
		}
		cout << "You decided to rest next to the campfire... But you stay awake" << endl;
		cout << "At night you hear some noise coming from the merchants side." << endl;
		cout << "You notice that somebody is trying to steal goods from Vendors. You are going to interrupt them." << endl;
		cout << "You recognize thiefs as the Elvish Vendors - your compadres" << endl;
		Sleep(10000);
		sleep = 0;
		choice = 0;
	}
	while (choice == 0)
	{
		cout << "What you do?" << endl;
		cout << "1. Fight them  2. Let them free, if they give you gold." << endl;
		cin >> choice;
	}

		if (choice == 1)
		{
			cout << string(50, '\n');
			cout << "You decided to fight..." << endl;
			Sleep(3000);
			// WALKA
			cout << "You have won. Your strength and toughness is raised by 1. Also you received 150 gold." << endl;
			ch->SetStrength(ch->GetStrength() + 1);
			ch->SetToughness(ch->GetToughness() + 1);
			ch->SetGold(ch->GetGold() + 150);
			cout << "After a long fight, you rest a while and go back on the trail...." << endl;
			cin >> choice;
			return true;
		}
		if (choice == 2)
		{
			cout << string(50, '\n');
			cout << "You have earned 100 gold, and let them free..." << endl;
			cout << "You are going back on the road..." << endl;
			cin >> choice;
			ch->SetGold(ch->GetGold() + 100);
			return true;
		}
	}

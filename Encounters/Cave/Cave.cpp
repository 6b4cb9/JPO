#pragma once
#include "Cave.h"

using namespace std;

bool Cave::Proceed(Character* t_Adventurer) {
	Adventurer = t_Adventurer;
	system("cls");
	cout << "You have just came into dark cave..." << endl;
	srand(time(NULL));
	int lost_gold = 1 + rand() % (11);
	Adventurer->SetGold(Adventurer->GetGold() - lost_gold);
	cout << "Oh no! You have lost " << lost_gold << " gold coins!" << endl;
	getchar();

	if (Adventurer->GetIntelligence() > 2) {
		cout << "We must find that gold!" << endl;
		Sleep(600);
		cout << "Oh, here it is! And it is even more (+5) than we had lost!" << endl;
		Adventurer->SetGold(Adventurer->GetGold() + lost_gold + 5);
	}
	getchar();
	bool check;
	check = Goblin();
	if (!check) return false;
	Sleep(800);
	check = Dreisine();
	if (!check) return false;

	int present;
	present = rand() % 3;
	cout << "Look! There is cave's exit!" << endl;
	if (present == 2) {
		cout << "Wow, leaving the cave, you found magic golden ring!" << endl;
		cout << "+10 mana, +20 gold" << endl;
		Adventurer->SetMana(Adventurer->GetMana() + 10);
		Adventurer->SetGold(Adventurer->GetGold() + 20);
	}

	getchar();
	return true;
}

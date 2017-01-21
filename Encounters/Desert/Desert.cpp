#pragma once
#include "Desert.h"

using namespace std;
bool Desert::Proceed(Character* t_Adventurer) {
	Adventurer = t_Adventurer;
	bool check;
	system("cls");
	cout << "After long journey through the mountains you reached the Blood Desert... Good luck... " << endl;
	srand((unsigned int)time(NULL));
	int rand_choice = rand() % 1 + 1;
	getchar();
	cout << "Look! It's oasis! Come on, have some water." << endl;
	getchar();
	if (rand_choice == 1) {
		cout << "Oh no, it was a mirage... You are still thristy... Lost 5 hp" << endl;
		Adventurer->SetHP(Adventurer->GetHP() - 5);
		if (Adventurer->GetHP() <= 0) return false;
	}
	else if (rand_choice == 2) {
		cout << "You were lucky! +5 hp!" << endl;
		Adventurer->SetHP(Adventurer->GetHP() + 5);
	}
	else cout << "Uups! An error occured! Don't worry, you can play on." << endl;

	getchar();
	cout << "Do you want to go (1) East or (2) West?" << endl;
	char choice;
	do {
		cin >> choice;
		if (choice == '1') {
			check = East();
			if (!check) return false;
		}
		else if (choice == '2') {
			check = West();
			if (!check) return false;
		}
		else cout << "Choose one of displayed options!!!" << endl;

	} while ((choice != '2') && (choice != '1'));
	getchar();
	cout << "Look, it's town on the horizon!" << endl;
	return true;
	getchar();
}

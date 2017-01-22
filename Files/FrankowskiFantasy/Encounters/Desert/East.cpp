#include"stdafx.h"
#include "Desert.h"

using namespace std;
bool Desert::East(void) {
	bool check;
	char choice;
	srand((unsigned int)time(NULL));
	int rand_choice = rand() % 2 + 1;

	if (rand_choice == 1) {
		cout << "Lucky you! You found mysterious talisman.   +10 mana" << endl; 
		Adventurer->SetMana(Adventurer->GetMana() + 10);
	}

	cout << "It's growing dark." << endl << " You meet Creepy Ghost." << endl;
	cout << "If you want go on, you must defeat it." << endl;
	cout << "Now, you can try to (1)attack or (2)nagiotiate?" << endl;

	do {
		cin >> choice;
		if (choice == '1') {
			check = Attack();
			if (!check) return false;
		}
		else if (choice == '2') {
			check = Negotiation();
			if (!check) return false;
		}

		else cout << "Choose one of displayed options!!!" << endl;

	} while ((choice != '2') && (choice != '1'));

	return true;
}
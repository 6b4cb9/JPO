#include"stdafx.h"
#include "Cave.h"

bool Cave::Goblin(void) {
	cout << "You meet ugly Goblin... If you want go on, first defeat him." << endl << "Do you want to (1) deceive him or (2) attack?" << endl;
	char choice;

	do {
		cin >> choice;
		if (choice == '1') {
			if (Adventurer->GetCharisma() > 2) {
				cout << "Great! He believed in your silly story! You can go on!" << endl;
				cout << "+1 charisma" << endl;
				Adventurer->SetCharisma(Adventurer->GetCharisma() + 1);
			}
			else {
				cout << "Hmm, he didn't believe you... You lost 8 hp!" << endl;
				Adventurer->SetHP(Adventurer->GetHP() - 8);
				if (Adventurer->GetHP() <= 0) return false;
			}
		}
		else if (choice == '2') {
			if (Adventurer->GetStrength() > 2) {
				cout << "Wow! You defeated him!" << endl;
				cout << "+1 strength" << endl;
				Adventurer->SetStrength(Adventurer->GetStrength() + 1);
			}
			else {
				cout << "You were too weak to attack him... You lost 10 hp..." << endl;
				Adventurer->SetHP(Adventurer->GetHP() - 10);
				if (Adventurer->GetHP() <= 0) return false;
			}
		}
		else {
			cout << "Choose one of displayed options!!!" << endl;
		}
		getchar();

	} while ((choice != '2') && (choice != '1'));
	return true;
}
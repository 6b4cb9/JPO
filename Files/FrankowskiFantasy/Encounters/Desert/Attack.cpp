#include"stdafx.h"
#include "Desert.h"

bool Desert::Attack(void) {
	srand((unsigned int)time(NULL));
	int rand_choice = rand() % 3;
	if (rand_choice == 1) {
		cout << "Oh no, it called The Mongolian death worm!  -80 hp" << endl;
		Adventurer->SetHP(Adventurer->GetHP() - 80);
		if (Adventurer->GetHP() <= 0) return false;
	}

	for (int i = 0; i<3; i++) cout << "Attack!" << endl;
	if (Adventurer->GetStrength() > 2) {
		cout << "You are able to defeat it!" << endl;
		getchar();
		cout << "You won!    +1 agility" << endl;
		Adventurer->SetAgility(Adventurer->GetAgility() + 1);
		getchar();
		cout << "You can kill the Ghost, but it's begging you not to do this. Will you? (1) Yes / (2) No" << endl;
		char choice;
		do {
			cin >> choice;
			if (choice == '1') {
				cout << "So you did it... " << endl;
				cout << "+1 toughness" << endl;
				Adventurer->SetToughness(Adventurer->GetToughness() + 1);
				getchar();
				cout << "In ravenge, you were suddenly attacked by Mysterius Ghost!!" << endl;
				getchar();
				cout << "-3 hp" << endl;
				Adventurer->SetHP(Adventurer->GetHP() - 3);
				if (Adventurer->GetHP() <= 0) return false;
			}
			else if (choice == '2') {
				cout << "Thank you, Dear " << Adventurer->GetName() << ", you still have a heart. +1 charisma" << endl;
				cout << "Please take this Lightning Headband, I don't need it anyway." << endl << " +10 mana, +2 strength" << endl;
				Adventurer->SetMana(Adventurer->GetMana() + 10);
				Adventurer->SetStrength(Adventurer->GetStrength() + 2);
			}
			else {
				cout << "Choose one of displayed options!!!" << endl;
			}
		} while ((choice != '2') && (choice != '1'));
	}
	else {
		cout << "I don't think you are strong enough to defeat it..." << endl;
		getchar();
		cout << "You won, but also you lost 10 hp..." << endl << "+1 toughness" << endl;
		Adventurer->SetToughness(Adventurer->GetToughness() + 1);
		Adventurer->SetHP(Adventurer->GetHP() - 10);
		if (Adventurer->GetHP() <= 0) return false;
		char choice2;
		getchar();
		cout << "Caravan has stopped next you. What can you do: " << endl;
		cout << "(1) Buy medcines (10 gold coins, +10 hp)" << endl << "(2) Try to use charisma to buy medcines cheaper(3 gold coins, +10 hp)" << endl;
		cout << "(3) Try rob caravan" << endl;
		do {
			cin >> choice2;
			if (choice2 == '1') {
				cout << "+10 hp" << endl;
				Adventurer->SetHP(Adventurer->GetHP() + 10);
				Adventurer->SetGold(Adventurer->GetGold() - 10);
			}
			else if (choice2 == '2') {
				if (Adventurer->GetCharisma() > 3) {
					cout << "Hmm, nice, you get it! " << endl;
					cout << "+1 charisma" << endl;
					Adventurer->SetHP(Adventurer->GetHP() + 10);
					Adventurer->SetGold(Adventurer->GetGold() - 3);
					Adventurer->SetCharisma(Adventurer->GetCharisma() + 1);
				}
				else {
					cout << "Nope, you won't get this cheaper. Now you can get it for 15 gold coins. Do you want to? (1)Yes/(2)No" << endl;
					char choice3;
					do {
						cin >> choice3;
						if (choice3 == '1') {
							cout << "Deal!" << endl;
							Adventurer->SetHP(Adventurer->GetHP() + 10);
							Adventurer->SetGold(Adventurer->GetGold() - 15);
						}
						else if (choice3 == '2') cout << "Ok then. It was nice to meet you!" << endl;
						else  cout << "Choose one of displayed options!!!" << endl;
					} while ((choice3 != '2') && (choice3 != '1'));
				}
			}
			else if (choice2 == '3') {
				if (Adventurer->GetStrength() + Adventurer->GetAgility() > 8) {
					cout << "You made it!" << endl;
					cout << "+20 hp, +5 mana, +1 strength" << endl;
					Adventurer->SetHP(Adventurer->GetHP() + 20);
					Adventurer->SetMana(Adventurer->GetMana() + 5);
					Adventurer->SetStrength(Adventurer->GetStrength() + 1);
				}
				else {
					cout << "You were too weak to rob caravan." << endl;
					getchar();
					cout << "-5 hp" << endl;
					Adventurer->SetHP(Adventurer->GetHP() - 5);
					if (Adventurer->GetHP() <= 0) return false;
				}
			}
			else cout << "Choose one of displayed options!!!" << endl;
		} while ((choice2 != '2') && (choice2 != '1') && (choice2 != '3'));

	}
	return true;
}
#include "Desert.h"

bool Desert::Negotiation(void) {
	srand(time(NULL));

	cout << "-Hello My Dear..." << endl;
	int rand_choice = rand() % 2 + 1;
	if (rand_choice == 1) {
		cout << "Can you help me? I am looking for my friend... He died here fifty years ago... To find him I need a mortal human's blood." << endl;
		cout << "Will you help me? (1) Yes/ (2) No" << endl;
		char choice;
		do {
			cin >> choice;
			if (choice == '1') {
				cout << "Let's try! " << endl;
				for (int i = 0; i < 3; i++) {
					if (Adventurer->GetMana() < 2) return false;
					cout << "Come here my friend!		-2 mana" << endl;
					Adventurer->SetMana(Adventurer->GetMana() - 2);
					Sleep(500);
				}
				cout << "Yes, yes, here he is! Thank you and good luck!" << endl;
				cout << "+1 wisdom, +1 charisma" << endl;
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);
				Adventurer->SetCharisma(Adventurer->GetCharisma() + 1);
			}
			else if (choice == '2') {
				cout << "Ok, I see... If I suffer, you must suffer too... " << endl;
				Sleep(500);
				cout << "I will take your blood anyway!" << endl;
				if (Adventurer->GetAgility() > 3) {
					cout << "You are too fast! I can't catch you! " << endl;
					Sleep(500);
					cout << "Wrr, I will find another human!" << endl;
					cout << "+1 agility" << endl;
					Adventurer->SetAgility(Adventurer->GetAgility() + 1);
				}
				else {
					cout << "I told you... " << endl << "-10 hp, -3 mana" << endl;
					Adventurer->SetHP(Adventurer->GetHP() - 10);
					if (Adventurer->GetMana() < 3) return false;
					Adventurer->SetMana(Adventurer->GetMana() - 3);
					if (Adventurer->GetHP() <= 0) return false;
				}
			}
			else cout << "Choose one of displayed options!!!" << endl;

		} while ((choice != '2') && (choice != '1'));

	}
	else {
		cout << "or Hello Liar! You are stupid, lying creature, like every human!!" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Get out from here!" << endl;
			Sleep(500);
		}
		cout << "-1 hp" << endl;
		Adventurer->SetHP(Adventurer->GetHP() - 1);
		if (Adventurer->GetHP() <= 0) return false;
		rand_choice = rand() % 3 + 1;
		if (rand_choice == 2) {
			cout << "Sorry for my behaviour. Please, take this bottle of water (+10 hp) and don't be angry at me" << endl << "+1 wisedom" << endl;
			Adventurer->SetHP(Adventurer->GetHP() + 10);
			Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);
		}
	}
	return true;
}
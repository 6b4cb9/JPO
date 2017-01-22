#include"stdafx.h"
#include "Cave.h"

bool Cave::Dreisine(void) {
	srand((unsigned int)time(NULL));
	cout << "Look! Dreisine! (pol. drezyna) Let's see where it leads!" << endl;
	int rand_choice = rand() % (2);
	char choice;
	if (rand_choice == 0) {
		cout << "Oh, you found a pick in the dreisine! +10 gold" << endl;
		Adventurer->SetGold(Adventurer->GetGold() + 10);
	}
	rand_choice = rand() % (2);
	Sleep(700);
	cout << "Wow, it's so fast!" << endl;
	if (rand_choice == 1) {
		cout << "BUUUUUUUUUUUUUUUUUUUM" << endl;
		Sleep(700);
		cout << "What has happend? Fortunately, you are all right... " << endl;
		Sleep(700);
		cout << "... but you hurt someone! Will you (1) help him or (2) go away?" << endl;
		do {
			cin >> choice;
			if (choice == '1') {
				cout << "Uff, he is all right! It was a noble deed! +1 charisma" << endl;
				Sleep(700);
				cout << "And he gives you some gold! +5 gold" << endl;
				Adventurer->SetCharisma(Adventurer->GetCharisma() + 10);
				Adventurer->SetGold(Adventurer->GetGold() + 5);
			}
			else if (choice == '2') {
				cout << "Oops... He saw you. Though you escaped, he stole you some gold!" << endl;
				Adventurer->SetGold(Adventurer->GetGold() - rand()%6);
			}
			else cout << "Choose one of displayed options!!!" << endl;
		} while ((choice != '2') && (choice != '1'));

	}

	else {
		cout << "There is a wall in front of us! Save yourself and escape from this trolley!" << endl;
		if (Adventurer->GetAgility()>1) {
			cout << "Nice jump! +1 agility" << endl;
			Adventurer->SetAgility(Adventurer->GetAgility() + 1);
		}
		else {
			cout << "Hmm, maybe you haven't broken anything, but certainly you have hurt... -2 hp" << endl;
			Adventurer->SetHP(Adventurer->GetHP() + 1);
			if (Adventurer->GetHP() <= 0) return false;
		}

	}
	return true;
}
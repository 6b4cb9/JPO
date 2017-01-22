#include"stdafx.h"
#include "Desert.h"

bool Desert::Companion(void) {
	srand((unsigned int)time(NULL));
	cout << "The Man in Black is attacking the Gunslinger! You must defend yourself!" << endl;
	Sleep(500);
	cout << "In this fight your new friend adds +5 to your strength and toughness" << endl;
	Sleep(500);
	cout << "Do you want to (1) help him or (2) run?" << endl;
	char choice;
	do {
		cin >> choice;
		if (choice == '1') {
			if (Adventurer->GetStrength() + Adventurer->GetToughness() + 5 > 10) {
				for (int i = 0; i < 3; i++) {
					cout << "Attack!" << endl;
					Sleep(500);
				}
				cout << "Congratulations! You defeated the enemy! Moreover, this was a noble decision to help your new friend" << endl;
				cout << "+1 strength, +1 wisdom" << endl;
				Adventurer->SetStrength(Adventurer->GetStrength() + 1);
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);
				getchar();
			}
			else {
				for (int i = 0; i < 3; i++) {
					cout << "Attack!" << endl;
					Sleep(800);
				}
				cout << "..." << endl << "You were too weak to help your friend... He died..." << endl;
				Sleep(500);
				cout << "You lost 10 hp... However, you were very brave and noble! You get +1 wisdom." << endl;
				Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);
				Adventurer->SetHP(Adventurer->GetHP() - 10);
				if (Adventurer->GetHP() <= 0) return false;

			}
		}
		else if (choice == '2') {
			cout << "You escaped from the fight area." << endl;
			getchar();
			int rand_choice = rand() % 3 + 1;

			if (rand_choice == 1) {
				cout << "However, The Man in Black and his friends caught you!" << endl;
				Sleep(500);
				cout << "Now you have to fight with them" << endl;
				for (int i = 0; i < 3; i++) {
					cout << "Attack!" << endl;
					Sleep(800);
				}
				if (Adventurer->GetStrength() + Adventurer->GetToughness() + Adventurer->GetAgility() > 10) {
					cout << "Wow, it was exhausting fight" << endl;
					Sleep(500);
					cout << "However, you won!  +1 toughness" << endl;
					Adventurer->SetToughness(Adventurer->GetToughness() + 1);
				}
				else {
					cout << "You were too weak to defeat them..." << endl;
					Sleep(500);
					cout << "You lost 20 hp" << endl;
					Adventurer->SetHP(Adventurer->GetHP() - 20);
					if (Adventurer->GetHP() <= 0) return false;
				}
			}
			else if (rand_choice == 2) {
				cout << "Something is approaching to you" << endl;
				Sleep(5000);
				cout << "You are attacked by two cobras!" << endl;
				for (int i = 0; i < 3; i++) {
					cout << "Fight!" << endl;
					Sleep(600);
				}
				if (Adventurer->GetAgility() > 3) {
					cout << "Uff, it was easy, but dangerous fight!" << endl << "+1 agility" << endl;
					Adventurer->SetAgility(Adventurer->GetAgility() + 1);
				}
				else {
					cout << "You were too weak and they hurt you..." << endl << "-10 hp" << endl;
					Adventurer->SetHP(Adventurer->GetHP() - 10);
					if (Adventurer->GetHP() <= 0) return false;
				}
			}
			else {
				cout << "So, now you are looking for any sign of life. And you walk..." << endl;
				for (int i = 0; i < 3; i++) {
					cout << "Walk..." << endl;
					Sleep(600);
				}
				cout << "All right, now you have to think a little." << endl;
				Sleep(500);
				cout << "Oh no, you have lost!" << endl;
				if (Adventurer->GetIntelligence() > 3) {
					cout << "Eureka! You need only to check stars location and you know where to go!" << endl;
					getchar();
					cout << "Nice! +1 intelligence" << endl;
					Adventurer->SetIntelligence(Adventurer->GetIntelligence() + 1);
				}
				else {
					cout << "Sorry, you are too stupid to manage with this situation..." << endl;
					getchar();
					for (int i = 0; i < 3; i++) {
						cout << "You are dying, -2 hp" << endl;
						Adventurer->SetHP(Adventurer->GetHP() - 2);
						Sleep(500);
					}
					if (Adventurer->GetHP() <= 0) return false;
					cout << "Look, it's caravan, so there is a road. " << endl;
				}
			}
		}
		else cout << "Choose one of displayed options!!!" << endl;
	} while ((choice != '2') && (choice != '1'));
	return true;
}
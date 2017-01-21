#include "Desert.h"

bool Desert::NoCompanion(void){
	srand((unsigned int)time(NULL));
	cout << "I don't trust you. If you answer correctly, you can go. Otherwise, I will attack you." << endl;
	cout << "In two years, I will be looking for The Man in the Black for ten years. How long have I been looking for him? " << endl;
	string answer;
	cin >> answer;
	if (answer == "8") {
		cout << "Ok, you can go. Good luck!   +1 intelligence" << endl;
		Adventurer->SetIntelligence(Adventurer->GetIntelligence() + 1);
		getchar();
		if (Adventurer->GetIntelligence() > 2) {
			cout << "Wait! I think you are enough intelligent to answer to the second question" << endl << "Don't go, I will find you anyway" << endl;
			cout << "If you answer wrong, you give 5 gold coins." << endl;
			Sleep(600);
			cout << "If five vultures eat five rabbits in five minutes, how much vultures eat one hundred rabbits in one hundred minutes?" << endl;
			string answer2;
			cin >> answer2;
			if (answer2 == "5") {
				cout << "Ok then... You can go... Good luck!" << endl;
				cout << "+1 intelligence" << endl;
				Adventurer->SetIntelligence(Adventurer->GetIntelligence() + 1);
			}
			else {
				cout << "Ha! You are wrong! Give my money, you fool!" << endl;
				cout << "-5 gp" << endl;
				Adventurer->SetGold(Adventurer->GetGold() - 5);
			}
		}
		else {
			cout << "Hmm, the another question may be too hard for you. Let's check your strength!" << endl;
			cout << "If you lift up that stone, I will let you free. Otherwise, you will give 5 gold coins." << endl;
			if (Adventurer->GetStrength() > 3) {
				cout << "Wow, you are strong! You can go" << endl;
				cout << "+1 strength" << endl;
				Adventurer->SetStrength(Adventurer->GetStrength() + 1);
			}
			else {
				cout << "Ha ha, give me my money!" << endl;
				cout << "-5 gp" << endl;
				Adventurer->SetGold(Adventurer->GetGold() - 5);
			}	
		}
	}
	else {
		cout << "Wrong answer..." << endl;
		int rand_choice = rand() % 2 + 1;
		if (rand_choice == 1) {
			cout << "I promised to attack you, but I don't think that you are my enemy... You can go!" << endl << "+2 hp" << endl;
			Adventurer->SetHP(Adventurer->GetHP() + 2);
		}
		else {
			cout << "Defend yourself! " << endl;
			for (int i = 0; i < 2; i++) cout << "Watch out!" << endl;
			cout << "Nice fight! Anyway, you lose 3 hp!" << endl;
			Adventurer->SetHP(Adventurer->GetHP() - 3);
			if (Adventurer->GetHP() <= 0) return false;
		}
	}
	return true;
}
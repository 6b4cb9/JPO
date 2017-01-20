#include "Desert.h"

using namespace std;
bool Desert::West(void) {
	bool check;
	char choice;
	srand(time(NULL));
	cout << "It's growing dark. You meet Gunslinger." << endl;
	cout << "Hello, do you want to be my companion?  (1) Yes / (2) No" << endl;
	do {
		cin >> choice;
		if (choice == '1') {
			int rand_choice = rand() % 2 + 1;
			cout << "Great, I haven't talked to anybody for weeks!" << endl << "I am looking for my enemy- The Man in Black. But it's dangerous journey... Extremely dangerous..." << endl;
			getchar();

			if (rand_choice == 2) {
				cout << "Do you want something to eat? Please, help yourself.      +5 hp" << endl;
				Adventurer->SetHP(Adventurer->GetHP() + 5);
				getchar();
			}

			check = Companion();
			if (!check) return false;
		}
		else if (choice == '2') {
			check = NoCompanion();
			if (!check) return false;
		}
		
		else cout << "Choose one of displayed options!!!" << endl;

	} while ((choice != '2') && (choice != '1'));
	return true;
}


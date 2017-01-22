#include "RedricInn.h"
#include<iostream>
#include<string>
using namespace std;

bool RedricInn::Proceed(Character * Adventurer) {
	int choice = introduce();
	int choice1=event(choice);
	event1(choice1, Adventurer); 
	return false;
	
}
int RedricInn::introduce() {

	cout << "You are in the RedrickInn, the most famous inn in this city." << endl;
	cout << "Always you meet here a lot of bad characters. You should be cautious and trust only yourself." << endl;
	cout << "Here you can get a chance for an interesting adventure" << endl;
	cout << "You should see on the notice board or sit down at the table." << endl;
	cout << endl;
	cout << "Make your choice:" << endl;
	cout << "1.Look on the notice board" << endl;
	cout << "2.Sit down at the table" << endl;
	int choice1;
	cin >> choice1;
	if (choice1 == 1) return 1;
	else return 2;

}
int RedricInn::event(int a) {

	if (a == 1) {
		cout << "In the board are 2 notice:" << endl;
		cout << "1.Someone needs help at the opening of the precious chest. Award is 10 gold." << endl;
		cout << "2.Cooker needs 4 fish for dinner. You have 12 traps, award is elixir( +1 strength, +1 toughhess,+1 agility)"<<endl;
		cout << endl;
		cout << " Press 1 or 2." << endl;
		int choice;
		cin >> choice;
		if (choice == 1) return 1;
		else if (choice == 2) return 2;

		
	}

}
void RedricInn::event1(int a, Character * Adventurer) {
	if (a == 1) {
		cout << "You found the right person. You have only 5 attempts because you have 5 skeleton keys.Chest has 3 locks." << endl;
			
			int win=0;
			for (int i = 0; i < 5; i++) {
				cout << "Chance " << i+1 << "/5 " << endl;
				string score;
				for (int i = 1; i <= 3; i++) {
					string x;
					cout << "Lock number ["<<i<<"]. Enter a number from 1 to 3" << endl;
					cin >> x;
					string _str = to_string(i);

					if (x == _str) cout << "Good choice" << endl;
					else {
						cout << "Bad choice. "; break;
					}
					score = score + x;
					
				}
				if (score == "123") {
					win = 1; break;
				}
				else cout << "Try again!" << endl;
			}
			if (win == 0) cout << "You did not perform the task" << endl;
			else {
				cout << "Congratulations. Your reward is 10 gold." << endl;
				int gold;
				gold=Adventurer->getgold();
				Adventurer->setgold(gold + 10);
				
			}
	}
	else if (a == 2) {
		cout << "Here everything depends on luck and your skills." << endl;
		cout << "Sometimes you can catch something precious." << endl;
		cout << "Once you can set the 3 traps .\n Here we go!" << endl;
		int trap[4];
		int i = 1;
		int ii = 1;
		int fish = 0;
		do {
			cout << "1.Set traps\n2.Check traps" << endl;
			int b;
			cin >> b;
			if (b == 1 && b < 4) {
				if(i<4){
				cout << "Trap[" << i << "] set. Wait for the fish." << endl;
				trap[i] = 1;}
				else cout << "No traps" << endl;
				i++;
			}
			
			
			else {
				cout << "Select the number of traps" << endl;
				int sel;
				
				int happiness = rand() % (10 + 1);
				int wisdom = Adventurer->getwisdom();
				int agility = Adventurer->getagility();

				cin >> sel;
				if (sel <= 3 && sel >= 1) {
					if (trap[sel] == 0) cout << " This trap is not set" << endl;
					else if(trap[sel]==1){
						if (agility > 4 && wisdom > 2 && happiness >= 5 && happiness < 7) { cout << "Fish !\n"; fish++; ii++; trap[sel] = 2; }
						else if (happiness >= 0 && happiness < 5) {
							cout << "Nothing\n"; ii++; trap[sel] = 2;
						}
						else if (agility > 5 && wisdom > 3 && happiness >= 9) { cout << "You are lucky. Fish + Gem(+1 gold)\n"; ii++; trap[sel] = 2; Adventurer->setgold(Adventurer->getgold() + 1); }
						else if (agility > 4 && wisdom > 2 && happiness >= 7 && happiness < 9) { cout << "Gem(+1 gold)\n"; ii++; trap[sel] = 2; Adventurer->setgold(Adventurer->getgold() + 1); }
						
						}
					else cout << "Trap checked" << endl;
				}
				else cout << "Bad number" << endl;
			}
		} while (ii<4);

		if (fish >= 4) { cout << "Good job" << endl; 
		Adventurer->setstrength(Adventurer->getstrength() + 1);
		Adventurer->settoughness(Adventurer->gettoughness() + 1);
		Adventurer->setagility(Adventurer->getagility() + 1);
		}
	}

	
	else { 
		cout << "Buy:\n1.Beer\n2.Dinner" << endl;
		int a;
		cin >> a;
		if (a == 1) { cout << "Strength +1, Gold -1" << endl; Adventurer->setstrength(Adventurer->getstrength() + 1); Adventurer->setgold(Adventurer->getgold() - 1);
		}
		else if(a==2){ cout << "Strength +2, Gold -2" << endl; Adventurer->setstrength(Adventurer->getstrength() + 2); Adventurer->setgold(Adventurer->getgold() - 2);
		}
		cout << endl; }

}
RedricInn::RedricInn()
{
}


RedricInn::~RedricInn()
{
}


#include "Graveyard.h"


Graveyard::Graveyard()
{
}


Graveyard::~Graveyard()
{
}

bool Graveyard::Proceed(Character * Adventurer)
{ 
	PlaceDescriber(Adventurer);
	system("pause");
	system("cls");
	
	FirstAction(Adventurer);
	SecondAction(Adventurer);
	ThirdAction(Adventurer);

	return true;


}

void Graveyard::PlaceDescriber(Character * Adventurer)
{
	cout << "===============================================================================" << endl;
	cout << "Helo " << Adventurer->GetName() << endl;
	cout << "It's midnight. You have just come across an Old Graveyard. " << endl;
	cout << "The notes of acient Druids say that there is a lot of gold," << endl;
	cout<<"which is hidden underground." << endl;
	cout << "The only thing you have to do is explore." << endl;
	cout << "===============================================================================" << endl;
}

void Graveyard::FirstAction(Character* Adventurer)
{
	cout << "You have found a grave of Great Magus called Ignis." << endl;
	cout << "Do you want to explote it?  1.Yes  2. No" << endl;
	int choice;
	int counter;
	cin >> choice;
	if (choice == 1) {
		system("cls");
		cout << "You have to answer this question to open this grave:  " << endl;
		cout << "Take off my skin - I won't cry, but you will! What am I? You have 3 chances" << endl;
		string answer;
		

		for (counter = 0; counter < 3; counter++) {
			cin >> answer;
			if (answer == "onion") {
				cout << "Good answer,  your gold increases by 2" << endl;
				Adventurer->SetGold(Adventurer->GetGold() + 2);
				break;
			}
			else if(counter<2) {
				cout << "Bad answer, ty again" << endl;
			}
			else {
				cout << "Bad answer" << endl;
			}
		}
		cout << "You can go further" << endl;
		system("pause");
		system("cls");
	}
	

}

void Graveyard::SecondAction(Character * Adventurer)
{
	cout << "You came across the terrible ghost, guardian of this Graveyard." << endl;
	system("pause");
	if (Adventurer->GetIntelligence() >= 9) {
		cout << "Your intelligence is high enough to persuate him that you are not enemy" << endl;
		cout << "Your charisma increases by 1, and wisdom increases by 1" << endl;
		Adventurer->SetCharisma(Adventurer->GetCharisma() + 1);
		Adventurer->SetWisdom(Adventurer->GetWisdom() + 1);
		system("pause");
	}
	else {
		cout << "You have to use your MANA points to chase him off" << endl;
		cout << "Your mana decresases by 1" << endl;
		Adventurer->SetMana(Adventurer->GetMana() - 1);
		system("pause");
	}

}

void Graveyard::ThirdAction(Character * Adventurer)
{
	
	system("cls");
	cout << "You falled into the grave." << endl;
	for (int counter = 0; counter < 14; counter++) {
		for (int counter2 = 0; counter2 < 200000000; counter2++) {
		}
		cout << ". ";
	}
	cout << endl;
	system("pause");

	int random_number;
	//srand(time(NULL));
	random_number = rand() % 11;

	if (random_number < 5) {
		cout << "You were lucky. Gravedigger was walking near the hole. He can help you but not  for free. He wants 2 golds. Do you agree? You can also wait to next morning.    1.Yes  2.No" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "He helped you. You lost 2 golds" << endl;
			Adventurer->SetGold(Adventurer->GetGold() - 2);
		}
		else {
			cout << "OK. So we have to wait." << endl;
			for (int counter = 0; counter < 14; counter++) {
				for (int counter2 = 0; counter2 < 200000000; counter2++) {
				}
				cout << ". ";
			}
			cout << endl << "Your toughness decreases by 2, strength by 1 and charisma by 1." << endl;
			Adventurer->SetToughness(Adventurer->GetToughness() - 2);
			Adventurer->SetStrength(Adventurer->GetStrength() - 1);
			Adventurer->SetCharisma(Adventurer->GetCharisma() - 1);
		}
	}
	else {
		cout << "Noone is comming. You have to wait to next morning" << endl;

		for (int counter = 0; counter < 14; counter++) {
			for (int counter2 = 0; counter2 < 200000000; counter2++) {
			}
			cout << ". ";
		}
		cout << endl << "Your toughness decreases by 2 and strength by 1." << endl;
		Adventurer->SetToughness(Adventurer->GetToughness() - 2);
		Adventurer->SetStrength(Adventurer->GetStrength() - 1);
	}
	system("pause");
	system("cls");
}

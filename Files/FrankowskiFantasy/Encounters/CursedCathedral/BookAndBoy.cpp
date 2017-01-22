#include "stdafx.h"
#include "BookAndBoy.h"


BookAndBoy::BookAndBoy()
{
}


BookAndBoy::~BookAndBoy()
{
}

void BookAndBoy::execute(Character * character){
	
	PlotRead * read = new Adapter();
	read->ReadFile("stage_four.txt", 1);
	bool isCorrect;
	int deciision;
	do {
		string decision;
		cout << endl;
		cout << "1: Yes I am" << endl;
		cout << "2: No I am not" << endl;
		cin >> decision;
		if (decision == "1") {
			deciision = 1 ;
			break;
		}

		if (decision == "2") {
			deciision = 2;
			break;
		}
		else {
			cout << "Incorrect decision, type again" << endl;
			isCorrect = false;
		}
	} while (!isCorrect);

	system("cls");
	
	if (deciision == 1) {
		read->ReadFile("stage_four.txt", 2);
		int curingResutl = curing(character);
		system("cls");

		if (curingResutl == 1) {
			read->ReadFile("stage_four.txt", 3);

			cout << endl << endl << "Intelligence , wisdom, agility and charisma  are incresed by 2 " << endl;
			character->setIntelligence(character->getIntelligence() + 2);
			character->setAgility(character->getAgility() + 2);
			character->setCharisma(character->getCharisma() +2);
			character->setWisdom(character->getWisdom() +2);
		}
		
		if (curingResutl == 0) {
			read->ReadFile("stage_four.txt", 4);
			cout << endl << endl << "Intelligence and agility  are decresed by 1 " << endl;
			character->setIntelligence(character->getIntelligence() -1);
			character->setAgility(character->getAgility() -1);
		}


	}

	if (deciision == 2) {
		read->ReadFile("stage_four.txt", 5);
		cout << endl << endl << "Intelligence and agility  are incresed by 1 " << endl;
		character->setIntelligence(character->getIntelligence() + 1);
		character->setAgility(character->getAgility() + 1);
	}


}

int BookAndBoy::curing(Character * adventourer) {

	PlotRead * read = new Adapter();;
	int intel = adventourer->getIntelligence();
	int wisdom = adventourer->getWisdom();
	int agility = adventourer->getAgility();
	int strength = adventourer->getStrength();
	int charsima = adventourer->getCharisma();

	int mainFactor = intel + wisdom + agility + strength + charsima;
	srand(time(NULL));
	int number = rand() % 100;
	mainFactor = 3 * mainFactor - 150;

	if (mainFactor < 1) {
		mainFactor = 1;
	}

	if (mainFactor > 100) {
		mainFactor == 100;
	}

	if (number <= mainFactor) {
		cout << "Type spell" << endl;
		string spell;
		cin>>spell;
		
		if (spell == "expecto_patronum") {
			return 1;
		
		}
		if (spell != "expecto_patronum") {
			return 0;
		}

	}
	if (number > mainFactor) {
		return 0;
	}
}


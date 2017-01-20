#include "stdafx.h"
#include "SecondStage.h"


SecondStage::SecondStage()
{
}


SecondStage::~SecondStage()
{
}

bool SecondStage::proceed(Character * adventourer){
	system("cls");
	PlotRead * read = new Adapter();

	for (int i = 0; i <= 3; i++) {
		read->ReadFile("stage_two.txt", i);
	}
	findKey(adventourer);

	if (getChest() == true & getWadrobe() == true) { // you found both keys
		read->ReadFile("stage_two.txt", 7);
		bool decision = chooseKey();
		system("cls");
		if (decision == true) {
			read->ReadFile("stage_two.txt", 9);
			setBook(true);
			this->nextStage->status(this->getChest(), this->getWadrobe(), this->getBook());
			system("pause");
			nextStage->proceed(adventourer);
			return false;
		}
		else {
			read->ReadFile("stage_two.txt", 10);
			read->ReadFile("stage_two.txt", 11);
			setBook(true);
			setWardrobeKey(false);
			this->nextStage->status(this->getChest(), this->getWadrobe(), this->getBook());
			system("pause");
			nextStage->proceed(adventourer);
			setWardrobeKey(true);
			return false;
		}
	}
	if (getChest() == true & getWadrobe() == false) { //you have found only key to chest
		read->ReadFile("stage_two.txt", 9);
		setBook(true);
		this->nextStage->status(this->getChest(), this->getWadrobe(), this->getBook());
		system("pause");
		nextStage->proceed(adventourer);
		return false;
	}
	if (getChest() == false) { // you have found nothing
		this -> setBook(false);
		read->ReadFile("stage_two.txt", 12);
		this->nextStage->status(this->getChest(), this->getWadrobe(), this->getBook());
		system("pause");
		nextStage->proceed(adventourer);
		return false;
	}
}

void SecondStage :: findKey(Character * adventourer) {
	int intel = adventourer->getIntelligence();
	int wisdom = adventourer->getWisdom();
	int agility = adventourer->getAgility();
	int strength = adventourer->getStrength();
	int charsima = adventourer->getCharisma();

	int mainFactor = intel + wisdom + agility +strength + charsima;
	srand(time(NULL));
	int chancetoChest = rand() % 100;
	int chancetoWardrobe = rand() % 100;
	mainFactor = 3 * mainFactor - 150;
	PlotRead * read = new Adapter();
	
	if (mainFactor < 1) {
		mainFactor = 1;
	}

	if (mainFactor > 100) {
		mainFactor == 100;
	}

	if (chancetoChest<=mainFactor) {
		this -> setChestKey(true);
		Sleep(1000);
		read->ReadFile("stage_two.txt", 4);

		if (chancetoWardrobe <= mainFactor) {
			this->setWardrobeKey(true);
			Sleep(1000);
			read->ReadFile("stage_two.txt", 5);
			Sleep(1000);

		}
		
	}
	if (chancetoChest > mainFactor) {
	}
}

bool SecondStage::chooseKey() {
	PlotRead * read = new Adapter();

	string decision;
	bool isCorrect = false;

	do {
		cout << endl;
		read->ReadFile("stage_two.txt", 8);
		cout << "1: Key with chest" << endl;
		cout << "2: Key without chset" << endl;
		cin >> decision;
		if (decision == "1") {
			return true;
			break;
		}

		if (decision == "2") {
			return false;
		}
		else {
			cout << "Incorrect decision, type again" << endl;
			isCorrect = false;
		}
	} while (!isCorrect);
}


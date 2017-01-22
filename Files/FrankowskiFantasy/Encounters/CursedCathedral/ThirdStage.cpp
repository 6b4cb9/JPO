#include "stdafx.h"
#include "ThirdStage.h"


ThirdStage::ThirdStage()
{
}


ThirdStage::~ThirdStage()
{
}

bool ThirdStage::proceed(Character * adventourer) {

	if (getWadrobe() == true) {
		PlotRead * read = new Adapter();
		system("cls");
		read->ReadFile("stage_three.txt", 0);
		bool noticed = notice(adventourer);

		if (noticed == true) {		 ///you have found wardrobe
			read->ReadFile("stage_three.txt", 1);
			bool decision = fightDecision();
			system("cls");
			if (decision == true) {
				int score = fight(adventourer);
				if (score == 1) {   //won
					read->ReadFile("stage_three.txt", 4);
					setBook(true);
					setChild(true);
					this->nextStage->status(this->getChild(), this->getBook());
					system("pause");
					this->nextStage->proceed(adventourer);
					return false;


				}
				if (score == 0) { //lost
					setBook(false);
					setChild(false);
					read->ReadFile("stage_three.txt", 3);
					this->nextStage->status(this->getChild(), this->getBook());
					system("pause");
					this->nextStage->proceed(adventourer);
					return false;

				}
			}
			if (decision == false) {
				setBook(true);
				setChild(false);
				this->nextStage->status(this->getChild(), this->getBook());
				system("pause");
				this->nextStage->proceed(adventourer);
				return false;
			}
		}
		else {						// you have not found wardrobe
			setBook(true);
			setChild(false);
			read->ReadFile("stage_three.txt", 2);
			this->nextStage->status(this->getChild(), this->getBook());
			system("pause");
			return false;
			this->nextStage->proceed(adventourer);
		}
	    
	}
	else {
		setChild(false);
		this->nextStage->status(this->getChild(), this->getBook());
		this->nextStage->proceed(adventourer);
		return false;
	}
}

bool ThirdStage::notice(Character * adventourer) {
	int intel = adventourer->getIntelligence();
	int wisdom = adventourer->getWisdom();
	int agility = adventourer->getAgility();
	int strength = adventourer->getStrength();
	int charsima = adventourer->getCharisma();

	int mainFactor = intel + wisdom + agility + strength + charsima;

	srand(time(NULL));
	int chancetoNotice = rand() % 100;
	mainFactor = 3* mainFactor - 150;

	if (mainFactor < 1) {
		mainFactor = 1;
	}

	if (mainFactor > 100) {
		mainFactor = 100;
	}

	if (chancetoNotice <= mainFactor) {
		return true;
	}
	if (chancetoNotice > mainFactor) {
		return false;
	}
}

int ThirdStage :: fight(Character * adventourer) {
	
	srand(time(NULL));
	int number = rand() % 100;
	int tempAgility = adventourer->getAgility();
	int tempIntell = adventourer->getIntelligence();
	int tempWisdom = adventourer->getWisdom();
	int tempStrength = adventourer->getStrength();
	int powerfactor = (tempAgility + tempIntell + tempStrength+tempWisdom);
	powerfactor = 7* powerfactor - 390;
	if (powerfactor <1) {
		powerfactor = 1;
	}
	if (powerfactor > 100) {
		powerfactor = 100;
	}

	if (number <= powerfactor) {
		return 1;																	//you won fight
	}
	if (number > powerfactor) {
		return 0;																	// you lost
	}

}

bool ThirdStage :: fightDecision() {

	PlotRead * read = new Adapter();
	string decision;
	bool isCorrect = false;

		do {
			cout <<endl<< "Would you like to fight" << endl;
			cout << "1: Yes" << endl;
			cout << "2: No" << endl;
			cin >> decision;
			if (decision == "1") {
				return true;
				break;
			}

			if (decision == "2") {
				return false;
				break;
			}
			else {
				cout << "Incorrect decision, type again" << endl;
				isCorrect = false;
			}
		} while (!isCorrect);
}



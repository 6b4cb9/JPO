#include "stdafx.h"
#include "FirstStage.h"


FirstStage::FirstStage(){
	this->lvl = 3;
	this->book = false;
	this->chestKey = false;
	this->wardrobeKey = false;
}


FirstStage::~FirstStage()
{
}

bool FirstStage::proceed(Character * adventourer){
	system("cls");
	PlotRead * read = new Adapter();

	for (int i = 0; i <= 1; i++) {
		read->ReadFile("stage_one.txt", i);
	}

	string decision;
	bool isCorrect = false;

	do{
		cout << endl <<"Choose one option" << endl;
		for (int i =2; i <= 3; i++) {
			cout << i - 1 << ": ";
			read->ReadFile("stage_one.txt", i);
		}

		cin >> decision;
		if (decision == "1") {
			this->nextStage->status(this->chestKey, this->wardrobeKey, this->book);
			this->nextStage->proceed(adventourer);
			break;
		}

		if (decision == "2") {
			cout << "you leaving cathedral " << endl;
			break;
		}
		else{
			cout << "Incorrect decision, type again" << endl;
			isCorrect = false;
		}
	} while (!isCorrect);	
	return false;
}

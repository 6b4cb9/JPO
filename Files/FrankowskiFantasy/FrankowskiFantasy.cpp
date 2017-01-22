// FrankowskiFantasy.cpp : Defines the entry point for the console application.
//

#pragma once
#include"stdafx.h"
#include <iostream>
#include "UserInterface.h"
#include"Character.h"
#include "Location.h"
#include "Map.h"
#include "Walk.h"
using namespace std;

int main() {
	system("mode 650");
	/*
	int in;
	Location* loc = new Location("Redania", "You're in Redania" ,"R");
	loc->AddEncounter(new FishStall());
	loc->AddEncounter(new BrokenTree());
	cout << "NEW GAME\n\n";
	cout << "Hero lvl?";
	in = UserInterface::getInstance()->getAns(3);
	cout << endl << endl;

	while (1) {
	loc->RunLocation(new Character(in));
	cout << "END GAME\n\n";
	system("PAUSE");
	}
	*/

	Character * hero = new Character(1);
	Walk * walk = new Walk();
	Map * mapa = Map::GetInstance();
	hero->SetCurrentLocation(mapa->GetMap(3, 7));
	while (1) {
		mapa->Show(hero);
		walk->MoveCharacter(hero);
		//system("PAUSE");
	}
	return 0;
}
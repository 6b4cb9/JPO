#include"stdafx.h"
#include "Location.h"

void Location::RunLocation(Character * hero) {
	gui->clearScreen();
	gui->write(description);
	currentEncounter = 0;
	exit = false;
	while (!exit) {
		finished[currentEncounter] = encounters[currentEncounter]->Proceed(hero);
		endLocation = testEndLocation();
		currentEncounter++;
		if (currentEncounter == 1) {
			ExitSafeEncounter(hero);
		}
		else if (currentEncounter == encounters.size()) {
			MissionSucceed(hero);
		}
		else {
			FinishEncounter(hero);
		}
	}
}

void Location::FinishEncounter(Character * hero) {
	int ans;
	gui->write(finish[rand() % 3]);
	gui->write(gosomwhere[rand() % 4]);
	gui->write("1)\tContinue the adventure!");
	gui->write("2)\tGo back!");
	ans = gui->getAns(2);
	if (ans == 2) {
		currentEncounter = 0;
		finished[0] = false;
	}
}

void Location::ExitSafeEncounter(Character* hero) {
	if (!endLocation) {
		int ans;
		gui->write(gosomwhere[rand() % 4]);
		gui->write("1)\tContinue the adventure!");
		gui->write("2)\tExit location");
		ans = gui->getAns(2);
		if (ans == 1) {
			finished[0] = false;
		}
		else {
			exit = true;
		}
	}
	else {
		exit = true;
	}
}

void Location::AddEncounter(Encounter * en) {
	encounters.push_back(en);
	finished.push_back(false);
}

bool Location::testEndLocation() {
	bool tmp = true;
	for (unsigned int i = 1; i < finished.size(); i++) {
		tmp &= finished[i];
	}
	return tmp;
}

void Location::MissionSucceed(Character* hero) {
	currentEncounter = 0;
	exit = true;
	for (int i = 0; i < 4; i++)
		permisions[i] = true;
	SetBorderPermission();
	gui->wait();
}

Location::Location()
{
	gui = UserInterface::getInstance();
	endLocation = false;
}

Location::Location(string name, string d, string sym) {
	Location();
	this->name = name;
	this->description = d;
	this->symbol = sym;
}

Location::~Location()
{
}

void Location::SetBorderPermission() {
	if (x == 0) {
		permisions[3] = false;
	}
	if (y == 0) {
		permisions[2] = false;
	}
	if (x == size_x - 1) {
		permisions[1] = false;
	}
	if (y == size_y - 1) {
		permisions[0] = false;
	}
}

string Location::show(int line) {
	line %= pic_y;
	return symbol.substr(line*pic_x, pic_x);
}

void Location::SetName(string name) {
	this->name = name;
}

void Location::SetDescritpion(string description) {
	this->description = description;
}

void Location::SetSybmol(string symbol) {
	this->symbol = symbol;
}

void Location::SetPermissions(bool * tab) {
	for (int i = 0; i < 4; i++) {
		this->permisions[i] = tab[i];
	}
}

void Location::SetPermissionTrue(int id) {
	permisions[id] = true;
}

void Location::SetX(int x) {
	this->x = x;
}

void Location::SetY(int y) {
	this->y = y;
}

string Location::GetDescription() {
	return description;
}

string Location::GetName() {
	return name;
}

string Location::GetSymbol() {
	return symbol;
}

bool * Location::GetPermissions() {
	return permisions;
}

int Location::GetX() {
	return x;
}

int Location::GetY() {
	return y;
}

int Location::GetPicY() {
	return pic_y;
}

int Location::GetPicX() {
	return pic_x;
}


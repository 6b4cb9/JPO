// level 1;
//  charisma at level 2 could help.
// Adventurer meet a merchant. You togheter solve quests.

#pragma once
#include "..\..\Encounter.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "..\..\UserInterface.h"
#include"stdafx.h"
using namespace std;

class BrokenTree :
	public Encounter
{
public:
	BrokenTree();
	~BrokenTree();
	bool  Proceed(Character* hero) override;
private:
	bool robbed, joined,passed,save,ignore,succed;
	int rescpet,salary;
	void chapter1(Character* hero);
	void chapter2(Character* hero);
	void chapter3(Character* hero);
	void FinishEncounter(Character* hero);
	UserInterface * gui;
	int treeDamage(Character* hero);
	void helpMerchant(Character* hero);
	void negotiation(Character * hero);
	void fight(Character *hero);
};


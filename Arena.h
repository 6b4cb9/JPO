#pragma once
#include "Character.h"
#include "Encounter.h"
#include "Monster.h"
#include "MonsterComposite.h"

class Arena : public Encounter{
private:


protected:
	string name;
	string description;
	int bonus;
	
public:
	
	MonsterComposite * monsters;

	Arena();
	~Arena();
	virtual bool Proceed(Character *) = 0;
	virtual int AtackBonus(Character*) = 0;
	void Fight(Character*);
	void SetName(string);
	string GetName();
	void SetDescription(string);
	string GetDescription();

	




};




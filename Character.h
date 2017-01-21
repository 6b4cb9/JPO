#pragma once
#ifndef _CHARACTER_
#define _CHARACTER_
class Character;
class EQ;
using namespace std;

#include <string>
#include "Item.h"
#include "Location.h"
#include "EQ.h"

class Character
{
public:
	Character();
	Character(int);
	~Character();
	int strength;
	int toughness;
	int agility;
	int intelligence;
	int wisdom;
	int charisma;
	int gold;
	int hp;
	int mana;
	string name;
	string profession;
	Item * armor;
	Item * rangedWeapon;
	Item * meleeWeapon;
	Location * currentLocation;
public:
	EQ *myEQ;
	virtual int MeleeAttack();
	virtual int RangedAttack();
	//Setters
	void SetArmor(Item *);
	void SetRangedWeapon(Item *);
	void SetMeleeWeapon(Item *);
	void SetCurrentLocation(Location *);
	void SetStrength(int IVariable);
	void SetToughness(int IVariable);
	void SetAgility(int IVariable);
	void SetIntelligence(int IVariable);
	void SetWisdom(int IVariable);
	void SetCharisma(int IVariable);
	void SetGold(int IVariable);
	void SetMana(int IVariable);
	void SetHP(int IVariable);

	//Getters
	Item * GetArmor();
	Item * GetRangedWeapon();
	Item * GetMeleeWeapon();
	Location * GetCurrentLocation();
	int GetStrength();
	int GetToughness();
	int GetAgility();
	int GetIntelligence();
	int GetWisdom();
	int GetCharisma();
	int GetGold();
	int GetHP();
	int GetMana();
	string GetName();
	string GetProfession();
};

#endif

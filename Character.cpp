#include "Character.h"

Character::Character(int lvl)
{
	if (lvl == 1) {
		strength=11;
		toughness=11;
		agility=11;
		intelligence=11;
		wisdom=9;
		charisma=11;
		gold=1000;
		hp=60;
		mana=60;
	}
	else if (lvl == 2) {
		strength = 14;
		toughness = 14;
		agility = 14;
		intelligence = 14;
		wisdom = 14;
		charisma = 14;
		gold = 1000;
		hp = 80;
		mana = 80;
	}
	else {
		strength = 18;
		toughness = 18;
		agility = 18;
		intelligence = 18;
		wisdom = 18;
		charisma = 18;
		gold = 1000;
		hp = 100;
		mana = 100;
	}
}

int Character::MeleeAttack() {
	return strength;
}

int Character::RangedAttack() {
	return agility;
}

Character::~Character()
{
}

//Setters
void Character::SetArmor(Item * arg) {
	this->armor = arg;
}
void Character::SetRangedWeapon(Item *arg) {
	this->rangedWeapon = arg;
}
void Character::SetMeleeWeapon(Item *arg) {
	this->meleeWeapon = arg;
}
void Character::SetCurrentLocation(Location *arg) {
	this->currentLocation = arg;
}
void Character::SetStrength(int IVariable)
{
	strength = IVariable;
	myEQ->SetCapacity(toughness , strength);
}
void Character::SetToughness(int IVariable)
{
	toughness = IVariable;
	myEQ->SetCapacity(toughness, strength);
}
void Character::SetAgility(int IVariable)
{
	agility = IVariable;
}
void Character::SetIntelligence(int IVariable)
{
	intelligence = IVariable;
}
void Character::SetWisdom(int IVariable)
{
	wisdom = IVariable;
}
void Character::SetCharisma(int IVariable)
{
	charisma = IVariable;
}
void Character::SetGold(int IVariable)
{
	gold = IVariable;
}
void Character::SetMana(int IVariable)
{
	mana = IVariable;
}
void Character::SetHP(int IVariable)
{
	hp = IVariable;
}

//Getters
Item *  Character::GetArmor() {
	return armor;
}
Item *  Character::GetRangedWeapon() {
	return rangedWeapon;
}
Item *  Character::GetMeleeWeapon() {
	return meleeWeapon;
}
Location *  Character::GetCurrentLocation() {
	return currentLocation;
}

int Character::GetStrength()
{
	return strength;
}
int Character::GetToughness()
{
	return toughness;
}
int Character::GetAgility()
{
	return agility;
}
int Character::GetIntelligence()
{
	return intelligence;
}
int Character::GetWisdom()
{
	return wisdom;
}
int Character::GetCharisma()
{
	return charisma;
}
int Character::GetGold()
{
	return gold;
}
int Character::GetHP()
{
	return hp;
}
int Character::GetMana()
{
	return mana;
}
string Character::GetName()
{
	return name;
}
string Character::GetProfession()
{
	return profession;
}

Character::Character(){}

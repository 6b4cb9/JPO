#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H
#pragma once
class MeleeWeapon;
#include "Item.h"
class MeleeWeapon : public Item
{
private:
	static Item* Example;
public:
	MeleeWeapon();
	~MeleeWeapon();
	static Item* NoMeleeWeapon();
	void Action(Character*);
	virtual void Wear(Character*);
	virtual void Unwear(Character*);
};

#endif
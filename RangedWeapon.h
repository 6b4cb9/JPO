#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H
#pragma once
class RangedWeapon;
#include "Item.h"
class RangedWeapon : public Item
{
private:
	static Item* Example;
public:
	RangedWeapon();
	~RangedWeapon();
	static Item* NoRangedWeapon();
	void Action(Character*);
	virtual void Wear(Character*);
	virtual void Unwear(Character*);
};

#endif
#ifndef ARMOR_H
#define ARMOR_H
#pragma once
class Armor;
#include "Item.h"
#include"stdafx.h"
class Armor : public Item
{
private:
	static Item* Example;
public:
	Armor();
	~Armor();
	static Item* NoArmor();
	void Action(Character*);
	virtual void Wear(Character*);
	virtual void Unwear(Character*);
};

#endif
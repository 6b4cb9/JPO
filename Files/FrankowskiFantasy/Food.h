#ifndef FOOD_H
#define FOOD_H
#pragma once
class Food;
#include"stdafx.h"
#include "Item.h"

class Food : public Item
{
public:
	Food();
	~Food();
	void Action(Character*);
	virtual void Use(Character*)=0;
};

#endif
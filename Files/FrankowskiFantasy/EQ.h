#ifndef EQ_H
#define EQ_H
#pragma once
class EQ;
class Item;
class Character;
#include"stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class EQ
{
private:
	double capacity;
	vector<Item*> content;
public:
	EQ();
	~EQ();
	void SetCapacity(int strength, int toughness);
	bool Add(Item* item);
	void Remove(int ind);
	void View();
	void VievWithDescriptions();
	void Use(int ind, Character* character);
	double SumWeights();
	void Refresh();
	Item* Get(int ind);
	int GetQuantity();
	double GetCapacity(void);
};
#include "Item.h"
#endif



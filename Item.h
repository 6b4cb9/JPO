#ifndef ITEM_H
#define ITEM_H
#pragma once
class Item;
class Character;
#include <string>
#include <iostream>
using namespace std;

class Item
{
private:
	int price;
	double weight;
	string name;
	string description;
protected:
	bool used;
	bool weared;
public:
	Item();
	~Item();
	virtual void Action(Character*) {}
	void SetPrice(int);
	int GetPrice();
	void SetWeight(double);
	double GetWeight();
	void SetName(string);
	string GetName();
	void SetDescription(string);
	string GetDescription();
	bool IsUsed();
	bool IsWeared();
};

#include "Character.h"
#endif
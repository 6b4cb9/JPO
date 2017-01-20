#ifndef EQ_H
#define EQ_H
#pragma once
class EQ;
class Item;
class Character;
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
	~EQ() {}
	void SetCapacity(int, int) {}
	bool Add(Item*) { return 0; }
	void Remove(int) {}
	void View() {}
	void VievWithDescriptions() {}
	void Use(int, Character*) {}
	double SumWeights() { return 0; }
	int GetQuantity() {
		return content.size();
	}
	double GetCapacity(void) { return capacity; }
	Item* GetItem(int i) {
		return content[i]; 
	}
};

#include "Item.h"
#endif
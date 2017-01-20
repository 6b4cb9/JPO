/*
Level: 2
Recommended location: forest
Ready to use: true
Priority: high
Needs classes: SkoliodoiAbstract, SkoliodoiMercenary, SkoliodoiDoulos, SkoliodoiAristocrat
*/
#ifndef SKOLIODOI_H
#define SKOLIODOI_H
#pragma once
class Skoliodoi;
#include <string>
#include <iostream>
#include "Encounter.h"
using namespace std;

class Skoliodoi : public Encounter
{
public:
	Skoliodoi();
	~Skoliodoi();
	void Describe(Character * Hero);
	virtual bool Proceed(Character * Adventurer);
};

#endif

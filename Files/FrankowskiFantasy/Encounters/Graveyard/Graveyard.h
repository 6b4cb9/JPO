#pragma once
//difficulty 1
//priority 2
//cymbalista maciek
#include"stdafx.h"
#include "..\..\Encounter.h"
class Graveyard :
	public Encounter
{
public:
	Graveyard();
	~Graveyard();
	bool Proceed(Character* Adventurer);
	void PlaceDescriber(Character * Adventurer);
	void FirstAction(Character* Adventurer);
	void SecondAction(Character* Adventurer);
	void ThirdAction(Character* Adventurer);
};


#pragma once
#ifndef _WALK_
#define _WALK_

class Walk;
#include"stdafx.h"
#include"Character.h"

class Walk
{
public:
	Walk() {}
	~Walk() {}
	void MoveCharacter(Character*);
	std::string Permission(bool); //convert bool into string- says if can go into this location or not
	std::string EndMap(Character* character, int a, int b);
	std::string Neighbourhood(int, int) {} //return all information about naighbourhood location
	std::string CompassRose(int line);					   //void Escape(Character*);
};

#endif

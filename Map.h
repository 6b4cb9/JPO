#pragma once
#ifndef _MAP_
#define _MAP_

class Location;
class Map;
#include "Character.h"
#include "Location.h"
#include <iostream>
#include "UserInterface.h"
#include "Forest.h"
#include "Meadow.h"
#include "Mountain.h"
#include <math.h>
#include "GhastlyHeath.h"
#include "TestLocation.h"
#include "Route.h"
#include "Dungeons.h"
#include "Tower.h"
#include "Camp.h"
//class Location;
using namespace std;
class Map
{
private:
	std::string CompassRose(int);
	static const int size_x = 10;
	static const int size_y = 10;
	Location* CurrentLocation;
	Location * MapT[size_x][size_y];
	static Map* Instance;

public:
	void AddLocation(Location *, int x, int y);
	void Create();
	void Show(Character* h);
	int GetSizeX();
	int GetSizeY();
	Location* GetMap(int x, int y);
	static Map* GetInstance();
	~Map();
private:
	string showHero(int);
	Map();
};

#endif


#pragma once

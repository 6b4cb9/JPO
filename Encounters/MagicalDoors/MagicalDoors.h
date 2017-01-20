#pragma once

#include "..\..\Encounter.h"
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <ctime>

class MagicalDoors :
	public Encounter
{
public:
	MagicalDoors();
	~MagicalDoors();
	bool Proceed(Character*);
};

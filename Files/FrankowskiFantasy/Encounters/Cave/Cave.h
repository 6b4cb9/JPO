/*						Cave
	Desription :	Encounter with Goblin, travel on Dreisine;
	Place:			Mounatains
	Level :			1
	Priority:		3
	Magdalena Rybicka
	Potrzebne jest za³¹czenie biblioteki stdafx.h i oczywiœcie pliki z funkcjami tej klsy
*/
#pragma once
#pragma once
#include"stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <time.h>
#include <Windows.h>
#include "..\..\Character.h"
#include "..\..\Encounter.h"

using namespace std;
class Cave : public Encounter {
private:
	Character* Adventurer;
	bool Dreisine(void);
	bool Goblin(void);
public:
	bool Proceed(Character* t_Adventurer);
};

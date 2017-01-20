/*			Desert
	Desription: 	Crossroad, encounter with Creepy Ghost or Gunslinger;
	Place:			Road
	Level: 			3
	Priority:		3	
	Magdalena Rybicka
	Potrzebne jest za³¹czenie biblioteki stdafx.h i oczywiœcie pliki z funkcjami tej klasy
*/

#pragma once
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
class Desert : public Encounter {
private:
	Character* Adventurer;
	bool East(void);
	bool West(void);
	bool Companion(void);
	bool NoCompanion(void);
	bool Attack(void);
	bool Negotiation(void);

public:
	bool Proceed(Character* t_Adventurer);
}; 
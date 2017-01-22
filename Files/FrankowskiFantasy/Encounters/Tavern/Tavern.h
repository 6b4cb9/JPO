#include"..\..\stdafx.h"
#include <iostream>
#include "..\..\Character.h"
#include "..\..\Encounter.h"


using namespace std;

class Tavern :public Encounter
{
	char choice1;
	char choice2;
	char answer1;
	char answer2;

public:
	virtual bool Proceed(Character * Adventurer);
};
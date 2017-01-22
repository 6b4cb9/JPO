#include"stdafx.h"
#include <iostream>
#include "..\..\Character.h"
#include"..\..\Encounter.h"

using namespace std;


class Farm :public Encounter
{
	char choice;

public:
	virtual bool Proceed(Character * Adventurer);
};

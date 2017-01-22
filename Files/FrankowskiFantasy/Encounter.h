#pragma once
#ifndef _ENCOUNTER_
#define _ENCOUNTER_

class Encounter; 
#include"stdafx.h"
#include "Character.h"
class Encounter
{
public:
	Encounter();
	~Encounter();
	virtual bool Proceed( Character *) = 0;
};

#endif


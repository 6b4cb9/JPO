#pragma once
#ifndef _SAFEENCOUNTER_
#define _SAFEENCOUNTER_

class SafeEncounter; 

#include "Encounter.h"
#include "EQ.h"
#include"Character.h"
class SafeEncounter :
	public Encounter
{
public:
	SafeEncounter() {}
	~SafeEncounter() {}
	//virtual bool Proceed(Character *) = 0;
	void Trade(Character*);
	void Rest(Character*);
	EQ shop;
};

#endif

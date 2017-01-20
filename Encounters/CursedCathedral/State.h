#pragma once
#include "Character.h"

class State
{
public:

	virtual void execute(Character * character) = 0;

};


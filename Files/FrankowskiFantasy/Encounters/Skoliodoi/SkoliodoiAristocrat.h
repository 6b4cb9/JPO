/*
Part of encounter Skoliodoi
*/
#ifndef SKOLIODOIARISTOCRAT_H
#define SKOLIODOIARISTOCRAT_H
#pragma once
class SkoliodoiAristocrat;
#include "SkoliodoiAbstract.h"

class SkoliodoiAristocrat : public SkoliodoiAbstract
{
public:
	void FirstDay(Character*);
	void SecondDay(Character*);
	SkoliodoiAristocrat();
	~SkoliodoiAristocrat();
};

#endif

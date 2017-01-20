/*
Part of encounter Skoliodoi
*/
#ifndef SKOLIODOIMERCENARY_H
#define SKOLIODOIMERCENARY_H
#pragma once
class SkoliodoiMercenary;
#include "SkoliodoiAbstract.h"

class SkoliodoiMercenary : public SkoliodoiAbstract
{
public:
	void FirstDay(Character*);
	void SecondDay(Character*);
	SkoliodoiMercenary();
	~SkoliodoiMercenary();
};

#endif

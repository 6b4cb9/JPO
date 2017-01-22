/*
Part of encounter Skoliodoi
*/
#ifndef SKOLIODOIDOULOS_H
#define SKOLIODOIDOULOS_H
#pragma once
class SkoliodoiDoulos;
#include "SkoliodoiAbstract.h"

class SkoliodoiDoulos : public SkoliodoiAbstract
{
public:
	void FirstDay(Character*);
	void SecondDay(Character*);
	SkoliodoiDoulos();
	~SkoliodoiDoulos();
};

#endif

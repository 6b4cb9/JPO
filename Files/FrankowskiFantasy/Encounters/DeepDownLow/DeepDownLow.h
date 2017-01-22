#pragma once
#include"stdafx.h"
#include "..\..\Character.h"
#include "..\..\Encounter.h"

class DeepDownLow: public Encounter
{
public:
	DeepDownLow();
	~DeepDownLow();
	bool Proceed(Character* hh);
};


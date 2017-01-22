#pragma once
#include"stdafx.h"
#include "Location.h"
#include "Character.h"
#include "EmptyLocation.h"
class Forest :
	public EmptyLocation
{
public:
	Forest(int);
	~Forest();
	//void RunLocation(Character *) override;
};


#pragma once
#include"stdafx.h"
#include "Location.h"
class EmptyLocation :
	public Location
{
public:
	EmptyLocation(std::string name, std::string description, std::string symbol);
	~EmptyLocation();
	void RunLocation(Character *) override;
};


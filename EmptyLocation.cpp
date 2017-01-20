#include "EmptyLocation.h"



EmptyLocation::EmptyLocation(std::string name, std::string description, std::string symbol) : Location(name, description, symbol)
{
	bool tab[4] = { true, true, true, true };
	SetPermissions(tab);
}


EmptyLocation::~EmptyLocation()
{
}

void EmptyLocation::RunLocation(Character* h) {}
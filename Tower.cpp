
#include "Tower.h"


Tower::Tower() : Location("Never Ending Tower", "I can spot increadibly high building which top touches sky", "  VVV     |_|     |_|     |_|   ")
{
	this->AddEncounter(new Neverending_Tower_Hard());
}


Tower::~Tower()
{
}

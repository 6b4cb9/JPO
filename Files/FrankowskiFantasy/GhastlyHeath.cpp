#pragma once
#include"stdafx.h"
#include "GhastlyHeath.h"


GhastlyHeath::GhastlyHeath() : Location("Ghastly Heath", "A long time ago it was a beautiful place full of colourfull flowers. Now it is a little bit scary here, and flowers are unnaturally bloody red.", "          ( \")    /  \\    \"\"\"\"          ")
{
	this->AddEncounter(new MagicalDoors());
}


GhastlyHeath::~GhastlyHeath()
{
}

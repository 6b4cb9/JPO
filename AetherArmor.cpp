#include "AetherArmor.h"


AetherArmor::AetherArmor()
{
}


AetherArmor::~AetherArmor()
{
}

void AetherArmor::Wear(Character* Hero)
{
	Hero->SetToughness(Hero->GetToughness() + 7);
	Hero->SetStrength(Hero->GetStrength() + 3);
	Hero->SetAgility(Hero->GetAgility() + 5);
}

void AetherArmor::Unwear(Character* Hero)
{
	Hero->SetToughness(Hero->GetToughness() - 7);
	Hero->SetStrength(Hero->GetStrength() - 3);
	Hero->SetAgility(Hero->GetAgility() - 5);
}
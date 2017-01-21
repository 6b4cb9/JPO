#include "AetherArmorFactory.h"


AetherArmorFactory::AetherArmorFactory()
{
}


AetherArmorFactory::~AetherArmorFactory()
{
}

Item* AetherArmorFactory::CreateItem()
{
	Item* example = new AetherArmor;
	example->SetName("Aether Armor");
	example->SetDescription("Aether Armor increases toughness by 7, strength by 5 and agility by 3");
	example->SetPrice(500);
	example->SetWeight(50);
	return example;
}
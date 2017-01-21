#ifndef AETHERARMOR_H
#define AETHERARMOR_H
#pragma once
class AetherArmor;
#include "Armor.h"

class AetherArmor : public Armor
{
public:
	AetherArmor();
	~AetherArmor();
	void Wear(Character*);
	void Unwear(Character*);
};

#endif
#include"stdafx.h"
#include "MeleeWeapon.h"


MeleeWeapon::MeleeWeapon()
{
}


MeleeWeapon::~MeleeWeapon()
{
}

Item* MeleeWeapon::Example = NULL;

Item* MeleeWeapon::NoMeleeWeapon()
{
	if (Example == NULL)
	{
		Example = new MeleeWeapon;
		Example->SetDescription("No melee weapon");
		Example->SetName("No melee weapon");
		Example->SetPrice(0);
		Example->SetWeight(0);
	}
	return Example;
}


void MeleeWeapon::Wear(Character*) {}
void MeleeWeapon::Unwear(Character*) {}

void MeleeWeapon::Action(Character* Hero)
{
	if (this->weared)
	{
		this->weared = false;
		this->Unwear(Hero);
		Hero->SetMeleeWeapon(NoMeleeWeapon());
	}
	else
	{
		this->weared = true;
		Hero->GetMeleeWeapon()->Action(Hero); //couses unwearing becouse weared == true
		Hero->SetMeleeWeapon(this);
		this->Wear(Hero);
	}
}
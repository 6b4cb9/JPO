#include "RangedWeapon.h"


RangedWeapon::RangedWeapon()
{
}


RangedWeapon::~RangedWeapon()
{
}


Item* RangedWeapon::Example = NULL;

Item* RangedWeapon::NoRangedWeapon()
{
	if (Example == NULL)
	{
		Example = new RangedWeapon;
		Example->SetDescription("No ranged weapon");
		Example->SetName("No ranged weapon");
		Example->SetPrice(0);
		Example->SetWeight(0);
	}
	return Example;
}


void RangedWeapon::Wear(Character*) {}
void RangedWeapon::Unwear(Character*) {}

void RangedWeapon::Action(Character* Hero)
{
	if (this->weared)
	{
		this->weared = false;
		this->Unwear(Hero);
		Hero->SetRangedWeapon(NoRangedWeapon());
	}
	else
	{
		this->weared = true;
		Hero->GetRangedWeapon()->Action(Hero); //couses unwearing becouse weared == true
		Hero->SetRangedWeapon(this);
		this->Wear(Hero);
	}
}
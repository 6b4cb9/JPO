#include"stdafx.h"
#include "Armor.h"



Armor::Armor()
{
}


Armor::~Armor()
{
}

Item* Armor::Example = NULL;

Item* Armor::NoArmor()
{
	if (Example == NULL)
	{
		Example = new Armor;
		Example->SetDescription("No armor");
		Example->SetName("No armor");
		Example->SetPrice(0);
		Example->SetWeight(0);
	}
	return Example;
}


void Armor::Wear(Character*){}
void Armor::Unwear(Character*){}

void Armor::Action(Character* Hero)
{
	if (this->weared)
	{
		this->weared = false;
		this->Unwear(Hero);
		Hero->SetArmor(NoArmor());
	}
	else
	{
		this->weared = true;
		Hero->GetArmor()->Action(Hero); //couses unwearing becouse weared == true
		Hero->SetArmor(this);
		this->Wear(Hero);
	}
}
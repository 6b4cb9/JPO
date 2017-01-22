#pragma once
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "Element.h"

//Joanna Kawa³ko
//level 1
//gameplay 3
//use in location: town 

class MorbusEpidemic: public Element
{
public:
	MorbusEpidemic();
	~MorbusEpidemic();

	bool Proceed(Character* Adventurer);

	void EpidemicDescription();
	void ChanceDescription();
	void BuyingDescription();
	void DiseaseDescription();
	void DruidHelpDescription();
	void WaitingDescription();

	string SaveAChoice();
	void Death();

	void BuyingMedicine(Character*);
	void Waiting(Character*);
};


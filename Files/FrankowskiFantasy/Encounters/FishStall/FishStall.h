//level 1
// need inteligance and wisdom on level 2
// find out a secret of one merchant.

#pragma once
#include"..\..\stdafx.h"
#include "..\..\Encounter.h"
#include"..\..\UserInterface.h"
#include <time.h>
class FishStall :
	public Encounter
{
public:
	FishStall();
	~FishStall();
	bool  Proceed(Character* hero) override;
private:
	bool coin, hint1, hint2,blackmail,succed;
	UserInterface * gui;
	void Niuthe(Character * hero);
	void Ikkitha(Character * hero);
	void Berbelek(Character * hero);
	int speach();
	static time_t lastVisit;
	int const lag = 60;
}; 


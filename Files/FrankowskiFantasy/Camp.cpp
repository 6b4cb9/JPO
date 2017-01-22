#include"stdafx.h"
#include "Camp.h"


Camp::Camp() : Location("Camp", "A huge campground ahead of you! Finally some people on your way", " '-,     __I__, /___/  \\|___|[]|")
{
//	this->AddEncounter(new RedricInn());
	this->AddEncounter(new Tavern());
	this->AddEncounter(new FishStall());
}


Camp::~Camp()
{
}

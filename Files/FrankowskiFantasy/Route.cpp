#include"stdafx.h"
#include "Route.h"


Route::Route() : Location("Route", "A beautiful, vivid path going thru the forrest", " '-,     __I__, /___/  \\|___|[]|")
{
	this->AddEncounter(new Farm());
	this->AddEncounter(new MeetingSage());
	this->AddEncounter(new BrokenTree());
	this->AddEncounter(new ChallengingTower());
	this->AddEncounter(new Owl());
}


Route::~Route()
{
}

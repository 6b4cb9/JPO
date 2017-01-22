#include"stdafx.h"
#include "TestLocation.h"



TestLocation::TestLocation() : Location("Redania", "You're in Redania", " R ")
{
	
	this->AddEncounter(new FishStall());
//	this->AddEncounter(new BrokenTree());

}


TestLocation::~TestLocation()
{
}

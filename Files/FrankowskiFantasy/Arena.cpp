#include"stdafx.h"
#include "Arena.h"


Arena::Arena()
{
}


Arena::~Arena()
{
}


void Arena::Fight(Character * character){
	this->monsters->Fight(character);
}

void Arena::SetName(string name){
	this->name = name;
}

string Arena::GetName()
{
	return this->name;
}

void Arena::SetDescription(string description ){

	this->description = description;
}

string Arena::GetDescription()
{
	return this->description;
}



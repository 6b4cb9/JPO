#include"stdafx.h"
#include "Monster.h"

std::string  Monster::GetDescription() {
	return this->description;
}

void Monster::SetDescription(std::string outlook) {
	this->description = outlook;
}


Monster::Monster()
{
}


Monster::~Monster()
{
}

#include"stdafx.h"
#include "Food.h"


Food::Food()
{
}


Food::~Food()
{
}

void Food::Action(Character* Hero)
{
	used = true;
	Use(Hero);
}
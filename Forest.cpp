#include "Forest.h"

//void Forest::RunLocation(Character* h){}

Forest::Forest(int num) : EmptyLocation("forest", "You are in forest, a forest full of tree.", "/\\  /\\  / \\ / \\ / \\ / \\  |   |  ")
{
	if (num % 2)
		this->SetSybmol(" /\\  /\\  / \\ / \\ / \\ / \\  |   | ");
}


Forest::~Forest()
{
}

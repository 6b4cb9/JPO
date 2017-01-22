// Difficulty level 2
// Krystian Bytnar
// It is suitable to game : scale 2.66 cos Nothing is perfect
// Requirements: minimal strength = 14
// Place : Unerground
// Proceed function use functions declared and definded in UndergroundRescue.cpp
#pragma once
#include "Element.h"
#include "Character.h"

class UndergroundRescue : public Element
{
public:
	bool Proceed(Character *Adventurer);
};
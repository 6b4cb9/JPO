#pragma once
#include "Location.h"
#include "Character.h"
#include "Encounters\ImprisonmentDungeons\ImprisonmentDungeons.h"
#include "Encounters\Maze\Maze.h"
#include "Encounters\Cave\Cave.h"
#include "Encounters\Desert\Desert.h"

class Dungeons :
	public Location
{
public:
	Dungeons();
	~Dungeons();
};


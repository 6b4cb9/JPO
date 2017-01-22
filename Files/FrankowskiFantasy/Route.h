#pragma once
#include"stdafx.h"
#include "Location.h"
#include "Character.h"
#include "Encounters\BrokenTree\BrokenTree.h"
#include "Encounters\ChallengingTower\ChallengingTower.h"
#include "Encounters\Owl\Owl.h"
#include "Encounters\MeetingSage\MeetingSage.h"
#include "Encounters\Farm\Farm.h"

class Route :
	public Location
{
public:
	Route();
	~Route();
};


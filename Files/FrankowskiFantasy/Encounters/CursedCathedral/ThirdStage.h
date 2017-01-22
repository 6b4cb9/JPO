#pragma once
#include "PlotRead.h"
#include <cstdlib>
#include <ctime>
#include "Adapter.h"
#include "Stage.h"
#include <cstdlib>
#include <ctime>

class ThirdStage :public Stage
{
public:
	ThirdStage();
	~ThirdStage();
	bool proceed(Character * adventourer);
	bool notice(Character * adventourer);
	int fight(Character * adventourer);
	bool fightDecision();
};


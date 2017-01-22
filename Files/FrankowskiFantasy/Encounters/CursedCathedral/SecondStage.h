#pragma once
#include "Stage.h"
#include "PlotRead.h"
#include "Adapter.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "FourthStage.h"
#include "ThirdStage.h"

class SecondStage :public Stage
{
public:
	SecondStage();
	~SecondStage();
	bool proceed(Character * adventourer);
	void findKey(Character * adventourer);
	bool chooseKey();
};


#pragma once
#include "Stage.h"
#include "PlotRead.h"
#include "Adapter.h"
#include "SecondStage.h"
class FirstStage : public Stage{
public:
	FirstStage();
	~FirstStage();
	bool proceed(Character * adventourer);


};


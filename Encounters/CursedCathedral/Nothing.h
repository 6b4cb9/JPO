#pragma once
#include "State.h"
#include "PlotRead.h"
#include "Adapter.h"

class Nothing : public State{

public:
	Nothing();
	~Nothing();
	void execute(Character * character);
};


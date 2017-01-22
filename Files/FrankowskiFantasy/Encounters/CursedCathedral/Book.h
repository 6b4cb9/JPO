#pragma once
#include "State.h"
#include "PlotRead.h"
#include "Adapter.h"

class Book : public State{

public:
	Book();
	~Book();
	void execute(Character * character);
};


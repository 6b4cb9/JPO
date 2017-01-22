#pragma once
#include"State.h"
#include "PlotRead.h"
#include "Adapter.h"
#include <cstdlib>
#include <ctime>
#include "Character.h"

class BookAndBoy :public State {
public:

	BookAndBoy();
	~BookAndBoy();
	virtual void execute(Character * character) ;

	int curing(Character * adventourer);
	
};

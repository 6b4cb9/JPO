#pragma once
#include "PlotRead.h"
#include "Adapter.h"
#include "Stage.h"
#include "State.h"
#include "Book.h"
#include "BookAndBoy.h"
#include "Nothing.h"


class FourthStage: public Stage{
	
	State * state;

public:
	FourthStage();
	~FourthStage();
	bool proceed(Character * adventourer);
	void setBook();
	void setBookAndBoy();
	void setNothing();
};


#pragma once
#include "PlotRead.h"
#include "Read.h"
class Adapter :public PlotRead{
	Read * read;
public:
	void ReadFile(string sourceFile, int lineNumber);
	Adapter();
	~Adapter();
};


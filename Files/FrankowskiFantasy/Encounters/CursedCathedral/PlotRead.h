#pragma once
#include <string>

using namespace std;
class PlotRead
{
public:
	virtual void ReadFile(string sourceFile, int lineNumber)=0;

};


#include "stdafx.h"
#include "Adapter.h"



Adapter::Adapter()
{
	this->read = new Read();
}


Adapter::~Adapter()
{
}

void Adapter::ReadFile(string sourceFile, int lineNumber){
	string line = this->read->ReadFile(sourceFile, lineNumber);
	cout << line << endl;
}




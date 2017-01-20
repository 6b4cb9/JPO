#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Read{
public:
	Read();
	string ReadFile(string sourceFile, int lineNumber);

};


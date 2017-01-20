#include "stdafx.h"
#include "Read.h"

Read::Read() {
}

string Read::ReadFile(string sourceFile, int lineNumber) {

	ifstream file;
	file.open(sourceFile);
	string line;
	if (file.good()) {
		for (int i = 0; i <= lineNumber; i++) {
			getline(file, line);
			if (i == lineNumber) {
				return line;
			}
		}
	}
	else {
		cout << "Nie mozna odczytac pliku" << endl;
	}
}


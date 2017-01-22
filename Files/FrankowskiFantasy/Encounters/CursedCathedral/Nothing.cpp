#include "stdafx.h"
#include "Nothing.h"


Nothing::Nothing()
{
}


Nothing::~Nothing()
{
}

void Nothing::execute(Character * character) {
	PlotRead * read = new Adapter();
	read->ReadFile("stage_four.txt", 6);
	cout << endl << endl << "Intelligence and agility have not  changed " << endl;

}
#include "stdafx.h"
#include "Book.h"


Book::Book()
{
}


Book::~Book()
{
}

void Book::execute(Character * character){
	PlotRead * read = new Adapter();
	read->ReadFile("stage_four.txt", 0);
	cout << endl << endl << "Intelligence and agility  are incresed by 1 " << endl;
	character->setIntelligence(character->getIntelligence() + 1);
	character->setAgility(character->getAgility() + 1);
}

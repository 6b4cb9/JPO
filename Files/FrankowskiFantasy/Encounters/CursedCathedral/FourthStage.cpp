#include "stdafx.h"
#include "FourthStage.h"


FourthStage::FourthStage()
{
}


FourthStage::~FourthStage()
{
}

bool FourthStage::proceed(Character * adventourer){
	bool book = getBook();
	bool bookChild=getChild();
	
	system("cls");

	if (book == true & child == true) {
		setBookAndBoy();
		this->state->execute(adventourer);
		setFinishingstatus(true);
		return true;

	}

	if (book == true & child == false) {
		setBook();
		this->state->execute(adventourer);
		setFinishingstatus(true);
		return true;
	}
	if (book == false & child == false) {
		setNothing();
		this->state->execute(adventourer);
		setFinishingstatus(false);
		return false;
	}
}


void FourthStage::setBook(){
	delete this->state;
	this->state = new Book();
}

void FourthStage::setBookAndBoy(){
	delete this->state;
	this->state = new BookAndBoy();

}

void FourthStage::setNothing(){
	delete this->state;
	this->state = new Nothing();

}





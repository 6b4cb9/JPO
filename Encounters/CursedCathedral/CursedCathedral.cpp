#include "stdafx.h"
#include "CursedCathedral.h"


CursedCathedral::CursedCathedral()
{
}


CursedCathedral::~CursedCathedral()
{
}

bool CursedCathedral::Proceed(Character * adventourer){
	Stage* first = new FirstStage();
	Stage* second = new SecondStage();
	Stage* third = new ThirdStage();
	Stage* fourth = new FourthStage();
	first->setNextStage(second);
	second->setNextStage(third);
	third->setNextStage(fourth);
	first->proceed(adventourer);
	bool status =  fourth->getFinishingstatus();
	cout << "pizda " << status << endl;
	return status;

}

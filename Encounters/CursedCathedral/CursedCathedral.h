#pragma once
#include "../../Encounter.h"
#include "../../Character.h"
#include "FirstStage.h"
#include "SecondStage.h"

class CursedCathedral :public Encounter{

	/*
		Morawiec Micha³, jest to nawiedzona katedra, pasuje w mojej opini albo do wioski albo na trakt. LVL trudnosci - 3. Wsztstkie pliki zawarte w folderze CursedCathedral sa potrzebne
	*/

public:
	CursedCathedral();
	~CursedCathedral();
	bool Proceed(Character* adventourer);
};


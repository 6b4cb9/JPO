/*
Part of encounter Skoliodoi
*/
#ifndef SKOLIODOIABSTRACT_H
#define SKOLIODOIABSTRACT_H
#pragma once
class SkoliodoiAbstract;
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <string>
#include "Character.h"
using namespace std;

class SkoliodoiAbstract
{
public:
	virtual void FirstDay(Character*)=0;
	virtual void SecondDay(Character*)=0;
	void End(Character*);
	void Wait(int);
	int Read(int);
	SkoliodoiAbstract();
	~SkoliodoiAbstract();
};

#endif

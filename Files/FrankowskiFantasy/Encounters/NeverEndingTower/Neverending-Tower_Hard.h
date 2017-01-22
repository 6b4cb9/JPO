#pragma once

//Author: Kamil Janowski
// Difficulty: 3
// Priority : 3
#include"stdafx.h"
#include "..\..\Character.h"
#include "..\..\Encounter.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <cstdlib> 
#include <chrono>


class Neverending_Tower_Hard : public Encounter
{
private:
	void Read_Note(string Name_Of_File);
	bool First_Floor(Character* Character);
	bool Second_Floor(Character* Character);
	bool Third_Floor(Character* Character);
	bool Fourth_Floor(Character* Character);
	bool Fifth_Floor(Character* Character);
	bool Sixth_Floor(Character* Character);
	bool Seventh_Floor(Character* Character);
public:
	bool Proceed(Character* Character);
};

#pragma once
// Difficulty level 2
// Pawel Kozlowski
// It is suitable to game : scale 1
// Requirements: hp > 0
// Place : House
// Proceed function use functions declared and definded in SkillsTest.cpp
#include<fstream>
#include<string>
#include"Element.h"
#include <ctime>
class SkillsTest:public Element
{
public:
	SkillsTest();
	~SkillsTest();

	bool Proceed(Character* );
	int breakPassword(Character*);
	int livingRoom(Character*);
	void SecondChoice(Character*);
	void Meeting(Character*);
	void FindDocument(Character*);
};


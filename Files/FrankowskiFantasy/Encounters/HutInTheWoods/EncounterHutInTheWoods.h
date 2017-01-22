#pragma once
#include "Element.h"
#include "Character.h"

#include <string>
#include <iostream>
#include <sstream>

/*
	--- OPIS ---
	Miejsce zdarzenia - las.
	Treœæ zdarzenia - postaæ natrafia na opuszczon¹ hatê. 
	Trudnoœæ - 2.
	U¿ytecznoœæ - 2/3
*/

class EncounterHutInTheWoods :
	public Element
{
public:
	EncounterHutInTheWoods();
	~EncounterHutInTheWoods();

	const int difficulty = 2;
	const std::string locName = "Hut in the woods";

	virtual bool run();
	virtual bool proceed(Character* chPtr) { ch = chPtr; return run(); }

private:
	Character* ch;

	int choice_1();
	int choice_2();
	int choice_3();

	void wait_for_input();
	void print_msg(std::string msg, bool skipSleep = false);
	void print_choice(int num, std::string msg);
	int get_choice(int maxChoiceNum);

	const int RCODE_EXIT = 0x00;
	const int RCODE_CONTINUE = 0x01;

	const int MSG_DELAY_MS = 750;
};


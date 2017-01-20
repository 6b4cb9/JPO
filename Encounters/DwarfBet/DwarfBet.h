/*Damian Smela

Skala trudnoœci - wrêcz 0
Skala priorytetu - 2


u¿ywa wszystkich klas w encounter_1.h
definicje s¹ w encounter_1.cpp
*/



#include <iostream>
#include <stdlib.h>
#include "stdio.h"
#include <cstdlib>
#include <ctime>
#include "Zaslepka.h"

using namespace std;



class DwarfBetDialogs
{
private:
	static int bet_temp;
public:
	static int EncounterIntro(Character *Adventurer);
	static int EncounterBetRules(Character *Adventurer);
	static void EncounterFight(Character* Adventurer);
	static void FirstThrow();
	static void SecondThrow();
	static void ThirdThrow();
};

class DwarfBetEncounter :public Encounter
{
public:
	bool Proceed(Character * Adventurer);
	void FinishEncounter(Character * Adventurer) {} 
};

class DwarfDiceGame
{
private:
	int bet;
	int winner;
public:
	void SetBet(int b);
	void Play();
	void Results(Character *Adventurer);
};
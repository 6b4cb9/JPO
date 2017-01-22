#pragma once

/*
	Pawe³ Jacalski, czw. 12:50
	difficulty: 1
	priority: 1

	location: woods
	
	requires: #include <ctime>,	in main loop: srand(time(null))
	
	comment: all command line inputs are protected from invalid input
	no exceptions should be raised during execution of the code
*/

#include "Element.h"
#include <iostream>
class ElementTicTacToe :
	public Element
{
	int gameInstance(int intelligence);
	void printBoard(char (&board)[3][3]);
	void checkBoard(char (&board)[3][3], bool &playGame, int &GAMEENDFLAG);
	int verifyMove(int move, char (&board)[3][3], bool &playGame, int &GAMEENDFLAG, int &currentPlayer);
public:
	ElementTicTacToe();
	~ElementTicTacToe();
	bool Proceed(Character * Adventurer);
};


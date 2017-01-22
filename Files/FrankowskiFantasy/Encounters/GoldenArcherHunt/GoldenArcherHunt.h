#pragma once
#include"Element.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cmath>
#include<conio.h>
#include<limits>
class GoldenArcherHunt : public Element {
private:
	int board[15][15];
	int maxMove;
	int playerPositionX;
	int playerPositionY;
	int goldenArcherPositionX;
	int goldenArcherPositionY;
public:
	GoldenArcherHunt();
	void Proceed(Character * Adventurer);
	void GenerateBoard();
	void DisplayBoard();
	int MovePlayer(Character * Player);
	void DisplayMenu();
	int MoveGoldenArcher(int direction, int length);
	void DestroyWall();
	int CPUMove(Character * Player);

};
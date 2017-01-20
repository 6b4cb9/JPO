#pragma once
#include "..\..\Encounter.h"
#include"..\..\Character.h"

//skala trudnoœci: 2
//skala nadawania: 2
//Tomasz Spyrka

class Maze :
	public Encounter
{
public:
	Maze();
	~Maze();

	bool Proceed(Character* adventurer);

private:
	void loadMaze();
	void drawMaze();
	void placeAdventurer(int x, int y);
	char getSymbol(int x, int y);
	void deleteAdventurer();
	bool checkMove(int x, int y);
	void adventurerMove();
	void reward();
	void qte();

	std::string mazeLines[25];
	int adventurerX;
	int adventurerY;
	bool solved;
	long int time;
	Character* character;
};


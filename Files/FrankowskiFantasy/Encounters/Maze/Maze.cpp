#include"stdafx.h"
#include "Maze.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <ctime>


Maze::Maze()
{
	
}


Maze::~Maze()
{
}

bool Maze::Proceed(Character * adventurer)
{
	time = 0;
	solved = false;
	adventurerX = 1;
	adventurerY = 1;
	system("cls");
	std::cout << "You entered the maze!" << std::endl;
	std::cout << "You (A) must find exit (E) to obtain reward!" << std::endl;
	std::cout << "W - up, S - down, A - left, D - right" << std::endl;
	std::cout << "AVOID ROCKS!" << std::endl;
	std::cout << "Press space to start!" << std::endl;
	while (_getch() != ' ') {}
	clock_t time = clock() / CLOCKS_PER_SEC;
	character = adventurer;
	loadMaze();
	placeAdventurer(1, 1);
	drawMaze();
	adventurerMove();
	system("cls");
	return true;
}

void Maze::loadMaze()
{
	int lineNumber = 0;
	std::fstream *maze = new std::fstream();
	maze->open("Encounters/Maze/Maze1.txt", std::ios::in);
	if (maze->good() == false)
	{
		std::cout << "Cannot enter the maze..." << std::endl;
		delete this;
	}
	while (getline(*maze, mazeLines[lineNumber])) lineNumber++;
}

void Maze::drawMaze()
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	for (int i = 0; i < 24; i++)
	{
		printf("%s\n", mazeLines[i].c_str());
	}
}

void Maze::placeAdventurer(int x, int y)
{
	mazeLines[y].replace(x, 1, "A");
}

char Maze::getSymbol(int x, int y)
{
	return mazeLines[y][x];
}

void Maze::deleteAdventurer()
{
	mazeLines[adventurerY].replace(adventurerX, 1, " ");
}

bool Maze::checkMove(int x, int y)
{
	char check = getSymbol(x, y);
	if (check == '#') return false;
	else if (check == ' ') return true;
	else if (check == 'E')
	{
		solved = true;
		return false;
	}
	else return false;
}

void Maze::adventurerMove()
{
	char action;
	int rocks;
	while (!solved)
	{
		do
		{
			action = _getch();
		} while (action != 'w' && action != 's' && action != 'a' && action != 'd');
		rocks = rand() % 100;
		switch (action)
		{
		case 'w':
			if (checkMove(adventurerX, adventurerY - 1))
			{
				deleteAdventurer();
				adventurerY -= 1;
				placeAdventurer(adventurerX, adventurerY);
				if (rocks > 89) qte();
			}
			break;
		case 's':
			if (checkMove(adventurerX, adventurerY + 1))
			{
				deleteAdventurer();
				adventurerY += 1;
				placeAdventurer(adventurerX, adventurerY);
				if (rocks > 89) qte();
			}
			break;
		case 'a':
			if (checkMove(adventurerX - 1, adventurerY))
			{
				deleteAdventurer();
				adventurerX -= 1;
				placeAdventurer(adventurerX, adventurerY);
				if (rocks > 89) qte();
			}
			break;
		case 'd':
			if (checkMove(adventurerX + 1, adventurerY))
			{
				deleteAdventurer();
				adventurerX += 1;
				placeAdventurer(adventurerX, adventurerY);
				if (rocks > 89) qte();
			}
			break;
		default:
			break;
		}
		drawMaze();
	}
	time = clock() / CLOCKS_PER_SEC - time;
	system("cls");
	std::cout << "You find exit!" << std::endl;
	std::cout << "Your time: " << time << std::endl;
	reward();
	std::cout << "Press space to continue..." << std::endl;
	while (_getch() != ' ') {}
}

void Maze::reward()
{
	std::cout << "Founder of the maze decided to bless you!" << std::endl;
	if (time < 30)
	{
		character->SetIntelligence(character->GetIntelligence() + 5);
		std::cout << "Reward: Blessing of Gods" << std::endl;
	}
	else if (time < 45)
	{
		character->SetIntelligence(character->GetIntelligence() + 3);
		std::cout << "Rward: Blessing of Kings" << std::endl;
	}
	else if (time < 60)
	{
		character->SetIntelligence(character->GetIntelligence() + 2);
		std::cout << "Reward: Blessing of Owl" << std::endl;
	}
	else
	{
		character->SetIntelligence(character->GetIntelligence() + 1);
		std::cout << "Reward: Blessing of Chaotic Escape" << std::endl;
	}
}

void Maze::qte()
{
	char key = ' ';
	system("cls");
	std::cout << "Press X to avoid falling rocks!!!" << std::endl;
	int timer = clock() / CLOCKS_PER_SEC;
	while (1)
	{
		if (_kbhit())
		{
			if (_getch() == 'x')
			{
				std::cout << "You are so skillful! Rain of rocks isn't the problem for You!" << std::endl;
				std::cout << "Press space to continue..." << std::endl;
				while (_getch() != ' ') {}
				break;
			}
		}
		if (clock() / CLOCKS_PER_SEC - timer > character->GetAgility() / 8)
		{
			std::cout << "Rock hits You... You lose 10 hp" << std::endl;
			std::cout << "Press space to continue..." << std::endl;
			while (_getch() != ' ') {}
			if (character->GetHP() - 10 <= 0)
			{
				system("cls");
				std::cout << "You are dead" << std::endl;
				std::cout << "Press space to exit..." << std::endl;
				while (_getch() != ' ') {}
				exit(0);
			}
			std::cout << "Your hp: " << character->GetHP() - 10 << std::endl;
			std::cout << "Be careful next time!" << std::endl;
			std::cout << "Press space to continue..." << std::endl;
			while (_getch() != ' ') {}
			character->SetHP(character->GetHP() - 10);
			break;
		}
	}
}

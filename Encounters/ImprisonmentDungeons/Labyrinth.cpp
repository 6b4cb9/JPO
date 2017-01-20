/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1

#include <iostream>
#include <conio.h>
#include <cstdlib>

#include <string>
#include "Labyrinth.h"

using namespace std;

void Labyrinth::create_first()
{

	int x_pos = 0;  //	x - kolumny
	int y_pos = 0;  //	y - wiersze
	bool exit = false;

	char movement;
	char character_pos = 'X';

	char MapOfDungeon1[10][10] =

	{
		' ', ' ', ' ', '|', '|', '-', '-', '-', '-', '\\',

		'|', '-', ' ', '-', '-', ' ', ' ', '-', ' ', '|',

		'|', ' ', ' ', ' ', '|', '|', '-', ' ', ' ', '|',

		'|', ' ', '|', ' ', '|', '|', ' ', ' ', ' ', '|',

		'|', ' ', '|', ' ', '|', '|', ' ', ' ', ' ', '|',

		'|', ' ', '|', ' ', ' ', ' ', ' ', '-', '-', '|',

		'|', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|',

		'|', ' ', '-', '-', '-', ' ', ' ', '-', ' ', '|',

		'|', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', 'O',

		'\\', '-', '-', '-', '-', '-', '-', '-', '-', '/'

	};


	while (!exit)

	{
		system("cls");
		cout << "*** LABYRINTH ***\nReach end of the Dungeons\n\n";
		for (int y = 0; y<10; y++)
		{
			for (int x = 0; x<10; x++)
			{
				if (x == x_pos && y == y_pos)
				{
					cout << character_pos;
				}
				else
				{
					cout << MapOfDungeon1[y][x];
				}
			}
			cout << "\n";
		}

		movement = _getch();

		switch (movement)
		{

		case 'a':
			if (MapOfDungeon1[y_pos][x_pos - 1] == ' ' || MapOfDungeon1[y_pos][x_pos - 1] == 'O')
			{
				--x_pos;
				break;
			}
		case 'd':
			if (MapOfDungeon1[y_pos][x_pos + 1] == ' ' || MapOfDungeon1[y_pos][x_pos + 1] == 'O')
			{
				++x_pos;
				break;
			}
		case 'w':
			if (MapOfDungeon1[y_pos - 1][x_pos] == ' ' || MapOfDungeon1[y_pos - 1][x_pos] == 'O')
			{
				--y_pos;
				break;
			}

		case 's':
			if (MapOfDungeon1[y_pos + 1][x_pos] == ' ' || MapOfDungeon1[y_pos + 1][x_pos] == 'O')
			{
				++y_pos;
				break;
			}
		case 'q':
			break;

		}

		if (MapOfDungeon1[y_pos][x_pos] == 'O')
		{
			exit = true;
		}

	}
}

void Labyrinth::create_second()
{

	int x_pos = 0;  //	x - kolumny
	int y_pos = 0;  //	y - wiersze
	bool exit = false;

	char movement;
	char character_pos = 'X';

	char MapOfDungeon1[10][10] =

	{
		' ', ' ', ' ', '|', '|', '-', '-', '-', '-', '\\',

		'|', ' ', ' ', '-', '-', ' ', ' ', '-', ' ', '|',

		'|', ' ', ' ', '-', '|', '|', '-', ' ', ' ', '|',

		'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|',

		'|', ' ', '|', '-', ' ', '|', '-', '-', ' ', '|',

		'|', ' ', '|', ' ', ' ', '|', ' ', '-', ' ', '|',

		'|', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', '|',

		'|', ' ', ' ', ' ', '-', ' ', ' ', '-', ' ', '|',

		'|', ' ', '|', ' ', ' ', ' ', '-', ' ', ' ', 'O',

		'\\', '-', '-', '-', '-', '-', '-', '-', '-', '/'

	};


	while (!exit)

	{
		system("cls");
		cout << "*** LABYRINTH ***\nReach end of the Dungeons\n\n";
		for (int y = 0; y<10; y++)
		{
			for (int x = 0; x<10; x++)
			{
				if (x == x_pos && y == y_pos)
				{
					cout << character_pos;
				}
				else
				{
					cout << MapOfDungeon1[y][x];
				}
			}
			cout << "\n";
		}

		movement = _getch();

		switch (movement)
		{

		case 'a':
			if (MapOfDungeon1[y_pos][x_pos - 1] == ' ' || MapOfDungeon1[y_pos][x_pos - 1] == 'O')
			{
				--x_pos;
				break;
			}
		case 'd':
			if (MapOfDungeon1[y_pos][x_pos + 1] == ' ' || MapOfDungeon1[y_pos][x_pos + 1] == 'O')
			{
				++x_pos;
				break;
			}
		case 'w':
			if (MapOfDungeon1[y_pos - 1][x_pos] == ' ' || MapOfDungeon1[y_pos - 1][x_pos] == 'O')
			{
				--y_pos;
				break;
			}

		case 's':
			if (MapOfDungeon1[y_pos + 1][x_pos] == ' ' || MapOfDungeon1[y_pos + 1][x_pos] == 'O')
			{
				++y_pos;
				break;
			}
		case 'q':
			break;

		}

		if (MapOfDungeon1[y_pos][x_pos] == 'O')
		{
			exit = true;
		}

	}
}
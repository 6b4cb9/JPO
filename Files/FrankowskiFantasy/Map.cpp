#include "stdafx.h"
#include "Map.h"

void Map::Show(Character * hero)
{
	UserInterface::getInstance()->clearScreen();
	int rose = 0;
	for (int i = size_y - 1; i>-1; --i) {
		for (int k = 0; k < Location::GetPicY(); k++) {
			for (int ii = 0; ii < size_x; ii++) {
				if (hero->GetCurrentLocation()->GetX() == ii && hero->GetCurrentLocation()->GetY() == i)
					cout << showHero(k);
				else {
					//cout << "[" << MapT[ii][i]->GetY() << ";" << MapT[ii][i]->GetX() << "]";
					cout << MapT[ii][i]->show(k);
				}

			}
			cout << CompassRose(rose++);
			/*

			*/
		}
	}
	//cout << "Hero:" << hero->GetCurrentLocation()->GetX() <<" "<<hero->GetCurrentLocation()->GetY()<<endl;
}

void Map::Create() {
	for (int i = 0; i<size_y; i++) {
		int ii = size_y - i - 1;
		for (int j = 0; j < size_x; j++) {
			if ((j / 4 + 7 * size_x / 10) <= i) {
				MapT[j][i] = new Mountain(i);
			}
			else if ((j + 3 * sin(j)) >= i) {
				MapT[j][i] = new Meadow();
			}
			else {
				MapT[j][i] = new Forest(i);
			}
			MapT[j][i]->SetX(j);
			MapT[j][i]->SetY(i);
			MapT[j][i]->SetBorderPermission();
		}
	}
	//test
	AddLocation(new GhastlyHeath, 8, 2);
	AddLocation(new Route, 3, 5);
	AddLocation(new Dungeons, 2, 9);
	AddLocation(new Tower, 8, 8);
	AddLocation(new Camp, 2, 1);
}

string Map::showHero(int line) {
	string symbol = "            O      /|\\     / \\  ";
	line %= Location::GetPicY();
	return symbol.substr(line* Location::GetPicX(), Location::GetPicX());
}

//Getters
Map* Map::Instance = 0;
int Map::GetSizeX() {
	return size_x;
}

int Map::GetSizeY() {
	return size_y;
}

Location * Map::GetMap(int x, int y) {
	return MapT[x][y];
}

Map* Map::GetInstance() {
	if (Instance == 0)
	{
		Instance = new Map();
	}
	return Instance;
}

void Map::AddLocation(Location * loc, int x, int y) {
	delete MapT[x][y];
	MapT[x][y] = loc;
	MapT[x][y]->SetX(x);
	MapT[x][y]->SetY(y);
	MapT[x][y]->SetBorderPermission();
}

Map::~Map()
{
}
Map::Map() {
	Create();
}

std::string Map::CompassRose(int line) {
	int size = 5;
	string *compass = new string[size];
	compass[0] = "      (N)\n";
	compass[1] = "      /\\ \n";
	compass[2] = " (W) <  > (E)\n";
	compass[3] = "      \\/ \n";
	compass[4] = "      (S)\n";
	if (--line < size && line >= 0) return compass[line];
	else return "\n";
}
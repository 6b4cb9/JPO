#pragma once
#include"stdafx.h"
#include <vector>
#include "Monster.h"
#include "Character.h"
#include <time.h>
#include <cstdlib>


class MonsterComposite{

	vector <Monster*> monsters;

	void menu();
	void drawMap();
	void ChampionMove();
	bool check(int x, int y);
	void mainMenu();
	int choice(int value);
	void showMystats(Character * character);
	void showEnemystats(Monster * monster);
	int fightMenu(Monster * monster);
	char map[6][6];
	int charCoordinates[2];
	int monsterCoordinates[2];
	bool checkArea();
	void monsterTurn(Monster*, Character*);
	void monsterMove();
	int atackFunction();

public:
	MonsterComposite();
	~MonsterComposite();
	void addMonster(Monster * m);	
	Monster* getMonster(int number);
	int getSize();
	void Fight(Character * character);
	int MeleeAttack();
	int RangedAttack();


};


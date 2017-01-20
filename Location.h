#pragma once
#ifndef _LOCATION_
#define _LOCATION_

using namespace std;

class Location;
class Map;
#include <vector>
#include <string>
#include "Character.h"
#include "UserInterface.h"
#include <cstdlib>
#include "Encounter.h"

class Location
{
public:
	Location(string name, string des, string sym);
	Location();
	~Location();
	string show(int);

	virtual void RunLocation(Character *);
	void AddEncounter(Encounter*);

	//Setters
	void SetBorderPermission();
	void SetName(std::string);
	void SetDescritpion(std::string);
	void SetSybmol(std::string);
	void SetPermissions(bool *);
	void SetPermissionTrue(int id);
	void SetX(int);
	void SetY(int);
	//Getters
	static int GetPicX();
	static int GetPicY();
	//int GetSizeX();
	//int GetSizeY();
	std::string GetName();
	std::string GetDescription();
	std::string GetSymbol();
	bool * GetPermissions();
	int GetX();
	int GetY();

private:
	static const int size_x = 10;
	static const int size_y = 10;
	static const int pic_x = 8;
	static const int pic_y = 4;
	void FinishEncounter(Character * hero);
	void ExitSafeEncounter(Character * hero);
	bool testEndLocation();
	void MissionSucceed(Character * hero);

private:
	//std::vector<Location *>neighbour;
	bool permisions[4]; //NESW
	std::vector<Encounter*> encounters;
	std::vector<bool>finished;
	std::string name;
	std::string description;
	std::string symbol;
	UserInterface* gui;
	string finish[3] = { "You complete the adventure!", "Mission succeed!" ,"Congratulation!" };
	string gosomwhere[4] = { "What to do now?", "Where to go now?" ,"What shall you do?" , "Do you have any ida what to do now?" };
	int currentEncounter;
	bool  exit, endLocation;
	int x, y;
	static const int maxX = 9, maxY = 9;
};

#endif
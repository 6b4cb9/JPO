#pragma once
#ifndef _MONSTER_
#define _MONSTER_
#include"stdafx.h"
#include "Character.h"
#include <string>
class Monster :
	public Character
{
public:
	Monster();
	~Monster();
	std::string GetDescription();
	void SetDescription(std::string);
private:
	std::string description;
};
#endif

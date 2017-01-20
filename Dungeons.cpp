
#include "Dungeons.h"

Dungeons::Dungeons() : Location("Dungeons", "A grim, cold place among high hills ", "   /\\     /  \\   / __ \\ / /##\\ \\")
{
	this->AddEncounter(new Maze());
	this->AddEncounter(new Cave());
	this->AddEncounter(new ImprisonmentDungeons());
	this->AddEncounter(new Desert());
}


Dungeons::~Dungeons()
{
}

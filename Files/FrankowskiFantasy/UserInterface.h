#pragma once
#include"stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
class UserInterface
{
public:
	void wait();
	void clearScreen();
	~UserInterface();
	int getAns(int num);
	void write(std::string);
	int choice(std::vector <std::string> text, std::string invit = " ");
	static UserInterface * getInstance();
private:
	UserInterface();
	static UserInterface* instance;
};


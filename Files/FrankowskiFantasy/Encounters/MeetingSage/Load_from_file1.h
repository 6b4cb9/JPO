/// Autor: KAMIL �ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWI�ZIENIE - pasuje mi to do LOCH�W (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z M�DRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1
#pragma once 
#include "..\..\Character.h"
#include <iostream>
#include"stdafx.h"
using namespace std;

class Text
{
public:
	void load(string);
	void press_any();
	void show_stats(Character* );
};
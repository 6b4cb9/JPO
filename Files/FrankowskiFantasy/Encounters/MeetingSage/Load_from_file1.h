/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
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
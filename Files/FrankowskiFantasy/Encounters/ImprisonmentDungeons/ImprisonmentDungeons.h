/// Autor: KAMIL �ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWI�ZIENIE - pasuje mi to do LOCH�W (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z M�DRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1
#include"..\..\stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "..\..\Character.h"
#include "..\..\Encounter.h"

using namespace std;


//uwi�zenie w lochach
class ImprisonmentDungeons : public Encounter
{
public:
	bool Proceed(Character* Character);
};

/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1

#include <iostream>
#include <cstdlib>
#include <conio.h>

#include "..\..\Character.h"
#include "..\..\Encounter.h"

using namespace std;


//spotkanie z Mêdrcem
class MeetingSage : public Encounter
{
public:
	bool Proceed(Character* Character);
};
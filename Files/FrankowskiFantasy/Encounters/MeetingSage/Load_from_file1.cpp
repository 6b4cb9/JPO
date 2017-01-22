#include"stdafx.h"
#include "Load_from_file1.h"

/// Autor: KAMIL £ECZYCKI GR. 3 11:15
/// MOJE WYDARZENIA:

///		-TO UWIÊZIENIE - pasuje mi to do LOCHÓW (sterowanie w labiryncie W,S,A,D)
///		-stopien trudnosci: 2


///		-ROZMOWA Z MÊDRCEM W JEGO CHACIE - pasuje mi to do LASU
//		-stopien trudnosci: 1

#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;

void Text::load(string name)
{
	name = "Encounters/MeetingSage/" + name;
	
	
	fstream plik;
	plik.open(name, ios::in);

	if (plik.good() == false)
	{
		cout << "Can't open the file!";
		exit(0);
	}
	string linia;
	cout << endl;
	while (getline(plik, linia))
	{
		cout << linia << endl;
	}

	plik.close();

}

void Text::press_any()
{
		char z;
		cout << endl << "\nPress any key to continue ..." << endl;
		z = getchar();
		getchar();
	
}

void Text::show_stats(Character * Character)
{
	
	cout << "*** YOUR STATS ***" << endl;
	cout << "Name: \t\t" << Character->GetName() << endl;
	cout << "Profession: \t" << Character->GetProfession() << endl;
	cout << "HP: \t\t" << Character->GetHP() << endl;
	cout << "Strength: \t" << Character->GetStrength() << endl;
	cout << "Toughness: \t" << Character->GetToughness() << endl;
	cout << "Wisdom: \t" << Character->GetWisdom() << endl;
	cout << "Intelligence: \t" << Character->GetIntelligence() << endl;
	cout << "Mana: \t\t" << Character->GetMana() << endl;
	cout << "Agiglity: \t" << Character->GetAgility() << endl;
	cout << "Charisma: \t" << Character->GetCharisma() << endl;
	cout << "Gold: \t\t" << Character->GetGold() << endl;
	
	
}
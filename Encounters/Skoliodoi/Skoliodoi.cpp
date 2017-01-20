#include "stdafx.h"
#include "Skoliodoi.h"
#include "SkoliodoiDoulos.h"
#include "SkoliodoiMercenary.h"
#include "SkoliodoiAristocrat.h"


Skoliodoi::Skoliodoi()
{
}


Skoliodoi::~Skoliodoi()
{
}

void Skoliodoi::Describe(Character * Hero)
{
	cout << "Name = " << Hero->GetName() << endl;
	cout << "Proffesion = " << Hero->GetProfession() << endl;
	cout << "Strength = " << Hero->GetStrength() << endl;
	cout << "Agility = " << Hero->GetAgility() << endl;
	cout << "Toughness = " << Hero->GetToughness() << endl;
	cout << "Charisma = " << Hero->GetCharisma() << endl;
	cout << "Intelligence = " << Hero->GetIntelligence() << endl;
	cout << "Wisdom = " << Hero->GetWisdom() << endl;
	cout << "HP = " << Hero->GetHP() << endl;
	cout << "Mana = " << Hero->GetMana() << endl;
	cout << "Gold = " << Hero->GetGold() << endl << endl;
}

bool Skoliodoi::Proceed(Character * Adventurer)
{
	Describe(Adventurer);
	int Level;
	int Form = 2 * Adventurer->GetCharisma() + Adventurer->GetIntelligence();
	SkoliodoiAbstract* First;
	if (Form <= 40)
	{
		First = new SkoliodoiDoulos;
		Level = 1;
	}
	else if (Form < 50)
	{
		First = new SkoliodoiMercenary;
		Level = 2;
	}
	else
	{
		First = new SkoliodoiAristocrat;
		Level = 3;
	}
	First->FirstDay(Adventurer);
	delete First;
	cout << endl << endl;
	Describe(Adventurer);
	

	cout << endl << endl;
	Form = 2 * Adventurer->GetCharisma() + Adventurer->GetIntelligence();
	SkoliodoiAbstract* Second;
	if (Form <= 40)
	{
		if (Level > 1)
		{
			cout << "STORY\tIn the night.\n";
			cout << "Zajdar:\tYou shouldn't be one of us! I was wrong, you aren't a free man, you are just a doulos!\n";
		}
		Second = new SkoliodoiDoulos;
	}
	else if (Form < 50)
	{
		if (Level == 1)
		{
			cout << "STORY\tIn the night.\n";
			cout << "Zajdar:\tI was wrong, you have a great talent. Become one of us, a mercenary.\n";
		}
		if (Level == 3)
		{
			cout << "STORY\tIn the night.\n";
			cout << "Zajdar:\tWe won't listen to your order any more! You are just a mercenary, noone more.\n";
		}
		Second = new SkoliodoiMercenary;
	}
	else
	{
		if (Level < 3)
		{
			cout << "STORY\tIn the night.\n";
			cout << "Zajdar:\tI'm impressed, you have a great talent. Become our leader, I believe we will survive thanks to you.\n";
		}
		Second = new SkoliodoiAristocrat;
	}
	Second->SecondDay(Adventurer);
	Second->End(Adventurer);
	delete Second;
	cout<<"THE END\n";
	cout << endl << endl;
	Describe(Adventurer);
	return true;
}

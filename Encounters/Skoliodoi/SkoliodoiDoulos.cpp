#include "stdafx.h"
#include "SkoliodoiDoulos.h"


SkoliodoiDoulos::SkoliodoiDoulos()
{
}


SkoliodoiDoulos::~SkoliodoiDoulos()
{
}

void SkoliodoiDoulos::FirstDay(Character* Hero)
{
	cout << "Doulos 1\n";
	int choice;
	bool ok;

	Wait(2);
	cout << "Zajdar:\tStay! Come here! Who are you?\n";
	Wait(2);
	cout << Hero->GetName() << ":\tI'm " << Hero->GetName() << ". What do you want from me?\n";
	Wait(2);
	cout << "Zajdar:\tI'm Zajdar. I organize an expedition inside this forest and I need people. This is Berbelek, Omixos and Njute. There are a few douloses, our slaves\n";
	Wait(2);
	cout << Hero->GetName() << ":\tHi, I'm What's unusual in this forest?\n";
	Wait(2);
	cout << "Zajdar:\tHunters say that inside there is a strange magic. There are creatures with a lion's body and bird's head, woter flows up, fires walk on ground and many more. We can find a lot of treasures.\n";
	Wait(2);
	cout << "Zajdar:\tGreat! Everybody, listen to me! This is " << Hero->GetName() << " and he will join us\n";
	Wait(2);
	cout << "Omixos:\tWhy do we need him? Look at him, he will run when we meet the first monster\n";
	Wait(2);
	cout << "CHOOSE THE ANSWER:\n1) Ok, if you don't want me, I go my own way.\n2) Don't worry, I can handle it.\n3) Trust me, I killed more monsters than you. Do you want to check if I can fight?\n";
	choice = Read(3);
	switch (choice)
	{
	case 1:
		Hero->SetCharisma(Hero->GetCharisma() - 1);
		cout << "Zajdar:\t No, no, wait. Don't listen to him. Omixos, shut up, everyone may help us. Let's go!\n";
		break;
	case 2:
		Hero->SetCharisma(Hero->GetCharisma() + 1);
		cout << "Zajdar:\tGreat, we have a deal! Let's go!\n";
		break;
	case 3:
		Hero->SetCharisma(Hero->GetCharisma() + 2);
		cout << "Zajdar:\tGreat, we have a deal! Let's go!\n";
		break;
	default:
		cout << "...\n";
	}

	cout << endl;
	Wait(4);
	cout << "STORY:\tSome time later\n";
	cout << "Zajdar:\tI think we are deep enough in the forest. Try to find some strange phenomenons\n";
	ok = false;
	if (Hero->GetAgility() >= 14)
	{
		cout << "STORY:\tYour agility has has enough high level.\n";
		cout << "CHOOSE:\n";
		cout << "1) Look for traces on the ground\n2) Climb a tree\n";
		choice = Read(2);
		switch (choice)
		{
		case 1:
			Hero->SetAgility(Hero->GetAgility() - 1);
			cout << "STORY:\tYou don't find anything interesting\n";
			break;
		case 2:
			Hero->SetAgility(Hero->GetAgility() + 1);

			if (Hero->GetIntelligence() >= 11)
			{
				cout << "STORY:\tYou see a few things. Choose what describe to Zajdar.\n";
				cout << "CHOOSE\n";
				cout << "1) Monkeys with legs of spiders\n2) Huge butterflies\n3) Rain falling up\n4) Fog and fire inside\n";
				choice = Read(4);
				switch (choice)
				{
				case 1:
					Hero->SetIntelligence(Hero->GetIntelligence() + 3);
					ok = true;
					break;
				default:
					ok = false;
				}
			}
			else
			{
				cout << "STORY:\tYou see a few things but you don't know if anything is interesting so you decide to tel Zajdar nothing.\n";
			}
			break;
		default:
			cout << "...\n";
		}
	}
	else
	{
		cout << "STORY:\tYour agility has has not enough high level so you can't look for traces.\n";
	}
	if (ok)
	{
		Wait(2);
		cout << "Zajdar:\tGreat! Hunting! Here you have some gold.\n";
		Hero->SetGold(Hero->GetGold() + 20);
	}
	else
	{
		Wait(2);
		cout << "Zajdar:\tWhat? Berbelek has found monkeys with legs of spiders. Hunting!\n";
	}

	cout << endl;
	Wait(2);
	cout << "STORY:\tAccidently you saw a lizard with a tail of a scorpion and it is attacking you.\n";
	cout << "CHOOSE WHAT YOU DO\n";
	cout << "1) Try to dogde and kill the monster\n2)\ Try to attack first\n";
	choice = Read(2);
	switch (choice)
	{
	case 1:
		if (Hero->GetAgility() >= 15)
		{
			cout << "STORY:\tYou agility is enough\n";
			cout << "Njute:\tYou did it! You killed it!\n";
			Hero->SetAgility(Hero->GetAgility() + 3);
			Hero->SetCharisma(Hero->GetCharisma() + 2);
		}
		else
		{
			cout << "STORY:\tYou agility is not enough. Njute kills the monster\n";
			cout << "Njute:\tWhat did you try to do!? Didn't you see it? You should attack first!\n";
			Hero->SetHP(Hero->GetHP() - 30);
			Hero->SetCharisma(Hero->GetCharisma() - 1);
		}
		break;
	case 2:
		if (Hero->GetToughness() < 30)
		{
			Hero->SetHP(Hero->GetHP() - 30 + Hero->GetToughness());
		}
		cout << "STORY:\tYou get damages but kill monster\n";
		cout << "Njute:\tYou did it! You killed it! But couldn't you dodge?\n";
		break;
	default:
		cout << "...\n";
	}
	cout << "STORY:\tAll team hunt and kill a few monsters\n";

	if (Hero->GetHP() < 10)
	{
		cout << "STORY:\tYou are to hurt to do anything more this day. You must bear your wounds\n";
	}
	else
	{
		cout << endl;
		Wait(2);
		int a;
		cout << "STORY:\tYou do autopsy.\n";
		cout << "CHOOSE WHAT TO EXPLORE (NUMBER OD POSSIBILITIES DEPENDS ON YOUR WISDOM)\n";
		cout << "1) Stomach\n2) Claws\n";
		a = 2;
		if (Hero->GetWisdom() > 11)
		{
			cout << "3) Head\n";
			a = 3;
		}
		if (Hero->GetWisdom() > 15)
		{
			cout << "4) Tail\n";
			a = 4;
		}
		choice = Read(a);
		switch (choice)
		{
		case 1:
			cout << "STORY:\tYou found remains od rats\n";
			Hero->SetWisdom(Hero->GetWisdom() + 1);
			break;
		case 2:
			cout << "STORY:\tClaws are very sharp and hard. Someone must buy them.\n";
			Hero->SetWisdom(Hero->GetWisdom() + 2);
			Hero->SetGold(Hero->GetGold() + 10);
			break;
		case 3:
			cout << "STORY:\tEyes respond to ligths even after death. Some collector must buy them.\n";
			Hero->SetWisdom(Hero->GetWisdom() + 3);
			Hero->SetGold(Hero->GetGold() + 30);
			break;
		case 4:
			cout << "STORY:\tVenom is very strong. Some professor must buy it.\n";
			Hero->SetWisdom(Hero->GetWisdom() + 4);
			Hero->SetGold(Hero->GetGold() + 50);
			break;
		default:
			cout << "...\n";
		}

		cout << endl;
		Wait(2);
		cout << "Zajdar:\tTime to split the spoils\n";
		cout << "CHOOSE WHAT TO DO\n";
		cout << "1) Don't take anything.\n2) Take your parts\n3) Take more than your parts\n";
		choice = Read(3);
		switch (choice)
		{
		case 1:
			Hero->SetCharisma(Hero->GetCharisma() - 1);
			break;
		case 2:
			cout << "Omixos:\tGive me it!\n";
			cout << Hero->GetName() << ":\tBut...\n";
			cout << "Omixos:\tShut up!\n";
			cout << "STORY:\tOmixos hits you\n";
			Hero->SetCharisma(Hero->GetCharisma() + 1);
			break;
		case 3:
			cout << "Omixos:\tIt's mine!\n";
			cout << "STORY:\tOmixos hits you\n";
			Hero->SetCharisma(Hero->GetCharisma() - 1);
			Hero->SetHP(Hero->GetHP() - 5);
			break;
		default:
			cout << "...\n";
		}
	}
	Wait(2);
	cout << "Zajdar:\tIt's late. Let's sleep and tomorrow we will go further.\n";
}

void SkoliodoiDoulos::SecondDay(Character* Hero)
{
	int choice;
	Wait(2);
	cout << "STORY:\tIn the morning you go further. You are deep in the forest. It's time to choose the last way to the heart of the forest. ";
	Wait(2);
	cout << "You and the other douloses get order to find safe trace. You know nothing but you must check one.\n";
	cout << "1)  1\n2)  2\n3)  3\n4)  4\n5)  5\n";
	choice = Read(5);
	switch (choice)
	{
	case 1:
		Hero->SetHP(Hero->GetHP() - 20);
		cout << "STORY:\tTrees attack you and your hands turn into branches. You loose some HP points.\n";
		break;
	case 2:
		Hero->SetHP(Hero->GetHP() - 30);
		Hero->SetMana(Hero->GetMana() + 20);
		cout << "STORY:\tYou go into strange storm. You loose some HP points but get mana\n";
		break;
	case 3:
		Hero->SetHP(Hero->GetHP() - 25);
		cout << "STORY:\tFlaming flies try to get into your mouth. You loose your voice and some HP points\n";
		break;
	case 4:
		Hero->SetHP(Hero->GetHP() + 20);
		cout << "Przechodzisz bezpiecznie i jestes pelen energii, ale wyrasta Ci dodatkowa para rak\n";
		break;
	case 5:
		Hero->SetHP(Hero->GetHP() - 50);
		cout << "STORY:\tYour skin turn into slimy rock and you vomit. You loose some HP points\n";
		break;
	default:
		cout << "...\n";
	}
}

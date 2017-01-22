#include "stdafx.h"
#include "SkoliodoiAristocrat.h"


SkoliodoiAristocrat::SkoliodoiAristocrat()
{
}


SkoliodoiAristocrat::~SkoliodoiAristocrat()
{
}

void SkoliodoiAristocrat::FirstDay(Character* Hero)
{
	cout << "Aristocrat 1\n";
	int choice;
	bool ok;

	Wait(2);
	cout << "Zajdar:\tHi, I'm Zajdar. I see you are an aristocrat, would you like o join us? I organize an expedition inside this forest and this is my team.\n";
	Wait(2);
	cout << Hero->GetName() << ":\tHi, I'm " << Hero->GetName() << ". What's unusual in this forest?\n";
	Wait(2);
	cout << "Zajdar:\tHunters say that inside there is a strange magic. There are creatures with a lion's body and bird's head, woter flows up, fires walk on ground and many more. We can find a lot of treasures.\n";
	Wait(2);
	cout << Hero->GetName() << ":\It sounds interesting. I'm not in a hurry. Give me a few slaves and we may go.\n";
	Wait(2);
	cout << "Zajdar:\tGreat! Everybody, listen to me! This is " << Hero->GetName() << " and he will join us. " << Hero->GetName() << ", this is Berbelek, Omixos and Njute. There are a few douloses, our slaves.\n";
	Wait(2);
	cout << "Omixos:\tWhy do we need him? Look at him, he will run when we meet the first monster\n";
	Wait(2);
	cout << "CHOOSE THE ANSWER:\n1) Don't worry, I can handle it.\n2) Trust me, I killed more monsters than you. Do you want to check if I can fight?\n";
	choice = Read(2);
	switch (choice)
	{
	case 1:
		Hero->SetCharisma(Hero->GetCharisma() + 1);
		cout << "Zajdar:\tGreat, we have a deal! Let's go!\n";
		break;
	case 2:
		Hero->SetCharisma(Hero->GetCharisma() + 2);
		cout << "Wszyscy sie smieja i chca, bys im towarzyszyl\n";
		break;
	default:
		cout << "...\n";
	}

	cout << endl;
	Wait(4);
	cout << "STORY:\tSome time later\nZajdar send scouts to find something interesting. One of them saw monkeys with legs of spiders. You go hunting.\n";

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
			Hero->SetCharisma(Hero->GetCharisma() + 1);
			Hero->SetGold(Hero->GetGold() + 20);
			break;
		case 3:
			cout << "Omixos:\tIt's mine!\n";
			cout << Hero->GetName() << ":\t How dare you!?\n";
			cout << "STORY:\tYou hit Omixos.\n";
			Hero->SetCharisma(Hero->GetCharisma() + 2);
			Hero->SetGold(Hero->GetGold() + 50);
			break;
		default:
			cout << "...\n";
		}
	}
	Wait(2);

}

void SkoliodoiAristocrat::SecondDay(Character* Hero)
{
	int choice;
	Wait(2);
	cout << "STORY:\tIn the morning you go further. You are deep in the forest. It's time to choose the last way to the heart of the forest. First douloses and later warriors go to reconnoitre. They come back and you may watch then and choose where to go.\n";
	Wait(2);
	cout << "CHOOSE THE WAY. DESCRIPTION OF EVERY WARRIOR IS BELOW\n";
	Wait(2);
	cout << "1) His fingers turned into leafs\n2) He shoots lightning\n3) It has burned larynx\n4) He is hyperactive\n5) His skin is slimy and he vomits\n";
	choice = Read(5);
	switch (choice)
	{
	case 1:
		Hero->SetHP(Hero->GetHP() - 10);
		cout << "STORY:\tTrees attack you. You loose some HP points\n";
		break;
	case 2:
		Hero->SetHP(Hero->GetHP() - 20);
		Hero->SetMana(Hero->GetMana() + 20);
		cout << "STORY:\tYou go into strange storm. You loose some HP points but get mana\n";
		break;
	case 3:
		Hero->SetHP(Hero->GetHP() - 15);
		cout << "STORY:\tFlaming flies try to get into your mouth. You loose some HP points\n";
		break;
	case 4:
		Hero->SetHP(Hero->GetHP() + 20);
		cout << "STORY:\tYou pass safely ang you are full of energy\n";
		break;
	case 5:
		Hero->SetHP(Hero->GetHP() - 25);
		cout << "STORY:\tYour skin gets slimy and you vomit. You loose some HP points\n";
		break;
	default:
		cout << "...\n";
	}

}

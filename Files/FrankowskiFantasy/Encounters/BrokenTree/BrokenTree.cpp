#include"stdafx.h"
#include "BrokenTree.h"



BrokenTree::BrokenTree()
{
	this->robbed = false;
	this->joined = false;
	this->passed = false;
	this->save = false;
	this->ignore = false;
	this->succed = false;
	this->rescpet = 0;
	this->salary = 0;
	gui = UserInterface::getInstance();
}


BrokenTree::~BrokenTree()
{
}


bool BrokenTree::Proceed(Character* hero)
{	
	chapter1(hero);
	chapter2(hero);
	chapter3(hero);
	FinishEncounter(hero);
	return true;
}

void BrokenTree::chapter1(Character* hero) {
	int ans = 2, tmp;
	gui->write("You noticed huge oak lying on the road. Noble tree ended her life in a second. The problem is not the brutality of nature, but blocked road. There is a merchant with their cars, who can't pass too. He has the same problem.");
	gui->write("1)\tWho cares? Jump over the tree and continue your journey.");
	gui->write("2)\tHelp him.");
	if (hero->GetStrength() > 14) {
		gui->write("3)\tPick up the oak.");
		ans++;
	}
	ans = gui->getAns(ans);
	switch (ans)
	{
	case 1:
		tmp = hero->GetAgility() - 10;
		if (rand() % tmp) {
			gui->write("You're succed!");
			ignore = true;
		}
		else {
			int dmg = treeDamage(hero);
			gui->write("You've been fallen from the tree. Moreover you get " + to_string(dmg) + " damage points.");
			hero->SetHP(hero->GetHP() - dmg);
			rescpet -= 2;
		}
		break;
	case 2:
		passed = true;
		helpMerchant(hero);
		break;
	case 3:
		tmp = 21 - hero->GetStrength() - rand() % 7;
		if (tmp <= 0) {
			passed = true;
			gui->write("You're succed!");
			rescpet += 3;
		}
		else {
			int dmg = treeDamage(hero);
			gui->write("Oak is too heavy. Moreover you have been scratched by branches and get " + to_string(dmg) + "damage points.");
			hero->SetHP(hero->GetHP() - dmg);
			rescpet -= 1;
		}
		break;
	}
	if (!passed && ignore==false) {
		gui->write("If you want reach our destination today, you have to cooperate with marchant."); // sth to say
		helpMerchant(hero);
	}
}

void BrokenTree::chapter2(Character* hero) {
	if (passed) {
		int ans = 2;
		gui->write("Good morning! My name is Hugo. Thank for your help. I'm not very reach, but pleas take this.");
		int gold = (hero->GetCharisma())/3 + 20 + 5 * rescpet;
		hero->SetGold(hero->GetGold() + gold);
		gui->write("You recive " + to_string(gold) + " gold");
		gui->write("We're going in the same diraction. I would be glad if you join me.");
		gui->write("1)\tYes, of course!");
		gui->write("2)\tSorry, but I'm in a hurry and your cart must be slow.");
		if (hero->GetCharisma() > 14) {
			ans++;
			gui->write("3)\tI heard about bandits on this road. I can assist you, but it will cost.");
		}
		ans = gui->getAns(ans);
		switch (ans)
		{
		case 1:
			joined = true;
			rescpet++;
			if(rescpet>1)
				gui->write("Great! Come on.");
			else
				gui->write("Let's go.");
			break;
		case 2:
			if(rescpet>0)
				gui->write("What a shame. See you!");
			else
				gui->write("Goodbey.");
			break;
		case 3:
			negotiation(hero);
			break;
		}

	}
}

void BrokenTree::chapter3(Character* hero) {
	//bandits atack;
	gui->write("A quarter later...");
	gui->write("Stop! This is robbery!");

	gui->write("1)\tBargain.");
	gui->write("2)\tAttack!.");
	gui->write("3)\tGive gold.");
	switch (gui->getAns(3)) {
	case 1:
		gui->write("You must by rational man and you don't want problems.\n So do I. I will give you 50 gold and we will say goodbye in pice.");
		if (joined) {
			gui->write("Ok, but the other guy have to pay to!");
			if (hero->GetGold() < 50) {
				gui->write("Cheater! You haven't gold!");
				hero->SetGold(0);
				fight(hero);
			}
			else {
				hero->SetGold(hero->GetGold()-50);
				gui->write("Robbers walk away.");
			}
		}
		else {
			gui->write("Ok, but you will give us 100 gold.");
			gui->write("1)\tOK\n2)\tAttack!");
			int a = gui->getAns(2);
			if (a == 1) {
				if (hero->GetGold() < 100) {
					gui->write("Cheater! You haven't gold!");
					hero->SetGold(0);
					fight(hero);
				}
				else {
					hero->SetGold(hero->GetGold() - 100);
					gui->write("Robbers walk away.");
				}
			}
			else {
				fight(hero);
			}
		}
		break;
	case 2:
		fight(hero);
		save = true;
		gui->write("You win! Robbers run away!");
		break;
	case 3:
		gui->write("You lost " + to_string(hero->GetGold()) + " gold.");
		hero->SetGold(0);
		if (joined)
			gui->write("Hugo was robbed! He has nothing");
		break;
	}
}

void BrokenTree::FinishEncounter(Character* hero) {
	succed = true;
	if (joined && salary) {
		if (save) {
			hero->SetGold(hero->GetGold() + salary);
			gui->write("Thank for your help, you saved my life. Here's your salary.");
		}
		else {
			gui->write("Your protection was horrible. Salary? No way! Get out!");
		}
	}
}
int BrokenTree::treeDamage(Character* hero) {
	int dmg = 25-(hero->GetStrength())-(hero->GetAgility());
	if (dmg < 1)
		dmg = 1;
	dmg += rand() % 2;
	if (dmg >= hero->GetHP())
		dmg = hero->GetHP() - 1;
	return dmg;
}

void BrokenTree::helpMerchant(Character* hero){
	gui->write("What to tell him?");
	gui->write("1)\tHi! Let's move this tree together.");
	gui->write("2)\tWhat are you looking at? Hepl me now.");
	int ans = gui->getAns(2);
	if (ans == 1) {
		gui->write("Great idea! I'm glad to meet you!");
		rescpet += 1;
	}
	else {
		gui->write("...");
		rescpet -= 1;
	}
	gui->write("After few minuts of work, you've menaged to move the oak from the road.");
	passed = true;
}

void BrokenTree::negotiation(Character * hero) {
	int cash = 5;
	if (hero->GetCharisma() > 16)
		cash *= 2;
	if (hero->GetCharisma() > 19)
		cash *= 2;
	gui->write("Oh, really? I don't know. I have lots of  precious goods. Ok, a can get you "+ to_string(cash)+" gold.");
	gui->write("1)\tOK");
	gui->write("2)\tNo, I want " + to_string(2 * cash) + ".");
	gui->write("3)\tAre you kidding? " + to_string(3 * cash) + " That's my price.");
	int ans = gui->getAns(3);
	switch (ans)
	{
	case 1:
		salary = cash;
		joined = true;
		break;
	case 2:
		if (rescpet + hero->GetCharisma() + rand() % 5 > 20) {
			salary = 2*cash;
			joined = true;
			gui->write("Fine!");
		}
		else {
			gui->write(to_string(cash)+"is all I can propose.");
			gui->write("1)\tAccept.");
			gui->write("2)\tReject.");
			ans = gui->getAns(2);
			if (ans == 1) {
				salary = cash;
				joined = true;
			}
		}
		break;
	case 3:
		if (rescpet + hero->GetCharisma() + rand() % 5 > 25) {
			salary = 3 * cash;
			joined = true;
			gui->write("Uhh...Fine! You're lucky that my carrgo is so precious.");
		}
		else {
			gui->write("It's too much. I will go alone.");
		}
		break;
	}
}

void BrokenTree::fight(Character * hero) {
	int dmg = 80 - (hero->MeleeAttack()) - (hero->GetStrength()) - (hero->GetAgility())-rand()%5;
	if (joined)
		dmg -= (30+2*rescpet);
	if (dmg < 1)
		dmg = rand() % 4;
	hero->SetHP(hero->GetHP() - dmg);
	if (hero->GetHP() < 1)
		hero->SetHP(1);
	gui->write("Recived " + to_string(dmg) + " of damage.");
	if (joined)
		gui->write("Hugo helped you fight");
}
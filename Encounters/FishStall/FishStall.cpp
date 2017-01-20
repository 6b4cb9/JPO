#include "FishStall.h"

time_t FishStall::lastVisit = 0;

FishStall::FishStall()
{
	this->coin = true;
	this->hint1 = false;
	this->hint2 = false;
	this->succed = false;
	this->blackmail = false;
	gui = UserInterface::getInstance();
}

bool FishStall::Proceed(Character * hero) {
	// przyd³ugi wstêp;
	int	ans = 4,fb=0;
	while (fb != 4) {
		gui->write("...Fish! Fish from Tretogot!...");
		if (hint1 == false && ( hero->GetWisdom()) > 15) {
			gui->write("WHAT?! Tretogot has no access to the sea.");
			hint1 = true;
		}
		gui->write("1)\tGo to Niuthe.");
		gui->write("2)\tVisit Ikkita.");
		gui->write("3)\tTrade with Berbelek.");
		gui->write("4)\tGo away.");
		if (coin && (hero->GetIntelligence()) > 14) {
			gui->write("5)\tYou noticed something shiny in the mad. Check it.");
			ans++;
		}
		fb = gui->getAns(ans);
		switch (fb)
		{
		case 1:
			Niuthe(hero);
			break;
		case 2:
			Ikkitha(hero);
			break;
		case 3:
			Berbelek(hero);
			break;
		case 5:
			gui->write("You found gold coin!");
			hero->SetGold(hero->GetGold() + 1);
			coin = false;
			break;
		}
	}
	return false;
}

FishStall::~FishStall()
{
}

void FishStall::Niuthe(Character * hero) {
	int tmp = 0;
	while(tmp!=3){
		tmp= speach();
		if (tmp == 1) {
			gui->write("I have the best quality slik in city. It's incredible soft. Touch it, please.");
		}
		else if(tmp==2){
			gui->write("Its quite calm place, but... Berbeleks buyers... criminals.");
			if (hero->GetIntelligence() > 16 && hint2==false) {
				hint2 = true;
				gui->write("Hmm... They look like criminals... Intresting.");
			}
		}
	}
}

void  FishStall::Ikkitha(Character * hero) {
	int tmp = 0;
	while (tmp != 3) {
		tmp = speach();
		if (tmp == 1) {
			gui->write("I can sell you fresh fruits. Do you want a deliciosu appel? Only 1 gold.");
			gui->write("1)\tYes, I do.");
			gui->write("2)\tMayby another time.");
			if (gui->getAns(2) == 1) {
				if (hero->GetGold() > 0) {
					hero->SetGold(hero->GetGold() - 1);// a co jak w nieskonczonoœæ?
					if (hero->GetHP() < (hero->GetToughness()) * 6) {
						hero->SetHP(hero->GetHP() + 1);
						gui->write("Tasty! HP+1");
					}
				}
			}
		}
		else if (tmp == 2) {
			gui->write("I like this market. It lives.");
		}
	}
}

void FishStall::Berbelek(Character * hero) {
	int tmp = 0;
	if (succed) {
		if (blackmail) {
			while (tmp != 2) {
				gui->write("1)\tHello my friend, it's time to pay.");
				gui->write("2)\tBye!");
				tmp = gui->getAns(2);
				if (tmp == 1) {
					if (difftime(time(0), lastVisit) > lag) {
						lastVisit = time(0);
						hero->SetGold(hero->GetGold() + 20);
						gui->write("Recived 20 gold.");
					}
					else {
						gui->write("I've paid today!");
					}
				}
			}
		}
		else {
			while (tmp != 3) {
				tmp = speach();
				if (tmp == 1) {
					gui->write("I can offer you fishes. The best of the best.");
				}
				else if (tmp == 2) {
					gui->write("I am new here. I come from Tretogot.");
				}
			}
		}
	}
	else {
		while (tmp != 3) {
			tmp = speach();
			if (tmp == 1) {
				gui->write("I can offer you fishes. The best of the best.");
				if (hint1 && hint2) {
					gui->write("1)\tDo you have any sword-fish? Or even swords?\n\tTretogot is in the middle of nowhere,\n\tbut theirs blacksmiths are famouse all over the world.");
					gui->write("2)\tNo, thanks.");
					int a = gui->getAns(2);
					if (a == 1) {
						gui->write("Be quiet. Someone could hear us. 50 gold and you forget about me.");
						gui->write("1)\tI accept your gift.");
						gui->write("2)\tOk, but what if I remind it in the future?.");
						a = gui->getAns(2);
						if (a == 1) {
							succed = true;
							hero->SetGold(hero->GetGold() + 50);
							tmp = 3;
						}
						else {
							succed = true;
							blackmail = true;
							hero->SetGold(hero->GetGold() + 50);
							tmp = 3;
							if (hero->GetCharisma() > 0) {
								hero->SetCharisma(hero->GetCharisma() - 1);
								gui->write("Charisma -1");
								lastVisit = time(0);
							}
						}
					}
				}
			}
			else if (tmp == 2) {
				gui->write("I am new here. I come from Tretogot.");
			}
		}
	}
}

int FishStall::speach() {
	gui->write("1)\tWhat do you sell?");
	gui->write("2)\tTell me about market.");
	gui->write("3)\tBye!");
	return gui->getAns(3);
}
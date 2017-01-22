#include "stdafx.h"
#include "UndergroundRescue.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;



//Proceed function uses below declared functions
int assign_string_number(string x);
int assign_string_number2(string x);
int assign_string_number3(string x);
void escape(Character *Adventurer);
void MixtureEvent(Character *Adventurer);
void BeerBox(Character *Adventurer);

bool UndergroundRescue::Proceed(Character *Adventurer)
{
	srand(time(NULL));
	string tekst;
	string opcja;
	ifstream ifile;
	ifile.open("intro.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	
	
	
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			return false;
		}
		else if (assign_string_number3(opcja) == 1)
		{
			break;
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	ifile.open("Underground.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			cout << "You got out of cocoon but " << endl;
			cout << "spiders noticed that you are trying to reach knife. " << endl;
			cout << "There is no way to take boy" << endl;
			cout << "You have to escape " << endl;
			escape(Adventurer);
			if (Adventurer->getHp() <= 0)
			{
				cout << "Spiders killed you" << endl;
				//return;
				system("PAUSE");
				exit(0);
			}
			cout << "You escaped from spiders," << endl;
			cout << "but you don't have the boy" << endl;
			cout << "Mission is over" << endl;
			return false;
		}
		else if (assign_string_number3(opcja) == 1)
		{
			break;
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	
	ifile.open("RepairUnderground.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			cout << "Spiders consider you as useless." << endl;
			cout << "They want to kill you" << endl;
			cout << "You have to escape " << endl;
			escape(Adventurer);
			if (Adventurer->getHp() <= 0)
			{
				cout << "Spiders killed you" << endl;
				system("PAUSE");
				exit(0);
				//return ;
			}
			cout << "You escaped from spiders," << endl;
			cout << "but you don't have the boy" << endl;
			cout << "Mission is over" << endl;
			return false;
		}
		else if (assign_string_number3(opcja) == 1)
		{
			break;
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	int los = rand() % 2;
	if (los)
		MixtureEvent(Adventurer);
	if (Adventurer->getHp() <= 0)
	{
		cout << "You don't have hp" << endl;
		cout << "Game is over" << endl;
		//return false;
		system("PAUSE");
		exit(0);
	}
	if (Adventurer->getStrength() < 14)
	{
		cout << "You have too low strenght to manage work so hard" << endl;
		cout << "You died of exhaustion" << endl;
		Adventurer->setHp(0);
		system("PAUSE");
		exit(0);
	}
	ifile.open("WhileHelping.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			escape(Adventurer);
			if (Adventurer->getHp() <= 0)
			{
				cout << "Spiders killed you" << endl;
				//return;
				system("PAUSE");
				exit(0);
			}
			cout << "You escaped from spiders," << endl;
			cout << "but you don't have the boy" << endl;
			cout << "Mission is over" << endl;
			return false;
		}
		else if (assign_string_number3(opcja) == 1)
		{
			if (!los)
				BeerBox(Adventurer);
			if (Adventurer->getHp() <= 0)
			{
				cout << "You don't have hp" << endl;
				cout << "Game is over" << endl;
				//return;
				system("PAUSE");
				exit(0);
			}
			ifile.open("AfterWork.txt");
			while (getline(ifile, tekst))
			{
				cout << tekst << endl;
			}
			ifile.close();
			Adventurer->setToughness((Adventurer->getToughness() + 2));
			break;
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	ifile.open("Reward.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{			
			cout << "King of spiders didn't keep his word" << endl
				<< "and he killed you with his big fangs" << endl;
			Adventurer->setHp(0);
			//return;
			system("PAUSE");
			exit(0);
		}
		else if (assign_string_number3(opcja) == 1)
		{
			
			cout << "You killed the king of spiders! " << endl
				<< "You use situation(chaos) to escape with boy " << endl;
			// f-cja ucieczki
			escape(Adventurer);
			if (Adventurer->getHp() <= 0)
			{
				cout << "Spiders killed you" << endl;
				//return;
				system("PAUSE");
				exit(0);
			}
				
			break;
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	ifile.open("Finish.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			cout << "You don't take money " << endl;
			cout << "You get 2 Charisma points  " << endl;
			Adventurer->setCharisma(Adventurer->getCharisma() + 2);
			break;
		}
		else if (assign_string_number3(opcja) == 1)
		{

			cout << "You take money " << endl;
			Adventurer->setGold(Adventurer->getGold() + 200);
			break;
			
		}
		else 
		{
			cout << "There is no such option" << endl;
		}
	}
	return true;
}




void escape(Character *Adventurer)
{
	srand(time(NULL));
	string direction;
	cout << "You are trying to escape from undeground" << endl;
	int i = 0;
	while(i<5)
	{
		cout << "Use commands : \"letf\", \"right\", \"straight\"" << endl;
		cin >> direction;
		int dir = assign_string_number(direction);
		int los = rand() % 2;
		//cout << los << endl;
		if (dir == 0)
		{
			if (los)
			{
				cout << "Good way" << endl;
			}
			else
			{
				cout << "Bad way" << endl;
				cout << "Spiders attaks you " << endl;
				cout << "You lost 10 hp" << endl;
				Adventurer->setHp((Adventurer->getHp() - 10));
				if (Adventurer->getHp() <= 0)
				{
					//return;
					system("PAUSE");
					exit(0);
				}

			}
			i++;
		}
		else if (dir == 1)
		{
			if (!los)
			{
				cout << "Good way" << endl;
			}
			else
			{
				cout << "Bad way" << endl;
				cout << "Spiders attaks you " << endl;
				cout << "You lost 10 hp" << endl;
				Adventurer->setHp((Adventurer->getHp() - 10));
				if (Adventurer->getHp() <= 0)
				{ 
					//return;
					system("PAUSE");
					exit(0);
				}
			}
			i++;
		}
		else if (dir == 2)
		{
			if (los)
			{
				cout << "Good way" << endl;
			}
			else
			{
				cout << "Bad way" << endl;
				cout << "Spiders attaks you " << endl;
				cout << "You lost 10 hp" << endl;
				Adventurer->setHp((Adventurer->getHp() - 10));
				if (Adventurer->getHp() <= 0)
				{
					//return;
					system("PAUSE");
					exit(0);
				}
			}
			i++;
		}
		else if (dir == 666)
		{
			cout << "There is no such option" << endl;
		}

	}
}

void MixtureEvent(Character *Adventurer) // w któym bêd¹ 2 mini gry losowe eventy
{
	string tekst;
	ifstream ifile;
	ifile.open("MixtureEvent.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	cin >> tekst;
	int opcja = assign_string_number2(tekst);
	if (opcja == 0)
	{
		cout << "Mixture changed you into frog" << endl;	
		bool say = false;
		while (!say)
		{
			cout << "What does the frog say ?" << endl;
			cin >> tekst;
			if (tekst == "ribbit" || tekst == "Ribbit")
			{
				ifile.open("ribbit.txt");
				while (getline(ifile, tekst))
				{
					cout << tekst << endl;
				}
				ifile.close();
				say = true;
			}
			else
			{
				cout << "No! Frog doesn't say that!" << endl;
			}
		}
		return;
	}
	else if (opcja == 1)
	{
		cout << "You drunk a poison. You lost 30 hp" << endl;
		Adventurer->setHp((Adventurer->getHp() - 30));
		if (Adventurer->getHp() <= 0)
		{
			//return;
			system("PAUSE");
			exit(0);
		}
		cout << "Wizard teleport you back into underground" << endl;
		return;
	}
	else if (opcja == 2)
	{
		cout << "You drunk a strenght potion. " << endl;
		cout << "You get 3 strength points " << endl;
		Adventurer->setStrength((Adventurer->getStrength() + 3));
		if (Adventurer->getHp() <= 0)
		{
			//return;
			system("PAUSE");
			exit(0);
		}
		cout << "Wizard teleport you back into underground" << endl;
		return;
	}
	else 
	{
		cout << "There is no such option" << endl;
	}

}

void BeerBox(Character *Adventurer)
{
	string tekst;
	ifstream ifile;
	string opcja;
	ifile.open("Beer.txt");
	while (getline(ifile, tekst))
	{
		cout << tekst << endl;
	}
	ifile.close();
	while (1)
	{
		cin >> opcja;
		if (assign_string_number3(opcja) == 2)
		{
			cout << "You return to work" << endl;
			cout << "***********************************************" << endl;
			break;
		}
		else if (assign_string_number3(opcja) == 1)
		{

			cout << "You are so drunk that you hit your head against wall " << endl;
			cout << "You lost 5 hp" << endl;
			cout << "Tomorrow you will return to work" << endl;
			cout << "***********************************************" << endl;
			Adventurer->setHp((Adventurer->getHp()-5)); // I check if died just after of this BeerBox function in UndergroundRescue function
			break;

		}
		else
		{
			cout << "There is no such option" << endl;
		}
	}
	return;
}

int assign_string_number(string x)
{
	if (x == "left") return 0;
	else if (x == "right") return 1;
	else if (x == "straight") return 2;
	else return 666;
}

int assign_string_number2(string x)
{
	if (x == "first") return 0;
	else if (x == "second") return 1;
	else if (x == "third") return 2;
	else return 666;
}

int assign_string_number3(string x)
{
	if (x == "a" || x == "A") return 1;
	if (x == "b" || x == "B") return 2;
	else return 666;
}


// bêdzie jakieœ losowanie liczby i porawna liczba bêdzie siê 
// losowaæ z zakresu 0,1,2


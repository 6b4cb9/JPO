#include "stdafx.h"
#include "SkillsTest.h"


SkillsTest::SkillsTest()
{
}


SkillsTest::~SkillsTest()
{
}

bool SkillsTest::Proceed(Character *Player)
{

	fstream file;
	file.open("intro.txt", ios::in);
	if (file.good())
	{
		string temp;
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
		file.close();
	}
	else 
		cout << "File Error!!!" << endl;
	cout << "The password contains four numbers" << endl;
	cout << "243, 29, 85, 89, 145, 42, 20, 4, 16..." << endl;
	cout << "This might be helpful hint to brak this password" << endl;
	cout << "Find two another numbers and enter them " << endl;
	cout << "It will not be difficult task . To be honest" << endl;
	int b=breakPassword(Player);
	//breakPassword(Player);
	if (b == 1) {
		file.open("FirstChoice.txt", ios::in);
		if (file.good())
		{
			string temp;
			while (!file.eof())
			{
				getline(file, temp);
				cout << temp << endl;
			}
			file.close();
		}
		else {
			cout << "File Error!!!" << endl;
		}

	}
	while (1) 
	{ 
		int choice;
		cin>> choice;
		if (choice == 1)
		{
			livingRoom(Player);
			SecondChoice(Player);
			break;
		}
		else if (choice == 2)
		{
			SecondChoice(Player);
			break;
		}
		else
			cout << "Choose once again" << endl;

		}
	return true;
	}

	  


int SkillsTest::breakPassword(Character *Player)
{
	string password;
	while (1) {
		cout << "Password: " << endl;
		cin >> password;
		if (password == "3758")
		{
			cout << "Congratulations!!! Now you enter house and get additional point to intelligence." << endl;
			Player->setIntelligence(Player->getIntelligence() + 3);
			cout << "Your intelligence: " << Player->getIntelligence() << endl;
			return 1;
			break;
		}
		else if (password != "3758")
		{
			cout << "Password is incorrect!!! You lost  hp because of being hit by lightinig. " << endl;
			Player->setHp(Player->getHp() - (rand() % 2 + 1));
			cout << "Your Hp: " << Player->getHp() << endl;
			if (Player->getHp() <= 0) {
				system("cls");
				cout << "You are dead" << endl;
				system("PAUSE");
				exit(0);
			}
		}
		else
			cout << "I don't know what are you doing now !!" << endl;
	}
}

int SkillsTest::livingRoom(Character *Player)
{
	fstream file;
	file.open("AgilityTest.txt", ios::in);
	
	if (file.good())
	{
		string temp;
		int c;
		
		while (!file.eof())
		{
			
			getline(file, temp);
			cout << temp << endl;
			
			
			}
		
		file.close();
	}
	else {
		cout << "File Error!!!" << endl;
	}
	int correctAnsawer=0;
	for (int i= 0; i < 6; i++) 
	{
		int option1;
		int option2;
		int time;
		time = clock() / CLOCKS_PER_SEC;
		option1 = rand() % 1000 + 1;
		option2 = rand() % 1000 + 2;
		cout << "Which number is greater.Choose fast and correctly.Type:left or right depending on corrext option" << endl;
		cout << " Left: " << option1 << " Right: " << option2 << endl;
		string c;
	    
		cin >> c;
		if ((option1 > option2) && c == "left")
		{
			cout << "Correct!" << endl;
			Player->setIntelligence(Player->getIntelligence() + 1);
			correctAnsawer++;
		}
		else if ((option1 > option2) && c == "right")
		{
			cout << "Wrong choice!!!" << endl;
		}
		else if ((option1 < option2) && c == "right")
		{
			cout << "Correct!" << endl;
			Player->setIntelligence(Player->getIntelligence() + 1);
			correctAnsawer++;
		}
		else if ((option1 > option2) && c == "right")
		{
			cout << "Wrong choice!!!" << endl;
		}
		else
			cout << "You lost your chance." << endl;
		time = clock() / CLOCKS_PER_SEC - time;
		cout << "Ansawer time is : " << time <<"seconds" << endl;
		cout << "You ansawer correctly " << correctAnsawer << " times" << endl;
		Player->setAgility(Player->getAgility() + (rand()%3+1));

	}
	return 0;
}

void SkillsTest::SecondChoice(Character *Player)
{
	fstream file;
	file.open("SecondChoice.txt", ios::in);
	if (file.good())
	{
		string temp;
		string c;
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
		file.close();
	}
	else {
		cout << "File Error!!!" << endl;
	}
	while (1)
	{
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			Meeting(Player);
			FindDocument(Player); 
			break;
		}
		else if (choice == 2)
		{
			FindDocument(Player);
			break;
		}
		else
			cout << "Choose once again" << endl;

	}

}

void SkillsTest::FindDocument(Character *Player)
{
	
	
		fstream file;
		file.open("FindDocument.txt", ios::in);
		if (file.good())
		{
			string temp;
			while (!file.eof())
			{
				getline(file, temp);
				cout << temp << endl;
			}
			file.close();
		}
		else
			cout << "File Error!!!" << endl;
		while (1)
		{
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				
				Player->setHp(Player->getHp() + rand() % 2 + 1);
				Player->setIntelligence(Player->getGold() + (rand() % 3 + 1));
				Player->setCharisma(Player->getCharisma() + (rand() % 2 + 1));
				break;
			}
			else if (choice == 2)
			{
				Player->setGold(Player->getGold() + (rand()%3+1));
				Player->setStrength(Player->getGold() + (rand()%5+1));
				break;
			}
			else
				cout << "Choose once again" << endl;

		}
	}


void SkillsTest::Meeting(Character *Player)
{
	fstream file;
	file.open("Meeting.txt", ios::in);
	if (file.good())
	{
		string temp;
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
		file.close();
	}
	else {
		cout << "File Error!!!" << endl;
	}
	while (1)
	{
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			Player->setCharisma(Player->getCharisma() + (rand() % 2 + 1));
			break;
		}
		else if (choice == 2)
		{
			
			Player->setGold(Player->getGold() + (rand() % 3 + 1));
			Player->setWisdom(Player->getWisdom() - 2);
			break;
		}
		else
			cout << "Choose once again" << endl;
	}
}




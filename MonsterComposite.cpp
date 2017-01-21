//#include "stdafx.h"
#include "MonsterComposite.h"


MonsterComposite::MonsterComposite()
{
}


MonsterComposite::~MonsterComposite()
{
}

void MonsterComposite::addMonster(Monster * m){

	this->monsters.push_back(m);
}

Monster * MonsterComposite::getMonster(int number){

	return this->monsters[number];
 	
}

int MonsterComposite::getSize()
{
	return this->monsters.size();
}

void MonsterComposite::Fight(Character * character) {
	for (unsigned int counter = 0; counter<  this -> monsters.size(); counter++) {

		system("pause");
		Monster* monster;
		monster = getMonster(counter);
		bool finished = false;
		this->charCoordinates[0] = 3; // wiersz 
		this->charCoordinates[1] = 0; // kolumna
		this->monsterCoordinates[0] = 3;
		this->monsterCoordinates[1] = 5;

		int choice1;
		do {
			mainMenu();
			choice1 = choice(4);
			switch (choice1) {
			case 1:
				while (1) {
					if (character->GetHP() > 0) {
						system("cls");
						int fightChoice = fightMenu(monster);      //case1 = fight
						if (fightChoice == 1) {
							ChampionMove();
						}
						if (fightChoice == 2) {
							bool possibility = checkArea();
							if (possibility == false) {
								int demage;
								int option = atackFunction();

								if (option == 1) {
									demage = character->RangedAttack();
								}
								if (option == 2) {
									demage = character->RangedAttack()/2;
								}
								if (option == 3) {
									demage = character->RangedAttack() * 3 / 4;
								}
								
								monster->SetHP(monster->GetHP() - demage);
								cout << "demage: " << demage << endl;
								cout << "enemy hp: " << monster->GetHP() << endl;
							}
							else {
								cout << "Bad attack" << endl;

							}
							system("pause");
						}
						if (fightChoice == 3) {
							bool possibility = checkArea();
							if (possibility == true) {
								int demage = character->MeleeAttack();
								monster->SetHP(monster->GetHP() - demage);
								cout << "demage: " << demage << endl;
								cout << "enemy hp: " << monster->GetHP() << endl;;
							}
							else {
								cout << "Bad attack" << endl;
							}
							//system("pause");
						}
					}
					if (character->GetHP() <= 0) {
						cout << "You have lost" << endl;
						system("pause");
						exit(0);
					}
					if (monster->GetHP() > 0) {
						monsterTurn(monster, character);
					}
					if (monster->GetHP() <= 0) {
						finished = true;
						break;
					}
				}
				break;
			case 2:
				showEnemystats(monster);
				break;
			case 3:
				showMystats(character);
				break;
			case 4:
				break;
			default:
				break;

			}
		} while (!finished);

	}
}

int MonsterComposite::MeleeAttack()
{
	return 0;
}

int MonsterComposite::RangedAttack()
{
	return 0;
}





void MonsterComposite::menu() {

}

void MonsterComposite::drawMap() {
	int j;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {

			map[i][j] = 'x';
		}
	}

	int charx = this->charCoordinates[0];
	int chary = this->charCoordinates[1];
	int monsterx = this->monsterCoordinates[0];
	int monstery = this->monsterCoordinates[1];

	map[charx][chary] = 'C';
	map[monsterx][monstery] = 'O';
	for (int i = 0; i <= 5; i++) {
		j = 0;
		cout << map[i][j] << "  " << map[i][j + 1] << "  " << map[i][j + 2] << "  " << map[i][j + 3] << "  " << map[i][j + 4] << "  " << map[i][j + 5] << endl;
	}
}

void MonsterComposite::ChampionMove() {

	bool isCorrect;

	do {
		cout << "Where you want to move" << endl;
		char decision;
		cin >> decision;
		switch (decision) {

		case '1': {
			int rows = this->charCoordinates[0] + 1;
			int column = this->charCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}

		case '2': {
			int rows = this->charCoordinates[0] + 1;
			int column = this->charCoordinates[1];

			bool checkIn = check(rows, column);

			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '3': {
			int rows = this->charCoordinates[0] + 1;
			int column = this->charCoordinates[1] + 1;

			bool checkIn = check(rows, column);

			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '4': {
			int rows = this->charCoordinates[0];
			int column = this->charCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '6': {
			int rows = this->charCoordinates[0];
			int column = this->charCoordinates[1] + 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '7': {
			int rows = this->charCoordinates[0] - 1;
			int column = this->charCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '8': {
			int rows = this->charCoordinates[0] - 1;
			int column = this->charCoordinates[1];

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case '9': {
			int rows = this->charCoordinates[0] - 1;
			int column = this->charCoordinates[1] + 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				cout << "You cant move there" << endl;
				isCorrect = false;

			}
			else {
				this->charCoordinates[0] = rows;
				this->charCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		default:
			isCorrect = false;
			break;

		}


	} while (!isCorrect);

}

bool MonsterComposite::check(int rows, int column) {
	if (rows > 5 || rows < 0) {

		return false;
	}
	if (column > 5 || column < 0) {
		return false;
	}
	if (rows == this->monsterCoordinates[0] && column == this->monsterCoordinates[1]) {
		return false;
	}
	if (rows == this->charCoordinates[0] && column == this->charCoordinates[1]) {
		return false;
	}

	else {
		return true;
	}

}


void MonsterComposite::mainMenu()
{
	system("cls");
	cout << "===============================================================================" << endl;
	cout << "Welcome to Arena" << endl;
	cout << "What do you want to do?" << endl;
	cout << "===============================================================================" << endl;
	cout << "1.Start fighting" << endl;
	cout << "2.Show enemy" << endl;
	cout << "3.Show my stats" << endl;
	cout << "4.Back to save ecounter" << endl;

}


int MonsterComposite::choice(int value)
{
	int choice;
	do {
		cin >> choice;
	} while (choice > value);

	return choice;
}



void MonsterComposite::showMystats(Character* character)
{
	system("cls");
	cout << "strength: " << character->GetStrength() << endl;
	cout << "toughness: " << character->GetToughness() << endl;
	cout << "agility: " << character->GetAgility() << endl;
	cout << "inteligence: " << character->GetIntelligence() << endl;
	cout << "wisdom: " << character->GetWisdom() << endl;
	cout << "charisma: " << character->GetCharisma() << endl;
	cout << "gold: " << character->GetGold() << endl;
	cout << "hp: " << character->GetHP() << endl;
	cout << "mana: " << character->GetMana() << endl;
	cout << "name: " << character->GetName() << endl;
	cout << "profession: " << character->GetProfession() << endl << endl;
	system("pause");

}

void MonsterComposite::showEnemystats(Monster * monster)
{
	system("cls");
	cout << "strength: " << monster->GetStrength() << endl;
	cout << "toughness: " << monster->GetToughness() << endl;
	cout << "agility: " << monster->GetAgility() << endl;
	cout << "inteligence: " << monster->GetIntelligence() << endl;
	cout << "wisdom: " << monster->GetWisdom() << endl;
	cout << "charisma: " << monster->GetCharisma() << endl;
	cout << "gold: " << monster->GetGold() << endl;
	cout << "hp: " << monster->GetHP() << endl;
	cout << "mana: " << monster->GetMana() << endl;
	cout << "name: " << monster->GetName() << endl;
	cout << "profession: " << monster->GetProfession() << endl;
	cout << "outlook: " << monster->GetDescription() << endl << endl;
	system("pause");
}

int MonsterComposite::fightMenu(Monster * monster)
{
	system("cls");
	cout << "===============================================================================" << endl;
	cout << "Welcome to fight menu." << endl;
	cout << "You are fighting with " << monster->GetName() << endl;
	cout << "Chose option: " << endl;
	cout << "===============================================================================" << endl;
	drawMap();
	cout << "1.Move" << endl;
	cout << "2.Range attack" << endl;
	cout << "3.Meele attack" << endl;
	int choice1 = choice(3);
	return choice1;
	system("cls");
}

bool MonsterComposite::checkArea()
{
	int charx = this->charCoordinates[0];
	int chary = this->charCoordinates[1];
	int monx = this->monsterCoordinates[0];
	int mony = this->monsterCoordinates[1];


	if (((charCoordinates[0] - monsterCoordinates[0])*(charCoordinates[0] - monsterCoordinates[0]) + (charCoordinates[1] - monsterCoordinates[1])*(charCoordinates[1] - monsterCoordinates[1])) <= 2) {
		return true;
	}
	else return false;
}

void MonsterComposite::monsterTurn(Monster *monster, Character *character) {
	cout << endl << "MONSTERS TURN" << endl;
	srand((unsigned int)time(NULL));
	bool possibility = checkArea();

	if (possibility == false) {
		int rand1 = rand() % 11;
		if (rand1 <= 5) {
			monsterMove();
			cout << "Its possition has been changed";
		}
		if (rand1 > 5) {
			int demage = monster->RangedAttack();
			character->SetHP(character->GetHP() - demage);
			cout << "demage: " << demage << endl;
			cout << "your hp: " << character->GetHP() << endl;

		}
	}
	if (possibility == true) {

		int demage = monster->MeleeAttack();
		character->SetHP(character->GetHP() - demage);
		cout << "demage: " << demage << endl;
		cout << "your hp: " << character->GetHP() << endl;

	}


	system("pause");
}

void MonsterComposite::monsterMove()
{
	srand((unsigned int)time(NULL));
	bool isCorrect;

	do {
		int rand1 = rand() % 10;
		switch (rand1) {

		case 1: {
			int rows = this->monsterCoordinates[0] + 1;
			int column = this->monsterCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}

		case 2: {
			int rows = this->monsterCoordinates[0] + 1;
			int column = this->monsterCoordinates[1];

			bool checkIn = check(rows, column);

			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 3: {
			int rows = this->monsterCoordinates[0] + 1;
			int column = this->monsterCoordinates[1] + 1;

			bool checkIn = check(rows, column);

			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 4: {
			int rows = this->monsterCoordinates[0];
			int column = this->monsterCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 6: {
			int rows = this->monsterCoordinates[0];
			int column = this->monsterCoordinates[1] + 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 7: {
			int rows = this->monsterCoordinates[0] - 1;
			int column = this->monsterCoordinates[1] - 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 8: {
			int rows = this->monsterCoordinates[0] - 1;
			int column = this->monsterCoordinates[1];

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		case 9: {
			int rows = this->monsterCoordinates[0] - 1;
			int column = this->monsterCoordinates[1] + 1;

			bool checkIn = check(rows, column);
			if (checkIn == false) {
				isCorrect = false;

			}
			else {
				this->monsterCoordinates[0] = rows;
				this->monsterCoordinates[1] = column;
				isCorrect = true;

			}
			break;
		}
		default:
			isCorrect = false;
			break;

		}


	} while (!isCorrect);

}

int MonsterComposite::atackFunction()
{
	int distance;
	distance = ((charCoordinates[0] - monsterCoordinates[0])*(charCoordinates[0] - monsterCoordinates[0]) + (charCoordinates[1] - monsterCoordinates[1])*(charCoordinates[1] - monsterCoordinates[1]));
	if (distance >= 4 && distance <= 8) {
		return 1;                    //100% of rangeattack
	}
	if (distance >= 25) {
		return 2;                    //50% of rangeAttack
	}
	if (distance > 8 && distance < 25) {
		return 3;                     //75% of range Attack
	}
}

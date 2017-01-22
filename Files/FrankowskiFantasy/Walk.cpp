#include"stdafx.h"
#include "Walk.h"
#include "Map.h"
#include <conio.h>

using namespace std;

void Walk::MoveCharacter(Character* character) {

	//cout << Map::GetInstance()->GetMap(3, 1)->GetX() << Map::GetInstance()->GetMap(3, 1)->GetY();
	//Map::GetInstance()->Show(character);


	int CurrentLocationX = (character->GetCurrentLocation())->GetX();
	int CurrentLocationY = (character->GetCurrentLocation())->GetY();
	//int MaxLoxation = Map::GetInstance()->GetSize();

	cout << "N - " << EndMap(character, 0, 1);
	cout << "\t" << Permission(((character->GetCurrentLocation())->GetPermissions())[0]) << endl;
	cout << "E - " << EndMap(character, 1, 0);
	cout << "\t" << Permission(((character->GetCurrentLocation())->GetPermissions())[1]) << endl;
	cout << "S - " << EndMap(character, 0, -1);
	cout << "\t" << Permission(((character->GetCurrentLocation())->GetPermissions())[2]) << endl;
	cout << "W - " << EndMap(character, -1, 0);
	cout << "\t" << Permission(((character->GetCurrentLocation())->GetPermissions())[3]) << endl;

	char choice;
	do {
		while (1) {
			if (choice = _getch()) {
				//choice = _getch();
				break;
			}
		}

		choice = toupper(choice);
		if (choice == 'W') {
			if (((character->GetCurrentLocation())->GetPermissions())[0])
			{
				character->SetCurrentLocation(Map::GetInstance()->GetMap(CurrentLocationX, CurrentLocationY + 1));
				(character->GetCurrentLocation())->SetPermissionTrue(2);
			}
			else {
				choice = 0;
			}
		}
		else if (choice == 'D') {
			if (((character->GetCurrentLocation())->GetPermissions())[1])
			{
				character->SetCurrentLocation(Map::GetInstance()->GetMap(CurrentLocationX + 1, CurrentLocationY));
				(character->GetCurrentLocation())->SetPermissionTrue(3);
			}
			else {
				choice = 0;
			}
		}
		else if (choice == 'S') {
			if (((character->GetCurrentLocation())->GetPermissions())[2])
			{
				character->SetCurrentLocation(Map::GetInstance()->GetMap(CurrentLocationX, CurrentLocationY - 1));
				(character->GetCurrentLocation())->SetPermissionTrue(0);
			}
			else {
				choice = 0;
			}

		}
		else if (choice == 'A') {
			if (((character->GetCurrentLocation())->GetPermissions())[3])
			{
				character->SetCurrentLocation(Map::GetInstance()->GetMap(CurrentLocationX - 1, CurrentLocationY));
				(character->GetCurrentLocation())->SetPermissionTrue(1);
			}
			else {
				choice = 0;
			}

		}
		//else cout << endl;
	} while (choice != 'A' && choice != 'S' &&choice != 'W' &&choice != 'D');
	character->GetCurrentLocation()->RunLocation(character);
	//cout<<(character->GetCurrentLocation()->GetName()) << endl;
}

std::string Walk::Permission(bool permission) {
	if (permission == 0) return " ->NOPE";
	else return "";
}

std::string Walk::EndMap(Character* character, int a, int b) {
	int CurrentLocationX = (character->GetCurrentLocation())->GetX();
	int CurrentLocationY = (character->GetCurrentLocation())->GetY();
	int MaxLocationX = Map::GetInstance()->GetSizeX();
	int MaxLocationY = Map::GetInstance()->GetSizeY();
	if (CurrentLocationX + a < 0 || CurrentLocationX + a > MaxLocationX - 1 || CurrentLocationY + b < 0 || CurrentLocationY + b > MaxLocationY - 1) {
		return "The end of the map!";
	}
	else {
		return (Map::GetInstance()->GetMap(CurrentLocationX + a, CurrentLocationY + b))->GetName();
	}
}

std::string Walk::CompassRose(int line) {
	int size = 5;
	string *compass = new string[size];
	compass[0] = "     (N)\n";
	compass[1] = "     /\\ \n";
	compass[2] = "(W) <  > (E)\n";
	compass[3] = "     \\/ \n";
	compass[4] = "     (S)\n";
	if (line < size) return compass[line];
	else return "";
}
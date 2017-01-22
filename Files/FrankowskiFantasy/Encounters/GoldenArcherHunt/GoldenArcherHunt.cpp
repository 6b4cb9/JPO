#include"GoldenArcherHunt.h"

GoldenArcherHunt::GoldenArcherHunt() {
	GenerateBoard();
}

void ClearBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ReadInputInt() {
	int input;
	while (!(std::cin >> input)) {
		std::cout << "Enter a number" << std::endl;
		ClearBuffer();
	}
	ClearBuffer();
	return input;
}
void GoldenArcherHunt::Proceed(Character * Adventurer) {
	int huntExit = 0;
	system("cls");
	std::cout << "Instructions" << std::endl
		<< "Your goal is to catch the golden archer. On your turn you can either move or destroy adjacent wall. If you try to move and there is wall blocking your path"
		<< " you will move as much as possible. If you enter incorrect direction you will waste your moves."
		<< " The amount of fields you can move depends on your agility. You can move only left, right, up and down. The archer will"
		<< " shoot at you if it is in the same row or column and within certain distance, which depends on your charisma. If you are shot, you lose hp."
		<< " You win and receive gold when you move to archer's position. The archer can jump over walls. Press any key to continue" << std::endl;
	getch();
	while (!huntExit) {
		system("cls");
		DisplayBoard();
		DisplayMenu();
		std::cout << Adventurer->GetHp() << std::endl;
		int decision;
		do {
			decision = ReadInputInt();
			if (decision > 1 || decision < 0) std::cout << "Enter correct number" << std::endl;
		} while (decision > 1 || decision < 0);
		switch (decision) {
		case 0:
			huntExit = MovePlayer(Adventurer);
			if (huntExit) return;
			break;
		case 1:
			DestroyWall();
			break;
		}
		huntExit = CPUMove(Adventurer);
		if (huntExit) return;
	}
}

void GoldenArcherHunt::GenerateBoard() {
	//Fill board with 0
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = 0;
		}
	}
	int walls = 0;
	int length, x, y;
	//Fill board with around 125 walls
	while (walls < 125) {
		length = std::rand() % 5 + 1;
		x = std::rand() % (16 - length);
		y = std::rand() % (16 - length);
		for (int i = 0; i < length; i++) {
			board[x + i][y] = 1;
		}
		walls += length;
	}
	//Place player
	playerPositionX = 0;
	playerPositionY = 0;
	board[playerPositionX][playerPositionY] = 3;
	//Place golden archer
	goldenArcherPositionX = 14;
	goldenArcherPositionY = 14;
	board[goldenArcherPositionX][goldenArcherPositionY] = 2;
}

void GoldenArcherHunt::DisplayBoard() {
	system("cli");
	std::cout << "--------------------------------" << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cout << "|";
		for (int j = 0; j < 15; j++) {
			switch (board[i][j]) {
			case 0:
				std::cout << "  ";
				break;
			case 1:
				std::cout << "w ";
				break;
			case 2:
				std::cout << "g ";
				break;
			case 3:
				std::cout << "p ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

void GoldenArcherHunt::DisplayMenu() {
	std::cout << "[0] Move" << std::endl;
	std::cout << "[1] Destroy wall" << std::endl;
}

int GoldenArcherHunt::MovePlayer(Character * Player) {
	maxMove = Player->GetAgility() / 5;
	int movesLeft = maxMove;
	while (movesLeft > 0) {
		system("cls");
		DisplayBoard();
		std::cout << "Moves left: " << movesLeft << std::endl;
		std::cout << "Choose direction" << std::endl;
		std::cout << "[2] DOWN" << std::endl
			<< "[4] LEFT" << std::endl
			<< "[6] RIGHT" << std::endl
			<< "[8] UP" << std::endl;
		int direction, length;
		direction = ReadInputInt();
		std::cout << "Choose length of move" << std::endl;
		length = ReadInputInt();
		int newPlayerPositionX = playerPositionX, newPlayerPositionY = playerPositionY;
		if (length > Player->GetAgility() / 5) length = Player->GetAgility() / 5;
		if (length > movesLeft) length = movesLeft;
		while (length > 0) {
			switch (direction) {
			case 2:
				newPlayerPositionX++;
				break;
			case 4:
				newPlayerPositionY--;
				break;
			case 6:
				newPlayerPositionY++;
				break;
			case 8:
				newPlayerPositionX--;
				break;
			}
			movesLeft--;
			if (board[newPlayerPositionX][newPlayerPositionY] == 0) {
				board[playerPositionX][playerPositionY] = 0;
				board[newPlayerPositionX][newPlayerPositionY] = 3;
				playerPositionX = newPlayerPositionX;
				playerPositionY = newPlayerPositionY;
			}
			else if (board[newPlayerPositionX][newPlayerPositionY] == 2) {
				std::cout << "You won" << std::endl;
				Player->SetGold(Player->GetGold() + 70);
				return 1;
			}
			else break;
			length--;
		}
	}
	return 0;
}

int GoldenArcherHunt::MoveGoldenArcher(int direction, int length) {
	int newGoldenArcherPositionX = goldenArcherPositionX, newGoldenArcherPositionY = goldenArcherPositionY, moveSuccess = 0;
	while (length > 0) {
		switch (direction) {
		case 2:
			newGoldenArcherPositionX++;
			break;
		case 4:
			newGoldenArcherPositionY--;
			break;
		case 6:
			newGoldenArcherPositionY++;
			break;
		case 8:
			newGoldenArcherPositionX--;
			break;
		}
		if (board[newGoldenArcherPositionX][newGoldenArcherPositionY] == 0) {
			board[goldenArcherPositionX][goldenArcherPositionY] = 0;
			board[newGoldenArcherPositionX][newGoldenArcherPositionY] = 2;
			goldenArcherPositionX = newGoldenArcherPositionX;
			goldenArcherPositionY = newGoldenArcherPositionY;
			moveSuccess = 1;
		}
		length--;
	}
	return moveSuccess;
}

void GoldenArcherHunt::DestroyWall() {
	std::cout << "Choose direction" << std::endl;
	std::cout << "[2] DOWN" << std::endl
		<< "[4] LEFT" << std::endl
		<< "[6] RIGHT" << std::endl
		<< "[8] UP" << std::endl;
	int direction;
	direction = ReadInputInt();
	switch (direction) {
	case 2:
		board[playerPositionX + 1][playerPositionY] = 0;
		break;
	case 4:
		board[playerPositionX][playerPositionY - 1] = 0;
		break;
	case 6:
		board[playerPositionX][playerPositionY + 1] = 0;
		break;
	case 8:
		board[playerPositionX - 1][playerPositionY] = 0;
		break;
	default:
		break;
	}
}

int GoldenArcherHunt::CPUMove(Character * Player) {
	int direction = 8, distance = 14;
	int distanceXFromPlayer = std::abs(playerPositionX - goldenArcherPositionX);
	int distanceYFromPlayer = std::abs(playerPositionY - goldenArcherPositionY);
	if ((distanceXFromPlayer == 0 && distanceYFromPlayer < 7) || (distanceYFromPlayer == 0 && distanceXFromPlayer < 7)) {
		if (Player->GetToughness() <= 15) {
			Player->SetHp(Player->GetHp() - (20 - Player->GetToughness()));
		}
		else {
			Player->SetHp(Player->GetHp() - 5);
		}
		direction = 0;
		if (Player->GetHp() <= 0) {
			std::cout << "You have been killed" << std::endl;
			return 1;
		}
	}
	else if ((distanceYFromPlayer < distanceXFromPlayer && distanceYFromPlayer != 0) || (distanceXFromPlayer < distanceYFromPlayer && distanceXFromPlayer == 0)) {
		distance = distanceYFromPlayer;
		if (playerPositionY > goldenArcherPositionY) {
			direction = 6;
		}
		else if (playerPositionY < goldenArcherPositionY) {
			direction = 4;
		}
	}
	else if ((distanceXFromPlayer < distanceYFromPlayer && distanceXFromPlayer != 0) || (distanceYFromPlayer < distanceXFromPlayer && distanceYFromPlayer == 0)) {
		distance = distanceXFromPlayer;
		if (playerPositionX > goldenArcherPositionX) {
			direction = 2;
		}
		else if (playerPositionX < goldenArcherPositionX) {
			direction = 8;
		}
	}
	int moveSuccess;
	if (direction != 0) {
		if (distance > 1) {
			moveSuccess = MoveGoldenArcher(direction, 2);
		}
		else {
			moveSuccess = MoveGoldenArcher(direction, 1);
		}
		if (!moveSuccess) {
			switch (direction) {
			case 2:
				board[goldenArcherPositionX + 1][goldenArcherPositionY] = 0;
				break;
			case 4:
				board[goldenArcherPositionX][goldenArcherPositionY - 1] = 0;
				break;
			case 6:
				board[goldenArcherPositionX][goldenArcherPositionY + 1] = 0;
				break;
			case 8:
				board[goldenArcherPositionX - 1][goldenArcherPositionY] = 0;
				break;
			default:
				break;
			}
		}
	}
	return 0;
}
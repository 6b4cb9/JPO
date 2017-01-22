#include "stdafx.h"
#include "ElementTicTacToe.h"

int ElementTicTacToe::gameInstance(int intelligence)
{
	char board[3][3] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
	bool playGame = true;
	int currentPlayer;

	if (intelligence > 10)
	{
		currentPlayer = 1;
		std::cout << "The goblin has deemed you worthy of the first move.\n";
	}
	else {
		currentPlayer = 2;
		std::cout << "The goblin has deemed you not worthy of the first move.\n";
	}
	
	int nextPos;
	int GAMEENDFLAG = 0;

	while (playGame) {
		int tmpFlag = -1;
		
		
		while (tmpFlag == -1) {
			if (currentPlayer == 1) {
				printBoard(board);
				//char nextPosCharBuffer[10];
				std::string nextPosCharBuffer;
				char nextPosChar[1];
				std::cout << "It's your turn. What's your move?\n";
				std::cin >> nextPosCharBuffer;
				if ((nextPosCharBuffer[0] > 48) && (nextPosCharBuffer[0] < 58)) {
					nextPosChar[0] = nextPosCharBuffer[0];
					nextPos = atoi(nextPosChar);
					tmpFlag = verifyMove(nextPos, board, playGame, GAMEENDFLAG, currentPlayer);
				}
				else std::cout << "\nInvalid input!\n";
				
			}
			else {
				nextPos = (rand() % 9) + 1;
				tmpFlag = verifyMove(nextPos, board, playGame, GAMEENDFLAG, currentPlayer);
			}
		}
	}

	return GAMEENDFLAG;
}

void ElementTicTacToe::printBoard(char (&board)[3][3])
{
	std::cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << board[i][j];
			if (j < 2) std::cout << " | ";
		}
		if (i < 2) std::cout << "\n- + - + -\n";
	}
	std::cout << "\n\n";
}

void ElementTicTacToe::checkBoard(char (&board)[3][3], bool &playGame, int &GAMEENDFLAG)
{
	// left column and top row check
	if (board[0][0] != '1') {
		if ((board[0][0] == board[0][1]) && (board[0][0] == board[0][2])) {
			playGame = false;
		}
		if ((board[0][0] == board[1][0]) && (board[0][0] == board[2][0])) {
			playGame = false;
		}
	}

	// double xross check	
	if (board[1][1] != '5') {
		if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
			playGame = false;
		}
		if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
			playGame = false;
		}
		if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) {
			playGame = false;
		}
		if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])) {
			playGame = false;
		}
	}

	// right column and bottom row check
	if (board[2][2] != '9') {
		if ((board[2][0] == board[2][2]) && (board[2][2] == board[2][1])) {
			playGame = false;
		}
		if ((board[0][2] == board[2][2]) && (board[2][2] == board[1][2])) {
			playGame = false;
		}
	}

	int counter = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] > 57)
				counter++;
		}
	}

	if (counter == 9) {
		playGame = false;
		GAMEENDFLAG = -1;
	}
}

int ElementTicTacToe::verifyMove(int move, char(&board)[3][3], bool &playGame, int &GAMEENDFLAG, int &currentPlayer)
{
	if (currentPlayer == 1) {
		if ((board[move / 3][move % 3 - 1]) != 'o' && (board[move / 3][move % 3 - 1]) != 'x') {
			board[move / 3][move % 3 - 1] = 'o';
			currentPlayer = 2;
			checkBoard(board, playGame, GAMEENDFLAG);
			if (!playGame) {
				printBoard(board);
				//std::cout << "Player one has won!\n";
				if (GAMEENDFLAG != -1) {
					GAMEENDFLAG = 1;
				}
			}
			return 1;
		}
		else std::cout << "Invalid move!\n";
		return -1;
	}
	else {
		if ((board[move / 3][move % 3 - 1]) != 'o' && (board[move / 3][move % 3 - 1]) != 'x') {
			board[move / 3][move % 3 - 1] = 'x';
			currentPlayer = 1;
			checkBoard(board, playGame, GAMEENDFLAG);
			if (!playGame) {
				printBoard(board);
				//std::cout << "Player two has won!\n";
				if (GAMEENDFLAG != -1) {
					GAMEENDFLAG = 2;
				}
			}
			return 1;
		}
		else //std::cout << "Invalid move!\n";
		return -1;
	}
	return 1;
}

ElementTicTacToe::ElementTicTacToe()
{
}


ElementTicTacToe::~ElementTicTacToe()
{
}

bool ElementTicTacToe::Proceed(Character * Adventurer)
{
	std::cout << "Wandering through the forest you encounter a goblin. He challenges you to play a game of ancients sages.\n\n";
	std::cout << "If you win you will win a magic amulet. Will you accept the challenge [y/n]?\n";

	std::string tmpIn;
	std::cin >> tmpIn;

	std::cout << "\n";

	if (tmpIn[0] == 'y') {
		int tmp = -1;
		while (tmp == -1) {

			tmp = gameInstance(Adventurer->GetIntelligence());

			switch (tmp) {
			case -1:
				std::cout << "It was a tie! Do you want to rechallenge the goblin? [y/n]\n";
				char tmpIn;
				std::cin >> tmpIn;
				if (tmpIn != 'y') tmp = 0;
				break;
			case 1:
				std::cout << Adventurer->GetName() << " has won!\n";
				Adventurer->SetIntelligence(Adventurer->GetIntelligence() + 2);
				std::cout << "Magical amulet has incresed your intelligence to " << Adventurer->GetIntelligence() << "\n";
				break;
			case 2:
				std::cout << "Goblin has won! Laughing nastily he dissapears in a cloud of smoke.\n ";
				break;
			default:
				break;
			}
		}
	}

	std::cout << "\nYou walk away and continue your journey.\n";
	return true;
}

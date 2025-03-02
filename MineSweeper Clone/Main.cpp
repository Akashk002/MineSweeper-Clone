#include "Game.h"
#include <iostream>
using namespace std;

enum levelDifficulty
{
	EASY = 1,
	MEDIUM,
	HARD
};

void chooseDifficulty(int& side, int& mines)
{
	int level;
	cout << "Choose Difficulty Level:" << endl;
	cout << "1. EASY (9x9 Cells and 10 Mines)" << endl;
	cout << "2. MEDIUM (16x16 Cells and 40 Mines)" << endl;
	cout << "3. HARD (24x24 Cells and 99 Mines)" << endl;
	cin >> level;

	if (level == EASY)
	{
		side = 9;
		mines = 10;
	}
	else if (level == MEDIUM)
	{
		side = 16;
		mines = 40;
	}
	else if (level == HARD)
	{
		side = 24;
		mines = 99;
	}
	else
	{
		cout << "Invalid choice. Defaulting to EASY." << endl;
		side = 9;
		mines = 10;
	}
}
void displayMessage()
{
	cout << "==============================================================================" << endl;
	cout << "                            Welcome to Minesweeper!                           " << endl;
	cout << "==============================================================================" << endl;
	cout << "   Rules of the Game:" << endl;
	cout << "1. The board is a grid of hidden cells. Some cells contain mines!" << endl;
	cout << "2. Your goal is to reveal all the cells that do not contain mines." << endl;
	cout << "3. If you reveal a cell with a mine, the game is over." << endl;
	cout << "4. Numbers on revealed cells indicate how many mines are adjacent to that cell." << endl;
	cout << "5. Use logic to determine where the mines are and avoid them!" << endl;
	cout << "6. You can flag cells where you suspect there’s a mine." << endl;
	cout << endl;
	cout << "Good luck, and may your moves be safe!" << endl;
	cout << "==============================================================================" << endl << endl;
}

int main()
{
	int side, mines;
	displayMessage();
	chooseDifficulty(side, mines);
	Game game(side, mines);
	game.start();
	return 0;
}
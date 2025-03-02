#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Board::Board(int side, int mines) : side(side), mines(mines)
{
	initializeBoard();
}
void Board::initializeBoard()
{
	grid.resize(side, vector<Cell>(side));

	srand(time(0));
	int placedMines = 0;

	while (placedMines < mines)
	{
		int row = rand() % side;
		int col = rand() % side;

		if (!grid[row][col].hasMine())
		{
			grid[row][col].setMine(true);
			placedMines++;
		}
	}

	calculateAdjacentCells();
}
void Board::calculateAdjacentCells()
{
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			if (grid[i][j].hasMine())
				continue;

			int mine_count = 0;

			for (int row = i - 1; row <= i + 1; row++)
			{
				for (int col = j - 1; col <= j + 1; col++)
				{
					if (row >= 0 && row < side && col >= 0 && col < side)
					{
						if (grid[row][col].hasMine())
							mine_count++;
					}
				}
			}

			grid[i][j].setAdjacentMines(mine_count);
		}
	}
}
void Board::displayBoard(bool debugMode)
{
	cout << "     ";
	for (int i = 0; i < side; i++)
	{
		cout << setw(2) << setfill('0') << i << " ";
	}
	cout << "\n\n";

	for (int i = 0; i < side; i++)
	{
		cout << setw(2) << setfill('0') << i << "  |";
		for (int j = 0; j < side; j++)
		{
			if (debugMode)
				grid[i][j].debugPrint();
			else
				grid[i][j].display();
		}
		cout << endl;

		if (side == 9)
			cout << "    ----------------------------";
		else if (side == 16)
			cout << "    -------------------------------------------------";
		else if (side == 24)
			cout << "    -------------------------------------------------------------------------";

		cout << endl;
	}
}
void Board::displaySettings()
{
	cout << "=====================================" << endl;

	cout << "Grid Size: " << side << "x" << side << endl;
	cout << "Number of Mines: " << mines << endl;

	cout << "=====================================" << endl << endl;
}
int Board::getSide()
{
	return side;
}
int Board::getMines()
{
	return mines;
}
Cell& Board::getCell(int row, int col)
{
	return grid[row][col];
}
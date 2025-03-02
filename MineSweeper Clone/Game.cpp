#include "Game.h"
#include <iostream>

Game::Game(int side, int mines)
{
	board = new Board(side, mines);
}
Game::~Game()
{
	delete board;
}
void Game::revealCell(int row, int col)
{
	if (row < 0 || row >= board->getSide() || col < 0 || col >= board->getSide())
	{
		cout << "Invalid Coordinates." << endl;
		return;
	}

	Cell& cell = board->getCell(row, col);
	if (cell.isOpen())
	{
		cout << " Cell already revealed. " << endl;
		return;
	}

	cell.revealCell(true);

	if (cell.hasMine())
	{
		cout << "\n=====================================" << endl;
		cout << "       OH NO! YOU HIT A MINE :(    " << endl;
		cout << "=====================================\n" << endl;
		board->displayBoard(true);
		gameLostDisplay();
		return;
	}

	if (cell.getAdjacentMines() == 0)
	{
		revealAdjacentCells(row, col);
	}

	checkWinCondition();
}
void Game::revealAdjacentCells(int row, int col)
{
	for (int r = row - 1; r <= row + 1; r++)
	{
		for (int c = col - 1; c <= col + 1; c++)
		{
			if (r >= 0 && r < board->getSide() && c >= 0 && c < board->getSide())
			{
				Cell& adjacentCell = board->getCell(r, c);
				if (!adjacentCell.isOpen() && !adjacentCell.hasMine())
				{
					revealCell(r, c);
				}
			}
		}
	}
}
void Game::checkWinCondition()
{
	int revealedCells = 0;
	int totalCells = board->getSide() * board->getSide();

	for (int i = 0; i < board->getSide(); i++)
	{
		for (int j = 0; j < board->getSide(); j++)
		{
			if (board->getCell(i, j).isOpen())
			{
				revealedCells++;
			}
		}
	}

	if (revealedCells == (totalCells - board->getMines()))
	{
		board->displayBoard(true);
		gameWinDisplay();
	}
}
void Game::gameWinDisplay()
{
	cout << "\n\n==============================================================================" << endl;
	cout << "                               Y O U   W I N !                                " << endl;
	cout << "==============================================================================" << endl;
	cout << " Congratulations! You've successfully revealed all the safe cells!" << endl;
	cout << " You avoided all the mines like a true Minesweeper Master!" << endl;
	cout << "==============================================================================" << endl;
	cout << "                                  Play Again Soon!          " << endl;
	cout << "==============================================================================" << endl;
}
void Game::gameLostDisplay()
{
	cout << "==============================================================================" << endl;
	cout << "                              G A M E   O V E R                           " << endl;
	cout << "==============================================================================" << endl;
	cout << "  Oh no! You stepped on a mine and lost the game." << endl;
	cout << " Better luck next time, Minesweeper Warrior!" << endl;
	cout << "==============================================================================" << endl;
	cout << "                              Try Again to Win!                           " << endl;
	cout << "==============================================================================" << endl;
}
void Game::start()
{
	board->displaySettings();
	board->displayBoard();

	int row, col;
	while (true)
	{
		cout << "Enter row and column to reveal (e.g., 0 0): ";
		cin >> row >> col;

		revealCell(row, col);
		if (board->getCell(row, col).hasMine())
			break;
		board->displayBoard();
	}
}
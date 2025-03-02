#pragma once
#include <vector>
#include "Cell.h"

class Board {
private:
	int side;
	int mines;
	std::vector<std::vector<Cell>> grid;
	void calculateAdjacentCells();

public:
	Board(int side, int mines);
	void initializeBoard();
	void displayBoard(bool debugMode = false);
	void displaySettings();
	int getSide();
	int getMines();
	Cell& getCell(int row, int col);
};

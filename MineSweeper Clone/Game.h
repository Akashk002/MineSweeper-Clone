
#include "Board.h"

class Game {
private:
	Board* board;
	void revealAdjacentCells(int row, int col);
	void checkWinCondition();
	void gameWinDisplay();
	void gameLostDisplay();

public:
	Game(int side, int mines);
	~Game();
	void revealCell(int row, int col);
	void start();
};
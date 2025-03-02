#pragma once
#include <iostream>
using namespace std;

class Cell {
private:
	bool isMine;
	bool isRevealed;
	int adjacentMines;

public:
	Cell();
	bool hasMine();
	void setMine(bool mine);
	bool isOpen();
	void revealCell(bool revealed);
	int getAdjacentMines();
	void setAdjacentMines(int count);
	void debugPrint();
	void display();
};
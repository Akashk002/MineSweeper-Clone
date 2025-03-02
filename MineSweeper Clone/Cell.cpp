#include "Cell.h"
#include <string>
using namespace std;

Cell::Cell() : isMine(false), isRevealed(false), adjacentMines(0)
{

}
bool Cell::hasMine()
{
	return isMine;
}
void Cell::setMine(bool mine)
{
	isMine = mine;
}
bool Cell::isOpen()
{
	return isRevealed;
}
void Cell::revealCell(bool revealed)
{
	isRevealed = revealed;
}
int Cell::getAdjacentMines()
{
	return adjacentMines;
}
void Cell::setAdjacentMines(int count)
{
	adjacentMines = count;
}
void Cell::debugPrint()
{
	cout << (isMine ? "*| " : to_string(adjacentMines) + "| ");
}
void Cell::display()
{
	cout << (isRevealed ? (isMine ? " *|" : to_string(adjacentMines) + "| ") : " -|");
}
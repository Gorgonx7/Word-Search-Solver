#include "Cell.h"


Cell::Cell() // default constructor definition
{
	m_Data = 'A';
	m_PuzzleSize = 0;
}


Cell::~Cell() // default destructor
{

}
// assignment opperator
Cell& Cell::operator=(const Cell & rhs)
{
	m_Data = rhs.m_Data;
	m_X = rhs.m_X;
	m_Y = rhs.m_Y;
	m_BottomLeft = rhs.m_BottomLeft;
	m_BottomRight = rhs.m_BottomRight;
	m_TopLeft = rhs.m_TopLeft;
	m_TopRight = rhs.m_TopRight;
	m_Up = rhs.m_Up;
	m_Down = rhs.m_Down;
	m_Left = rhs.m_Left;
	m_Right = rhs.m_Right;
	m_PuzzleSize = rhs.m_PuzzleSize;
	return *this;
}






///Method to search in a specific direction it takes:
// pDirection - a enum for the direction to search in
// pWord - the word to search for, passed by reference
// NumberOfCells - value for the algorithm to increment while searching
bool Cell::SolveInDirection(const Direction pDirection, const std::string &pWord, int &NumberOfCells)
{
	NumberOfCells++; // increment the number of cells accessed
	if (pWord[pWord.size() - 1] == GetData()&& pWord.size() == 1)  {
		
		return true; //if last character is equal to the current data and the size of the word is 1 the word has been found
	}
	const char holder = GetData(); // get the current cell data value
	//switch the current direction to search in
	switch (pDirection) {

	case Direction::LEFT:
		if (pWord[0] != holder) { // if the starting character of the word is not equal to the current data, then return false
			return false;
		}
		else if (Left() != nullptr) { // else if the cell in the next direction is not null
			if (!Left()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) { // recourse into that cell until it returns true or false
				return false; // if it returns false the word has not been found
			}
		}
		else {
			return false; // if the next cell is null return false
		}
		break;
	case Direction::RIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Right() != nullptr) {
			if (!Right()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::DOWN:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Down() != nullptr) {
			if (!Down()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::UP:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Up() != nullptr) {
			if (!Up()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells))
			{
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::TOPLEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (TopLeft() != nullptr) {
			if (!TopLeft()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::TOPRIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (TopRight() != nullptr) {
			if (!TopRight()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::BOTTOMLEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (BottomLeft() != nullptr) {
			if (!BottomLeft()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case Direction::BOTTOMRIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (BottomRight() != nullptr) {
			if (!BottomRight()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
		}
		break;

	}

	return true; // if the algorithm has not returned false the word must have been found so return true
}
#include "Cell.h"


Cell::Cell()
{
	m_Data = 'A';
	m_PuzzleSize = 0;
}


Cell::~Cell()
{

}

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







bool Cell::SolveInDirection(const Direction pDirection, const std::string &pWord, int &NumberOfCells)
{
	NumberOfCells++;
	if (pWord[pWord.size() - 1] == GetData()&& pWord.size() == 1)  {
		
		return true;
	}
	const char holder = GetData();

	switch (pDirection) {

	case Direction::LEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Left() != nullptr) {
			if (!Left()->SolveInDirection(pDirection, pWord.substr(1), NumberOfCells)) {
				return false;
			}
		}
		else {
			return false;
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

	return true;
}
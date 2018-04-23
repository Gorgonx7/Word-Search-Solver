#include "Cell.h"


Cell::Cell()
{
}


Cell::~Cell()
{

}

Cell Cell::operator=(const Cell & rhs)
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
	return *this;
}

// This method checks all the cells finds a direction and then trys to solve in that direction
bool Cell::Solve(const std::string &pWord)
{
	
	
		if (SolveInDirection(LEFT, pWord) || SolveInDirection(RIGHT, pWord) || SolveInDirection(DOWN, pWord) || SolveInDirection(UP, pWord) || SolveInDirection(TOPLEFT, pWord) || SolveInDirection(TOPRIGHT, pWord) || SolveInDirection(BOTTOMLEFT, pWord) || SolveInDirection(BOTTOMRIGHT, pWord)) {
			return true;
		}
	
	return false;
}





bool Cell::SolveInDirection(const Direction pDirection, const std::string &pWord)
{
	if (pWord[pWord.size() - 1] == GetData()&& pWord.size() == 1)  {
		
		return true;
	}
	const char holder = GetData();

	switch (pDirection) {

	case LEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Left() != nullptr) {
			if (!Left()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case RIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Right() != nullptr) {
			if (!Right()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case DOWN:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Down() != nullptr) {
			if (!Down()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case UP:
		if (pWord[0] != holder) {
			return false;
		}
		else if (Up() != nullptr) {
			if (!Up()->SolveInDirection(pDirection, pWord.substr(1))) 
			{
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case TOPLEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (TopLeft() != nullptr) {
			if (!TopLeft()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case TOPRIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (TopRight() != nullptr) {
			if (!TopRight()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case BOTTOMLEFT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (BottomLeft() != nullptr) {
			if (!BottomLeft()->SolveInDirection(pDirection, pWord.substr(1))) {
				return false;
			}
		}
		else {
			return false;
		}
		break;
	case BOTTOMRIGHT:
		if (pWord[0] != holder) {
			return false;
		}
		else if (BottomRight() != nullptr) {
			if (!BottomRight()->SolveInDirection(pDirection, pWord.substr(1))) {
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
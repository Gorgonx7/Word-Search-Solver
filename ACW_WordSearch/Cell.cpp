#include "Cell.h"

Cell* m_Right;
char m_Data;
enum Direction{
	LEFT, RIGHT, UP, DOWN, TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT
};

Cell::Cell()
{
}


Cell::~Cell()
{

}

Cell Cell::operator=(const Cell & rhs)
{
	m_Data = rhs.m_Data;
	return *this;
}

// This method checks all the cells finds a direction and then trys to solve in that direction
bool Cell::Solve(std::string pWord)
{
	
	return false;
}





 bool Cell::SolveInDirection(const Direction pDirection, std::string pWord)
 {
	 switch (pDirection) {
	 
	 case LEFT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!Left()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case RIGHT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!Right()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case DOWN:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (Down()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case UP:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!Up()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case TOPLEFT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!TopLeft()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case TOPRIGHT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!TopRight()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case BOTTOMLEFT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!BottomLeft()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
	 case BOTTOMRIGHT:
		 if (pWord[0] != GetData()) {
			 return false;
		 }
		 else if (!BottomRight()->SolveInDirection(pDirection, pWord.substr(1))) {
			 return false;
		 }
		 break;
		 
	 }
	 
	 return true;
 }
 
 
 //Getters and Setters -----------------------------------------------------------------------------------------------------------------------------------------------------------------
void Cell::SetData(char & Data)
{
	m_Data = Data;
}

 char const Cell::GetData()
{
	return m_Data;
}
 inline void Cell::SetRight(Cell * pCell)
 {
	 m_Right = pCell;
 }

 inline void Cell::SetLeft(Cell * pCell)
 {
	 m_Left = pCell;
 }

 inline void Cell::SetTopLeft(Cell * pCell)
 {
	 m_TopLeft = pCell;
 }

 inline void Cell::SetUp(Cell * pCell)
 {
	 m_Up = pCell;
 }

 inline void Cell::SetDown(Cell * pCell)
 {
	 m_Down = pCell;
 }

 inline void Cell::SetTopRight(Cell * pCell)
 {
	 m_TopRight = pCell;
 }

 inline void Cell::SetBottomLeft(Cell * pCell)
 {
	 m_BottomLeft = pCell;
 }

 void Cell::SetBottomRight(Cell * pCell)
 {
	 m_BottomRight = pCell;
 }

 inline Cell * Cell::Left()
 {
	 return m_Left;
 }
 inline Cell * Cell::Right()
 {
	return m_Right;
 }
 inline Cell * Cell::Up()
 {
	 return m_Right;
 }

 inline Cell * Cell::Down()
 {
	 return m_Down;
 }

 inline Cell * Cell::TopLeft()
 {
	 return m_TopLeft;
 }

 inline Cell * Cell::TopRight()
 {
	 return m_TopRight;
 }

 inline Cell * Cell::BottomLeft()
 {
	 return m_BottomLeft;
 }

 inline Cell * Cell::BottomRight()
 {
	 return m_BottomRight;
 }

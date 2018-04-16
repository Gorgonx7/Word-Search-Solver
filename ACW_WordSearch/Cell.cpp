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

bool Cell::Solve(std::string pWord)
{

	return false;
}

Cell * Cell::Right()
{
	return m_Right;
}

void Cell::SetData(char & Data)
{
	m_Data = Data;
}

 char const Cell::GetData()
{
	return m_Data;
}

 bool Cell::SolveInDirection(Direction pDirection, std::string pWord)
 {
	 switch (pDirection) {
	 
	 case LEFT:
		 if (pWord[0] != Left()->GetData()) {
			 return false;
		 }
		 else if (Left()->SolveInDirection(pDirection, pWord.substr(1))) {

		 }
		 break;
	 case RIGHT:
		 if (pWord[0] != Right()->GetData())
			 return false;
		 break;
	 case DOWN:
		 if (pWord[0] != Down()->GetData())
			 return false;
		 break;
	 case UP:
		 if (pWord[0] != Up()->GetData())
			 return false;
		 break;
	 case TOPLEFT:
		 if (pWord[0] != TopLeft()->GetData())
			 return false;
		 break;
	 case TOPRIGHT:
		 if (pWord[0] != TopRight()->GetData())
			 return false;
		 break;
	 case BOTTOMLEFT:
		 if (pWord[0] != BottomLeft()->GetData())
			 return false;
		 break;
	 case BOTTOMRIGHT:
		 if (pWord[0] != BottomRight()->GetData())
			 return false;
		 break;
		 
	 }
	 
	 return true;
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

 inline void Cell::SetUP(Cell * pCell)
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

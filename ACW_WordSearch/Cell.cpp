#include "Cell.h"

Cell* m_Right;
char m_Data;


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
	char Letter = pWord[0];
	if (Letter == m_Data) {
		if(SolveInDirection(LEFT, pWord.substr(1)) || SolveInDirection(RIGHT, pWord.substr(1)) || SolveInDirection(DOWN, pWord.substr(1)) || SolveInDirection(UP, pWord.substr(1)) || SolveInDirection(TOPLEFT, pWord.substr(1)) || SolveInDirection(TOPRIGHT, pWord.substr(1)) || SolveInDirection(BOTTOMLEFT, pWord.substr(1)) || SolveInDirection(BOTTOMRIGHT, pWord.substr(1))){
			return true;
		}
	}
	return false;
}





 bool Cell::SolveInDirection(Direction pDirection, std::string pWord)
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
  void Cell::SetRight(Cell * pCell)
 {
	 m_Right = pCell;
 }

  void Cell::SetLeft(Cell * pCell)
 {
	 m_Left = pCell;
 }

  void Cell::SetTopLeft(Cell * pCell)
 {
	 m_TopLeft = pCell;
 }

  void Cell::SetUp(Cell * pCell)
 {
	 m_Up = pCell;
 }

  void Cell::SetDown(Cell * pCell)
 {
	 m_Down = pCell;
 }

  void Cell::SetTopRight(Cell * pCell)
 {
	 m_TopRight = pCell;
 }

  void Cell::SetBottomLeft(Cell * pCell)
 {
	 m_BottomLeft = pCell;
 }

 void Cell::SetBottomRight(Cell * pCell)
 {
	 m_BottomRight = pCell;
 }

  Cell * Cell::Left()
 {
	 return m_Left;
 }
  Cell * Cell::Right()
 {
	return m_Right;
 }
  Cell * Cell::Up()
 {
	 return m_Right;
 }

  Cell * Cell::Down()
 {
	 return m_Down;
 }

  Cell * Cell::TopLeft()
 {
	 return m_TopLeft;
 }

  Cell * Cell::TopRight()
 {
	 return m_TopRight;
 }

  Cell * Cell::BottomLeft()
 {
	 return m_BottomLeft;
 }

  Cell * Cell::BottomRight()
 {
	 return m_BottomRight;
 }

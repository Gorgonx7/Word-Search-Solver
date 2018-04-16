#pragma once
#include <iostream>
#include <string>
class Cell
{
	
public:
	Cell(const char pCharacter) : m_Data(pCharacter) {};
	Cell();
	~Cell();
	Cell operator=(const Cell &rhs);
	bool Solve(std::string pWord);
	inline void SetRight(Cell* pCell), SetLeft(Cell* pCell), SetUP(Cell* pCell), SetDown(Cell* pCell), SetTopRight(Cell* pCell), SetTopLeft(Cell* pCell), SetBottomRight(Cell* pCell), SetBottomLeft(Cell* pCell);
	

private:
	enum Direction;
	void SetData(char &Data);
    char const GetData();
	char m_Data;
	bool SolveInDirection(Direction pDirection, std::string pWord);
	
	inline Cell* Right();
	inline Cell* Left();
	inline Cell* Up();
	inline Cell* Down();
	inline Cell* TopLeft();
	inline Cell* TopRight();
	inline Cell* BottomLeft();
	inline Cell* BottomRight();
	Cell* m_Right;
	Cell* m_Left;
	Cell* m_Up;
	Cell* m_Down;
	Cell* m_TopLeft;
	Cell* m_TopRight;
	Cell* m_BottomLeft;
	Cell* m_BottomRight;
};


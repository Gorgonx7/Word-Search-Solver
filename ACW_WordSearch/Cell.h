#pragma once
#include <iostream>
#include <string>
enum Direction {
	LEFT, RIGHT, UP, DOWN, TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT
};
class Cell
{
	friend class PuzzleAssembler;
public:
	
	Cell(const char pCharacter, int pX, int pY) : m_Data(pCharacter), m_X(pX), m_Y(pY) {};
	Cell();
	~Cell();
	Cell operator=(const Cell &rhs);
	bool Solve(std::string pWord);
	void SetRight(Cell* pCell);
	void SetLeft(Cell* pCell);
	void SetUp(Cell* pCell);
	void SetDown(Cell* pCell);
	void SetTopRight(Cell* pCell);
	void SetTopLeft(Cell* pCell);
	void SetBottomRight(Cell* pCell);
	void SetBottomLeft(Cell* pCell);
	

private:
	
	void SetData(char &Data);
    char const GetData();
	char m_Data;
	int m_X;
	int m_Y;
	bool SolveInDirection(Direction pDirection, std::string pWord);
	
	Cell* Right();
	Cell* Left();
	Cell* Up();
	Cell* Down();
	Cell* TopLeft();
	Cell* TopRight();
	Cell* BottomLeft();
	Cell* BottomRight();
	Cell* m_Right;
	Cell* m_Left;
	Cell* m_Up;
	Cell* m_Down;
	Cell* m_TopLeft;
	Cell* m_TopRight;
	Cell* m_BottomLeft;
	Cell* m_BottomRight;
};


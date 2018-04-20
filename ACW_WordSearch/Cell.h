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
	char const GetData();

private:
	
	void SetData(char &Data);
    
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
	Cell* m_Right = nullptr;
	Cell* m_Left = nullptr;
	Cell* m_Up = nullptr;
	Cell* m_Down = nullptr;
	Cell* m_TopLeft = nullptr;
	Cell* m_TopRight = nullptr;
	Cell* m_BottomLeft = nullptr;
	Cell* m_BottomRight = nullptr;
};


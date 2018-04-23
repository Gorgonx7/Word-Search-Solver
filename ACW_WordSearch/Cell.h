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
	bool Solve(const std::string &pWord);
	inline void SetRight(Cell* pCell) {
		m_Right = pCell;
	};
	inline void SetLeft(Cell* pCell) {
		m_Left = pCell;
	};
	inline void SetUp(Cell* pCell) {
		m_Up = pCell;
	};
	inline void SetDown(Cell* pCell) {
		m_Down = pCell;
	};
	inline void SetTopRight(Cell* pCell) {
		m_TopRight = pCell;
	};
	inline void SetTopLeft(Cell* pCell) {
		m_TopLeft = pCell;
	}
	;
	inline void SetBottomRight(Cell* pCell) {
		m_BottomRight = pCell;
	};
	inline void SetBottomLeft(Cell* pCell) {
		m_BottomLeft = pCell;
	};
	inline char const GetData() {
		return m_Data;
	};

private:
	Cell(const Cell &rhs) {};
	inline void SetData(char &Data) {
		m_Data = Data;
	};
    
	char m_Data;
	int m_X = 0;
	int m_Y = 0;
	bool SolveInDirection(const Direction pDirection, const std::string &pWord);
	
	inline Cell* Right() {
		return m_Right;
	};
	inline Cell* Left() {
		return m_Left;
	};
	inline Cell* Up() {
		return m_Up;
	};
	inline Cell* Down() {
		return m_Down;
	};
	inline Cell* TopLeft() {
		return m_TopLeft;
	};
	inline Cell* TopRight() {
		return m_TopRight;
	};
	inline Cell* BottomLeft() {
		return m_BottomLeft;
	};
	inline Cell* BottomRight() {
		return m_BottomRight;
	};
	Cell* m_Right = nullptr;
	Cell* m_Left = nullptr;
	Cell* m_Up = nullptr;
	Cell* m_Down = nullptr;
	Cell* m_TopLeft = nullptr;
	Cell* m_TopRight = nullptr;
	Cell* m_BottomLeft = nullptr;
	Cell* m_BottomRight = nullptr;
};
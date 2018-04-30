#pragma once
#include <iostream>
#include <string>
enum class Direction {
	LEFT, RIGHT, UP, DOWN, TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT
};
class Cell
{
	
public:
	
	Cell(const char pCharacter, const int pX, const int pY, const int pPuzzleSize) : m_Data(pCharacter),m_PuzzleSize(pPuzzleSize), m_X(pX), m_Y(pY)  {};
	Cell();
	~Cell();
	Cell& operator=(const Cell &rhs);
	inline bool Solve(const std::string &pWord, int &NumberOfCells) {
		//implement the efficency algorithm to improve performance

		if ((m_Y - pWord.size()) >= 0) {
			if (SolveInDirection(Direction::LEFT, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_Y + pWord.size() <= m_PuzzleSize) {
			if (SolveInDirection(Direction::RIGHT, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X + pWord.size() <= m_PuzzleSize) {
			if (SolveInDirection(Direction::DOWN, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X - pWord.size() >= 0) {
			if (SolveInDirection(Direction::UP, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X - pWord.size() >= 0 && m_Y - pWord.size() >= 0) {
			if (SolveInDirection(Direction::TOPLEFT, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X - pWord.size() >= 0 && m_Y + pWord.size() <= m_PuzzleSize) {
			if (SolveInDirection(Direction::TOPRIGHT, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X + pWord.size() <= m_PuzzleSize  && m_Y - pWord.size() >= 0) {
			if (SolveInDirection(Direction::BOTTOMLEFT, pWord, NumberOfCells)) {
				return true;
			}
		}
		if (m_X + pWord.size() <= m_PuzzleSize  && m_Y + pWord.size() <= m_PuzzleSize) {
			if (SolveInDirection(Direction::BOTTOMRIGHT, pWord, NumberOfCells))
			{
				return true;
			}
		}

		return false;
	};
	inline void SetRight(Cell* const pCell) {
		m_Right = pCell;
	};
	inline void SetLeft(Cell* const pCell) {
		m_Left = pCell;
	};
	inline void SetUp(Cell* const pCell) {
		m_Up = pCell;
	};
	inline void SetDown(Cell* const pCell) {
		m_Down = pCell;
	};
	inline void SetTopRight(Cell* const pCell) {
		m_TopRight = pCell;
	};
	inline void SetTopLeft(Cell* const pCell) {
		m_TopLeft = pCell;
	}
	;
	inline void SetBottomRight(Cell* const pCell) {
		m_BottomRight = pCell;
	};
	inline void SetBottomLeft(Cell* const pCell) {
		m_BottomLeft = pCell;
	};
	inline char GetData() const {
		return m_Data;
	};
	inline int GetX() const {
		return m_X;
	}
	inline int const GetY() const {
		return m_Y;
	}
private:
	Cell(const Cell &rhs) {
		m_Data = rhs.m_Data;
		m_PuzzleSize = rhs.m_PuzzleSize;

	};
	inline void SetData(const char &Data) {
		m_Data = Data;
	};
    
	char m_Data;
	int m_PuzzleSize;
	int m_X = 0;
	int m_Y = 0;
	bool SolveInDirection(const Direction pDirection, const std::string &pWord, int &NumberOfCells);
	
	inline Cell* Right() const {
		return m_Right;
	};
	inline Cell* Left() const {
		return m_Left;
	};
	inline Cell* Up() const {
		return m_Up;
	};
	inline Cell* Down() const {
		return m_Down;
	};
	inline Cell* TopLeft() const {
		return m_TopLeft;
	};
	inline Cell* TopRight() const {
		return m_TopRight;
	};
	inline Cell* BottomLeft() const {
		return m_BottomLeft;
	};
	inline Cell* BottomRight() const {
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
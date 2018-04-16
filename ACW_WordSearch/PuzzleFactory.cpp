#include "PuzzleFactory.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Cell** m_Puzzle;

PuzzleFactory::PuzzleFactory(int size)
{
	m_Puzzle = new Cell*[m_Size * m_Size];
	
}


PuzzleFactory::PuzzleFactory(const char * const filename)
{
	ifstream Reader((std::string(filename)));
	Reader >> m_Size;
	m_Puzzle = new Cell*[m_Size * m_Size];
	char Holder;
	int Index = 0;
	while(Reader >> Holder)
	{
		m_Puzzle[Index] = new Cell(Holder);
		Index++;
	}
}




PuzzleFactory::~PuzzleFactory()
{
	
	delete[] m_Puzzle;
}



PuzzleFactory PuzzleFactory::operator=(const PuzzleFactory rhs)
{
	m_Puzzle = rhs.m_Puzzle;
	return *this;
}



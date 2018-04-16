#include "PuzzleAssembler.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
using namespace std;



PuzzleAssembler::PuzzleAssembler(const char * const filename)
{
	ifstream Reader((std::string(filename)));
	Reader >> m_Size;
	char Holder;
	Cell* Data = new Cell[m_Size * m_Size];

	while (Reader >> Holder) {
		Cell * Temp = new Cell(Holder);

	}
}

PuzzleAssembler::~PuzzleAssembler()
{
}

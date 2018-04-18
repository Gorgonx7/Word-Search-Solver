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
	int x = 0;
	int y = 0;
	while (Reader >> Holder) {
		Cell * Temp = new Cell(Holder, x, y);
		if (x != 0) {
			//Temp->SetUP(&Data[(x * 9) + y - m_Size]);
			//Temp->SetTopLeft(&Data[(x * 9) + y - (m_Size + 1)]);
			//Temp->SetTopRight(&Data[(x * 9) + y - (m_Size - 1)]);
			

		}
		if (x != m_Size) {

		}
		if (y != 0) {

		}
		if (y != m_Size) {

		}


		y++;
		if (y > m_Size - 1) {
			x++;
			y = 0;
		}

	}
}

PuzzleAssembler::~PuzzleAssembler()
{
}

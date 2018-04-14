#include "Cell.h"

Cell m_Next;
char m_Data;
Cell::Cell(char pData)
{
	m_Data = pData;
}


Cell::~Cell()
{

}

Cell Cell::operator=(const Cell & rhs)
{
	return Cell(m_Data);
}

Cell & Cell::Next()
{
	return m_Next;
}

void Cell::SetData(char & Data)
{
	m_Data = Data;
}

char Cell::GetData()
{
	return m_Data;
}



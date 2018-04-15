#include "Cell.h"

Cell* m_Right;
char m_Data;
Cell::Cell(const char pData)
{
	m_Data = pData;
}

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

Cell * Cell::Right()
{
	return m_Right;
}

void Cell::SetData(char & Data)
{
	m_Data = Data;
}

 char const Cell::GetData()
{
	return m_Data;
}



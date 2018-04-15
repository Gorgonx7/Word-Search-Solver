#pragma once
class Cell
{
	
public:
	Cell(const char pCharacter);
	Cell();
	~Cell();
	Cell operator=(const Cell &rhs);
	Cell* Right();

	

private:
	void SetData(char &Data);
    char const GetData();
	char m_Data;
};


#pragma once
class Cell
{
public:
	Cell(char pCharacter);
	~Cell();
	Cell operator=(const Cell &rhs);
	Cell& const Next();

	void SetData(char &Data);
	char GetData();

private:
	
};


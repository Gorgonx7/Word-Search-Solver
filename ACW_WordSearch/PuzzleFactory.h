#pragma once

class PuzzleFactory
{
	
public:
	const Cell** CreatePuzzle (const char * const filename);


private:
	PuzzleFactory(int size) : m_Size(size) {};
	PuzzleFactory(const char * const filename) : m_FileName(filename) {};
	~PuzzleFactory();
	PuzzleFactory operator=(const PuzzleFactory rhs);
	const Cell** const GetPuzzle();
	int m_Size;
	const char * m_FileName;
};


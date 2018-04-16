#pragma once

class PuzzleFactory
{
	
public:
	Cell** m_Puzzle;
	PuzzleFactory operator=(const PuzzleFactory rhs);
	PuzzleFactory(const char * const filename) : m_FileName(filename) {};
	~PuzzleFactory();
private:
	PuzzleFactory(int size) : m_Size(size) {};
	
	
	
	
	int m_Size;
	const char * m_FileName;
	
};
Cell ** CreatePuzzle(const char * const pfilename)
{
	PuzzleFactory Factory(pfilename);
	return Factory.m_Puzzle;
};


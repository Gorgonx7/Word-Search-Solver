#pragma once

class PuzzleFactory
{
	
public:
	static Cell** CreatePuzzle (const char * const filename);


private:
	PuzzleFactory(int size) : m_Size(size) {};
	PuzzleFactory(const char * const filename) : m_FileName(filename) {};
	~PuzzleFactory();
	PuzzleFactory operator=(const PuzzleFactory rhs);
	Cell** GetPuzzle();
	int m_Size;
	const char * m_FileName;
	Cell **m_Puzzle;
};
Cell ** CreatePuzzle(const char * const pfilename)
{
	PuzzleFactory Factory(pfilename);
	return Factory.GetPuzzle();
};


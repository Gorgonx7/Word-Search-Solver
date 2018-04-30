#pragma once
#include <vector>
class WordSearch {
	
	
	// Add your code here

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();
	WordSearch(const WordSearch &rhs);
	WordSearch& operator=(const WordSearch &rhs);
	void ReadSimplePuzzle() const;
	void ReadSimpleDictionary() const;
	void ReadAdvancedPuzzle() const;
	void ReadAdvancedDictionary() const;
	void SolvePuzzleSimple() const;
	void SolvePuzzleAdvanced() const;
	void WriteResults(const	double loadTime, const double solveTime) const;
private:
	
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";
	// Add your code here
};


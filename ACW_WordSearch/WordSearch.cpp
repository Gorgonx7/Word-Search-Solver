#include "WordSearch.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;
vector<string> Dictionary;
bool debug = true;


WordSearch::WordSearch(const char * const filename) {
	// Add your code here
}

WordSearch::~WordSearch() {
	// Add your code here
}

void WordSearch::ReadSimplePuzzle() {
	const int simplePuzzleSize = 9;
	char simplePuzzle[simplePuzzleSize][simplePuzzleSize];
	ifstream Reader((std::string(puzzleName)));
	int simpleSize;
	Reader >> simpleSize;
	assert(simpleSize == simplePuzzleSize);
	if (Reader.is_open()) {
		for (int x = 0; x < simplePuzzleSize; x++) {
			for (int y = 0; y < simplePuzzleSize; y++) {
				Reader >> simplePuzzle[x][y];
			}
		}
	}
	
}

//This method loads in the dictionary in to a simple vector structure
void WordSearch::ReadSimpleDictionary() {
	ifstream Reader((std::string(dictionaryName))); // declare the reader
	if (Reader.is_open()) { // if the file is open and exsists
		std::string Holder; // create a holder string
		while (Reader >> Holder) // if you can read in to the string
		{
			Dictionary.push_back(Holder); // add it to the vector
		}
	}
}

void WordSearch::ReadAdvancedPuzzle() {
	// Add your code here
}

void WordSearch::ReadAdvancedDictionary() {
	// Add your code here
}

void WordSearch::SolvePuzzleSimple() {
	// Add your code here
}

void WordSearch::SolvePuzzleAdvanced() {
	// Add your code here
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	// Add your code here
	cout << "Read in " << Dictionary.size() << "words from the dictionary" << endl;

}
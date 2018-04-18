#include "WordSearch.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;
vector<string> Dictionary;
vector<string> FoundWords;
bool debug = true;
const int simplePuzzleSize = 9;
char simplePuzzle[simplePuzzleSize][simplePuzzleSize];
char* puzzelHolder;
const char* saveFileName;
bool Advanced = false;
WordSearch::WordSearch(const char * const filename) {
	
	saveFileName = filename;
	if (filename == "output_advanced.txt") {

	}
}

WordSearch::~WordSearch() {
	
	FoundWords.clear();
	Dictionary.clear();
}

void WordSearch::ReadSimplePuzzle() {
	
	
	ifstream Reader((std::string(puzzleName)));
	int simpleSize;
	Reader >> simpleSize;
	assert(simpleSize == simplePuzzleSize);
	if (Reader.is_open()) {
		for (int x = 0; x < simplePuzzleSize; ++x) {
			for (int y = 0; y < simplePuzzleSize; ++y) {
				Reader >> simplePuzzle[x][y];
			}
		}
	}
	puzzelHolder = &simplePuzzle[0][0];
	
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
	/*\
	|*| TODO
	|*| Load in all the letters
	|*| Store them alphabetically in a 26 length array
	|*| Ensure all the cells are linked correctly 
	\*/
}

void WordSearch::ReadAdvancedDictionary() {
	// Add your code here
}
// solves the puzzle simply
void WordSearch::SolvePuzzleSimple() {
	
	
	for (int x = 0; x < simplePuzzleSize; ++x) {
		for (int y = 0; y < simplePuzzleSize; ++y) {
			const char* const CurrentChar = puzzelHolder + (x * 9) + y;
			string CurrentWord = "";
			
			for (int WordNumber = 0; WordNumber < Dictionary.size(); WordNumber++) {
				if (Dictionary[WordNumber][0] == *CurrentChar) {
					//find if it the word
					CurrentWord += Dictionary[WordNumber][0];
					if (y != 9) {
						//right
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++)
						{
							if (Dictionary[WordNumber][letter] == CurrentChar[letter])
							{
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
					}
					if (y != 0) {
						//left
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar - letter)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
					}
					if (x != simplePuzzleSize - 1) {
						//down
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar + letter * 9)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
						//bottom right
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar + letter * 10)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
						//bottom left
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar + letter * 8)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
					}
					if (x != 0) {
						//up
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar - letter * 9)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
						//top right
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar - letter * 8)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
						//top left
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							if (Dictionary[WordNumber][letter] == (CurrentChar - letter * 10)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								goto AddWord;
							}
						}
					}
					
					
					
					
					
					CurrentWord = "";
					AddWord:
					if (CurrentWord != "") {
						FoundWords.push_back(CurrentWord);
						Dictionary.erase(Dictionary.begin() + WordNumber);
					}
					
				}
			}
			
			
		}
	}
	
}

void WordSearch::SolvePuzzleAdvanced() {
	// Add your code here
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	cout << "Load Time: " << loadTime << endl;
	cout << "Solve Time:" << solveTime << endl;
	cout << "Found " << FoundWords.size() << " words!" << endl;
	for each(string i in FoundWords) {
		cout << i << endl;
	}
	cout << "Read in " << Dictionary.size() << " words from the dictionary" << endl;

}
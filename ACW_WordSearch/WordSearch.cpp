#include "WordSearch.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;
vector<string> Dictionary; // vector of strings that contain the dictionary
vector<int> Coords; // coords of found words
vector<string> FoundWords;// the found words themselves
vector<string> UnfoundWords; // words that have not been found by the search algorithm
const int simplePuzzleSize = 9; // size of the simple puzzle 
int NumberOfWordsVisited = 0; // number of words that the algorithm visits
int NumberOfCellsVisited = 0; // number of cells visited by the algorithm
char simplePuzzle[simplePuzzleSize][simplePuzzleSize]; // the simple puzzle holding array for loading
char* puzzelHolder; // the pointer to the start of the simple puzzle array
const char* saveFileName; // the name of the output file to save too
vector<Cell *> Alphabet[26]; // the alphabet array consisting of a array of 26 vector cell pointers
int m_Size; // the size of the puzzle

/// Constructor for the word search
WordSearch::WordSearch(const char * const filename) {

	saveFileName = filename; // assign the name of the save file to be referenced later

}
/// destructor for the word search
WordSearch::~WordSearch() {

	FoundWords.clear(); // clear the found words
	UnfoundWords.clear(); // clear the unfound words
	Dictionary.clear(); // clear the dictionary
	Coords.clear(); // clear the coords
	NumberOfWordsVisited = 0; // reset the number of words visited
	NumberOfCellsVisited = 0; // reset the number of cells visited
}
/// Read simple puzzle structure in for solvinng
void WordSearch::ReadSimplePuzzle() const{


	ifstream Reader((std::string(puzzleName))); // open a stream readerr
	int simpleSize; // declare a size variable for debugging
	Reader >> simpleSize; // read in the size of the grid
	//assert(simpleSize == simplePuzzleSize); // enable if debugging to ensure that the data read in is solvable 
	if (Reader.is_open()) { // check to see if the reader is open
		for (int x = 0; x < simplePuzzleSize; ++x) { // for each row in the grid
			for (int y = 0; y < simplePuzzleSize; ++y) { // for each character in the row
				Reader >> simplePuzzle[x][y]; // read in the data to the appropriate slot in the array
			}
		}
	}

	puzzelHolder = &simplePuzzle[0][0]; // assign the start pointer

}

//This method loads in the dictionary in to a simple vector structure
void WordSearch::ReadSimpleDictionary() const {
	ifstream Reader((std::string(dictionaryName))); // declare the reader
	if (Reader.is_open()) { // if the file is open and exsists
		std::string Holder; // create a holder string
		while (Reader >> Holder) // if you can read in to the string
		{
			Dictionary.push_back(Holder); // add it to the vector
		}
	}
}
///read in the advanced puzzle into the advanced data structure
void WordSearch::ReadAdvancedPuzzle() const {
	
	ReadSimpleDictionary(); // read in the simple dictionary
	ifstream Reader((std::string(puzzleName))); // create a stream reader
	Reader >> m_Size; // read in the size of the grid
	char Holder; // create a holder to store data in
	Cell* Data = new Cell[m_Size * m_Size]; // create the array on the heap 
	int x = 0; // create an x and y holder
	int y = 0; 
	while (Reader >> Holder) { // while data can be read in
		const Cell * const Temp = new Cell(Holder, x, y, m_Size); // create a new cell object on the heap
		Data[x * m_Size + y] = *Temp; // assign that data to the array
		y++; // increment the coordinate counters
		if (y > m_Size - 1) {
			x++;
			y = 0;
		}
		

	}

	for (int x = 0; x < m_Size; x++) { 
		for (int y = 0; y < m_Size; y++) { // for every cell in the data grid
		    Cell* const Temp = &Data[x * m_Size + y]; // get the current cell
			/*\
			|*| The following checks are used to ensure that the pointers are set correctly, this ensures that no pointers are set to trash data
			|*|
			\*/
			if (x != 0) {
				Temp->SetUp(&Data[(x * m_Size) + y - m_Size]); 
				if (y != 0) {
					Temp->SetTopLeft(&Data[(x * m_Size) + y - (m_Size + 1)]);
				}
				if (y != m_Size - 1) {
					Temp->SetTopRight(&Data[(x * m_Size) + y - (m_Size - 1)]);
				}
			}
			if (x != m_Size - 1)
			{
				Temp->SetDown(&Data[(x * m_Size) + y + m_Size]);
				if (y != 0) {
					Temp->SetBottomLeft(&Data[(x * m_Size) + y + (m_Size - 1)]);
				}
				if (y != m_Size - 1) {
					Temp->SetBottomRight(&Data[(x * m_Size) + y + (m_Size + 1)]);
				}
			}
			if (y != 0) {
				Temp->SetLeft(&Data[(x * m_Size) + (y - 1)]);

			}
			if (y != m_Size - 1) {
				Temp->SetRight(&Data[(x * m_Size) + (y + 1)]);
			}
			const char Holder = Temp->GetData();
			const int index = Holder - 'A';
			Alphabet[index].push_back(Temp);

			
		}
	}
}
///un-implemented method for reading in the advanced dictionary
void WordSearch::ReadAdvancedDictionary() const {
	cout << "Read Advanced Dictionary is not Implemented" << endl;
}
/// solves the puzzle using the simple dictionary and data structure
void WordSearch::SolvePuzzleSimple() const {


	for (int x = 0; x < simplePuzzleSize; ++x) {
		for (int y = 0; y < simplePuzzleSize; ++y) { // for every cell in the grid
			const char * const CurrentChar = puzzelHolder + (x * simplePuzzleSize) + y; // get a pointer to the current character being searched
			string CurrentWord = ""; // create a holder for the current word being searched for
			NumberOfCellsVisited++; // increment the number of cells visited
			for (int WordNumber = 0; WordNumber < Dictionary.size(); WordNumber++) { // for every word in the dictionary...
				NumberOfWordsVisited++; // increment the number of words accessed
				if (Dictionary[WordNumber][0] == *CurrentChar) { // if the first character of the word is the current character on the grid
					CurrentWord += Dictionary[WordNumber][0]; // add the current character to the current word
					if (y != simplePuzzleSize && y + Dictionary[WordNumber].size() <= simplePuzzleSize) { // check if the word will fit in the right direction
						// solve in the right direction
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++)
						{
							NumberOfCellsVisited++; // increment the number of cells visited
							if (Dictionary[WordNumber][letter] == CurrentChar[letter])
							{
								CurrentWord += Dictionary[WordNumber][letter]; // the letter is the next in the sequence
							}
							else {
								CurrentWord = CurrentChar[0]; // reset the current word and search in the next direction
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								//cout << "RIGHT ";
								goto AddWord; // the word has been found add the word to found words
							}
						}
					}
					if (y != 0 && y - Dictionary[WordNumber].size() >= 0) { // check if the word will fit in the left direction

						//solve in the left direction
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
							NumberOfCellsVisited++;
							if (Dictionary[WordNumber][letter] == (CurrentChar - letter)[0]) {
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								//cout << "LEFT ";
								goto AddWord;
							}
						}
					}
					if (x != simplePuzzleSize - 1) { // check if the word will fit in the right direction
						if (x + Dictionary[WordNumber].size() <= simplePuzzleSize) {
							//down
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar + letter * simplePuzzleSize)[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "DOWN ";
									goto AddWord;
								}
							}
						}
						if (x + Dictionary[WordNumber].size() <= simplePuzzleSize && y + Dictionary[WordNumber].size() <= simplePuzzleSize) { // check if the word fits in the bottom right direction
							//solve in the bottom right direction
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar + letter * (simplePuzzleSize + 1))[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "BOTTOM_RIGHT ";
									goto AddWord;
								}
							}
						}
						if ((x + Dictionary[WordNumber].size() <= simplePuzzleSize && y - Dictionary[WordNumber].size() >= 0)) { // check to see if the word fits in the bottom left direction
							//search in the bottom left direction
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar + letter * (simplePuzzleSize - 1))[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "BOTTOM_LEFT ";
									goto AddWord;
								}
							}
						}
					}
					if (x != 0) { // check to see if the top three cells need to be searched
						if (x - Dictionary[WordNumber].size() >= 0) { // does the word fit in the up direction
							//search the up direction
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar - letter * simplePuzzleSize)[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "UP ";
									goto AddWord;
								}
							}
						}
						if (x - Dictionary[WordNumber].size() >= 0 && y + Dictionary[WordNumber].size() <= simplePuzzleSize) // does the word fit in the top right direction
						{
							//search in the top right direction
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar - letter * (simplePuzzleSize - 1))[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "TOP_RIGHT ";
									goto AddWord;
								}
							}
						}
						if (x - Dictionary[WordNumber].size() >= 0 && y - Dictionary[WordNumber].size() >= 0) { // does the word fit in the top right direction
							//search in the top left direction
							for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++) {
								NumberOfCellsVisited++;
								if (Dictionary[WordNumber][letter] == (CurrentChar - letter * (simplePuzzleSize + 1))[0]) {
									CurrentWord += Dictionary[WordNumber][letter];
								}
								else {
									CurrentWord = CurrentChar[0];
									break;
								}
								if (CurrentWord == Dictionary[WordNumber]) {
									//cout << "TOP_LEFT ";
									goto AddWord;
								}
							}
						}
					}




					
					CurrentWord = "";// if this is reached the word is not found so set it so the word will not be added
				AddWord: // goto lable if the word is found
					if (CurrentWord != "") { // if the word has been found
						FoundWords.push_back(CurrentWord); // add the current word to the list of found words
						Dictionary.erase(Dictionary.begin() + WordNumber); // erase the entry in the dictionary
						Coords.push_back(y); // add the y which is the x coordinate
						Coords.push_back(x); // add the x which is the y coordinate
					}

				}
				}


		}
	}
	for each(string i in Dictionary) { // at the end find all the words that have not been found by comparing the found words with the dictionary
		if (find(FoundWords.begin(), FoundWords.end(), i) == FoundWords.end()) {
			UnfoundWords.push_back(i);
		}
	}
}
///method that solves the advanced puzzle
void WordSearch::SolvePuzzleAdvanced() const {
	
	
	for (int word = 0; word < Dictionary.size(); word++) { // for every word in the dictionary...
		NumberOfWordsVisited++; // increment the number of words visited
		const int dictsize = FoundWords.size(); // save the current size of the dictionary
		for(int x = 0; x < Alphabet[Dictionary[word][0] - 'A'].size(); x++) { // for every possible starting point
			
			if (Alphabet[Dictionary[word][0] - 'A'][x]->Solve(Dictionary[word], NumberOfCellsVisited)) { // if the word has been found
				FoundWords.push_back(Dictionary[word]); // add the word to the list of found words
				Coords.push_back(Alphabet[Dictionary[word][0] - 'A'][x]->GetY()); // record the coordinates of the starting point
				Coords.push_back(Alphabet[Dictionary[word][0] - 'A'][x]->GetX());
				break;
			}
			else {
				
				
			}
			
		}
		if (dictsize == FoundWords.size()) { // if the found word vector is still the same 
			UnfoundWords.push_back(Dictionary[word]); // add the current word to the unfound list
		}
	}
	
}
///wordsearch copy constructor
WordSearch::WordSearch(const WordSearch &rhs) 
{
	puzzleName = rhs.puzzleName;
	dictionaryName = rhs.dictionaryName;
	
}
/// equals operator
WordSearch& WordSearch::operator=(const WordSearch& rhs) 
{
	puzzleName = rhs.puzzleName;
	dictionaryName = rhs.dictionaryName;
	
	return *this;
}
/// write the results as specified in the 
void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	ofstream Writer(saveFileName);
	Writer << "NUMBER_OF_WORDS_MATCHED " << FoundWords.size() << endl << endl;
	
	
	Writer << "WORDS_MATCHED_IN_GRID" << endl;
	
	for (int x = 0; x < FoundWords.size(); x++) {
		Writer << Coords[x * 2] << " " << Coords[x * 2 + 1] << " " << FoundWords[x] << endl;
		
	}
	Writer << endl;
	Writer <<"WORDS_UNMATCHED_IN_GRID" << endl;
	for each(string i in UnfoundWords) {
		Writer << i << endl;
	}
	Writer << endl;
	Writer << "NUMBER_OF_GRID_CELLS_VISITED " << NumberOfCellsVisited << endl;
	Writer << endl;
	Writer << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << NumberOfWordsVisited << endl;
	Writer << endl;
	Writer << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	Writer << endl;
	Writer << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;


}
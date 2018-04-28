#include "WordSearch.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;
vector<string> Dictionary;
vector<int> Coords;
vector<string> FoundWords;
vector<string> UnfoundWords;
bool debug = true;
const int simplePuzzleSize = 9;
int NumberOfWordsVisited = 0;
int NumberOfCellsVisited = 0;
char simplePuzzle[simplePuzzleSize][simplePuzzleSize];
char* puzzelHolder;
const char* saveFileName;
bool Advanced = false;
vector<Cell *> Alphabet[26] = {
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0),
	vector<Cell *>(0)
};
int m_Size;
WordSearch::WordSearch(const char * const filename) {

	saveFileName = filename;

}

WordSearch::~WordSearch() {

	FoundWords.clear();
	UnfoundWords.clear();
	Dictionary.clear();
	Coords.clear();
	NumberOfWordsVisited = 0;
	NumberOfCellsVisited = 0;
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
	ReadSimpleDictionary();
	ifstream Reader((std::string(puzzleName)));
	Reader >> m_Size;
	char Holder;
	Cell* Data = new Cell[m_Size * m_Size];
	int x = 0;
	int y = 0;
	while (Reader >> Holder) {
		const Cell * const Temp = new Cell(Holder, x, y, m_Size);
		Data[x * m_Size + y] = *Temp;
		y++;
		if (y > m_Size - 1) {
			x++;
			y = 0;
		}

	}
	for (int x = 0; x < m_Size; x++) {
		for (int y = 0; y < m_Size; y++) {
		    Cell* const Temp = &Data[x * m_Size + y];
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

void WordSearch::ReadAdvancedDictionary() {
	cout << "Read Advanced Dictionary is not Implemented" << endl;
}
// solves the puzzle simply
void WordSearch::SolvePuzzleSimple() {


	for (int x = 0; x < simplePuzzleSize; ++x) {
		for (int y = 0; y < simplePuzzleSize; ++y) {
			const char * const CurrentChar = puzzelHolder + (x * simplePuzzleSize) + y;
			string CurrentWord = "";
			NumberOfCellsVisited++;
			for (int WordNumber = 0; WordNumber < Dictionary.size(); WordNumber++) {
				NumberOfWordsVisited++;
				if (Dictionary[WordNumber][0] == *CurrentChar) {
					//find if it the word
					CurrentWord += Dictionary[WordNumber][0];
					if (y != simplePuzzleSize && y + Dictionary[WordNumber].size() <= simplePuzzleSize) {
						//right
						for (int letter = 1; letter < Dictionary[WordNumber].size(); letter++)
						{
							NumberOfCellsVisited++;
							if (Dictionary[WordNumber][letter] == CurrentChar[letter])
							{
								CurrentWord += Dictionary[WordNumber][letter];
							}
							else {
								CurrentWord = CurrentChar[0];
								break;
							}
							if (CurrentWord == Dictionary[WordNumber]) {
								//cout << "RIGHT ";
								goto AddWord;
							}
						}
					}
					if (y != 0 && y - Dictionary[WordNumber].size() >= 0) {

						//left
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
					if (x != simplePuzzleSize - 1) {
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
						if (x + Dictionary[WordNumber].size() <= simplePuzzleSize && y + Dictionary[WordNumber].size() <= simplePuzzleSize) {
							//bottom right
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
						if ((x + Dictionary[WordNumber].size() <= simplePuzzleSize && y - Dictionary[WordNumber].size() >= 0)) {
							//bottom left
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
					if (x != 0) {
						if (x - Dictionary[WordNumber].size() >= 0) {
							//up
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
						if (x - Dictionary[WordNumber].size() >= 0 && y + Dictionary[WordNumber].size() <= simplePuzzleSize) 
						{
							//top right
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
						if (x - Dictionary[WordNumber].size() >= 0 && y - Dictionary[WordNumber].size() >= 0) {
							//top left
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




					
					CurrentWord = "";
				AddWord:
					if (CurrentWord != "") {
						FoundWords.push_back(CurrentWord);
						//Dictionary.erase(Dictionary.begin() + WordNumber);
						Coords.push_back(y);
						Coords.push_back(x);
					}

				}
				}


		}
	}
	for each(string i in Dictionary) {
		if (find(FoundWords.begin(), FoundWords.end(), i) == FoundWords.end()) {
			UnfoundWords.push_back(i);
		}
	}
}

void WordSearch::SolvePuzzleAdvanced() {
	// for every word in the dictionary cast the first letter to the 
	
	for (int word = 0; word < Dictionary.size(); word++) {
		NumberOfWordsVisited++;
		const int dictsize = FoundWords.size();
		for(int x = 0; x < Alphabet[Dictionary[word][0] - 'A'].size(); x++) {
			
			if (Alphabet[Dictionary[word][0] - 'A'][x]->Solve(Dictionary[word], NumberOfCellsVisited)) {
				FoundWords.push_back(Dictionary[word]);
				Coords.push_back(Alphabet[Dictionary[word][0] - 'A'][x]->GetY());
				Coords.push_back(Alphabet[Dictionary[word][0] - 'A'][x]->GetX());
				break;
			}
			else {
				
				
			}
			
		}
		if (dictsize == FoundWords.size()) {
			UnfoundWords.push_back(Dictionary[word]);
		}
	}
	
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	ofstream Writer(saveFileName);
	Writer << "NUMBER_OF_WORDS_MATCHED " << FoundWords.size() << endl << endl;
	
	
	Writer << "WORDS_MATCHED_IN_GRID" << endl;
	int coordItterator = 0;
	for each(string i in FoundWords) {
		Writer << Coords[coordItterator] << Coords[coordItterator + 1] << i << endl;
	}
	
	Writer << "WORDS_UNMATCHED_IN_GRID" << endl;
	for each(string i in UnfoundWords) {
		Writer << i << endl;
	}
	Writer << "NUMBER_OF_GRID_CELLS_VISITED " << NumberOfCellsVisited << endl;
	Writer << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << NumberOfWordsVisited << endl;
	Writer << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	
	Writer << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;


}
#pragma once

class SudokuPuzzle
{
private:
	std::vector<int> initialpuzzle; 
	std::vector<int> puzzle;
	std::vector<int> puzzlesolution;

	int attempts;

public:
	// constructor 
	SudokuPuzzle();

	void getInitialPuzzle();
	void writeInitialPuzzleToConsole();
	void writePuzzleToConsole();
	void writePuzzleSolutionToConsole();

	int getAttempts(); 
	void setAttempts(int val);

	std::vector<int> getPuzzle();
	std::vector<int> getSolution();

	bool isValInPuzzleRow(int val, int position);
	bool isValInPuzzleColumn(int val, int position);
	bool isValInPuzzleSection(int val, int position);
	int findFirstEmptyCell();

	bool solvePuzzle();
};

	/*
	// copy constructor
	SudokuPuzzle(const SudokuPuzzle&) {

	};

	// assignment operator
	SudokuPuzzle& operator=(const SudokuPuzzle) {

	};

	// destructor needed?
	/*
	-SudokuPuzzle(){
	};
	*/

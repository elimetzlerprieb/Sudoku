// Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	int rc = 0;

	SudokuPuzzle newPuzzle;
	newPuzzle.writePuzzleToConsole();

	newPuzzle.getInitialPuzzle();
	newPuzzle.writeInitialPuzzleToConsole();
	newPuzzle.writePuzzleToConsole();
	newPuzzle.solvePuzzle();
	newPuzzle.writePuzzleToConsole();
	newPuzzle.writePuzzleSolutionToConsole();

	char y; 
	std::cout << "Get char" << std::endl; 
	std::cin >> y;

    return 0;
}


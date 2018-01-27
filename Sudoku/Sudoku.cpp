// Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	/*
	SudokuPuzzle newPuzzle;
	newPuzzle.getInitialPuzzle();
	newPuzzle.writeInitialPuzzleToConsole();
	newPuzzle.solvePuzzle();
	newPuzzle.writePuzzleToConsole();

	std::cout << "Nice" << std::endl;
	*/

	SudokuMiner miner;
	miner.minePuzzles(1, 25);



	char y; 
	std::cout << "Get char" << std::endl; 
	std::cin >> y;

    return 0;
}


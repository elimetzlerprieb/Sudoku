#include "stdafx.h"

// constructor 
SudokuPuzzle::SudokuPuzzle() :initialpuzzle(81, 0), puzzle(81, 0), puzzlesolution(81, 0)
{
	attempts = 0; 
}

int SudokuPuzzle::getAttempts()
{
	return attempts; 
}

void SudokuPuzzle::setAttempts(int val)
{
	attempts = val; 
}

std::vector<int> SudokuPuzzle::getPuzzle()
{
	return puzzle;
}

std::vector<int> SudokuPuzzle::getSolution()
{
	return puzzlesolution; 
}

void SudokuPuzzle::writeInitialPuzzleToConsole()
{
	for (size_t i = 0; i < initialpuzzle.size(); i++)
	{
		std::cout << initialpuzzle[i] << " ";

		if ((i + 1) % 9 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void SudokuPuzzle::writePuzzleToConsole()
{
	for (size_t i = 0; i < puzzle.size(); i++)
	{
		std::cout << puzzle[i] << " ";

		if ((i + 1) % 9 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void SudokuPuzzle::writePuzzleSolutionToConsole()
{
	for (size_t i = 0; i < puzzlesolution.size(); i++)
	{
		std::cout << puzzlesolution[i] << " ";

		if ((i + 1) % 9 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void SudokuPuzzle::getInitialPuzzle()
{
	std::ifstream file;
	file.open("testpuzzle.txt");

	char digit;

	for (size_t i = 0; i < initialpuzzle.size(); i++)
	{
		file >> digit;
		initialpuzzle[i] = digit - '0';
		puzzle[i] = digit - '0';
	}
}

bool SudokuPuzzle::solvePuzzle()
{
	// TODO: handle unsolvable puzzles

	int position = findFirstEmptyCell();

	// Non-base case (puzzle is not filled in)
	if (position > - 1)
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (isValInPuzzleRow(i, position) == false &&
				isValInPuzzleColumn(i, position) == false &&
				isValInPuzzleSection(i, position) == false)
				{
				puzzle[position] = i;

				if (solvePuzzle() == true)
				{
					return true;
				}

				puzzle[position] = 0;
			}

		}
		return false;
	}
	// Base Case (puzzle is full) 
	else if (position == -1)
	{
		return true;
	}
}


bool SudokuPuzzle::isValInPuzzleRow(int val, int position)
{
	int x = position / 9; // gives the 'row' by throwing away the remainder

	for (size_t i = (x * 9); i < (x * 9) + 9; i++)
	{
		if (puzzle[i] == val)
		{
			return true;
		}
	}
	return false;
}

bool SudokuPuzzle::isValInPuzzleColumn(int val, int position)
{
	int y = position % 9; // gives the 'column' by taking the remainder

	for (size_t i = 0; i < 9; i++)
	{
		if (puzzle[(i * 9) + y] == val)
		{
			return true;
		}
	}
	return false; 
}

bool SudokuPuzzle::isValInPuzzleSection(int val, int position)
{
	int k = 0;
	int j = 0;

	// determine if the position is in the first 3, middle 3, or bottom 3 rows
	if (position < 27) { k = 0; }
	else if (position < 54) { k = 3; }
	else if (position < 81) { k = 6; }

	// determine if the position is in the first 3, middle 3, or last 3 columns
	if (position % 9 < 3) { j = 0; }
	else if (position % 9 < 6) { j = 3; }
	else if (position % 9 < 9) { j = 6; }


	// loop through 3 rows and check the 3 colunns for the grid 'section' the position is in. 
	for (int i = k; i < k + 3; i++)
	{
		if (puzzle[(i * 9) + j] == val ||
			puzzle[(i * 9) + j + 1] == val ||
			puzzle[(i * 9) + j + 2] == val)
			return true;
	}
	return false;
}


int SudokuPuzzle::findFirstEmptyCell() 
{
	for (int i = 0; i < puzzle.size(); i++)
	{
		if (puzzle[i] == 0)
		{
			return i;
		}
	}
	
	return -1; // Puzzle is full
}

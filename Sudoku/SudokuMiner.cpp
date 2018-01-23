#include "stdafx.h"

std::vector<int> generateSeededPuzzle()
{
	// initial empty puzzle

	// add some number n of 'nodes' to the puzzle randomly

	// check to ensure that the puzzle is trivially solvable (nodes break the row, column, or section safety)

}

std::vector<int> generateSeededPuzzle(int difficulty)
{
	// how does the number of nodes relate to puzzle difficulty?

}

bool SudokuMiner::solvePuzzle()
{
	int position = findFirstEmptyCell();

	// Non-base case (puzzle is not filled in)
	if (position > -1)
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (isValInPuzzleRow(i, position) == false &&
				isValInPuzzleColumn(i, position) == false &&
				isValInPuzzleSection(i, position) == false)
			{
				Puzzle[position] = i;

				if (solvePuzzle() == true)
				{
					return true;
				}

				Puzzle[position] = 0;
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

void writePuzzleDataToFile()
{
	// write puzzle data to a text file, one puzzle per row 
	// puzzle id #, # nodes, RawPuzzleData, RawPuzzleSolution 

}

void minePuzzles()
{
	// the manager to run the puzzle finding operation
	// inputs: desired difficutly, desired number of puzzles, text file name for output
}

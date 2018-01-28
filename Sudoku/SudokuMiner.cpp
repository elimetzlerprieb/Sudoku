#include "stdafx.h"

SudokuMiner::SudokuMiner() : puzzle(81, 0), seed(81, 0)
{
	desired_difficulty = 25;
	desired_number_of_puzzles = 1;
	output_file = "output.txt";
	has_solution = false; 

}

void SudokuMiner::minePuzzles(int attempts, int difficulty)
{
	// for now count will be how many puzzles to mine before shutting off
	//int count = 1;
	
	std::srand(std::time(NULL)); // seed random number generator once per mining session rather than for each puzzle 

	has_solution = false;

	for (int i = 0; i < attempts; i++)
	{
		std::cout << "Mining for puzzle " << i + 1 << std::endl;

		resetAndSeedPuzzle(difficulty);

		writePuzzleToConsole();

		bool rc = solvePuzzle();

		if (rc == true)
		{
			std::cout << "Solved!" << std::endl;
			has_solution = true; 
		}
		else if (rc == false)
		{
			std::cout << "No Solution" << std::endl;
			has_solution = false;
		}

		writePuzzleToConsole();

		if (has_solution == true)
		{
			writePuzzleDataToFile();
		}
		else if (has_solution == false)
		{
			writeFailureToFile();
		}
	}
}


void SudokuMiner::resetAndSeedPuzzle(int random_nodes_count)
{
	// reset puzzle

	for (int i = 0; i < puzzle.size(); i++)
	{
		puzzle[i] = 0;
		seed[i] = 0; 
	}

	// add some number n of 'nodes' to the puzzle randomly
	//random_nodes_count = 25; // Strict minimum of 17 to ensure only 1 unique solution and upper bound ~35 before trivially easy

	for (int i = 0; i < random_nodes_count; i++)
	{
		int position = (std::rand() % 80); // pick a random cell 
		int val = (std::rand() % 9) + 1; // generate a new value 

		// ensure that a placed node doesn't break the solvability of the puzzle or overwrite an already placed node 
		while (puzzle[position] != 0 ||
			SudokuMiner::isValInPuzzleRow(val, position) == true ||
			SudokuMiner::isValInPuzzleColumn(val, position) == true ||
			SudokuMiner::isValInPuzzleSection(val, position) == true)
		{
			position = (std::rand() % 80);
		}

		puzzle[position] = val;
		seed[position] = val; 
	}
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

void SudokuMiner::writePuzzleDataToFile()
{
	// write puzzle data to a text file, one puzzle per row  
	// has_solution, seed, solution, number of nodes 

	std::ofstream outputfile;
	outputfile.open("puzzle_set.txt", std::ofstream::app);
	// this function only called if puzzle is solved successfully
	outputfile << "1,"; 

	// print the seed that was solved
	for (int i = 0; i < seed.size(); i++)
	{
		outputfile << seed[i];
	}

	outputfile << ",";

	// and the solved puzzle
	for (int i = 0; i < puzzle.size(); i++)
	{
		outputfile << puzzle[i];
	}

	// and the number of nodes 
	outputfile << "," << desired_difficulty; 

	outputfile << std::endl;

	outputfile.close();
}

void SudokuMiner::writeFailureToFile()
{
	std::ofstream outputfile;
	outputfile.open("puzzle_set.txt", std::ofstream::app);

	// this function only called if puzzle is unsolvable
	outputfile << "0,";

	// and the seed that was solved
	for (int i = 0; i < seed.size(); i++)
	{
		outputfile << seed[i];
	}

	outputfile << std::endl;

	outputfile.close();
}


bool SudokuMiner::isValInPuzzleRow(int val, int position)
{
	int x = position / 9; // gives the 'row' by throwing away the remainder

	for (int i = (x * 9); i < (x * 9) + 9; i++)
	{
		if (puzzle[i] == val)
		{
			return true;
		}
	}
	return false;
}

bool SudokuMiner::isValInPuzzleColumn(int val, int position)
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

bool SudokuMiner::isValInPuzzleSection(int val, int position)
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

int SudokuMiner::findFirstEmptyCell()
{
	for (size_t i = 0; i < puzzle.size(); i++)
	{
		if (puzzle[i] == 0)
		{
			return i;
		}
	}

	return -1; // Puzzle is full
}

void SudokuMiner::writePuzzleToConsole()
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

bool SudokuMiner::isSeedValid()
{
	return true; 
}

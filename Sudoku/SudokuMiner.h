#pragma once

class SudokuMiner
{
public:
	// constructor
	SudokuMiner(); 

	void minePuzzles(int attempts, int difficulty);
	void writePuzzleToConsole();

private:
	std::vector<int> puzzle; 

	int desired_difficulty;
	int desired_number_of_puzzles;
	std::string output_filefile; 

	void resetAndSeedPuzzle(int random_nodes_count);
	bool isSeedValid();

	bool solvePuzzle();
	bool isValInPuzzleRow(int val, int position);
	bool isValInPuzzleColumn(int val, int position);
	bool isValInPuzzleSection(int val, int position);
	int findFirstEmptyCell();
	
	
	
	void writePuzzleDataToFile();


};
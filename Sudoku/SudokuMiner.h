#pragma once

class SudokuMiner
{
public:
	// constructor
	SudokuMiner(); 

	void minePuzzles(int attempts, int difficulty);

private:
	std::vector<int> puzzle; 
	std::vector<int> seed; 

	void writePuzzleToConsole();

	int desired_difficulty;
	int desired_number_of_puzzles;
	bool has_solution;
	std::string output_file; 

	void resetAndSeedPuzzle(int random_nodes_count);
	bool isSeedValid();

	bool solvePuzzle();
	bool isValInPuzzleRow(int val, int position);
	bool isValInPuzzleColumn(int val, int position);
	bool isValInPuzzleSection(int val, int position);
	int findFirstEmptyCell();

	void writePuzzleDataToFile();
	void writeFailureToFile(); 
};
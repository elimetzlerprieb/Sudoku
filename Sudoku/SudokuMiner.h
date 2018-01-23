#pragma once

class SudokuMiner
{
private:
	int desired_difficulty;
	int desired_number_of_puzzles;
	std::string output_filefile; 

	std::vector<int> generateSeededPuzzle();
	std::vector<int> generateSeededPuzzle(int difficulty);

	bool solvePuzzle();
	
	void writePuzzleDataToFile();

public:
	void minePuzzles();
};
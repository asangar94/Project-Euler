#include "P11.h"

P11::P11()
{
	col = row = input = maxProduct = temp = 0;

	start();
}

void P11::start()
{
	//declare varibles
	std::string filename;

	//print start message
	std::cout << "This program will find the greatest product of four adjacent numbers in a grid." << std::endl
			  << "The grid must be a minimum of 4x4." << std::endl;

	//get number of rows
	std::cout << "Enter the number of rows in the grid: ";

	std::cin >> row;

	//get number of columns
	std::cout << "Enter the number of columns in the grid: ";

	std::cin >> col;

	//check grid bounds
	if (row < 4 || col < 4)
	{
		std::cout << "Error: Grid does not meet requirements." << std::endl;
		return;
	}

	//get text file name
	std::cout << "Enter the name of a .txt file with a grid of "
			  << row << "x" << col << " integers (without .txt): ";

	std::cin >> filename;

	//create file pointer
	std::ifstream file(filename + ".txt");

	//create dynamic 2D array to store grid
	int **grid = new int*[row];
	for (int i = 0; i < row; ++i)
		grid[i] = new int[col];

	//fill dynamic array with values from input file
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			file >> grid[i][j];

	//get current time (start)
	auto start = std::chrono::high_resolution_clock::now();

	//check vertical products
	for (int i = 0; i < row - 3; i++)
		for (int j = 0; j < col; j++)
		{
			temp = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			if (temp > maxProduct) maxProduct = temp;
		}

	//check horizontal products
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col - 3; j++)
		{
			temp = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			if (temp > maxProduct) maxProduct = temp;
		}

	//check right diagonal products
	for (int i = 0; i < row - 3; i++)
		for (int j = 0; j < col - 3; j++)
		{
			temp = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			if (temp > maxProduct) maxProduct = temp;
		}

	//check left diagonal products
	for (int i = 0; i < row - 3; i++)
		for (int j = 0; j < col - 3; j++)
		{
			temp = grid[i][j + 3] * grid[i + 1][j + 2] * grid[i + 2][j + 1] * grid[i + 3][j];
			if (temp > maxProduct) maxProduct = temp;
		}

	//get current time (finish)
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in milliseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << std::endl << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print end message
	std::cout << "The greatest product of four adjacent numbers in the " << row << "x" << col 
			  << " grid is: " << maxProduct << std::endl;

	//delete dynamic memory
	for (int i = 0; i < row; ++i)
		delete[] grid[i];
	delete[] grid;

	std::cin.ignore();
}


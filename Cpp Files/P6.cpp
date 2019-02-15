#include "P6.h"

P6::P6()
{
	sumOfSquares = squareOfSums = difference = 0;
	start();
}

void P6::start()
{
	std::cout << "Problem 6" << std::endl;
	
	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//calculate the sum of squares of numbers 1-100
	for (int i = 1; i < 101; i++)
		sumOfSquares += i * i;

	//calculate the square of sums of numbers 1-100
	for (int i = 1; i < 101; i++)
		squareOfSums += i;
	squareOfSums *= squareOfSums;

	//calculate difference
	difference = squareOfSums - sumOfSquares;

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print the difference between the sum of squares and the square of sums of numbers 1-100
	std::cout << "The difference between the sum of squares and the square of sums of numbers 1-100 is : "
		<< difference << std::endl;
}
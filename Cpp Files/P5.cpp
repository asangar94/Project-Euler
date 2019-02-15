#include "P5.h"

P5::P5()
{
	num = 0;
	start();
}

void P5::start()
{
	std::cout << "Problem 5" << std::endl;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//keep looping until a number is found
	//increment number while checking all the multiples
	while (true)
		if (checkMulti(num += 20)) break;

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print the smallest multiple of all numbers 1-20
	std::cout << "The smallest multiple of all numbers 1-20 is: " << num << std::endl;
}

bool P5::checkMulti(int num)
{
	//check all multiples 2-19 
	//do not need to check 20 and 1
	for (int i = 19; i > 1; i--)
		if (num % i != 0) return false;

	return true;
}
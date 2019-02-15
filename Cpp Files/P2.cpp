#include "P2.h"

P2::P2()
{
	fib1 = 1;
	fib2 = 2;
	fib3 = 3;
	sumOfEvens = 0;
	start();
}

void P2::start()
{
	std::cout << "Problem 2" << std::endl;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//loop for all fibonacci below 4000000
	while (fib2 < 4000000)
	{
		//add this term to the sum of evens because every 3rd fibonacci number is even
		sumOfEvens += fib2;

		//calculate next set of 3 fibonacci numbers
		fib1 = fib2 + fib3;
		fib2 = fib1 + fib3;
		fib3 = fib1 + fib2;
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " nanoseconds" << std::endl;

	//print sum of all even fibonacci numbers below 4000000
	std::cout << "The sum of all even fibonacci numbers below 4000000: " << sumOfEvens << std::endl;
}


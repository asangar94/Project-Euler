#include "P7.h"

P7::P7()
{
	counter = 0;
	current = 0;
	n = 10001;

	start();
}

void P7::start()
{
	std::cout << "Problem 7" << std::endl;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//check all odd numbers for primality
	//minus 1 from n since we skip evens and therefore did not count 2 in counter
	for (current = 3; counter < n - 1; current += 2)
		if (isPrime(current)) counter++;

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print the nth prime number (minus 2 because the loop incremented current before terminating)
	std::cout << "The 10001st prime number is : " << current - 2 << std::endl;
}

bool P7::isPrime(int num)
{
	for (int i = 3; i < num; i += 2)
		if (num % i == 0) return false;

	return true;
}
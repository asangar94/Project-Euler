#include "P10.h"

P10::P10()
{
	n = sum = 0;
	start();
}

void P10::start()
{
	std::cout << "Problem 10" << std::endl;

	std::cout << "This program will find the sum of all primes below a number n." << std::endl
		  	  << "Enter a number for n (0 = default): ";

	//get value for n
	std::cin >> n;
	
	if (n == 0) n = 2000000;

	//get current time (start)
	auto start = std::chrono::high_resolution_clock::now();

	//allocate dynamic memory for boolean array
	bool *isPrime = new bool[n];

	//initialize array
	for (int i = 0; i < n; i++)
		isPrime[i] = true;

	//find prime numbers and mark any multiples in isPrime[] as false
	//(Sieve of Erastothenes)
	for (int i = 2; i * i < n; i++)
		if (isPrime[i])
			for (int j = i * 2; j < n; j += i)
				isPrime[j] = false;

	//calculate sum of all prime numbers under n
	for (int i = 2; i < n; i++)
		if (isPrime[i]) sum += i;

	//get current time (finish)
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in milliseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << std::endl << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print the sum of prime numbers below n
	std::cout << "The sum of all prime numbers below " << n << " is: " << sum << std::endl;

	delete[] isPrime;

	std::cin.ignore();
}
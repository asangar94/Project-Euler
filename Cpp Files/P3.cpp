#include "P3.h"

P3::P3()
{
	num = save = 600851475143;
	i = 2;
	start();
}

void P3::start()
{
	int temp;

	std::cout << "Problem 3" << std::endl;
	std::cout << "Enter a number (0 = default): ";

	std::cin >> temp;

	if (temp > 0) num = save = temp;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//remove prime factor 2 from num
	//this so the next loop only requires checking odd numbers
	while (num % i == 0)
		num = num / i;
	i++;

	//loop until the square root of the number since the factors 
	//of that number must be within that range
	//This algorithm will find the prime factorization of 
	//a number, as it removes lower prime factors it will replace
	//num with a new number to find a prime factorization for
	while (i * i < num)
	{
		//keep dividing num by i, since i is a prime factor
		//and may been seen multiple times in the prime factorization
		//(i.e. 12 = 3 * 2 * 2, 2 is seen twice)
		while (num % i == 0)
			num = num / i;

		//increment
		i += 2;
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " nanoseconds" << std::endl;

	//print largest prime factor of 600851475143
	std::cout << "The largest prime factor of " << save << " is : " << num << std::endl;

	std::cin.ignore();
}
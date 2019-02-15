#include "P1.h"

P1::P1() 
{ 
	sum15 = sum5 = sum3 = 0;
	mul15 = 15;
	mul5 = 5;
	mul3 = 3;
	start();
};

void P1::start()
{
	std::cout << "Problem 1" << std::endl;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//loop until multiples of 15 are greater than or equal to 1000
	while (mul15 < 1000)
	{
		sum15 += mul15;
		mul15 += 15;

		sum5 += mul5;
		mul5 += 5;

		sum3 += mul3;
		mul3 += 3;
	}

	//continue looping until multiples of 5 are greater than or equal to 1000
	while (mul5 < 1000)
	{
		sum5 += mul5;
		mul5 += 5;

		sum3 += mul3;
		mul3 += 3;
	}

	//continue looping until multiples of 3 are greater than or equal to 1000
	while (mul3 < 1000)
	{
		sum3 += mul3;
		mul3 += 3;
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//output the time taken for program
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << std::endl;
	
	//output the sum of the multiples of 3 and 5 under 1000
	std::cout << "Sum of the multiples of three and five: " << (sum3 + sum5) - sum15 << std::endl;
}



#include "P17.h"
P17::P17() { start(); }

void P17::start()
{
	//one, two, ..., nine
	int ones[10] = { 0,3,3,5,4,4,3,5,5,4 };
	//ten, eleven, ..., nineteen
	int teens[10] = { 3,6,6,8,8,7,7,9,8,8 };
	//twenty, thirty, ..., ninety
	int tens[8] = { 6,6,5,5,5,7,6,6 };

	int sum = 0;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();
	
	//calculate sum of characters of 1-19
	for (int i = 0; i < 10; i++)
		sum = sum + ones[i] + teens[i];

	//calculate sum of characters of 20-99
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 10; j++)
			sum = sum + tens[i] + ones[j];

	//calculate sum of characters of 100-119/200-219/.../900-919
	//100-109 = ones[i] + ones[j] + 10 
	//110-119 = ones[i] + teens[j] + 10
	//the 10 constant for each is for 'hundred and'
	//**this means we must subtract 3 for each number ending in 00 later**
	//**no 'and' for those numbers**
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 10; j++)
			sum = sum + ones[i] + ones[i] + ones[j] + teens[j] + 20;

	//calculate sum of characters of 120-199/220-299/.../920-999
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 10; k++)
				sum = sum + ones[i] + tens[j] + ones[k] + 10;

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " nanoseconds" << std::endl;

	//add 11 (one thousand)
	//**subtract 3 * 9 = 27   100,200,...,900**
	std::cout << sum + 11 - 27 << std::endl;
}
	
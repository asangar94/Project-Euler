#include "P14.h"

P14::P14() { start(); }

void P14::start()
{
	std::cout << "Problem 14" << std::endl;

	//create array of 64 bit integers
	//create integer to store the index of the longest chain
	int64_t *arr = new int64_t[MAX];
	int64_t  maxIndex = 0;

	//initialize array
	for (int64_t i = 0; i < MAX; i++) arr[i] = 0;
	arr[0] = 1;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//populate the array with each number's corresponding chain value
	for (int64_t i = 0; i < MAX; i++)
		chain(arr, i + 1);

	//find the index of the number with the highest chain value in the array
	for (int64_t i = 0; i < MAX; i++)
		if (arr[i] > arr[maxIndex]) maxIndex = i;

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in milliseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " milliseconds" << std::endl;
	
	//print the index + 1 (array starts at 0)
	std::cout << maxIndex + 1 << std::endl;

	delete[] arr;
}

int64_t P14::chain(int64_t *arr, int64_t i)
{
	//check if i is under MAX (array boundary) and if it already exists in the array
	//return the value if so
	if ((i-1) < MAX && arr[i-1] != 0) return arr[i-1];

	//currentChain will keep track of the chain count if the number goes over MAX
	//		and account for the current(1) and recursed chains in the return value
	//temp will be used to calculate the intermediate value if the number goes over MAX
	//		it will remain the same as i if the number does not go over MAX
	int64_t currentChain = 1, temp = i;
	
	//a simple while loop can allow us to calculate values over MAX in a chain without
	//using expensive recursive calls
	while (temp > MAX)
	{
		currentChain++;
		if (temp % 2 == 0) temp /= 2;
		else temp = (3 * temp) + 1;
	}

	//use recursive calls to find the chain (or the rest of the chain if it went over MAX)
	if (temp % 2 == 0) currentChain += chain(arr, temp / 2);
	else currentChain += chain(arr, (3 * temp) + 1);

	//update the array with the current chain value
	if (i - 1 < MAX) arr[i-1] = currentChain;

	return currentChain;
}

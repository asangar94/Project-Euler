#include "P18.h"

P18::P18()
{
	//numEntries = total number of entries in the pyramid (used for input/output/intializing)
	//currIndex will be used to keep track of position in the pyramid
	numEntries = currIndex = 0;
	start();
}

void P18::start()
{
	
	for (int i = 0; i < DEPTH; i++) numEntries += i + 1;

	//create and initialize the array
	int *arr = new int[numEntries];
	readFile(arr, numEntries);

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//iterate once for all but the top row
	for (int i = 0; i < DEPTH - 1; i++)
	{
		//iterate once for every element in the current row
		for (int j = 0; j < (DEPTH - i) - 1; j++)
			//add the greater of the two current elements in the row to the 'parent'
			//increment currIndex
			arr[currIndex++ + (DEPTH - i)] +=
				arr[currIndex] > arr[currIndex + 1] ? 
				arr[currIndex] : arr[currIndex + 1];

		//increment currIndex to compare first two elements of new row
		currIndex++;
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " nanoseconds" << std::endl;

	//print top node of the pyramid
	std::cout << arr[numEntries - 1] << std::endl;

}

void P18::readFile(int *arr, int n)
{
	std::ifstream file("P18_Pyramid.txt");
	if (!file.is_open()) perror("File not found.");

	while (n > 0) file >> arr[--n];
}
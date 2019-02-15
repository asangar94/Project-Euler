#include "P13.h"

P13::P13()
{ 
	sum = 0;
	start(); 
}

void P13::start()
{
	//array for data storage
	//array for summing each place value in the 50-digit number
	//carryDigits = carry digits of the first 42 numbers
	//sumLastEight = sum the last eight digits and the carry digits

	//read data from file
	readFile(inputs);

	for (int i = 0; i < 100; i++)
		for (int j = 13; j > 0; j--)
			numbers[i] += (inputs[i][j - 1] - '0') * pow(10, 13 - j);

	for (int i = 0; i < 100; i++)
		sum += numbers[i];

	while (sum > 9999999999) sum /= 10;

	std::cout << sum << std::endl;
}

//read data from the text file
void P13::readFile(char numbers[100][50])
{
	std::ifstream numberFile;
	numberFile.open("P13_Numbers.txt");

	if (!numberFile.is_open()) perror("File not found.");

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 50; j++)
			numberFile >> numbers[i][j];

}
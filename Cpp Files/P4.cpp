#include "P4.h"

P4::P4()
{
	num1 = num2 = 999;
	largestPali = product = 0;
	start();
}

void P4::start()
{
	std::cout << "Problem 4" << std::endl;

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//brute force search through all 3 digit numbers
	while (num1 > 99)
	{
		while (num2 > 99)
		{
			//get product of two 3 digit numbers
			product = num1 * num2;

			//check if number is a palindrome and if product is greater than
			//the current largest palindrome
			if (isPalindrome(product) && product > largestPali)
				largestPali = product;

			//decrement
			num2--;
		}

		//reset second 3 digit number and decrement first
		num2 = 999;
		num1--;
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " milliseconds" << std::endl;

	//print largest palindrome of two 3 digit numbers
	std::cout << "The largest Palindrome of two 3 digit numbers is : " << largestPali << std::endl;
}

bool P4::isPalindrome(int num)
{
	//get length of number and convert to string for compare
	int len = numLength(num) - 1;
	std::string numString = std::to_string(num);

	//loop half the length since it is comparing from front and back
	//floor the length for odd lengths
	//returns false if numbers are not matching
	for (int i = 0; i <= floor(len / 2); i++)
		if (numString[i] != numString[len - i])
			return false;

	//return true if all numbers matched
	return true;
}

int P4::numLength(int num)
{
	//get length of the number
	int counter = 0;

	for (; num > 0; counter++)
		num /= 10;

	return counter;
}

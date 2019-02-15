#pragma once

#include <iostream>
#include <string>
#include <chrono>

class P4
{
public:

	P4();

	void start();

private:

	bool isPalindrome(int);
	int numLength(int);

	int num1, num2, largestPali, product;

	int64_t num, save, i;
};